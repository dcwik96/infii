#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <math.h>

int factorial(int n) {
    return n == 0 ? 1 : n * factorial(n - 1);
}

int main() {

  int wynik = 0;
  int n;

  printf("\nPodaj n:");
  scanf("%d", &n);

  int status = fork();

  if (status==-1){
    printf("cos jest zle\n");
  }
  else if (status==0){
    printf("potomek:Witaj!\n");
    //printf("potomek:Podaj n:");
    //scanf("%d", &n);
    wynik = factorial(n);
    printf("potomek:Wynik to: %d\n", wynik);
  }  else {
    printf("rodzic: czekam na wynik\n");
    wait(&wynik);
    printf("rodzic:Poczekalem i koncze program!\n");
  }
}
//-1 nie ma
//1 rodzic
// 0 potomny


// scanf n przed forkiem!!!
