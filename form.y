%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
extern int yylineno;  

void yyerror(const char *s);
int yylex();

#define MAX_FIELDS 100
char* used_fields[MAX_FIELDS];
int field_count = 0;

bool is_duplicate_field(const char* name) {
    for (int i = 0; i < field_count; i++) {
        if (strcmp(used_fields[i], name) == 0) return true;
    }
    return false;
}

void add_field(const char* name) {
    if (field_count < MAX_FIELDS) {
        used_fields[field_count++] = strdup(name);
    }
}

bool is_valid_field_type(const char* type) {
    const char* valid[] = {
        "text", "number", "password", "email", "date", "file",
        "checkbox", "radio", "dropdown", "textarea"
    };

    for (int i = 0; i < 10; i++) {
        if (strcmp(valid[i], type) == 0) return true;
    }
    return false;
}

char* concat(const char* s1, const char* s2) {
    char* result = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}
%}

//	Defines value types used by tokens
%union {
    char* str;
}

%token <str> IDENTIFIER STRING NUMBER ROWS COLS DEFAULT
%token FORM SECTION FIELD REQUIRED
%token META EQUAL
%token VALIDATE IF ERROR LT
%token OPTIONS TRUE FALSE
%token LBRACKET RBRACKET COMMA
%token COLON SEMICOLON LBRACE RBRACE
%token MIN MAX

//Declares return type of a non-terminal
%type <str> program section field_list field meta_list validate_block form_body option_list
%type <str> rowval colval defval

%%

program:
    meta_list FORM IDENTIFIER LBRACE form_body{
        printf("<!-- Form: %s -->\n", $3);
        printf("<form name=\"%s\">\n%s<div><button type=\"submit\">Submit</button></div>\n</form>\n", $3, $5);
    }
    validate_block RBRACE  {
     }
;

meta_list:
    meta_list meta_stmt { $$ = $1; }
    | /* empty */ { $$ = strdup(""); }
;

meta_stmt:
    META IDENTIFIER EQUAL STRING SEMICOLON {
        printf("<!-- Meta: %s = %s -->\n", $2, $4);
    }
;

//Groups multiple fields under a named section.
section:
    SECTION IDENTIFIER LBRACE field_list RBRACE {
        $$ = $4;
    }
;

field_list:
    field_list field { $$ = concat($1, $2); }
    | field { $$ = $1; }
;

field:
    FIELD IDENTIFIER COLON IDENTIFIER REQUIRED SEMICOLON {
        if (!is_valid_field_type($4)) {
            fprintf(stderr, "Error: Unknown field type '%s' for field '%s' at line %d\n", $4, $2, yylineno);
            YYABORT;            //Force parsing to stop with failure
        }
        if (is_duplicate_field($2)) {
            fprintf(stderr, "Error: Duplicate field '%s' at line %d\n", $2, yylineno);
            YYABORT;
        }
        add_field($2);
        char buffer[256];
        sprintf(buffer, "<div style=\"margin-bottom: 12px;\"><label>%s: <input type=\"%s\" name=\"%s\" required></label></div>\n", $2, $4, $2);

        $$ = strdup(buffer);   //Stores the generated HTML string as the result of this rule
    }

    | FIELD IDENTIFIER COLON IDENTIFIER LBRACKET option_list RBRACKET REQUIRED SEMICOLON {
        if (strcmp($4, "radio") != 0) {
            fprintf(stderr, "Error: Only 'radio' field can have direct options at line %d\n", yylineno);
            YYABORT;
        }
        if (is_duplicate_field($2)) {
            fprintf(stderr, "Error: Duplicate field '%s' at line %d\n", $2, yylineno);
            YYABORT;
        }
        add_field($2);
        char buffer[1024] = "";
        char* options = strdup($6);
        sprintf(buffer, "<div style=\"margin-bottom: 12px;\"><label>%s:</label><br>\n", $2);
        char* token = strtok(options, ",");
        while (token) {
            char line[256];
            sprintf(line, "<input type=\"radio\" name=\"%s\" value=%s> %s<br>\n", $2, token, token);
            strcat(buffer, line);
            token = strtok(NULL, ",");
        }
        strcat(buffer, "</div>\n");
        $$ = strdup(buffer);       
    }

    | FIELD IDENTIFIER COLON IDENTIFIER OPTIONS EQUAL LBRACKET option_list RBRACKET REQUIRED SEMICOLON {
        if (strcmp($4, "dropdown") != 0) {
            fprintf(stderr, "Error: Only 'dropdown' field can use 'options=' at line %d\n", yylineno);
            YYABORT;
        }
        if (is_duplicate_field($2)) {
            fprintf(stderr, "Error: Duplicate field '%s' at line %d\n", $2, yylineno);
            YYABORT;   
        }
        add_field($2);
        char buffer[1024] = "";
        char* options = strdup($8);
        sprintf(buffer, "<div style=\"margin-bottom: 12px;\"><label>%s: <select name=\"%s\" required>\n", $2, $2);
        char* token = strtok(options, ",");
        while (token) {
            char line[256];
            sprintf(line, "<option value=%s>%s</option>\n", token, token);
            strcat(buffer, line);
            token = strtok(NULL, ",");
        }
        strcat(buffer, "</select></label></div>\n");
        $$ = strdup(buffer);
    }

    | FIELD IDENTIFIER COLON IDENTIFIER EQUAL TRUE SEMICOLON {
        if (strcmp($4, "checkbox") != 0) {
            fprintf(stderr, "Error: Only 'checkbox' field can be assigned = true at line %d\n", yylineno);
            YYABORT;
        }
        if (is_duplicate_field($2)) {
            fprintf(stderr, "Error: Duplicate field '%s' at line %d\n", $2, yylineno);
            YYABORT;
        }
        add_field($2);
        char buffer[256];
        sprintf(buffer, "<div style=\"margin-bottom: 12px;\"><label><input type=\"checkbox\" name=\"%s\" checked> %s</label></div>\n", $2, $2);
        $$ = strdup(buffer);
    }

    | FIELD IDENTIFIER COLON IDENTIFIER SEMICOLON {
        if (!is_valid_field_type($4)) {
            fprintf(stderr, "Error: Unknown field type '%s' for field '%s' at line %d\n", $4, $2, yylineno);
            YYABORT;
        }
        if (is_duplicate_field($2)) {
            fprintf(stderr, "Error: Duplicate field '%s' at line %d\n", $2, yylineno);
            YYABORT;
        }
        add_field($2);
        char buffer[256];
        if (strcmp($4, "checkbox") == 0) {
            sprintf(buffer, "<div style=\"margin-bottom: 12px;\"><label><input type=\"checkbox\" name=\"%s\"> %s</label></div>\n", $2, $2);
        } else {
            sprintf(buffer, "<div style=\"margin-bottom: 12px;\"><label>%s: <input type=\"%s\" name=\"%s\"></label></div>\n", $2, $4, $2);
        }
        $$ = strdup(buffer);
    }

    | FIELD IDENTIFIER COLON IDENTIFIER ROWS EQUAL rowval COLS EQUAL colval DEFAULT EQUAL defval SEMICOLON {
        if (strcmp($4, "textarea") != 0) {
            fprintf(stderr, "Error: Only 'textarea' can have rows, cols, and default at line %d\n", yylineno);
            YYABORT;
        }
        if (is_duplicate_field($2)) {
            fprintf(stderr, "Error: Duplicate field '%s' at line %d\n", $2, yylineno);
            YYABORT;
        }
        add_field($2);
        char buffer[512];
        sprintf(buffer, "<div style=\"margin-bottom: 12px;\"><label>%s: <br><textarea name=\"%s\" rows=\"%s\" cols=\"%s\">%s</textarea></label></div>\n",
                $2, $2, $7, $11, $13);
        $$ = strdup(buffer);
    }

    | FIELD IDENTIFIER COLON IDENTIFIER MIN EQUAL STRING MAX EQUAL STRING REQUIRED SEMICOLON {
        if (!(strcmp($4, "number") == 0 || strcmp($4, "date") == 0)) {
            fprintf(stderr, "Error: Only 'number' or 'date' fields can use min/max at line %d\n", yylineno);
            YYABORT;
        }
        if (is_duplicate_field($2)) {
            fprintf(stderr, "Error: Duplicate field '%s' at line %d\n", $2, yylineno);
            YYABORT;
        }
        add_field($2);
        char buffer[512];
        sprintf(buffer, "<div style=\"margin-bottom: 12px;\"><label>%s: <input type=\"%s\" name=\"%s\" min=%s max=%s required></label></div>\n",
                $2, $4, $2, $7, $10);
        $$ = strdup(buffer);
    }
;

//default values for text area
rowval: NUMBER { $$ = $1; };
colval: NUMBER { $$ = $1; };
defval: STRING { $$ = $1; };

form_body:
    form_body section { $$ = concat($1, $2); }
    | form_body validate_block { $$ = concat($1, $2); 
     }
    | section { $$ = $1; }
;

validate_block:
    VALIDATE LBRACE IF IDENTIFIER LT NUMBER LBRACE ERROR STRING SEMICOLON RBRACE RBRACE {
        char buffer[2048];
        char *raw_msg = strdup($9);
        char *msg = raw_msg;

        // Remove surrounding quotes
        int len = strlen(msg);
        if (len >= 2 && msg[0] == '"' && msg[len - 1] == '"') {
            msg[len - 1] = '\0';  // Remove trailing quote
            msg++;                // Skip leading quote
        }

//JavaScript for Validation
        snprintf(buffer, sizeof(buffer),
            "<script>\n"
            "document.querySelector('form').addEventListener('submit', function(e) {\n"
            "    var val = document.forms[0]['%s'].value;\n"
            "    if (Number(val) < %s) {\n"
            "        e.preventDefault();\n"
            "        alert('%s');\n"
            "    }\n"
            "});\n"
            "</script>\n",
            $4, $6, msg
        );
        $$ = strdup(buffer);
    }
    | /* empty */ { $$ = strdup(""); }
;

//Builds a CSV string for options
option_list:
    STRING { $$ = $1; }
    | option_list COMMA STRING {
        char* temp = concat($1, ",");
        $$ = concat(temp, $3);
        free(temp);
    }
;

%%

//Error Handler
void yyerror(const char *s) {
    fprintf(stderr, "Syntax error at line %d: %s\n", yylineno, s);
}

int main() {
    return yyparse();
}