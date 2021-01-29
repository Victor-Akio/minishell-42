#include <unistd.h>
#include <stdio.h>

int		main(int argc, char *argv[], char **envv)
{
	(void) argc;
	(void) argv;
	int pid;
	// envv++;
	// envv++;
	// while (envv)
	// 	printf("%s\n", (*envv));
	char *args[] = {"echo","-n","aaaa"};
	char *env_args[] = {"PATH=/bin", (char*)0};

	pid = fork();
	if (pid == 0) {
	// Child process
		execve(args[0], args, envv);
	}
}