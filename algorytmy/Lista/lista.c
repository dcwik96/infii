#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*CREATE STRUCTURE*/
struct Node{
  char data[20];
  struct Node *next;
  struct Node *prev;
};

struct Node* head;
struct Node* last;
struct Node* current;

/*CHECK IF LIST IS EMPTY*/
bool isEmpty() {
  return head == NULL;
}

/*ADD DATA AT THE BEGINING OF LIST*/
void AddAtBegin()
{
  char newdata[20];
  printf("Podaj dane ktore chesz dodac na liste: ");
  scanf("%19s",newdata);

  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  strcpy(newNode->data,newdata);

  if(isEmpty()) last = newNode;
  else  head->prev = newNode;

  newNode->next = head;
  head=newNode;
}

/*PRINT WHOLE LIST*/
void PrintNode()
{
  int i=1;
  struct Node* temp = head;
  printf("Drukuje Liste\n");
  while (temp != NULL) {
    printf("%i\t%s\n",i,temp->data);
    temp = temp->next;
    i++;
  }
  printf("\n");
}

/*DELETE DATA FROM LIST WHICH IS GIVEN BY PERSON*/
struct Node* DeleteGiven(char search[])
{
  struct Node* current = head;

  if (head == NULL)
    return NULL;

  while (strcmp(current->data,search) != 0) {
    if (current->next == NULL)  return NULL;
    else  current = current->next;
  }

  if (current == head)  head = head->next;
  else  current->prev->next = current->next;

  if (current == last)  last = current->prev;
  else  current->next->prev = current->prev;

  return current;
}

/*FIND AND PRINT ONE DATA GIVEN BY PERSON*/
struct Node* FindGiven(char search[])
{
  struct Node* current = head;

  if (head == NULL)  return NULL;

  while (strcmp(current->data,search) != 0) {
    if (current->next == NULL)  return NULL;
    else  current = current->next;
  }
printf("%s\n",current->data);
  return current;
}

/*CLEAR ALL LIST --NOT WORKING*/
void ClearAll()
{
  struct Node* current = head;

  while (head != NULL) {
    if (current->next == NULL)  return NULL;
    else  current = current->next;
  }

  if (current == head)  head = head->next;
  else  current->prev->next = current->next;

  if (current == last)  last = current->prev;
  else  current->next->prev = current->prev;

}

/*MAIN*/
int main()
{
  head = NULL;
  char wyb;
  do{
    printf("A-dodaj, D-usun, F-szukaj studenta, S-pokaz liste, C-wyczysc liste, E-zakoncz\n");
    scanf("%c",&wyb);
    switch(wyb) {
      case 'A':
      case 'a':
        AddAtBegin();
      break;
      case 'D':
      case 'd':
        printf("Podaj co chcesz usunąć: ");
        char search[20];
        scanf("%19s",search);
        DeleteGiven(search);
      break;
      case 'F':
      case 'f':
        printf("Podaj czego szukasz: ");
        scanf("%19s",search);
        FindGiven(search);
      break;
      case 'S':
      case 's':
        PrintNode();
      break;
      case 'C':
      case 'c':
        ClearAll();
      case 'E':
      case 'e':
        return 0;
      break;
      default:
      break;
    }
  }
  while(scanf("%c",&wyb));
  return 0;
}
