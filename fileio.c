#include <stdio.h>

void ex01(){
    FILE * file = fopen("t1.txt","wt");

    if(file == NULL){
        printf("파일 포인터 생성 실패\n");
        return;
    }

    fprintf(file,"안녕하세요 %d\n",25);
    fprintf(file,"안녕하세요 %d\n",245);
    fprintf(file,"안녕하세요 %d\n",259);
    fprintf(file,"안녕하세요 %d\n",525);

    fputs("Hello\n",file);
    fputs("hello world\n",file);

    fclose(file);

}

void ex02(){
    FILE* file = fopen("t1.txt","rt");

    if(file == NULL){
        printf("파일 포인터 생성에 실패하였습니다.");
        return;
    }

    while(1){
        char buffer[1024];
        if(fgets(buffer,sizeof(buffer),file)==NULL) break;

        printf("%s",buffer);
    }

    fclose(file);

}

typedef struct {
    char name[20];
    int age;
}Member;

void ex03(){
    Member arr[3]={
        {"김철수",20},
        {"이영수",35},
        {"임영희",65}
    };
    //wb = write - binary

    FILE * file = fopen("member.dat","wb");

    if(file == NULL){
        printf("파일 포인터 생성 실패\n");
        return;
    }

    fwrite(arr,sizeof(Member),3,file);

    fclose(file);
}

void ex04(){
    Member arr[3];
    FILE* file = fopen("member.dat","rb");
    int i=0;

    if(file == NULL){
        printf("바이너리 파일 포인터 생성 실패\n");
        return;
    }
    
    while(fread(&arr[i],sizeof(Member),1,file)) i++;

    for(int i=0;i<3;i++){
        printf("%s %d\n",arr[i].name, arr[i].age);
    }


}

void ex05(){
    FILE* fp;
    int err = fopen_s(&fp, "t2.txt", "w");
    
    if(err != 0){
        printf("파일 포인터 생성 실패\n");
        return;
    }

    fclose(fp);
}

int main(void){
    //ex01();
    //ex02();
    //ex03();
    //ex04();
    ex05();
    
    return 0;
}