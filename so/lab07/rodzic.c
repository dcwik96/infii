#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main() {
  if (fork()==0)
    execl("/home/pracinf/mmiotk/SystemyOperacyjneDema/potomek","potomek",NULL);
  else
    while (1) {
      printf("Proces rodzicielski\n");sleep(5);
    }
}
