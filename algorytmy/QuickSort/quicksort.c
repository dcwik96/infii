#include "stdio.h"
#include <stdlib.h>
#include <time.h>
#define MLD 100000.0
void printarr(int arr[], int size){
  int i;
  for (i=0; i < size; i++)
      printf("%d ", arr[i]);
  printf("\n");
  }

void createarr(int revarr1[],int revarr2[],int ranarr1[],int ranarr2[],int size){
  int i=0;
  int j=size;
  srand( time( NULL ) );
  for(i=0;i<size;i++)
  {
    revarr1[i]=j;
    revarr2[i]=j;
    j--;
  }
  for(i = 0; i < size; i++ )
  {
    ranarr1[i]=rand()%100;
    ranarr2[i]=ranarr1[i];
  }

}

void bubblesort(int arr[], int n)
{
  int i, j;
  for (i = 0; i < n-1; i++)
    for (j = 0; j < n-i-1; j++)
      if (arr[j] > arr[j+1])
      {
        int tmp;
        tmp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=tmp;
      }
}

int partition (int arr[], int low, int high)
{
  int tmp=0;
  int pivot = arr[high];    // pivot
  int i = (low - 1);  // Index of smaller element
  for (int j = low; j <= high- 1; j++)
  {
    if (arr[j] <= pivot)    // If current element is smaller than or equal to pivot
    {
      i++;    // increment index of smaller element
      tmp=arr[i];
      arr[i]=arr[j];
      arr[j]=tmp;
      }
    }
    tmp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=tmp;
    return (i + 1);
}

void quicksort(int arr[], int low, int high)
{
  //printarr(arr,high);
  if (low < high) //low - p  high - r
  {
    int pi = partition(arr, low, high);
    quicksort(arr, low, pi - 1);
    quicksort(arr, pi + 1, high);
  }
  //printarr(arr,high);
}

void quicksortmodification(int arr[], int low, int high,int bubsize)
{
  //printarr(arr,high);
  if (low < high && high-low+1>=bubsize)
  {
    int pi = partition(arr, low, high);
    quicksortmodification(arr, low, pi - 1,bubsize);
    quicksortmodification(arr, pi + 1, high,bubsize);
  }
  if (low < high && high-low+1<bubsize) {
    printarr(arr,high);
    printf("Sortuje teraz przez bubble\n");
    bubblesort(arr,bubsize);
  }
}

int main() {
  printf("Podaj od jakiego momentu ma tablica byc sortowana by bubblesort\n");
  int bubsize;
  scanf("%i",&bubsize);
  printf("Podaj wielkosc tablicy");
  int size;
  scanf("%i",&size);
  int revarr1[size];
  int revarr2[size];
  int ranarr1[size];
  int ranarr2[size];
  createarr(revarr1,revarr2,ranarr1,ranarr2,size);

  struct timespec time0, time1;
      /*Data Type: struct timespec
          The struct timespec structure represents an elapsed time. It is declared in time.h and has the following members:
            time_t tv_sec
              This represents the number of whole seconds of elapsed time.
            long int tv_nsec
              This is the rest of the elapsed time (a fraction of a second), represented as the number of nanoseconds. It is always less than one billion.*/
  printf("\nQS niekorzystna\n");
  //printarr(revarr1,size);
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&time0);   //start clock
  quicksort(revarr1,0,size-1);   //start sorting
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&time1);   //end clock
  double finaltime1=(time1.tv_sec+time1.tv_nsec/MLD)-(time0.tv_sec+time0.tv_nsec/MLD);   //counting final time of sorting
  printarr(revarr1,size);
  printf("\nQS+BS niekorzystna\n");
  //printarr(revarr2,size);
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&time0);   //start clock
  quicksortmodification(revarr2,0,size-1,bubsize);   //start sorting
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&time1);   //end clock
  double finaltime2=(time1.tv_sec+time1.tv_nsec/MLD)-(time0.tv_sec+time0.tv_nsec/MLD);   //counting final time of sorting
  printarr(revarr2,size);
  printf("\nQS losowa\n");
  //printarr(ranarr1,size);
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&time0);   //start clock
  quicksort(ranarr1,0,size-1);   //start sorting
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&time1);   //end clock
  double finaltimemodification1=(time1.tv_sec+time1.tv_nsec/MLD)-(time0.tv_sec+time0.tv_nsec/MLD);
  printarr(ranarr1,size);   //printing array by function
  printf("\nQS+BS losowa\n");
  //printarr(ranarr2,size);
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&time0);   //start clock
  quicksortmodification(ranarr2,0,size-1,bubsize);   //start sorting
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&time1);   //end clock
  double finaltimemodification2=(time1.tv_sec+time1.tv_nsec/MLD)-(time0.tv_sec+time0.tv_nsec/MLD);
  printarr(ranarr2,size);   //printing array by function

  printf("Czasy sortowań:\nQuickSort  tablica odwrotna:%f\ttablica randomowa%f\n",finaltime1,finaltimemodification1);
  printf("QuickSort+BubbleSort  tablica odwrotna:%f\ttablica randomowa%f\n",finaltime2,finaltimemodification2);
  return 0;
}
