
#ifndef __ADDRESS_BOOK_H__
#define __ADDRESS_BOOK_H__
/* TODO: Add your structures here */ 
struct Person {
  char* name;
  char* age;
  char* number;
};

struct Address_book {
  int size;
  struct Person (*persons)[];

};

/* Function declarations. Do not modify! Implement those functions in address_book.c */
void print_person(const struct Person* person);
void print_address_book(const struct Address_book* address_book);

struct Address_book* create_address_book(void);
void destroy_address_book(struct Address_book* address_book);

#endif /* __ADDRESS_BOOK_H__ */
