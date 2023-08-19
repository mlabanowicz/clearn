#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int front_gear;
    int rear_gear;
} GearCombination;

int compareGearCombinations(const void *a, const void *b);

int compareGearCombinations(const void *a, const void *b) {
    GearCombination *comb1 = (GearCombination *)a;
    GearCombination *comb2 = (GearCombination *)b;
    
    return (comb1->front_gear * comb2->rear_gear) - (comb2->front_gear * comb1->rear_gear);
}

int main(void) {
    int N, M, i, j;
    int rear_gear;
    GearCombination *combinations;
    if (scanf("%d", &N) != 1) {
        fprintf(stderr, "Failed to read integer.\n");
        return EXIT_FAILURE;
    }
    
    combinations = (GearCombination *)malloc(N * sizeof(GearCombination));
    for (i = 0; i < N; i++) {
        if (scanf("%d", &combinations[i].front_gear) != 1) {
            fprintf(stderr, "Failed to read integer.\n");
            return EXIT_FAILURE;
        }
    }
    
    if (scanf("%d", &M) != 1) {
        fprintf(stderr, "Failed to read integer.\n");
        return EXIT_FAILURE;
    }
    
    for (j = 0; j < M; j++) {
        if (scanf("%d", &rear_gear) != 1) {
            fprintf(stderr, "Failed to read integer.\n");
            return EXIT_FAILURE;
        }
        
        for (i = 0; i < N; i++) {
            combinations[i].rear_gear = rear_gear;
        }

        qsort(combinations, N, sizeof(GearCombination), compareGearCombinations);
        
        for (i = 0; i < N; i++) {
            printf("%d/%d\n", combinations[i].front_gear, combinations[i].rear_gear);
        }
    }
    
    free(combinations);
    return EXIT_SUCCESS;
}
