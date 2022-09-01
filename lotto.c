#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//배열을 출력하는 함수
void PrintArray(int * array){
    for(int i=0;i<7;i++){
        printf("%d ",array[i]);
    }   
    printf("\n");
}

//배열에 중복된 값이 있는지 검사하는 함수
int CheckArray(int * array, int cmp_num){
    for(int i=0;i<7;i++){
        if(array[i]==cmp_num) return 1;
    }
    return 0;
}

int main(void){
    int lotto[7] = {0};
    int cmp_result, tmp;

    srand((unsigned int)time(NULL));

    for(int i=0;i<7;i++){
        tmp = rand()%45+1;
        cmp_result = CheckArray(lotto,tmp);
        if(cmp_result == 1){
            i--;
            continue;
        }
        lotto[i] = tmp;
    }

    printf("로또 번호 : ");
    for(int i=0;i<7;i++){
        printf("%d ",lotto[i]);
    }
    printf("\n");

    return 0;
}