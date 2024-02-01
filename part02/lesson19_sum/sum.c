/*nie widze dlaczego spoj nie zalicza mi tego rozwiazania*/
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C"
{
#endif

    int compare(const void *a, const void *b);
    int binarySearch(unsigned int arr[], int low, int high, unsigned int key);

    int compare(const void *a, const void *b)
    {
        return (*(unsigned int *)a - *(unsigned int *)b);
    }
    

    int binarySearch(unsigned int arr[], int low, int high, unsigned int key)
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] == key)
                return 1;

            if (arr[mid] < key)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return 0;
    }

    int main(void)
    {
        unsigned int n,m,i=0,x = 0,found,j;
        unsigned int *mleko = NULL;
        unsigned int *nutella = NULL;
        if ((scanf("%u %u\n",&n,&m)) != 2)
        {
            fprintf(stderr, "Failed to read 2 integers.\n");
            return EXIT_FAILURE;
        }
        mleko = (unsigned int *)malloc(n * sizeof(unsigned int));
        nutella = (unsigned int *)malloc(n * sizeof(unsigned int));

        if (mleko == NULL || nutella == NULL)
        {
            fprintf(stderr, "Memory allocation failed.\n");
            return EXIT_FAILURE;
        }
        for(i=0;i<n;i++){
            if (scanf("%u", &mleko[i]) != 1)
            {
                fprintf(stderr, "Failed to read integer.\n");
                return EXIT_FAILURE;
            }
        }
        for(i=0;i<n;i++){
            if (scanf("%u",&nutella[i]) != 1)
            {
                fprintf(stderr, "Failed to read integer.\n");
                return EXIT_FAILURE;
            }
        }

        qsort(nutella, n, sizeof(unsigned int), compare);

        for (i = 0; i < m; i++)
        {
            if (scanf("%u", &x) != 1)
            {
                fprintf(stderr, "Failed to read integer.\n");
                return EXIT_FAILURE;
            }

            found = 0;
            for (j = 0; j < n; j++)
            {
                if(mleko[j] < x){
                    if (binarySearch(nutella, 0, n - 1, x - mleko[j]))
                    {
                        found = 1;
                        break;
                    }
                    if (found)
                        break;
                }
            }

            if (found)
                printf("TAK\n");
            else
                printf("NIE\n");
        }
        free(mleko);
        free(nutella);
        return EXIT_SUCCESS;
    }

#ifdef __cplusplus
}
#endif
