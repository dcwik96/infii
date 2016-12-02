#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*maksymalna dlugosc slowa*/
#define MAX_DLG 50

/*definiujemy strukturê - napis z dwoma wskanikami na inne struktury*/
typedef struct L{
        char slowo[MAX_DLG+1];
        struct L *next;
        struct L *prev;
}elem;

/*kolejne dwie linijki definiujṗ element pusty NIL, który przypomina nieco wartownika*/
/*linijki te moṡna pominṗæ i uṡywaæ po prostu sġowa NULL (pusty element)*/
elem def_pusty = {"NIL", &def_pusty, &def_pusty};
elem *NIL = &def_pusty;

/*funkcja uzupelnia listy "elem" losowymi danymi i ustawia wskazniki*/
void uzupelnij_liste(elem *w, int size){
     int i, j, k, dlg;
     srand(time(NULL));
     /*petla edytujaca element*/
     for(i=0; i<size; i++){
              dlg = 1 + rand()% MAX_DLG;
              /*petla wstawiajaca losowe litery do slowa z elem*/
              for(j=0; j<dlg; j++){
                       k = 97 + rand()% 26;
                       (w+i)->slowo[j]=k;
              }
              /*reszta slowa zapelniana zerami*/
              for(j=dlg; j<MAX_DLG+1; j++)
                         (w+i)->slowo[dlg]=0;

              /*ustawienie wskaznikow prev i next z "elem"*/
              if (size>1)
                 if (i==0){
                           (w+i)->next = w+i+1;
                           (w+i)->prev = NIL;
                           } else if (i==size-1){
                                  (w+i)->next = NIL;
                                  (w+i)->prev = w+i-1;
                                  }else{
                                       (w+i)->next = w+i+1;
                                       (w+i)->prev = w+i-1;
                                       }
              else {
                   (w+i)->next = NIL;
                   (w+i)->prev = NIL;
                   }
     }

}

/*funkcja wypisuje slowa z listy elementow majac dana jej glowe*/
void wypisz_liste(elem *head){
     int i,j;
     elem *p;
     p = head;
     i = 0;
     while (p != NIL){
           j=0;
           printf("[%d]\t\t",i);
           while((p->slowo[j])!=0) {
                      printf("%c",p->slowo[j]);
                      j++;
           }
           printf("\n");
           p = p->next;
           i++;
     }
}


/*oblicza 2^k*/
int potega_2(int k){
    int i,l=1;
    for (i=1; i<=k; i++)
        l=l*2;
    return l;
}

int main(){
    int k,rozmiar;
    elem *wsk, *head;
    /*elem **head_wsk;  //podwojny wskaznik na potrzeby pracy wewn. funkcji
    head_wsk = &head;*/
    printf("Tworzymy liste o rozmiarze 2^k. Podaj wykladnik k: ");
    scanf("%d", &k);
    rozmiar = potega_2(k);
    wsk = malloc((rozmiar+1)*sizeof(elem));
    uzupelnij_liste(wsk, rozmiar);
    head = wsk;
    printf("\nLista:\n");
    wypisz_liste(head);
    getchar();
    free(wsk);
    return EXIT_SUCCESS;
}
