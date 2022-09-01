#include <stdio.h>

int main(void){
    int n1,count=0;
    printf("정수 입력 : ");
    scanf("%d",&n1);
    int list[n1];

    for(int i=1;i<=n1;i++){
        if(n1%i == 0)
            list[count++]=i;
    }

    for(int i=0;i<count;i++)
        printf("%d ",list[i]);
    
    printf("\n");

    return 0;
}