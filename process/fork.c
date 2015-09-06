#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
pid_t pid;
int rv;
switch(pid = fork()){

	case -1:
	perror("fork");
	exit(1);
	case 0:
	printf("CHILD, I AM CHILD PROCESS\n");
	printf("CHILD,MY PROCESS ID IS = %d\n", getpid() );
	printf("CHILD,MY PARENT PROCESS ID = %d\n", getppid() );
	printf("CHILD,Please enter your exit status:");
	scanf("%d", &rv);
	printf("CHILD,Recv outta");
	exit(rv);
	default:
	printf("PARENT, I AM PARENT\n");
	printf("PARENT, MY PROCESS ID IS = %d\n",getpid() );
	printf("PARENT, MY PARENT PROCESS ID IS = %d\n",getppid() );
	printf("MY CHILD PROCESS ID IS = %d\n",pid );
	printf("I am waitting the CHILD\n");
	wait(&rv);
	printf("PARENT, MY child exit status is: %d\n", WEXITSTATUS(rv) );
	printf("PARENT, I AM outta\n");




}
return 0;
}
