#ifndef SRC_PERSON_H_
#define SRC_PERSON_H_

#include <stdio.h>

typedef struct person_struct {
  char name[21];
  char lastName[21];
  int height;
} person_t;


int readPerson(person_t *P);
void printPerson(person_t *P);

#endif //endif SRC_PERSON_H_
