#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int main() {
    int N(0);
    vector<int> vec1;

    cin >> N;
    /*
    cin.ignore();

    string line;
    getline(cin, line);

    stringstream ss(line); //데이터 추출시 사용, 즉 초기화 ->stream에 str을 대입.
    string token; //임시저장할 토큰

    int i;

    while (getline(ss, token, ' ')) {
        vec1.push_back(stoi(token)); //이렇게 stringstream으로 token을 통해서 받는 것임
    }
    */


    //또 2번째 방법으로 이 방법도 가능하다. stringstream 사용할때 이것도 됨
    /*
    
	cin.ignore();

    string line;
    getline(cin, line);

    stringstream ss(line);
    int i;
	while (ss >> i) {
		vec1.push_back(i);
	}
    
    */
	// 이렇게 해도 ss >> i 면 >>가 C++에서는 연산자로 의미가 바뀌었기 때문에 ss값을 i에 넣어주는 것임

    for (int j = 0; j < N; j++) {
        int elem;
        cin >> elem;
        vec1.push_back(elem);
    }

    int O(0);
    int M(0);

    cin >> M >> O;

    auto start = vec1.begin();
    vec1.erase(start + M);

    vec1.erase(remove(begin(vec1), end(vec1), O), end(vec1));

    cout << vec1.size() << endl;
    for (auto& it : vec1)
        cout << it << " ";
}
