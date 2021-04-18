#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#ifdef __cplusplus
extern "C" {
#endif
    int main(void)
    {
        int count[UCHAR_MAX + 1] = { 0, };
        int c;
        while ((c = getchar()) != '?') {
            assert(c >= 32 && c <= 127);
            ++count[(unsigned char)c];
        }
        for (c = '!'; c <= '~'; ++c) {
            if (count[c]) {
                printf("%c:%d\n", c, count[c]);
            }
        }
        return EXIT_SUCCESS;
    }
#ifdef __cplusplus
}
#endif