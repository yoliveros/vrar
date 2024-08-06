// #include "compressor.h"
#include "files.h"
#include "freq.h"
#include <stdio.h>

int main(int argsc, char **argsv) {
  if (argsc < 2) {
    perror("Missing file name\n");
    return 1;
  }

  char *file_content = ReadFile(argsv[1]);

  int *freq = GetFreq(file_content);
  printf("%p\n", (void *)freq);

  // int size = file_content->total / sizeof(file_content->content[0]);

  // HuffmanCodes(file_content->content, freq->f_arr, size);

  return 0;
}
