#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
int main ()
{
  pid_t pid;
  /* wypisuje identyfikator procesu */
  printf("Moj PID = %d\n", getpid());
    /* tworzy nowy proces */
  switch (pid = fork()) {
    case -1: /* błąd */
        perror("Error in fork\n");
    case 0: /* proces potomny */
        printf("Jestem procesem potomnym. Mój PID = %d PPID: %d\n", getpid(),getppid());
        printf("Jestem procesem potomnym. Wartość przekazana przez fork() = %d\n", pid);
        return 0;
    default: /* proces macierzysty */
        printf("Jestem procesem macierzystym. Mój PID = %d PPID: %d\n", getpid(), getppid());
        printf("Jestem procesem macierzystym. Wartość przekazana przez fork() = %d\n", pid);
      /* czeka na zakończenie procesu potomnego */
        if(wait(0) == -1)
          perror("Error in wait\n");
        return 0;
  } /*switch*/
}
