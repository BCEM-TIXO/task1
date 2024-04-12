#include <stdio.h>
#include <stdlib.h>

#include "person.h"

int main() {
  int n, H;

  if (scanf("%d", &n) != 1) {
    printf("n/a");
    return 1;
  }

  person_t *persons = (person_t*)calloc(n, sizeof(person_t));
  if (persons != NULL) {
      printf("n/a");
      return 1;
  }
  for (int i = 0; i < n; ++i) {
    if (readPerson(persons+i) != 3) {
      printf("n/a");
      free(persons);
      return 1;
    }
  }
  if (scanf("%d", &H) != 1) {
    printf("n/a");
    return 1;
  }
  int flag = 1;
  for (int i = 0; i < n; ++i) {
    if (persons[i].height >= H) {
      flag = 0;
      printPerson(persons+i);
      if (i < n-1) {
        printf(", ");
      }
    }
  }
  if (flag) {
    printf("Nothing");
  }
  free(persons);
  return 0;
}