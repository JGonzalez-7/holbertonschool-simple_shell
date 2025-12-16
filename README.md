# Simple Shell

This project focuses on understanding **process control**, **system calls**, **memory management**, and **Unix internals**.

---

## Overview

**Simple Shell** is a custom implementation of a Unix command-line interpreter that mimics basic behavior of `/bin/sh`.  
It supports interactive and non-interactive modes, command execution, environment handling, and basic built-in commands.

---

## Objectives

- Learn how a Unix shell works internally
- Practice using low-level system calls (`fork`, `execve`, `wait`, etc.)
- Understand process creation and execution
- Handle environment variables
- Apply proper memory management in C
- Follow the **Betty coding style**

---

## Features

- Displays a prompt and waits for user input
- Executes commands with or without arguments
- Resolves commands using the `PATH` environment variable
- Graceful error handling
- Handles `Ctrl + D` (EOF)
- Built-in commands:
  - `exit` – exits the shell
  - `env` – prints environment variables
- Works in:
  - **Interactive mode**
  - **Non-interactive mode** (piped input)

---

## Project Tasks & Status

### Task 0 – Project Setup
- `README.md`
- `man_1_simple_shell`
- `AUTHORS`

### Task 1 – Coding Standards
- Code follows **Betty style**
- No memory leaks

### Task 2 – Basic Shell
- Display prompt
- Read and execute commands
- Handle errors
- Handle `Ctrl + D`

### Task 3 – Arguments
- Execute commands with arguments

### Task 4 – PATH Resolution
- Search for executables in `PATH`
- Avoid calling `fork()` if command does not exist

### Task 5 – Built-in: exit
- Exit the shell properly

### Task 6 – Built-in: env
- Print environment variables

---

## Compilation

Compile on **Ubuntu 20.04 LTS** using:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

---

## Contributors
This project was completed as a team effort by:

**Joshua Gonzalez:** [GitHub Profile](https://github.com/JGonzalez-7)
[LinkedIn Profile](https://www.linkedin.com/in/joshua-gonzalez-398b73267/)

Hello, I’m Joshua Gonzalez, one of the developers who worked on this project. Feel free to explore my work and connect with me on LinkedIn. I’m excited about the possibility of collaborating and exchanging ideas with you.

**Alexander Rivas:**
- [GitHub](https://github.com/acrcpr21)
- [LinkedIn](https://www.linkedin.com/in/ar-puertorico01/)

Hi, my name is Alexander Rivas, and I'm a software engineering student.
This project implements a simple UNIX shell, reinforcing concepts like processes, system calls, and memory management. I’m always open to connecting so don't hesitate to check my pages and reach out.
