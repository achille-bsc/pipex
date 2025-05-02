# Pipex Project

## Project Description

The purpose of the `pipex` project is to create a program that mimics the behavior of the shell pipeline. The project involves handling multiple processes, file descriptors, and executing commands in a sequence. Here are the key points:

* The program takes four arguments: an input file, two commands, and an output file.
* It reads from the input file, executes the first command, passes the output of the first command as input to the second command, and writes the final output to the output file.
* The project involves using system calls like `pipe`, `fork`, `dup2`, and `execve` to manage processes and file descriptors.
* The implementation includes error handling for file access and command execution.
* The project is structured with multiple source files and headers, including `src/main.c`, `src/parser.c`, `src/pipex.c`, and `headers/pipex.h`.

## Installation

To compile the project, use the provided `Makefile`. Run the following command in the project directory:

```sh
make
```

This will compile the project and generate the `pipex` executable.

## Usage

To run the `pipex` command, use the following syntax:

```sh
./pipex input_file "command1" "command2" output_file
```

Example usage:

```sh
./pipex infile "ls -l" "grep pipex" outfile
```

This will read from `infile`, execute the `ls -l` command, pass the output to the `grep pipex` command, and write the final output to `outfile`.

## Code Structure

The project is structured with the following files and directories:

* `src/main.c`: The main entry point of the program.
* `src/parser.c`: Contains functions for parsing command-line arguments.
* `src/pipex.c`: Contains the main logic for executing the pipeline.
* `src/cmd_executer.c`: Contains functions for executing commands.
* `headers/pipex.h`: Header file with function declarations and includes.
* `headers/structures.h`: Header file with structure definitions.
* `libft`: Directory containing the `libft` library used by the project.

## System Calls

The project uses the following system calls:

* `pipe`: Creates a pipe, a unidirectional data channel that can be used for interprocess communication.
* `fork`: Creates a new process by duplicating the calling process.
* `dup2`: Duplicates a file descriptor, making it possible to redirect input/output.
* `execve`: Executes a program, replacing the current process image with a new one.

## Error Handling

The project includes error handling for file access and command execution. If an error occurs, appropriate error messages are displayed, and the program exits with a non-zero status code.
