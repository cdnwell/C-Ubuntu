#include <stdio.h>

int main(void){
    int dan;
    printf("단 입력 : ");
    scanf("%d",&dan);

    printf("%d단\n",dan);
    for(int i=1;i<10;i++)
        printf("%d * %d = %d\n",dan,i,dan*i);

    return 0;
}