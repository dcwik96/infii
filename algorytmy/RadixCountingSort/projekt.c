#include <stdio.h>
#include <string.h>

int checklin(int lines)
{
  int temp=0;
  FILE *fo = fopen("tosort.txt", "r");
  if(fo == NULL) {
    printf("File not found");
  }
  while(!feof(fo))
  {
      temp=fgetc(fo);
      if(temp == '\n') lines++;
  }
  return lines;
}

unsigned int checklen(unsigned int MAXLength)
{
  char arr[50]; //nazwisko majace wiecej niz 50 znakow ?! nie ma opcji
  FILE *fo = fopen("tosort.txt", "r");
  if(fo == NULL) {
    printf("File not found");
  }
  while(!feof(fo)){
    fgets(arr, 50, fo);
    printf("String read: %s", arr);
    printf ("The sentence entered is %u characters long.\n\n",(unsigned)strlen(arr));

    if ((unsigned)strlen(arr)-1>MAXLength) MAXLength=(unsigned)strlen(arr)-1;
  }
  fclose(fo);
  return MAXLength;
}

void radix_sort(int lines, unsigned int MAXLength, char arr[][lines])
{
  int i,j;

  for ( j = 0; j < lines; j++)
  {
    for (i=MAXLength-1;i>=0;i--) {
    printf("%i", arr[i][j]);
  }
  printf("\n");
  }
}

int main() {
  unsigned int MAXLength=0;
  int lines=0;
  lines=checklin(lines); //sprawdzenie ilosci lini
  MAXLength=checklen(MAXLength); //sprawdzenie maksymalnej dlugosci napisu
  printf("%u\t%i\n", MAXLength,lines);
  char arr[MAXLength][lines];
  memset(arr, 0, MAXLength*lines*sizeof arr[0][0]); //wyczyszczenie tablicy

  FILE *fo;
  fo = fopen("tosort.txt", "r");

  while (!feof(fo)) {
    fscanf(fo,"%s",arr)
  }


  radix_sort(lines,MAXLength,arr);


  return 0;
}
