#include <stdlib.h>
#include <stdio.h>
#ifdef __cplusplus
extern "C"
{
#endif

int main(void){
    int vertex=0,edge=0,i,x=0;
    char c;
    printf("digraph\n{\n");
    scanf("%d %d",&vertex,&edge);
    for(i=1;i<=vertex;i++){
        printf("  %d [label=\"%d\\n",i,i);
        scanf("%c",&c);
        if(c == '\n'){
            scanf("%c",&c);
        }
        while(c != '\n'){
            printf("%c",c);
            scanf("%c",&c);
        }
        printf("\"];\n");
    }
    printf("\n");
    for (i = 0; i < edge; i++)
    {
        scanf("%d",&x);
        printf("  %d ->",x);
        scanf("%d",&x);
        printf(" %d [label=\"",x);
        scanf("%d",&x);
        printf("%d\"];\n",x);
    }
    printf("}\n");
    return EXIT_SUCCESS;
}


#ifdef __cplusplus
}
#endif