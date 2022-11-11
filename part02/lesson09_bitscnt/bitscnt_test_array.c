#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include <utils.h>

#ifdef __cplusplus
extern "C"
{
#endif

    int main(void)
    {
        size_t size = 0, result = 0;
        void *data = UTILS_LoadFile(stdin, &size);
        result = UTILS_BitsCountByArray(data, size);
        /* chcialem zeby probram wypisywal mi tez binarna postac ale jak przesuwam bity w lewo to te najwyzsze sie chyba nie zeruja(10000000>>1 = 100000000)?  */
        /* edit wydaje mi sie ze nawet jak mamy 8 bitowy wartosc to po operacji << x moze byc to 8 + x bitowa wartosc? (i jaki to jest tyop danych long int lub long double),*/
        /* po type castingu sie udalo :)*/
        printf("\n\njedyneczki ---> %ld\n\n", (unsigned long)result);
        free(data);

        return EXIT_SUCCESS;
    }

#ifdef __cplusplus
}
#endif
