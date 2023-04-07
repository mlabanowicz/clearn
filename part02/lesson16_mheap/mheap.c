#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifdef __cplusplus
extern "C"
{
#endif

    void del(int index, int array[]);

    void add(int a, int array[]);

    void dump(int array[]);

    void dump(int array[])
    {
        int i, j = 1, x = j, max, z = 1;
        max = array[0];
        printf("%d: [", max);
        for (i = 1; i <= max; i++)
        {
            x--;
            printf("%d ", array[i]);
            if (x == 0)
            {
                printf(" [");
                j = j << 1;
                x = j;
                z++;
            }
        }
        for (i = 0; i < z; i++)
        {
            printf("] ");
        }
        printf("\n");
    }

    void add(int a, int array[])
    {
        int index, parent, temp;
        array[0]++;
        index = array[0];
        array[index] = a;
        temp = index;
        if (index % 2 == 1)
        {
            temp--;
        }
        while (index > 1)
        {

            parent = temp / 2;
            /*       printf("\nLOG:parent = %d index = %d temp = %d\n",parent,temp,index);*/
            if (array[parent] > array[index])
            {
                array[index] = array[parent];
                array[parent] = a;
            }
            index = parent;
            temp = index;
        }
    }

    void del(int index, int array[])
    {
        int leaf, temp;
        int max = array[0];
        if (index != max)
        {
            array[index] = array[max];
        }
        array[0]--;
        max = array[0];
        while (1)
        {
            leaf = index * 2;
            if (leaf < max){
            temp = array[index];
            if (array[index] > array[leaf])
            {
                array[index] = array[leaf];
                array[leaf] = temp;}
            }
            else
            {
                leaf++;
                if (leaf < max){
                if (array[index] > array[leaf])
                {
                    array[index] = array[leaf];
                    array[leaf] = temp;
                }}
                else
                {
                    temp = index;
                    if(index % 2 == 1){
                        temp--;
                    }
                    leaf = index/2;
                    temp = array[index];
                    if (array[index] < array[leaf])
                    {
                        array[index] = array[leaf];
                        array[leaf] = temp;
                    }
                    else{
                        break;
                    }
                }
            }
            index = leaf;
        }
    }
    int main(void)
    {
        int array[100] = {0};
        char input[20];
        char *str;
        int val;
        const char delim[] = " \n";

        while (fgets(input, 20, stdin))
        {
            str = strtok(input, delim);

            if (strcmp(str, "dump") == 0)
            {
                dump(array);
            }
            else if (strcmp(str, "add") == 0)
            {
                str = strtok(NULL, delim);
                val = atoi(str);
                add(val,array);
            }
            else if (strcmp(str, "get") == 0)
            {
                printf("%d\n",array[1]);
            }
            else if (strcmp(str, "del") == 0)
            {
                str = strtok(NULL, delim);
                val = atoi(str);
                del(val,array);
            }
            else{
                printf("cos poszlo nie tak :/\n");
            }
        }

        return 0;
    }

#ifdef __cplusplus
}
#endif