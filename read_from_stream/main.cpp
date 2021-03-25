
#include <cstdio>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
  // Create a pipe
  int fd[2];
  pipe(fd);
  
  fprintf(stdout, "Starting the application\n");

  auto pid = fork();
  int parent_stdout = dup(1);
  
  if (pid == 0) {
    fprintf(stdout, "I am the child\n");
    dup2(fd[0], 0);
    close(fd[0]);
    close(fd[1]);
    execvp("head", argv);
  } else {
    fprintf(stdout, "I am the parent\n");
    dup2(fd[1], 1);
    close(fd[1]);
    close(fd[0]);
    execvp("ls", argv);
    wait(nullptr);    
  }

  dup2(parent_stdout, 1);
  close(parent_stdout);
  fprintf(stdout, "This should be printed to the terminal\n");

  return 0;
}
