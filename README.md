\# Unix Shell


A lightweight Unix-style command shell written in C to explore process creation and management on POSIX systems.


\#\# Features


\- Executes standard Unix commands such as \`ls\`, \`pwd\`, and \`date\`

\- Supports commands with arguments such as \`ls \-l\`

\- Creates child processes using \`fork()\`

\- Executes programs using \`execvp()\`

\- Waits for foreground processes using \`waitpid()\`

\- Supports background execution with \`&\`

\- Reaps completed background processes using \`WNOHANG\`

\- Handles invalid commands and process creation errors

\- Supports \`exit\` and \`quit\`


\#\# Example


\`\`\`text

mysh\> pwd

/Users/example/unix-shell


mysh\> ls \-l

...


mysh\> sleep 5 &

\[background process 12345 started\]


mysh\>

\[background process 12345 finished\]

```

## Build

On macOS or Linux:

```bash
clang -std=c11 -Wall -Wextra -pedantic shell.c -o shell
```

## Run

```bash
./shell
```

## Concepts Practiced

- Process creation with `fork()`
- Program execution with `execvp()`
- Parent and child processes
- Foreground and background execution
- Process synchronization with `waitpid()`
- Background process cleanup
- Basic command parsing
- Error handling for process creation and command execution