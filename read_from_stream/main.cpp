
#include <cstdio>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
  // Create a pipe, descriptor [0] is the read side
  // of the pipe, [1] is the write
  int fd[2];
  pipe(fd);
  
  fprintf(stdout, "Starting the application\n");

  // Remember, pid == 0 is what the child sees
  auto pid = fork();

  // The child executes the second instruction, reading
  // from the pipe the result of the first
  if (pid == 0) {
    fprintf(stdout, "I am the child\n");
    // Before calling execvp make sure that the reading end of
    // the pipe is set of stdin
    dup2(fd[0], 0);
    // Close all the other file descriptors
    close(fd[0]);
    close(fd[1]);
    // Remember, exec family of functions don't return
    // Whatever file descriptors exist at this point are
    // inherited by the new process
    execvp("head", argv);
  } else {
    fprintf(stdout, "I am the parent\n");
    // The parent forks a second process. The forked process
    // is executed first, and its ouput is fed to the second
    // via the pipe
    auto pid2 = fork();
    if (pid2 == 0) {
      dup2(fd[1], 1);
      close(fd[1]);
      close(fd[0]);
      execvp("ls", argv);
    }
  }
  
  // Make sure the parent closes the pipe, otherwise the
  // child processes may be left hanging
  close(fd[0]);
  close(fd[1]);

  // Two waits, to wait for the two forked processes
  wait(nullptr);
  wait(nullptr);
  fprintf(stdout, "Finishing parent process\n");
  return 0;
}
