#include <stdio.h>
#include <stdlib.h>
#ifdef __cplusplus
extern "C" {
#endif
    int main(void) {
    char i;
    while(scanf("%c",&i) != EOF){
        printf("%c",i);
    }
    return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif
