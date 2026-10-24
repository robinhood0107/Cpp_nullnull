#include<stdio.h>
#include<stdlib.h>
int number;
int B[100000];
int limit;

int log_2(int x){
    int ans=0;
    while(x){
        x>>=1;
        ans++;
    }
    return ans;
}
void box_ready(){
    scanf("%d",&number);
    limit = number + log_2(number);
    for(int i = 0;i<number;i++)scanf("%d",B+i);
}

int box_num(){return number;}

int box_comp(int i, int j){
    static int called = 0;
    if(++called>limit){
        printf("WA: limit exceeded\n");
        exit(0);
    }

    if(!(0<=i-1&&i-1<number)||!(0<=j-1&&j-1<number)) return 0;

    if(B[i-1]<B[j-1])return -1;
    else if(B[i-1]>B[j-1])return 1;
    else return 0;
}

void box_report(int w){
    printf("%d\n",w);
    exit(0);
}
