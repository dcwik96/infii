#include<stdio.h>

int main(){

	  char* s = "fqr  b qabxx xryc pqr";
//char* s = "abr";
    int x,y;
	  asm volatile (
          ".intel_syntax noprefix;"
                "mov ebx, %2;"
                "mov eax, 0;"
                "mov ecx, 0;"
        "petla:"
                "mov ecx, 0;"
                "cmp byte ptr [ebx], 'a';"
                "jne sprawdzb;"
                "inc ebx;"
                "inc eax;"
                 "inc ecx;"
                "jmp sprawdznotr;"
        "sprawdzb:"
                "cmp byte ptr [ebx], 'b';"
                "jne sprawdz0;"
                "inc ebx;"
                "inc eax;"
                 "inc ecx;"
        "sprawdznotr:"
                "cmp byte ptr [ebx], 'r';"
                "jne sprawdz1;"
                "inc ebx;"
                 "inc ecx;"
                 "jmp petla;"
        "szukanier:"
                "cmp byte ptr [ebx], 'r';"
                "jne sprawdz1;"
								"inc ecx;"
                "jmp wyjscie;"
        "sprawdz0:"
                 "cmp byte ptr [ebx], 0;"
                 "je wyjscie;"
                 "inc ebx;"
                 "inc eax;"
                 "jmp petla;"
        "sprawdz1:"
                 "cmp byte ptr [ebx], 0;"
                 "je wyjscie;"
                 "inc ebx;"
                 "inc ecx;"
                 "jmp szukanier;"
				"wyjscie:"
                "mov %0, eax;"
                "mov %1, ecx;"

                ".att_syntax prefix;"
                :"=r" (x), "=r" (y)
                :"r" (s)
                :"eax", "ebx", "ecx"
							);
  	printf("[ab][^r]=%hd\n +r=%hd\n", x, y);
		return 0;
}
