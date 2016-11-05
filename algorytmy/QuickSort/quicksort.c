#include "stdio.h"
#include "time.h"

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
  int pivot = arr[high];    // pivot
  int i = (low - 1);  // Index of smaller element
  for (int j = low; j <= high- 1; j++)
  {
    if (arr[j] <= pivot)    // If current element is smaller than or equal to pivot
    {
      i++;    // increment index of smaller element
      int tmp;
      tmp=arr[i];
      arr[i]=arr[j];
      arr[j]=tmp;
      }
    }
    int tmp;
    tmp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=tmp;
    return (i + 1);
}

void quicksort(int arr[], int low, int high)
{
  if (low < high) //low - p  high - r
  {
    int pi = partition(arr, low, high);
    quicksort(arr, low, pi - 1);
    quicksort(arr, pi + 1, high);
  }
}

void quicksortmodification(int arr[], int low, int high,int bubsize)
{
  if (low < high) //low - p  high - r
  {
    if(high-low+1>=bubsize)
    {
      int pi = partition(arr, low, high);
      quicksortmodification(arr, low, pi - 1,bubsize);
      quicksortmodification(arr, pi + 1, high,bubsize);
    }
    else{
      printf("Sortuje teraz przez bubble\n");
      bubblesort(arr,bubsize);
    }
  }
}

void printarr(int arr[], int size){
  int i;
  for (i=0; i < size; i++)
      printf("%d ", arr[i]);
  printf("\n");
  }

int main() {
  printf("Podaj od jakiego momentu ma tablica byc sortowana by bubblesort\n");
  int bubsize;
  scanf("%i",&bubsize);
  printf("Podaj wielkosc tablicy");
  int size;
  scanf("%i",&size);
  int arr[size];
  printf("Podaj wartosci do tablicy:\n");       //creating array
  int i;
  for (i = 0; i < size; i++) {
    scanf("%i", &arr[i]);
  }

  printarr(arr,size);   //printing array by function
  struct timespec time0, time1;
      /*Data Type: struct timespec
          The struct timespec structure represents an elapsed time. It is declared in time.h and has the following members:
            time_t tv_sec
              This represents the number of whole seconds of elapsed time.
            long int tv_nsec
              This is the rest of the elapsed time (a fraction of a second), represented as the number of nanoseconds. It is always less than one billion.*/
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&time0);   //start clock
  quicksort(arr,0,size);   //start sorting
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&time1);   //end clock
  double finaltime=(time1.tv_sec+time1.tv_nsec/10000.0)-(time0.tv_sec+time0.tv_nsec/10000.0);   //counting final time of sorting

  clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&time0);   //start clock
  quicksortmodification(arr,0,size,bubsize);   //start sorting
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&time1);   //end clock
  double finaltimemodification=(time1.tv_sec+time1.tv_nsec/10000.0)-(time0.tv_sec+time0.tv_nsec/10000.0);

  printf("%f\n%f\n",finaltime,finaltimemodification);
  printarr(arr,size);   //printing array by function


  return 0;
}
