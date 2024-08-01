#include "compressor.h"
#include "files.h"
#include <stdio.h>

int main(int argsc, char **argsv) {

  if (argsc < 2) {
    perror("Missing file name\n");
    return 1;
  }

  char *file_content = ReadFile(argsv[1]);

  printf("%s\n", file_content);

  // char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
  // int freq[] = {5, 9, 12, 13, 16, 45};

  // int size = sizeof(arr) / sizeof(arr[0]);

  // HuffmanCodes(file_content, freq, size);

  return 0;
}
