#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

static int walk(int const * array, int height, int leaf)
{
    int index = (int)(pow(height+1,2)-pow(height,2) + leaf-1);
    int sum=0;
    while(index != 0){
    sum += array[index];
    if(index % 2 == 1){
      index = (index -1) / 2;
    }
    else{
      index = index/2;
    }
    }
    return sum;
}


int main(void)
{
  int btree [] = {0/*unused*/, 6, 2, 4, 2, 0, 1, 3 };

  int r;

  r = walk(btree, 2, 3);

  printf("%d\n", r);

  return EXIT_SUCCESS;
}

#ifdef __cplusplus
}
#endif
