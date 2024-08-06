#include "compressor.h"
#include "files.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *GetFreq(char *file) {
  size_t increase = LOWER;
  size_t allocated = increase;
  int *f_arr = calloc(allocated, sizeof(int));
  size_t total_file = strlen(file);
  // printf("%s", file);
  // printf("%lo\n", total_file);
  size_t total;

  for (total = 0; total < total_file; total++) {
    f_arr[file[total] - 'a']++;
    // printf("%c, %d\n", file[total], f_arr[file[total]]);

    if (total >= allocated) {
      if (increase >= UPPER)
        increase = UPPER;

      allocated += increase;

      f_arr = realloc(f_arr, allocated);

      increase *= 2;
    }
  }

  // for (int i = 0; f_arr[i] != '\0'; i++) {
  //   char c = 'a' + i;
  //   printf("%c, %d\n", c, f_arr[i]);
  // }

  f_arr = realloc(f_arr, total);
  return f_arr;
}

int main(int argsc, char **argsv) {
  if (argsc < 2) {
    perror("Missing file name\n");
    return 1;
  }

  char *file_content = ReadFile(argsv[1]);
  // char *c = file_content;

  // while (c != NULL) {
  //   printf("%c", *c++);
  // }

  int *freq = GetFreq(file_content);
  printf("%p\n", (void *)freq);

  // for (int i = 0; freq[i] != '\0'; i++) {
  // char c = 'a' + i;
  // printf("");
  // printf("%c, %d\n", c, freq[i]);
  // }

  // int size = file_content->total / sizeof(file_content->content[0]);

  // HuffmanCodes(file_content->content, freq->f_arr, size);

  return 0;
}
