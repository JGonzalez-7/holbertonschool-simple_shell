# Simple Shell

A minimal Unix shell written in C, built as part of the Holberton School curriculum.

---

## Overview

**Simple Shell** is a custom implementation of a Unix command-line interpreter that mimics basic behavior of `/bin/sh`.  
It supports interactive and non-interactive modes, command execution, environment handling, and basic built-in commands.

This project focuses on understanding **process control**, **system calls**, **memory management**, and **Unix internals**.

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

```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh