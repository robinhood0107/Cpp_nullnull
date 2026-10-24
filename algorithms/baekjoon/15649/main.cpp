#include <iostream>

using namespace std;

//마치 중복 없이 n개를 고른 수열을 쭉 나열한다고 생각하면 된다 (조합)

//백트래킹 재귀로 작성한다.
//백트래킹의 전형적인 구조
int n,m;
int arr[10];
bool isused[10];

void func(int k){ //k까지 선택한 상태에서 arr[k]를 정하는 함수
    if(k == m){ //base condition //재귀함수이므로 base condition은 당연히 필요하다
        // k == m 이 되었으니 m개를 모두 택했다는 뜻이므로 수열 출력 후에 함수를 종료하라는 if문이다.
        for(int i = 0; i < m; i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
        }
        for(int i = 1; i <= n; i++){ //n가지의 자연수 중에서 사용되지 않은 수를 찾는다
            if(!isused[i]){ //사용하지 않은 수를 찾았으면
                arr[k] = i; //해당 수를 수열에 저장한 다음에
                isused[i] = 1; // 사용되고 있음을 저장한 후
                func(k+1); //재귀문을 돌려서 arr[k]=i로 둔 상태에서 func(k+1)에 들어갔다가 모든 과정을 끝냄
                isused[i] = 0; //사용을 전부 다 했으므로 전부 사용했다고 표시 //단 arr[k]는 다른 값으로 덮일 예정이라서 초기화 안해도 된다.
            }
        }
    }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0);
}