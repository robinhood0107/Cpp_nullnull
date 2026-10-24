
//생각

//일단 짝수인지 홀수인지로 구분하고 회문인지 유사회문인지 판별(1)
//유사회문일 경우 후보지를 총 3개 구분해서 검색한다.(2)
//이게 전부 아니라면 그냥 빠르게 3 출력하고 끝

//이거보다 더 좋은 방법을 생각해라 주어진 시간이 매우 짧기 때문에 필수임.

//무식한 알고리즘이란게 뭔지는 모르겠지만 일단 sorting과 관련있는것은 맞아보임.

//생각해보니까 reverse로 vector 뒤집어 버린 다음에 하나하나 아스키코드로 같은지 안같은지 빠르게 비트로 비교하면 되는거 아님?
//아님 이거 전체를 비트로 비교하던가
//걍 다르면 다를것 아니냐


//2번째 생각

//생각해보니까 pivot처럼 2개의 포인터 두고서 하나하나 올라가면서 확인하고 만나거나 어떻게 되는지에 따라서만 if문 나누면 되는거 아님?

#include <string>
#include <vector>
#include <iostream>

using namespace std;

//더 빨리 할 수 없을까 찾아보니 string은 컴파일러가 문자열을 받으면 string 생성자로 보내서 임시객체를 만들어서 문자열의 복사본도 힙에 생성함(짧은 문자열은 SSO지만 이건 예외)
//이렇게 임시객체로 복사본이 만들어진다는 것은 오버헤드가 발생한다는 것이기 때문에 읽기 전용 문자열은 string_view을 추천한다 함
//C++17 string_view은 내부에 문자열에 대한 pointer와 길이만 가짐(임시객체따위 만들지 않고 바로 문자열), 그리고 내부 null 종료 문자도 없음(주의)

bool mystrcompare(const string& s, int l, int r) {
    for (int i = 0; i < (r-l+1)/2; i++) {
        if (s[l+i] != s[r-i]) return false;
    }
    //어쩌피 유사회문 판별에서는 서로 다른 즉시 l에서 한칸 이동해서, 아님 r에서 한칸 이동해서 2가지 경우에 수 봐서 회문이면 유사회문이게 됨
    //r-l+1은 탐색할 string의 길이(l과 r의 인덱스 차이)
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie();

    int n;
    cin >> n;

    cin.ignore();
    vector<string> vec;

    string line;
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        vec.push_back(line);
    }

    for(const string& s : vec){
        //생각해보니까 여기서 불필요하게 매개변수로 복사하고 있었음 이러면 안된다. 참조시켜서 메모리랑 속도 아껴야지.
        int slen = static_cast<int>(s.length());
        int hidx = 0;
        int tidx = slen-1;
        char temp = '1';

        for(int i=0; i<slen/2; i++){
            if(s[hidx+i] == s[tidx-i]) continue;
            else{
                temp = (mystrcompare(s, hidx +i+1, tidx-i) || mystrcompare(s, hidx+i, tidx-i-1)) ? '2' : '3';
                //왼쪽 하나 건너뛰어봄이랑 오른쪽 하나 건너뛰어봄 비교해서 이게 하나라고 true면 유사회문인거고, 아니면 걍 문장인거임, or 그자체다.
                //어쩌피 다 같으면 회문이니까 생각할 이유는 없잖냐, 그리고 삼항연산자가 길이 줄이는데는 최고인듯
                break;
            }
        }
        cout << temp << "\n";
    }
}