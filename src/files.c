#include "files.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

FileContent *ReadFile(char *file_name) {
  FILE *file = fopen(file_name, "r");
  size_t increase = LOWER;
  size_t allocated = increase;
  FileContent *my_content = malloc(sizeof(FileContent));
  my_content->content = malloc(allocated);
  // my_content->total = 0;

  while (!feof(file) && !ferror(file)) {
    my_content->content[my_content->total++] = fgetc(file);

    if (my_content->total >= allocated) {
      if (increase >= UPPER)
        increase = UPPER;

      allocated += increase;

      my_content->content = realloc(my_content->content, allocated);

      increase *= 2;
    }
  }

  if (ferror(file)) {
    perror("Error reading from file");
    return NULL;
  }

  my_content->content = realloc(my_content->content, my_content->total);
  my_content->content[my_content->total - 1] = '\0'; // NULL

  fclose(file);
  return my_content;
}

void WriteFile() {}
