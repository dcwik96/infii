#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  int n;
  int a;
  printf("Rodzic: \n");
  switch (fork())
  {
    case -1:
      printf("BLAD\n");
    case 0:
      printf("Podaj n: \n");
      scanf("%d",&n);
      a = 3*n*n-2*n+4;

    case 1:  printf("Wynik to: %d\n",a);
      return 0;

    default:
      wait(NULL);
      printf("\nRodzic: poczekalem\n");
  }
  return EXIT_SUCCESS;
}
