#include <stdio.h>
#include <stdlib.h>

// 1. enum으로 EXIT, INSERT, SEARCH, DELETE, PRINT_ALL 열거형 변수 생성
// 2. struct 구조체 생성 익명 구조체 정의
// 3. 익명 구조체 배열 20개 생성
// 4. idx 전역변수 설정
// 5. InsertMember 함수 생성 - 이름 입력, 나이 입력, 성별 입력, 성별 앞에는 띄어쓰기(엔터가 남아있음)
// 6. SearchMember 함수 생성 - 검색할 이름 입력, 
//strcmp (같으면 0을 반환)함수 사용해 같은 이름 있는지 확인
// 7. DeleteMember 함수 작성, 검색할 이름 입력 후 이름 기준으로 배열 앞으로 땡기기
// 8. PrintAllMember 함수 생성
// 9. main 함수 생성

enum {
    EXIT, INSERT, SEARCH, DELETE, PRINT_ALL
};

typedef struct{
    char name[30];
    int age;
    char gender;
}Member;

Member arr[20] = {
    {"홍길동",57,'M'},
    {"김영수",42,'M'},
    {"이진선",37,'F'},
    {"진석설",72,'F'},
    {"박정진",27,'M'}
};

int idx = 5;

void InsertMember(){
    printf("이름 입력 : ");
    scanf("%s",&arr[idx].name);
    printf("나이 입력 : ");
    scanf("%d",&arr[idx].age);
    printf("성별 입력 : ");
    scanf(" %c",&arr[idx].gender);

    idx++;
}

void SearchMember(){
    char name[30];

    printf("검색할 이름 입력 : ");
    scanf("%s",name);

    for(int i=0;i<idx;i++){
        if(!strcmp(arr[i].name,name)){
            printf("%s %d %c\n",arr[i].name,arr[i].age,arr[i].gender);
            return;
        }
    }

    printf("데이터가 없습니다.\n");
}

void DeleteMember(){
    char name[30];

    printf("삭제할 멤버 이름 : ");
    scanf("%s",name);

    for(int i=0;i<idx;i++){
        if(!strcmp(arr[i].name,name)){
            for(int j=i;j<idx-1;j++){
                arr[j]=arr[j+1];
            }
            idx--;
            return;
        }
    }

    printf("삭제할 데이터가 없습니다.");
}

void PrintAllMember(){
    for(int i=0; i<idx;i++){
        printf("%s %d %c\n",arr[i].name,arr[i].age,arr[i].gender);
    }
}

int main(void){
    int n = -1;

    while(n != 0){
        printf("---멤버 조회 서비스---\n");
        printf("1. 멤버 정보 입력\n");
        printf("2. 멤버 검색\n");
        printf("3. 멤버 삭제\n");
        printf("4. 멤버 전체 조회\n");
        printf("0. 종료\n");
        printf("메뉴 번호 입력 : ");
        scanf("%d",&n);

        switch(n){
        case 1:
            InsertMember();
            break;
        case 2:
            SearchMember();
            break;
        case 3:
            DeleteMember();
            break;
        case 4:
            PrintAllMember();
            break;
        default:
            break;
        }
    }

    return 0;
}