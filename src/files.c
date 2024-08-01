#include "files.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LOWER 1024
#define UPPER 65536

char *ReadFile(char *file_name) {
  FILE *file = fopen(file_name, "r");
  size_t increase = LOWER;
  size_t allocated = increase;
  char *my_file = malloc(allocated);

  size_t total = 0;

  while (!feof(file) && !ferror(file)) {
    my_file[total++] = fgetc(file);

    if (total >= allocated) {
      if (increase >= UPPER)
        increase = UPPER;

      allocated += increase;

      my_file = realloc(my_file, allocated);

      increase *= 2;
    }
  }

  if (ferror(file)) {
    perror("Error reading from file");
    return NULL;
  }

  my_file = realloc(my_file, total);
  my_file[total - 1] = '\0'; // NULL

  fclose(file);
  return my_file;
}

int GetFreq() { return 0; }

void WriteFile() {}
