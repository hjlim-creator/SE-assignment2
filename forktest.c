#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>


int main(){


  int pid = fork();

  if (pid < 0)  //error
  {
     printf("Error: Creating process failed \n");
  }

  else if (pid == 0)     //child process
  {
     printf("child process: my pid = %d\n", getpid());
     printf("child process: my parent pid = %d\n", getppid());
     return 0;
  }


  else     // pid > 0,  parent process
  {
     printf("parent process: my pid = %d\n", getpid());
	      printf("parent process: my child pid = %d\n", pid);
     wait(NULL);
     return 0;
  }


} //end main


