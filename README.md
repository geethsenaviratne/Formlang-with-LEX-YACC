# FormLang++ – A Domain-Specific Language for Generating HTML Forms


## 📌 Overview

FormLang++ is a **Domain-Specific Language (DSL)** designed to simplify and streamline the creation of HTML forms. Built as part of the Programming Paradigms module at SLIIT, this project focuses on providing a high-level, declarative syntax for defining forms—abstracting away the verbose and error-prone nature of raw HTML form development.

The system is developed using **Flex (Lex)** and **Bison (Yacc)** to tokenize, parse, and generate clean HTML output based on `.form` files written in FormLang++ syntax.

---

## 🎯 Core Objectives

- ✅ Simplify HTML form creation using intuitive DSL syntax  
- ✅ Enforce structural and semantic validation during parsing  
- ✅ Generate clean, semantic, and fully functional HTML form code  

---

## ✨ Key Features

- 🔹 **Custom Lexer & Parser**  
  Designed with Flex and Bison to tokenize `.form` files, validate grammar, and build Abstract Syntax Trees (ASTs).

- 🔹 **EBNF Grammar Design**  
  Supports metadata, sections, form fields (text, number, radio, checkbox, dropdown, etc.), and validation blocks.

- 🔹 **Validation Rules**  
  Includes conditional logic (e.g., `if age < 18 then error`) to provide user-friendly validation feedback.

- 🔹 **Automatic HTML Code Generation**  
  Transforms DSL input into fully structured and styled HTML output.

- 🔹 **Error Handling**  
  Offers detailed syntax and semantic error messages, closely simulating behavior of modern compilers.

---

## 🧠 What I Learned

This project significantly enhanced my understanding of:

- Compiler construction (lexical analysis, parsing, semantic analysis)
- EBNF grammar design and implementation
- Modular software architecture
- Real-world applications of domain-specific languages
- Practical use of Flex and Bison for language development

---

## 🔧 Technologies Used

- **Flex (Lex)** – Token generation  
- **Bison (Yacc)** – Grammar parsing  
- **C/C++** – Compiler back-end logic  
- **HTML/CSS** – Output generation  

---

## 📁 Project Structure

FormLang++/
├── lexer.l # Flex lexer definition
├── parser.y # Bison parser rules
├── main.c # Entry point and integration
├── html_generator.c # HTML output generator
├── form_examples/ # Sample .form DSL files
├── output_html/ # Generated HTML files
└── README.md # Project documentatio
