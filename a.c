#include <unistd.h>
#include <stdio.h>

int main(){
	int pid;
	char *args[] = {"echo","-n","aaaa"};

	pid = fork();
	if (pid == 0) {
	// Child process
	if (execvp(args[0], args) == -1) {
		perror("lsh");
	}
	}
}