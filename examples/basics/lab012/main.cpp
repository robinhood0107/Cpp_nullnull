
//한번 시도 후 답 봐서 나중에 품품
//이 문제 접근을 할 때 항상 값을 한번에 다 받을 생각을 하지 말고 받은 즉시 출력을 해도 상관 없으니까 그런 방식으로 생각하기
//답 한번 봤으니 다른 문제 다 풀고 보기
//문제는 항상 출력값만 같으면 됨, 한방에 출력될 필요도 없고 걍 결과물만 보고 판단하니까 무조건 결과물만 같게 하면 된다.


//왜 자꾸 쳐 틀리는지 알았음 C++에서는 문자열 받을 꺼면 무조건!!!!!! string 써야한다 이거 필수임
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int p012() {
    int N=0;
    cout << "# of students:\n";
    cin >> N;
    string name;
    int grade=0;
    int sum=0;
    vector<int> vec;
    for (int i=0;i<N;i++) {
        cout << "name & score of student :";
        cin >> name >> grade;
        vec.push_back(grade);
        sum += grade;
    }
    sort(vec.begin(),vec.end());
    cout << "The average score of the students is " << sum/N << "\n";
    cout << "The student with the highest score is " << vec[N-1] << "\n";
}

























