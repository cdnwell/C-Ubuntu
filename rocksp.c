#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    //바위-1 가위-2 보-3
    int draw = 0, win = 0, lose = 0;
    char *str[3] = {"바위","가위","보"};
    srand((unsigned int)time(NULL));
    int rocksp;
    int com;

    for(int i=0;i<5;i++){
        printf("가위 - 2 바위 -1 보 -3 입력 : ");
        scanf("%d",&rocksp);
        
        com = rand()%3 + 1;

        printf("사용자 : %s\n",str[rocksp-1]);
        printf("컴퓨터 : %s\n",str[com-1]);
        if(com == rocksp){
            draw++;
            printf("비겼습니다.\n");
        }else if(com%3+1 == rocksp){
            printf("컴퓨터가 이겼습니다.\n");
            lose++;
        }else{
            printf("사용자가 이겼습니다..\n");
            win++;
        }

    }

    printf("win : %d lose : %d draw : %d\n",win,lose,draw);

    return 0;
}