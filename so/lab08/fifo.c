#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
  int fd[2];
  int r;
  r = pipe(fd);
  if (r == -1){
    perror ("Error in pipe");
    exit (1);
  }
  else{
    pid_t pid = fork();
    if (pid < 0){
      perror("Error in fork");
      exit(1);
    }
  else if (pid == 0){
    char buf[BUFSIZ];
    read(fd[0],buf,12);
    printf("Proces potomny: %s",buf);
  }
  else {
    printf("Proces rodzicielski\n");
    write(fd[1],"PiszeRodzic",12);
  }
 }
putchar('\n');
return EXIT_SUCCESS;
}
