#include "person.h"

int readPerson(person_t *P) {
  return scanf("%s\n", P->name) + scanf("%s\n", P->lastName) + scanf("%d", &(P->height));
}

void printPerson(person_t *P) {
  printf("%s %s", P->name, P->lastName);
}