#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C"
{
#endif

	int main(void)
	{
		unsigned long leaves = 0, i = 1, height = 0;
		while ((scanf("%lu\n", &leaves)) != EOF)
		{
			for (height = 0, i = 1; i < leaves; height++)
			{
				i = i << 1;
			}
			printf("%lu\n", height);
		}
		return EXIT_SUCCESS;
	}

#ifdef __cplusplus
}
#endif
