# minishell-42
Even a broken clock will be right at least twice per day.

## Instructions
- `make` - Compile everything and get ready!
- `./minishell` - Run and the pronpt should appear.

## Project
To better understand the bash and other functionalities, a simple shell.
Our own Bash written in C.
The project develop our capabilities to handle with file descriptors, poping up the concept of pipe(), dup(), wait(),
which was very fun. Being able to discover how fork() and execve() works to call the commands properly in child processes.
That enables lots of possibilities when solving future problems.

There are a few considerations to be remebered:
- This shell was made using the rules and conditions of the 2020 subject;
- Termcap is not implemented in this project.

## Useful Links
- [42 Docs - Minishell](https://harm-smits.github.io/42docs/projects/minishell);
- [Making your own minishell](https://www.geeksforgeeks.org/making-linux-shell-c/);
- [Bash - concepts](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/bash.html);
`Please, do remeber that the best source of information is the manual (man)`