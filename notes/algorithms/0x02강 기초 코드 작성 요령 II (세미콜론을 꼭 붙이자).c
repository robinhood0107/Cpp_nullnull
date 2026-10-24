#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
// 백준 2752
/*
int swap(int* x, int* y) {
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
    return 0;
}
int p2752() {
    int a, b, c = 0;
    scanf("%d %d %d", &a, &b, &c);

    int tmp;
    int arr[3] = { a, b, c };
    for (int j = 0; j < 2; j++) {
        for (int i = j + 1; i < 3; i++) {
            if (arr[j] > arr[i])
                swap(&arr[j], &arr[i]);
        }
    }
    printf("%d %d %d", arr[0], arr[1], arr[2]);
}
*/

// 가장 기본적인 정렬 방식인 버블 정렬을 이용해서 풀이 함(가장 간단하게 구현할 수 있는 정렬법)
// 버블정렬은 첫번째로 전부 다 비교해서 교환하고, 그 다음 두번째 수랑 전부랑 비교해서 교환하고... 이방식임(시간복잡도 n제곱, 공간복잡도 n)
// 
//(여담)선택정렬의 경우 전체에서 최소 찾고 저장 후 이제 나머지에서 또 최소 찾고... 이방식임(제일 마지막은 알아서 정렬됨)













//백준 2490번
/*
int p2490() {
    int arr[3][4] = { 0 };
    char score[3] = { 0 };

    scanf("%d %d %d %d", &arr[0][0], &arr[0][1], &arr[0][2], &arr[0][3]);
    scanf("%d %d %d %d", &arr[1][0], &arr[1][1], &arr[1][2], &arr[1][3]);
    scanf("%d %d %d %d", &arr[2][0], &arr[2][1], &arr[2][2], &arr[2][3]);

    int count[3] = {0};

    for (int j = 0; j < 3; j++){
        for (int i = 0; i < 4; i++) {
            if (arr[j][i] == 0) count[j]++;}
    }

    for (int j = 0; j < 3; j++){
        if (count[j] == 0) score[j] = 'E';
        if (count[j] == 1) score[j] = 'A';
        if (count[j] == 2) score[j] = 'B';
        if (count[j] == 3) score[j] = 'C';
        if (count[j] == 4) score[j] = 'D';
    }


    printf("%c\n%c\n%c", score[0], score[1], score[2]);
}
*/












//백준 2576번
/*
    int p2576() {
        int arr[7] = { 0 };
        for (int i = 0; i < 7; i++) {
            scanf("%d", &arr[i]);
        }

        int odd[7] = { 0 };
        int cnt = 0;
        int odd_count = 0;
        for (int i = 0; i < 7; i++) {
            if (arr[i] % 2 != 0) odd[i] = arr[i];
            if (arr[i] % 2 != 0) odd_count++;
            cnt += odd[i];
        }
        int tmp = 0;
        for (int j = 0; j < 6; j++)
            for (int i = j + 1; i < 7; i++) {
                if (odd[j] <= odd[i]) {//역순 정렬
                    tmp = odd[j];
                    odd[j] = odd[i];
                    odd[i] = tmp;
                    tmp = 0;
                }
            }
        if (cnt != 0) printf("%d\n%d", cnt, odd[odd_count-1]);
        else if (cnt == 0) printf("-1");//홀수 없음
}
*/
//최솟값 찾기-이거는 반드시 암기하고 있기(아래 반복문)
/*
for (int i = j + 1; i < odd_count; i++) {
    if (min < odd[i]) min = odd[j];
}
*/
//반드시 암기하고 있기!!!!










//백준 2438번
/*
    int p2438() {
        int n = 0;
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            for (int i = n-j-1; i < n; i++) {
                printf("*");
            }
            printf("\n");
        }
    }
*/






//백준 2587번
//이번에는 선택정렬로 구해보자
//버블정렬은
/*
    for (int j=0;j<n;j++){
        for (int i=j+1;i<n+1;i++){
            if(a<b) 주소교환(변수교환은 안된다)
        }
    }
    //이거는 꼭 암기해두기
*/

//선택정렬 설명
/*
1회전시 최솟값 찾아서 위치 저장 후 swap 1번 -> 2회전시 2번째부터 비교 ... (반복)
"1회전을 수행하고 나면 가장 작은 값의 자료가 맨 앞에 오게 되므로" 그 다음 회전에서는 두 번째 자료를 가지고 비교한다. 마찬가지로 3회전에서는 세 번째 자료를 정렬한다.



////(중요)/////////////버블정렬과의 가장 큰 차이점:"""""""""변수에다가 최솟값의 위치를 저장하는 방식(교환 X)""""""""""""////////////////////



//주의할 점: 최솟값이 자신과 같으면 움직이지 않는다는 조건 코딩할때 추가해줘라
//마지막 숫자는 자동 정렬(최솟값만 왼쪽으로 보내다보면 최대값은 제일 오른쪽으로 옴)
*/

//버블정렬과의 가장 큰 차이점:"""""""""변수에다가 최솟값의 위치를 저장하는 방식(교환 X)""""""""""""(버블정렬은 계속 교환하는 거고, 선택정렬은 최솟값위치를 변수에 저장하는거고)


//선택정렬 예시(암기) 
/*
    int selection_sort(int arr[],int n) {
        int i, j, min_loc, tmp;


        for (i = 0; i < n-1; i++) {
            min_loc = i; //1번 반복후엔 그 다음부터 최솟값 찾을 것이니까 "최솟값 위치"는 i에 맞춰줌...

            for (j = i + 1; j < n; j++) {
                if (arr[j] < arr[min_loc]) min_loc = j; // 최솟값 위치 변수에 저장
            }

            swap(&arr[min_loc],&arr[i]);//1회전에서 가장 최솟값만 i번째랑 교환("비교군중 가장 왼쪽으로")
        }
    }
*/
//이거 그대로 외워주면 됨 이런식으로 짠다고

//(swap 함수는 만들었다고 가정) 
//참고:전처리기 define으로 swap 함수 미리 만들어 놓고 갈수도 있음

//백준 2587번 코드
/*
    int swap(int* a, int* b) {
        int tmp=0;
        tmp = *a;
        *a = *b;
        *b = tmp;
    }

    int selection_sort(int arr[],int n) {
        int i, j, min_loc, tmp;

        
        for (i = 0; i < n-1; i++) {
            min_loc = i; //1번 반복후엔 그 다음부터 최솟값 찾을 것이니까 "최솟값 위치"는 i에 맞춰줌...

            for (j = i + 1; j < n; j++) {
                if (arr[j] < arr[min_loc]) min_loc = j; // 최솟값 위치 변수에 저장
            }

            swap(&arr[min_loc],&arr[i]);//1회전에서 가장 최솟값만 i번째랑 교환("비교군중 가장 왼쪽으로")
        }
    }

    int p2587() {
        int arr[5] = {0};
        int avg = 0;
         
        for (int i = 0; i < 5; i++) {
            scanf("%d", &arr[i]);
            avg += arr[i];
        }
        avg /= 5;
        selection_sort(arr,5);
        
        printf("%d\n%d",avg,arr[2]);
    }
*/



























//백준 2309번
//이번엔 삽입정렬 해보자
//__________________________________________________________(삽입정렬)______________________________________________________
/*
(오름차순 기준)
key변수을 기존에 정렬된 부분과 비교하면서 삽입할 위치 찾아서 넣음(key 바로 옆부터 가장 첫번째 인덱스(가장 왼쪽)까지 비교)

(요약)기존 것을 정렬하고 다음 것으로 넘어가서 또 정렬

/(즉!!!!)//////////////key변수 인덱스 올리면서 key 비교해 내려가면서 key의 삽입할 위치 찾아서 넣어 정렬하고 또 정렬하고 또 정렬해서 최종적으로 정렬되게 하는 것임//////////////////////////////////

간단하게 이야기하면 
key 비교해 내려가면서 key의 삽입할 위치 찾아서 넣음

1회전 2개 정렬 완(key인덱스 2번째로 설정)
2회전 3개 정렬 완(key인덱스 3번째로 설정)
3회전 4개 정렬 완(key인덱스 4번째로 설정)
...
n회전 n개 정렬 완(key인덱스n번째로 설정)
이 방식으로 기존것을 비교 후 교환해서 전부 정렬시키고 다음으로 넘어간다고 생각


*/
//삽입정렬 예시(암기 필수)(while로 하는 이유가 있음)
/*
    int insert_sort(int arr[], int n) {
        for (int i = 1; i < n; i++) {
            int key = arr[i]; //key는 j보다 1 커야되니 i로(j도 꼭 밖에 선언하기)
            int j = i - 1; 
            while (j >= 0 && key < arr[j]) {//key보다 인덱스 아래로 내려가면서 비교 후 정렬
                arr[j + 1] = arr[j];
                j--; //만약 여기서 while 조건문 만족 못하면 j값은 그냥 남아있게 됨
                //조건X 시 j값은 그냥 남아있게 하기 위해서 while 쓰는 이유가 있음(for쓰려면 break써야되서 복잡해짐)(아님 for 조건에다가 j >= 0 && key < arr[j] 넣기)
            }
            arr[j + 1] = key; //j+1로 해야 함(비교해서 조건 안맞으면 j값이 유지되서 그럼)
        }
    }
*/
//코드 설명
//int j = i-1;로 선언한 다음 
//while조건을 (j>=0 && key < arr[j])으로 하고 arr[j+1] = arr[j]; j--; 반복시키기 
//(어쩌피 key변수가 temp역할 하기 때문에 걍 arr[j+1] = arr[j]으로 값을 오른쪽으로 보내버리면 됨)
//마지막으로 while 끝나면 key값을 arr[i]에 대입해서 그 회차 정렬 끝

//swap 써도 되긴 하는데
//key가 버퍼(temp)역할 해줘서 swap 필요없음(걍 arr[j+1] = arr[j]로 값을 오른쪽으로 이동시켜버리면 됨)

/*(for 예시)(for 조건은 j >= 0 && key < arr[j] 필수)
    int insert_sort(int arr[], int n) {
        int key = 0;
        for (int i = 0; i < n; i++) {
            key = arr[i];
            int j=0;                //이렇게 반드시 j를 밖에 선언하기(for문 밖에서도 씀)
            for (j = i - 1; j >= 0 && key < arr[j] ; j--){
                if (key < arr[j]) arr[j+1] = arr[j];
                //
            }
            arr[j+1] = key; //j+1로 해야 함(비교해서 조건 안맞으면 j값이 유지되서 그럼)
    }
*/

//__________________________________________________________(조합)______________________________________________________
//조합 = 뽑을때 중복 안되게 오름차순이나 내림차순으로 뽑는다
//중복조합 = 뽑을때 그 전수와 같거나 크면 된다
//-------------(중요함)-----------------------------조합 코드 외워야하는 것---------------------------(중요함)-------------------------
//내가 외워야 하는 for 중첩문을 이용한 nCr 조합 풀이!!!!!!!(이거 반드시 외워라!!!!!!!!!)
//(9C2 문제 푸는 것)
/*
        for (int a = 0; a < 8; a++) {
            int total = 0; //a의 숫자 바뀔때 total 초기화
            for (int b = a + 1; b < 9; b++) { //a,b 서로 안겹치게 조건 잡고, 9개 중 a,b(2개) 조합(중첩 for문과 조건으로 a,b는 무조건 서로 다름)
                total = 0; //b의 숫자 바뀔때 total 초기화

                //(중요)이 위의 이중 중첩문이 9C2의 a,b 조합 개수만큼 반복하게 됨!!!!!!!

                //나머지 7명 저장
                for (int c = 0, i = 0; c < 9; c++) if (c != a && c != b) result[i++] = arr[c];//a,b를 제외한 나머지 조합 뽑는 코드
                                                                                              //a와 b는 제외하고 오름차순으로 조합의 인덱스 위치 기록(오름차순으로 중복피함)
                                                                                              //result에 a,b를 제외한 조합 저장
                                                                                              //(참고) c랑 i는 for문 안에서 선언 동시에 초기화한거임
                //여기에 추가적인 조건 적어주면 됨(출력이나)
                }
            }
*/

//조합 코드(좀 복잡하지만 확실하게 조합을 이해할 수 있는 코드)
/*
#include <stdio.h>
#include <stdlib.h>
//n = item 정보
//bucket = 뽑은 숫자를 담을 배열
//bucketSize = bucket에 대한 정보(배열의 크기)
//k = 앞으로 뽑아야 할 개수

void pick(int n, int* bucket, int bucketSize, int k) {
    int i, lastIndex, smallest;
    lastIndex = bucketSize - k - 1; // 가장 최근에 뽑힌 수가 저장된 위치 index

    if (k == 0) { // 다 뽑으면 출력하고 출력 마치면 다시 for문으로 돌아가기
        for (i = 0; i < bucketSize; i++)
            printf("%d ", bucket[i]);
        printf("\n");
        return; // 무한루프 방지
    }

    if (k == bucketSize) //-------------반복문에서 무슨 인덱스부터 뽑을 지 결정(밑의 for문에서 시작 i값 결정)
        smallest = 0;
    else
        smallest = bucket[lastIndex] + 1; // 조합은 가장 마지막에 뽑힌 수보다 큰 수를 뽑는다

    for (i = smallest; i < n; i++) {  //---------------뽑는 반복문
        bucket[lastIndex + 1] = i;
        pick(n, bucket, bucketSize, k - 1); // k-1 = 앞으로 뽑아야 할 개수를 하나 감소
    }
    return;
}
int main(void) {
    int n = 5; // item 정보
    int bucket[3]; // 뽑은 숫자를 담을 곳

    pick(n, bucket, 3, 3); // 조합 알고리즘
    return;
}
*/
//근데 2309번 문제에서는 합이 100인거만 구하면 되서 중첩 for으로 구현할 수 있음
//그 중첩 for문을 외워두자 좋은 코드다


//__________________________________________________________(백준 2309번 코드 문제 풀이)___________________________________________________________
//이 문제 풀때 가장 먼저 들어야 하는 생각이 9C7은 2C7이라는 것이다. 2개 뽑고 나머지 7개 더해서 100 되면 되는 거다. 

//백준 2309번 코드(이 코드는 중첩 for 문은 좀 외워둬라)(-------조합문제 중첩문 쓰는 방식을 외워두기--------)(이 중첩문은 nCr 조합문에서 사용할 수 있음!!!!!! 물론 저 위 코드도 사용가능)
/*
int insert_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i]; //key는 j보다 1 커야되니 i로
        int j = i - 1;
        while (j >= 0 && key < arr[j]) {//key보다 인덱스 아래로 내려가면서 비교 후 정렬
            arr[j + 1] = arr[j];
            j--; //만약 여기서 while 조건문 만족 못하면 j값은 그냥 남아있게 됨
            //조건X 시 j값은 그냥 남아있게 하기 위해서 while 쓰는 이유가 있음(for쓰려면 break써야되서 복잡해짐)(아님 for 조건에다가 j >= 0 && key < arr[j] 넣기)
        }
        arr[j + 1] = key; //j+1로 해야 함(비교해서 조건 안맞으면 j값이 유지되서 그럼)
    }
}

        
    int p2309() {
        int arr[9] = { 0 };
        int result[7] = { 0 };
        for (int i = 0; i < 9; i++) {
            scanf("%d", & arr[i]);
        }

        //9C7이랑 9C2는 같은 것이다. 9명중 2명 조합, 그래서 2명을 제외한 나머지 7명의합이 100이면 된다.
        //이 중첩문은 nCr 조합문제 풀때 아주 유용하게 사용할 수 있음
        //순수 조합문제는 다 풀린다 보면 됨
        for (int a = 0; a < 8; a++) {
            int total = 0; //a의 숫자 바뀔때 total 초기화
            for (int b = a + 1; b < 9; b++) { //a,b 서로 안겹치게 조건 잡고, 9개 중 a,b(2개) 조합(중첩 for문과 조건으로 a,b는 무조건 서로 다름)
                total = 0; //b의 숫자 바뀔때 total 초기화

                //(중요)이 위의 이중 중첩문이 9C2의 a,b 조합 개수만큼 반복하게 됨!!!!!!!
               
                //나머지 7명 저장(9C2 조합 찾아서 저장하는 코드)
                for (int c = 0, i = 0; c < 9; c++) if (c != a && c != b) result[i++] = arr[c];//a,b를 제외한 나머지 조합 뽑는 코드
                                                                                              //a와 b는 제외하고 오름차순으로 조합의 인덱스 위치 기록(오름차순으로 중복피함) 
                                                                                              //result에 a,b를 제외한 조합 저장
                                                                                              //(참고) c랑 i는 for문 안에서 선언 동시에 초기화한거임
                for (int i = 0; i < 7; i++) total += result[i];

                if (total == 100) break;
            }
            if (total == 100) break; //여기에도 꼭 넣기 (당연한 것)
        }
        
        insert_sort(result, 7);
        for (int i = 0; i < 7; i++) {
            printf("%d\n", result[i]);
        }
    }
*/


























//백준 10093번 코드
/*
int swap(long long * a, long long * b) {
    long long tmp = 0;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    long long a = 0, b = 0, n=0;

    scanf("%lld %lld", &a, &b);

    if (a > b) swap(&a, &b);

    n = b - a - 1;
    if (a == b || b - a == 1) printf("0");
    else {printf("%lld\n", n);

    for (long long i = a+1; i < b; i++) {
        printf("%lld ", i);
        }
    }
}
*/
    




//백준 1267번 코드
//한번 동적할당 배열 써볼 예정임
//원래는 걍 phonecallnum[20]짜리 배열 생성하면 됨(문제에 20개 까지만 있다고 했음)
//scanf 스페이스바 안붙여도 된다 꼭 기억해라 그냥 "%d"로만 해도 "41 41 41"이런거 받아 올 수 있음
/*
int p1267() {
    int phonecallnum = 0;
    int phonecalltime[20] = { 0 };
    int y = 0, m = 0;

    scanf("%d", &phonecallnum);

    for (int i = 0; i < phonecallnum; i++) { //배열은 입력받을 때는 -1 꼭 해줘라
        scanf("%d", &phonecalltime[i]); //스페이스바 안붙여도 된다 꼭 기억해라 그냥 "%d"로만 해도 "41 41 41"이런거 받아 올 수 있음
    }


    for (int i = 0; i < phonecallnum; i++) {
        if (phonecalltime[i] % 60 < 30 && phonecalltime[i] % 60 >= 0) y += 10;
        else if (phonecalltime[i] % 60 >= 30 && phonecalltime[i] % 60 < 60) y += 20;
        y += (phonecalltime[i] / 60) * 20;

        if (phonecalltime[i] % 60 < 60 && phonecalltime[i] % 60 >= 0) m += 15;
        m += (phonecalltime[i] / 60) * 15;
    }

    if (y > m) printf("M %d", m);
    else if (y == m) printf("Y M %d", y);
    else printf("Y %d", y);
}
*/










//백준 10804번 코드
/*
    int swap(int* x, int* y) {
        int tmp;
        tmp = *x;
        *x = *y;
        *y = tmp;
    }

    int p10804() {
        int arr[20] = { 0 };
        for (int i = 0; i < 20; i++) {
            arr[i] = i + 1;
        }

        int a[10] = { 0 }, b[10] = { 0 };

        for (int i = 0; i < 10; i++) {
            scanf("%d %d", &a[i], &b[i]);
        }

        for (int m = 0; m < 10; m++) {
            if (a[m] != b[m]) {
                if ((b[m] - a[m] + 1) % 2 == 0) {
                    for (int k=0, j = a[m] - 1, i = (b[m] - a[m] + 1) / 2; k < i; k++) {
                        swap(&arr[j+k], &arr[b[m]-1-k]);
                    }
                }
                else {
                    for (int k = 0, j = a[m] - 1, i = (b[m] - a[m]) / 2; k < i; k++) {
                        swap(&arr[j + k], &arr[b[m] - 1 - k]);
                    }

                }

            }
        }
        
    
        for (int k = 0; k < 20; k++) {
                printf("%d ", arr[k]);
        }
        
    }
*/
            







//제일 위가 최신
    int main() {
        //return p10804();
        //return p1267();
        //return p10093();
        //return p2309();
        //return p2587();
        //return p2438();
        //return p2576();
        //return p2490();
        //return p2752();
    }
