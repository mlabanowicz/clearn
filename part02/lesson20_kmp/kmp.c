#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *inputString(FILE *fp);
void computeT(char *W, int M, int *T);
void KMPSearch(char *W, char *S);

char *inputString(FILE *fp) {
    char *str = NULL;
    int ch;
    size_t len = 0;
    const size_t chunk = 16;

    while (EOF != (ch = fgetc(fp)) && ch != '\n') {
        if (len % chunk == 0) {
            char *temp = realloc(str, (len + chunk + 1) * sizeof(char));
            if (temp == NULL) {
                free(str);
                return NULL;
            }
            str = temp;
        }
        str[len++] = ch;
    }
    str[len] = '\0';

    return str;
}

void computeT(char *W, int M, int *T) {
    int len = 0;
    int i = 1;
    T[0] = 0;
    while (i < M) {
        if (W[i] == W[len]) {
            len++;
            T[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = T[len - 1];
            } else {
                T[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char *W, char *S) {
    int M = strlen(W);
    int N = strlen(S);

    int *T = (int *)malloc(M * sizeof(int));

    int i = 0;
    int j = 0;
    int count = 0;

    if (T == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }
    
    computeT(W, M, T);

    while (i < N) {
        if (W[j] == S[i]) {
            j++;
            i++;
        }

        if (j == M) {
            count++;
            j = T[j - 1];
        } else if (i < N && W[j] != S[i]) {
            if (j != 0) {
                j = T[j - 1];
            } else {
                i = i + 1;
            }
        }
    }
    printf("%d\n", count);
    free(T);
}

int main(void) {
    char *W = inputString(stdin);
    char *S = inputString(stdin);

    if (S == NULL || W == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(S);
        free(W);
        return EXIT_FAILURE;
    }

    KMPSearch(W, S);

    free(S);
    free(W);
    return EXIT_SUCCESS;
}