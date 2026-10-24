// 알아야 할 개념

//문자열의 끝은 null이다.

//C++ 입출력 관련 팁 (cin cout 쓰는 방법 및 어떤걸 써야 하는가)(외워라)
//
// 결론: cin/cout 씁시다, 그리고 "공백을 포함한 문자열"을 받을때는 scanf나 getline사용 (getline 추천 - 입력이 string일때만)
// 결론: cin/cout 쓸때는 반드시 입출력 시간초과를 생각해야함(즉, 시간제한 무조건 걸어야 한다는 것임)
// 결론: cin/cout만 사용한다면 ios::sync_with_stdio(0), cin.tie(0)이거 꼭 실행시키기
//
// cin << " ";
// cout >> " "; 이거 쓰자
//
//
//scanf/printf의 단점은 c++ string을 처리하지 못함
//그리고 scanf는 \n이 나오기 전까지만 입력을 받는다.는 사실을 꼭 기억하고 있어라
//
//
//
//
//
//"공백을 포함한 문자열"을 받는 방법(cin 못쓸때)
//1. getline (추천)(짧고 간결)(string형식을 받을때만 사용)
/*
	void main() {
		string s;
		getline(cin, s);
		cout << s;
	}
*/
//2. scanf 방식 (string이 아닐때, 예를들어 char방식으로 들어올때 사용, 근데 코딩할때 char로 받아도 바로 string으로 바꿔서 다른곳에서 활용하는게 편함)
/*
	void main(){
		char a1[10];
		scanf_s("%[^\n]", a1);
		printf("%[^\n]", a1);
	}
*/
// string 사용하자
// 
//	아시다시피 C에서는 char*으로 문자열을 다루는데 사실 char*보다 C++ string이 월등하게 편합니다. 
//	그래서 scanf/printf를 쓰면서도 C++ string을 활용하고 싶으면 일단 char*으로 입력을 받고 
//	string으로 형 변환을 해서 원하는 작업을 다 끝낸 후에 
//	c_str() 메소드를 이용해 출력하면 됩니다. 
//
// 
// 
// 
// 
//주의점(중요, 입출력 시간초과 관련)'
// 
//cin/cout은 입출력으로 인한 시간초과를 막기 위해서 ios::sync_with_stdio(0), cin.tie(0)이라는 두 명령을 실행시켜야 한다.
// 
// ios::sync_with_stdio(0), cin.tie(0)
// 
// 
//1. 입출력 빠르게 받기 ------------ ios::sync_with_stdio(0)
//
//원래는 기본적으로 scanf/printf와 cin/cout랑 동기화함 (C stream과 C++ stream)]
//근데 scanf/printf 안쓴다면 동기화 안하고 C++ stream만 사용해서 시간초과 안하게 더 빠르게 입력받아버릴 수 있음
//이 동기화 끊고 빠르게 입출력 받는 코드가 ios::sync_with_stdio(0)
//
//
//2. (온라인 저지 및 코테용) 입출력 빠르게 받기 ------------ cin.tie(0)
// 
//채점시에 출력만 사용한다는 점을 이용해 버퍼 비우라는 기본 작업을 생략해서 입출력 빠르게 받는 것
// 
//cin cout은 입출력시 buffer 사용
//기본적으로는 콘솔 출력을 순서대로 하려고 cin 버퍼를 비우고 cout 버퍼를 씀(중간에 버퍼 비우는 과정이 계속 들어감)
// 
//근데 백준같이 온라인 저지들은 출력값"만" 확인함 = 출력값만 받기 때문에 입력값이랑 출력값의 콘솔 순서 틀려도 아무 상관 없다는 것
// 
//그럼 버퍼 안지워도 됨
//그래서 cin.tie(0)는 버퍼를 비우지 말라는 명령이다 
//(cin.tie(nullptr) = cin.tie(0)라서 타이핑 아끼려고 걍 cin.tie(0) 사용)
//
//
//근데 VS2017이랑 VS2019 , VS2022는 코드를 쓰던 말던 걍 강제로 동기화를 진행시켜버려서 gcc 채점서버랑은 다른 결과가 나온다(믿지 말라는 소리임)
//우리는 항상 gcc 채점서버 기준으로 짜야되서 gcc 기준으로 """""""""""꼭 ios::sync_with_stdio(0), cin.tie(0) 써라"""""""""""""""""""""











//(중요)그리고 명심할것. 절대절대 절대절대 절대절대 endl 쓰지마라
//걍 잊어버리고 줄바꿈 필요하면 \n 출력해














//C++ STL을 직접 함수인자에 넣을때 주의할 점 팁 (STL을 함수에 넣을때)(외워라)
//											(참고로 STL과 구조체는 함수인자로 넣을때 똑같이 작동함) 
// 
// 결론 : 함수인자로 STL이나 구조체를 넣을때는 & 이렇게 형식을 주소값 즉 reference형식(&)으로 넣으라는 것
// 
//vector<int> v(num)
/*
#include <bits/stdc++.h>
using namespace std;

void func1(vector<int> v) {
	v[10] = 7;
}

int main(void) {
	vector<int> v(100);
	func1(v);
	cout << v[10];
}
*/
//이거에서 v[10] 값이 0일까 7일까
// 
//STL이나 구조체를 함수인자로 넣을 때
//0이다!!!!	함수인자로 실어보내도 복사본을 만들어서 함수로 보내니까 그냥 함수에서는 복사본을 조작하고 끝인거임 (원본은 그대로)
//			func1에서 바꾼건 원본에 영향을 주지 않는다.
//
//
//이래서 swap 함수 내가 직접 작성할때도 swap(int *a,int *b)이렇게 주소값으로 받아서 원본 건드려 바꿔버리는거임
//
//
//이 함수인자로 넣을 때 복사한다는 특징때문에 아래와 같은 상황이 벌어짐
/*
bool cmp1(vector<int> v1,vector<int> v2,int idx){
	return v1[idx] > v2[idx]
}
*/
//위의 함수는 가변배열 2개를 받아서 비교하는 함수임 vector 크기가 N이라면 시간복잡도는 얼마일까?
//놀랍게도 O(N)이 된다.
// v1과 v2에서 인자를 보낼때 원본으로 복사본을 만들때 = 반복문으로 복사해서 보내게 되잖아 N번
//그럼 반복문 돌아가는 거니까 당연히 O(N)이 됨
//
//그럼 저걸 O(1)로 만드는 것은? 주소값 형식 즉 reference(&)형식으로 함수인자 넣으면 됨
//
//bool cmp1(vector<int>& v1,vector<int>& v2,int idx)
//		return v1[idx] > v2[idx];
//
//
//
//
// 최종 결론 = 원본을 바꾸기 위해서는 주소값을 함수인자로 넣어야한다


































//--------------------------------------------------------------------0x03강 배열 개념------------------------------------------------------------------------//

//-------------------------------1. 배열
/*
배열의 성질
1.O(1)에서 k번째 원소를 확인/변경이 가능 (시간복잡도 O(1) - 시작주소에서 k칸 만큼만 오른쪽으로 이동하면 됨)
2.추가적으로 소모되는 메모리의 양(=overhead)가 거의 없음 (다른 자료구조와 다르게 추가적으로 소모되는 메모리가 없음. 배열은 배열 그 자체니까)
3.Cache Hit Ratio가 높음 (적중된 수/총 접근 수)
		(Cache Hit Ratio  = 캐시 적중률, 데이터와 콘텐츠를 연산한 후에	캐시 메모리에 저장해 두는 것을 caching(캐싱)이라 함. 한번 더 진행할때 빠르게 진행하기 위함)
		(1.캐시는 주기억장치(ROM,RAM) 와 CPU사이에 위치, 2.자주쓰는 프로그램과 데이터 기억, 3.캐시 메모리는 메모리 계층 구조에서 가장 빠른 소자, 처리속도는 CPU와 거의 비슷함)
		(4.캐시를 사용하면 주기억창지 접근 횟수 줄어들어 빨라짐, 5.캐시 주소표는 검색시간을 단출시키기 위해 주로 연관기억장치(CAM, Associative Memory)를 사용)
		(6.캐시의 크기는 보통 수십 킬로바이트에서 수백킬로바이트)
		(7.Cache Hit = 메모리에서 데이터를 성공적으로 검색해 제공,Cache Miss = 메모리에서 검색했지만 찾지못함, 이 경우콘텐츠에서 전송되서 캐시에 기록시킴)
4.메모리 상에서 연속된 구간을 잡아야 해서 할당에 제약이 걸림


배열 연산 속도

임의의 원소 확인/변경				(O(1), 찾고 변경하는 건데 당연히)
배열 끝에 원소 추가/제거			(O(1))
임의의 위치에 원소를 추가(끼워넣기)	(O(N), 그 뒤에 원소를 전부 한칸씩 뒤로 미뤄야 되기 때문에 O(N) 평균적으로는 N/2를 밀게 됨)
임의의 위치에 원소를 제거(사이빼기) (O(N), 마찬가지로 뒤 원소를 전부 한칸씩 앞으로 당겨야 되기 때문에 O(N) 평균적으로는 N/2를 밀게 됨)
*/

//C++에서 임의의 위치에 원소를 추가/제거를 하는 코드
/*
#include <bits/stdc++.h>
using namespace std;

void insert(int idx, int num, int arr[], int& len); //int& len = 함수가 받는게 주소값인 이유가 len 값이 변경되야 해서 지역함수라 함수에는 주소값 넣어야 전역변수처럼 가능

void erase(int idx, int arr[], int& len);

int main(void) {
	int arr[10] = {10, 50, 40, 30, 70, 20};
	int len = 6;
	insert(3, 60, arr, len); // 10 50 40 60 30 70 20
	erase(4, arr, len); //10 50 40 60 70 20
*/

//(연습) 직접 insert코드와 erase코드를 작성해보자
/*
#include <bits/stdc++.h>
using namespace std;

	void insert(int idx, int num, int arr[], int& len){
		//여기는 내가 작성
		//정답
		for (int i = len; i > idx; i--) { //실수 잘하는 부분 "i>idx"다!!!!! 꼭 기억해라
			arr[i] = arr[i - 1];
		}
		arr[idx] = num;
		len++;
		//주의 이렇게 짜면 절대 안된다. !!!!!~~~~내가 만약 오른쪽으로 한칸 옮기고 싶으면 왼쪽으로 가면서 연산해야함~~~~!!!!!
		//idx부터 len+1까지 가면 복사했던거 또 복사해서 모두 똑같은 번호로 만들어버리게 됨
		
		//	for (int i = idx; i < len+1; i++) {
		//		arr[i + 1] = arr[i];// 이렇게 짜면 절대 안된다
		//	}
		
	}

	void erase(int idx, int arr[], int& len){
		//여기는 내가 작성
		//!!!!!~~~~마찬가지로 내가 만약 왼쪽으로 한칸 옮기고 싶으면 오른쪽으로 가면서 연산해야함~~~~!!!!!
		for (int i = idx; i < len; i++) {
			arr[i] = arr[i + 1];
		}
		len--;
	}

	void printArr(int arr[], int& len){
	  for(int i = 0; i < len; i++) cout << arr[i] << ' ';
	  cout << "\n\n";
	}

	void insert_test(){
	  cout << "***** insert_test *****\n";
	  int arr[10] = {10, 20, 30};
	  int len = 3;
	  insert(3, 40, arr, len); // 10 20 30 40
	  printArr(arr, len);
	  insert(1, 50, arr, len); // 10 50 20 30 40
	  printArr(arr, len);
	  insert(0, 15, arr, len); // 15 10 50 20 30 40
	  printArr(arr, len);
	}

	void erase_test(){
	  cout << "***** erase_test *****\n";
	  int arr[10] = {10, 50, 40, 30, 70, 20};
	  int len = 6;
	  erase(4, arr, len); // 10 50 40 30 20
	  printArr(arr, len);
	  erase(1, arr, len); // 10 40 30 20
	  printArr(arr, len);
	  erase(3, arr, len); // 10 40 30
	  printArr(arr, len);
	}

	int main(void) {
	  insert_test();
	  erase_test();
	}
*/


//(팁이자 암기) 배열 전체를 특정값으로 전체 초기화 시킬 때 효율적으로 하는 코드 ( 이 방법 반드시 암기해두기 )
//가장 추천하는 방법 2개만 알려줌			1.for방법			2.fill방법(algorithm.h에 있음)
//
// 
// 
//1. for 방법 (for문으로 하나하나 전부 바꿈, 실수할 여지가 없기 때문에 무난함) //가장 흔히 함
/*
#include <bits/stdc++.h>
using namespace std;

void main(){
	int a[21];
	int b[21][21];
	for (int i = 0; i < 21; i++) { 
		a[i] = 0;
	}
	for (int i = 0; i < 21; i++) {		//이건 2차원 배열
		for (int j = 0; j < 21; j++) {
			b[i][j] = 0;
		}
	}
}
*/
//
// 
// 
//2. fill 방법 (마찬가지로 실수할 여지가 없고 코드가 짧아서 익숙해지면 가장 추천하는 방법) //추천하고 이렇게 사용하자 fill함수는 algorithm.h 사용한다는 건 기억
// 
//함수인자  =  fill(시작변수, 끝변수, 채울 값)
// 
//당연하지만 배열의 주소는 배열의 이름 arr, 
//arr = arr[0] 완전히 같은표현
// 
//arr은 arr[0], arr+1은 arr[1], arr+2 arr[1] 와 같이 배열의 시작 주소를 기준으로 배열 요소들의 개별 주소를 참조

/*
#include <bits/stdc++.h>
using namespace std;

void main() {
	int a[21];
	int b[21][21];
	fill(a, a+21, 0);
for (int i = 0; i < 21; i++){ //이건 2차원 배열
	fill(b[i], b[i] + 21, 0);
}
*/
//(비추 및 사용 금지)cstring.h의 memset 함수는 실수할 여지가 정말 많음, 0,-1을 안넣고 다른거 넣는다던지, 함수인자로 2차원배열 넣어 잘못 들어간다던지... 암튼 사용 금지








//-------------------------------2. STL vector
//배열과 거의 동일한 기능을 수행하는 자료구조

//














