//       {m                              dla n=0
//f(n,m)={1                              dla n=1
//       {0                              dla n=2
//       {f(n-1,m)+2*f(n-2,m)-f(n-3,m)   w pozostałych przypadkach
//(1)Pierwszy argument przekazywany przez rejestr EBX, pozostałe argumenty przekazywane przez stos.
//(2)Wynik zwracany przez rejestr ECX.
//(3)Za uporządkowanie stosu odpowiada wywołujący funkcję.
//(4)Wywoływana funkcja musi zachować wszystkie rejesty(oprócz rejestru, w którym zwracany jest wynik).

.intel_syntax noprefix
	.globl main
  .text

main:
	mov eax,10       //zmienna m
  mov ebx,4          //zmienna n
  xor ecx,ecx
  xor edx,edx
  push eax			//przekazanie m przez stos
  call f            //wywołanie funkcji
	add esp, 4		//czyszczenie stosu
//wypisanie wyniku
  push ecx
	push offset msg
	call printf
  add esp,8
  ret
  mov eax,0
	ret
f:
  mov ecx,0           //zerowanie rejestru z wynikiem
//zapamietane rejestrow na stosie
  push ebp
  mov ebp, esp	   //zapamietanie miejsca stosu
  push eax
  push ebx
  push edx
//******************
//wczytanie zmiennej m[eax] przez stos
  mov eax, [ebp+8]
//******************

//przypadek n=0
  cmp ebx,0
  jne a1
  mov ecx,eax
  jmp koniec
a1:
//******************
//przypadek n=1
  cmp ebx,1
  jne a2
  mov ecx,1
  jmp koniec
a2:
//******************
//przypadek n=2
  cmp ebx,2
  jne a3
  mov ecx,0
  jmp koniec
a3:
//******************
//pozostałe przypadki
//f(n-1,m)
  push ebx			//zapamietanie wartosci n
  sub ebx,1           //ustawienie ebx na n-1
  push ecx            //zapamietanie wyniku
//wywołanie funkcji
  push eax
  call f
  add esp, 4
  pop edx				//do edx wpisujemy ostatnia wartość na stosie czyli stare ecx
  add ecx,edx			//do nowego wyniku dodajemy stary
  pop ebx				//przywaracamy stare n
//******************
//2*f(n-2,m)
  push ebx            //zapamietanie wartosci n
  sub ebx,2           //ustawienie ebx na n-2
  push ecx            //zapamietanie wyniku
//wywołanie funkcji
  push eax
  call f
  add esp, 4
  pop edx				//do edx wpisujemy ostatnia wartość na stosie czyli stare ecx
  add ecx,ecx         //podwajamy nowy wynik (bo 2*f(n-2,m))
  add ecx,edx         //do nowego wyniku dodajemy stary
  pop ebx             //przywaracamy stare n
//******************
//-f(n-3,m)
  push ebx            //zapamietanie wartosci n
  sub ebx,3           //ustawienie ebx na n-3
  push ecx            //zapamietanie wyniku

  push eax
  call f
  add esp, 4

  pop edx             //do edx wpisujemy ostatnia wartość na stosie czyli stare ecx
  sub edx,ecx         //od starego wyniku odejmujemy nowy (bo -f(n-3,m))
  mov ecx,edx         //przenosimy wynik do ecx
  pop ebx             //przywaracamy stare n
//******************

koniec:
//przywracanie rejestrów
  pop edx
  pop ebx
  pop eax
  pop ebp
//******************
  ret

	.data
msg:	.asciz "Wynik:%d\n"
	.byte 0
