\# Unix Shell

&nbsp;

A lightweight Unix-style command shell written in C to explore

process creation and management on POSIX systems.

&nbsp;

\#\# Features

&nbsp;

\- Executes standard Unix commands such as \`ls\`, \`pwd\`, and \`date\`

\- Supports commands with arguments such as \`ls \-l\`

\- Creates child processes using \`fork()\`

\- Executes programs using \`execvp()\`

\- Waits for foreground processes using \`waitpid()\`

\- Supports background execution with \`&\`

\- Reaps completed background processes using \`WNOHANG\`

\- Handles invalid commands and process creation errors

\- Supports \`exit\` and \`quit\`

&nbsp;

\#\# Example

&nbsp;

\`\`\`text

mysh\> pwd

/Users/example/unix-shell

&nbsp;

mysh\> ls \-l

...

&nbsp;

mysh\> sleep 5 &

\[background process 12345 started\]

&nbsp;

mysh\>

\[background process 12345 finished\]

&nbsp;