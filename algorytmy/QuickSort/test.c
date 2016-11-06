#include "stdio.h"
#include <stdlib.h>
#include <time.h>

void printarr(int arr[], int size){
  int i;
  for (i=0; i < size; i++)
      printf("%d ", arr[i]);
  printf("\n");
  }

void createarr(int revarr1[],int size){
  int i;
  int j=size;
  for(i=0;i<size;i++)
    {revarr1[i]=j;
    j=j-1;}
}

int main() {
  printf("Podaj od jakiego momentu ma tablica byc sortowana by bubblesort\n");
  int bubsize;
  scanf("%i",&bubsize);
  printf("Podaj wielkosc tablicy");
  int size;
  scanf("%i",&size);
  int revarr1[size];

  createarr(revarr1,size);
  printarr(revarr1,size);
  return 0;
}
