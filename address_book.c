#include "address_book.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_person(const struct Person *person){

  printf("Name: %s", person->name);
  printf("Age: %s", person->age);
  printf("Phone number: %s", person->number);
}

void print_address_book(const struct Address_book *address_book){
  int i;
  for(i = 0; i<address_book->size;i++){

    print_person(*(address_book->persons)+i);
 
  }
}

struct Address_book *create_address_book(){
  int size, i;
  printf("Set size: ");
  scanf("%d", &size);

  struct Address_book* book;
  book = (struct Address_book*)malloc(sizeof(struct Address_book));//pointer to book
  if (!book) return NULL;
  book->size = size; 

  book->persons = malloc(sizeof(struct Person)*size);

  char buffer[100];
  fgets(buffer, 100, stdin);
  for(i = 0;i<book->size; i++){

    printf("Enter name of record %d: ", i+1);
    fgets(buffer, 100, stdin);
    (*(book->persons)+i)->name=malloc(strlen(buffer)+1);
    strcpy((*(book->persons)+i)->name, buffer);

    printf("\nEnter age of record %d: ", i+1);
    fgets(buffer, 100, stdin);
    (*(book->persons)+i)->age=malloc(strlen(buffer)+1);
    strcpy((*(book->persons)+i)->age, buffer);


    printf("\nEnter phone number of record %d: ", i+1);
    fgets(buffer, 100, stdin);
    (*(book->persons)+i)->number=malloc(strlen(buffer)+1);
    strcpy((*(book->persons)+i)->number, buffer);
  }
  return book;
}

void destroy_address_book(struct Address_book *address_book){
  int i;
  for (i = 0;i<address_book->size;i++){
    free((*(address_book->persons)+i)->name);
    free((*(address_book->persons)+i)->age);
    free((*(address_book->persons)+i)->number);
    free(*(address_book->persons)+i);
  }
  free(address_book);
}


int main(){
  struct Address_book *address_book = create_address_book();
  print_address_book(address_book);
  destroy_address_book(address_book);
  return 0;
}
