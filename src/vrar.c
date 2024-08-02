#include "compressor.h"
#include "files.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *f_arr;
  size_t total;
} Freq;

Freq *GetFreq(FileContent *file) {
  Freq *freq = malloc(sizeof(Freq));
  size_t increase = LOWER;
  size_t allocated = increase;
  freq->f_arr = calloc(allocated, sizeof(int));

  for (freq->total = 0; freq->total < file->total; freq->total++) {
    freq->f_arr[file->content[freq->total] - 'a']++;

    if (freq->total >= allocated) {
      if (increase >= UPPER)
        increase = UPPER;

      allocated += increase;

      freq->f_arr = realloc(freq->f_arr, allocated);

      increase *= 2;
    }
  }

  freq->f_arr = realloc(freq->f_arr, freq->total);
  return freq;
}

int main(int argsc, char **argsv) {
  if (argsc < 2) {
    perror("Missing file name\n");
    return 1;
  }

  FileContent *file_content = ReadFile(argsv[1]);

  Freq *freq = GetFreq(file_content);

  // for (size_t i = 0; i < freq->total; i++)
  //   printf("%c, %d\n", file_content->content[i], freq->f_arr[i]);

  // int size = file_content->total / sizeof(file_content->content[0]);

  // HuffmanCodes(file_content->content, freq->f_arr, size);

  return 0;
}
