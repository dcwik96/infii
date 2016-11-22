/*
 Demonstration of least significant digit (LSD) radix sort of strings
 Specifically UK vehicle registration numbers
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PLATELENGTH 7
#define ALPHABET 26

/* Characters must be uppercase or digits */
void lsd_string_sort(char* a[], const int length, int string_size) {
   int R = ALPHABET;
   int W = string_size;
   const int N = length;
   char id = 0;
   char *aux = malloc(length * string_size);

   for(int d = W-1; d >= 0; d--) {
      int* count = (int*)calloc(R+1, sizeof(int));
      /* whether character or digit */
      id = (*(a[0]+d) >= '0' && *(a[0]+d) <= '9') ? '0' : 'A';
      /* Compute frequency counts */
      for(int i = 0; i < N; i++)
         count[*(a[i]+d) - id + 1]++;
      /* transform counts to indices */
      for(int r = 0; r < R; r++)
         count[r+1] += count[r];
      /* distribute to temp array */
      for(int i = 0; i < N; i++)
          aux[count[(*(a[i]+d) - id)]++] = a[i];
      /* copy back to original array */
      for(int i = 0; i < N; i++)
         a[i] = aux[i];

      free(count);
   }
   free(aux);
}


int main() {

   /* in real application would use re-sizing array */
   char* plates[1000] = {0};

   int arr[10] = {0};
   char plate[16];  /* extra space just in case */
   int n = 0;
   printf("Please enter list of UK registration plates (skip spaces between registration numbers)\n");
   while(scanf("%15s", plate) == 1) {
      plates[n++] = strdup(plate);
   }

   printf("List before sorting\n");
  	for(int i = 0; i < n; i++) puts(plates[i]);

	 lsd_string_sort(&plates[0], n, PLATELENGTH);

   printf("List after sorting\n");
   for(int i = 0; i < n; i++)
      printf("%s\n", plates[i]);

   while(n > 0)
      free(plates[--n]);

   return 0;
}
