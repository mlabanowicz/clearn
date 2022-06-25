
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 0x100000
#endif

int main(void) {

  int result = EXIT_SUCCESS;

  char * buffer = (char *)malloc(BUFFER_SIZE);

  if (buffer) {

    size_t len;

    while ((len = fread(buffer, 1, BUFFER_SIZE, stdin)) > 0) {

      size_t wr = fwrite(buffer, 1, len, stdout);

      if (wr != len) {

        fprintf(stderr,
          "Failed to write data to output len=%lu != wr=%lu\n",
          (unsigned long)len, (unsigned long)wr
        );

        result = EXIT_FAILURE;

        break;
      }
    }

    free(buffer);

  } else {

    fprintf(stderr,
      "Failed to allocate %lu bytes!\n",
      (unsigned long)BUFFER_SIZE
    );

    result = EXIT_FAILURE;
  }

  return result;
}

#ifdef __cplusplus
}
#endif

