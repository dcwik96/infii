#include <stdio.h>

int main(void) {
  char *s = "fqr  b qabxx xryc pqr";//21 znakow
  int x,y;
  asm volatile (
    ".intel_syntax noprefix;"
    "xor eax,eax;"
    "xor ebx,ebx;"
    "xor ecx,ecx;"
    "mov ebx,%2;"
  "petla:"
    "mov al,[ebx];"
    "sub al, 0;"
    "cmp al, 'q';"
    "jz wyjscie;"
    "inc ecx;"
    "inc ebx;"
    "jmp petla;"
  "wyjscie:"
    "mov %0, eax;"
    "mov %1,ecx;"
    ".att_syntax prefix;"
    :"=r" (x), "=r" (y)
    :"r" (s)
    :"eax","ebx","ecx"
  );
  printf("%hd,%hd\n",x,y );
  return 0;
}
