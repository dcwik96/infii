#include "stdio.h"


int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
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

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index*/
void quicksort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);
    quicksort(arr, low, pi - 1);
    quicksort(arr, pi + 1, high);
  }
}

void printarr(int arr[], int size){
  int i;
  for (i=0; i < size; i++)
      printf("%d ", arr[i]);
  printf("\n");
  }

int main() {
  printf("Podaj wielkosc tablicy");
  int size;
  scanf("%i",&size);
  int arr[size];
  printf("Podaj wartosci do tablicy:\n");
  int i;
  for (i = 0; i < size; i++) {
    scanf("%i", &arr[i]);
  }

  printarr(arr,size);
  quicksort(arr,0,size);
  printarr(arr,size);


  return 0;
}
