#include<stdio.h>
#include<stdlib.h>
int N;
int L,R;

int QUERY_LIMIT = 35;
void initial(){
    scanf("%d",&N);
    scanf("%d %d",&L,&R);
}

int oil_size(){return N;}

int observe(int i, int j){
    QUERY_LIMIT--;
    if(QUERY_LIMIT<0){
        printf("WA: query limit over\n");
        exit(0);
    }
    if(i>j || 0>i || j>=N)return -1;
    int lp = i<L?L:i;
    int rp = j<R?j:R;

    if(lp>rp)return 0;
    else if(rp-lp==j-i)return 1;
    return 2;
}

void oil_report(int l, int r){
    if(l==L&&r==R)printf("AC");
    else printf("WA: incorrect answer\n");
}
