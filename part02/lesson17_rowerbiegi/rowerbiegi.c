#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int front_gear;
    int rear_gear;
} GearCombination;

int compareGearCombinations(const void *a, const void *b);

int compareGearCombinations(const void *a, const void *b)
{
    GearCombination const *comb1 = (GearCombination *)a;
    GearCombination const *comb2 = (GearCombination *)b;

    return (comb1->front_gear * comb2->rear_gear) - (comb2->front_gear * comb1->rear_gear);
}

int main(void)
{
    int N, M, i, j, *front_gear, rear_gear;
    GearCombination *combinations, previousCombination;
    if (scanf("%d", &N) != 1)
    {
        fprintf(stderr, "Failed to read integer.\n");
        return EXIT_FAILURE;
    }
    front_gear = (int *)malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
    {
        if (scanf("%d", &front_gear[i]) != 1)
        {
            fprintf(stderr, "Failed to read integer.\n");
            return EXIT_FAILURE;
        }
    }
    if (scanf("%d", &M) != 1)
    {
        fprintf(stderr, "Failed to read integer.\n");
        return EXIT_FAILURE;
    }
    combinations = (GearCombination *)malloc(N * M * sizeof(GearCombination));
    for (j = 0; j < M; j++)
    {
        if (scanf("%d", &rear_gear) != 1)
        {
            fprintf(stderr, "Failed to read integer.\n");
            return EXIT_FAILURE;
        }
        for (i = 0; i < N; i++)
        {
            combinations[N * j + i].front_gear = front_gear[i];
            combinations[N * j + i].rear_gear = rear_gear;
        }
    }
    qsort(combinations, N * M, sizeof(GearCombination), compareGearCombinations);

    previousCombination = combinations[0];
    printf("%d/%d\n", previousCombination.front_gear, previousCombination.rear_gear);
    for (i = 1; i < M * N; i++)
    {
        if (compareGearCombinations(&combinations[i], &previousCombination) != 0)
        {
            printf("%d/%d\n", combinations[i].front_gear, combinations[i].rear_gear);
        }
        previousCombination = combinations[i];
    }
    free(combinations);
    free(front_gear);
    return EXIT_SUCCESS;
}
