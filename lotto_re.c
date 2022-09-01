#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//배열을 출력하는 함수
void PrintAllArray(int * arr){
    for(int i=0;i<7;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

//배열이 중복되었는지 체크하는 함수
int ArrayCheck(int * arr, int n){
    // 1 = 배열이 중복되었다. 0 = 배열이 중복되지 않았다.
    for(int i=0;i<7;i++){
        if(arr[i]==n) return 1;
    }
    return 0;
}

int main(void){
    int lotto[7] = {0};
    int tmp, cmp_result;

    srand((unsigned int)time(NULL));

    for(int i=0;i<7;i++){
        tmp = rand()%45 +1;
        if(cmp_result = ArrayCheck(lotto,tmp)){
            i--;
            continue;
        }
        lotto[i]=tmp;
    }

    PrintAllArray(lotto);

    return 0;
}