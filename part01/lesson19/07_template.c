#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#ifdef __cplusplus
extern "C" {
#endif
static int findOffs(unsigned char const * base, int size, int a, int b) {
  int result = 0;
  while (size >= 2) {
    if (base[0] == a && base[1] == b) {
      return result;
    }
    size   -= 2;
    result += 2;
    base   += 2;
  }
  return -1;
}
int main(void) {
  static unsigned char const PL_LETTERS [2][9 * 2] = {
    {0xc4,0x85, 0xc4,0x87, 0xc4,0x99, 0xc5,0x82, 0xc5,0x84, 0xc3,0xb3, 0xc5,0x9b, 0xc5,0xbc, 0xc5,0xba},
    {0xc4,0x84, 0xc4,0x86, 0xc4,0x98, 0xc5,0x81, 0xc5,0x83, 0xc3,0x93, 0xc5,0x9a, 0xc5,0xbb, 0xc5,0xb9}
  };
  int a = getchar();
  while (a >= 0) {
    int b = getchar();
    int offs = -1;
    if (b >= 0) {
      int i = 0;
      while (i < 2) {
        /* find special char offset in array */
        if ((offs = findOffs(PL_LETTERS[i], sizeof(PL_LETTERS[i]), a, b)) >= 0) {
          /* ok, found special char */
          i ^= 1; /* change index array to opposite */
          putchar(PL_LETTERS[i][offs]);
          putchar(PL_LETTERS[i][++offs]);
          a = getchar();
          break;
        }
        ++i;
      }
    }
    if (offs < 0) {
      /* special char has not been found */
      putchar(isupper(a) ? tolower(a) : toupper(a));
      a = b;
    }
  }
  return EXIT_SUCCESS;
}
#ifdef __cplusplus
}
#endif
