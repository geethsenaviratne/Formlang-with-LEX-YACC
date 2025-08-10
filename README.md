<!DOCTYPE html>
<html lang="en">
<head>

</head>
<body>

  <h1>FormLang++ – A Domain-Specific Language for Generating HTML Forms</h1>

  <p>
    <img src="https://upload.wikimedia.org/wikipedia/en/5/5f/SLIIT_Logo.png" alt="SLIIT Logo" width="120" />
  </p>


  <hr />

  <h2>📌 Overview</h2>
  <p>
    <strong>FormLang++</strong> is a <em>Domain-Specific Language (DSL)</em> designed to simplify the creation of HTML forms.
    Developed as part of the Programming Paradigms module at SLIIT, this project introduces a high-level, declarative syntax
    for form definition, which is then parsed and compiled into clean HTML using <strong>Lex (Flex)</strong> and <strong>Yacc (Bison)</strong>.
  </p>

  <hr />

  <h2>🎯 Core Objectives</h2>
  <ul>
    <li>✅ Streamline form creation using an intuitive DSL syntax</li>
    <li>✅ Ensure structural and semantic validation during parsing</li>
    <li>✅ Generate fully functional and styled HTML form output</li>
  </ul>

  <hr />

  <h2>✨ Key Features</h2>
  <ul>
    <li><strong>🔹 Custom Lexer & Parser</strong><br />Built using Flex and Bison to tokenize <code>.form</code> DSL files and generate ASTs.</li>
    <li><strong>🔹 EBNF Grammar Design</strong><br />Includes metadata, sections, multiple field types (text, radio, dropdown, etc.), and validation blocks.</li>
    <li><strong>🔹 Validation Rules</strong><br />Allows logic-based checks (e.g., <code>if Age &lt; 18</code>) with helpful error reporting.</li>
    <li><strong>🔹 HTML Code Generator</strong><br />Outputs fully-structured HTML with correct tag hierarchy and styling.</li>
    <li><strong>🔹 Error Handling</strong><br />Provides detailed syntax and semantic error feedback during compilation.</li>
  </ul>

  <hr />

  <h2>🧠 Learning Outcomes</h2>
  <p>
    Through this project, I gained hands-on experience in:
  </p>
  <ul>
    <li>Compiler construction (lexing, parsing, semantic analysis)</li>
    <li>Designing formal grammars using EBNF</li>
    <li>Building modular C programs</li>
    <li>Real-world applications of DSLs for automation and productivity</li>
  </ul>

  <hr />

  <h2>🔧 Technologies Used</h2>
  <ul>
    <li><strong>Flex (Lex)</strong> – Lexical analysis</li>
    <li><strong>Bison (Yacc)</strong> – Grammar parsing</li>
    <li><strong>C</strong> – Compiler logic and integration</li>
    <li><strong>HTML/CSS</strong> – Form output</li>
  </ul>

  <hr />

  <h2>📁 Project Structure</h2>

  <pre><code>
FormLang++/
├── lexer.l             # Lex (Flex) lexer rules
├── parser.y            # Yacc (Bison) grammar rules
├── main.c              # Main driver program
├── html_generator.c    # HTML code generation logic
├── html_generator.h    # Header for HTML generator
├── ast.h               # AST structure definitions
├── ast.c               # AST builder and utilities
├── error_handling.c    # Error reporting logic
├── form_examples/      # Sample .form DSL input files
├── output_html/        # Directory for generated HTML outputs
└── README.md           # Project documentation
  </code></pre>
    <hr />

  <h2>🚀 Getting Started</h2>

  <h3>Prerequisites</h3>
  <p>Make sure the following tools are installed:</p>
  <ul>
    <li>Flex</li>
    <li>Bison</li>
    <li>GCC / Clang (C compiler)</li>
  </ul>

  <h3>Build & Run</h3>
  <pre><code>
flex lexer.l
bison -d parser.y
gcc -o formlang++ parser.tab.c lex.yy.c main.c html_generator.c -lfl
./formlang++ form_examples/sample.form
  </code></pre>
  <p>Generated HTML will be saved inside the <code>output_html/</code> folder.</p>

  <hr />

  <h2>📄 Sample DSL Input (<code>sample.form</code>)</h2>
  <pre><code>
form "User Registration"
section "Personal Info"
    text "Name"
    number "Age"
    radio "Gender" ["Male", "Female", "Other"]
end

validation
    if Age &lt; 18 then error "You must be at least 18 years old."
end
  </code></pre>

  <hr />

  <h2>🖼 Sample Output (HTML)</h2>
  <pre><code>
&lt;form&gt;
  &lt;label&gt;Name:&lt;/label&gt;
  &lt;input type="text" name="Name" required /&gt;

  &lt;label&gt;Age:&lt;/label&gt;
  &lt;input type="number" name="Age" required /&gt;

  &lt;label&gt;Gender:&lt;/label&gt;
  &lt;input type="radio" name="Gender" value="Male" /&gt;
  &lt;input type="radio" name="Gender" value="Female" /&gt;
  &lt;input type="radio" name="Gender" value="Other" /&gt;

  &lt;!-- Validation Script --&gt;
&lt;/form&gt;
  </code></pre>

  <hr />

  <h2>📬 Contact</h2>
  <p>
    If you have any questions or feedback, feel free to open an issue or reach out.
  </p>

  <blockquote>
    &copy; 2025 Geeth Senavirathna<br/>
    Project submitted for Programming Paradigms @ SLIIT
  </blockquote>

</body>
</html>


</body>
</html>
