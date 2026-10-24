#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;
    stack<int> s;

    int B=0;
    int A=0;
    for (int i=0;i<N;i++){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cin >> A;
        switch (A) {
            case 1:
                cin >> B;
            s.push(B);
            break;
            case 2:
                if (s.empty()) {
                    cout << -1 << "\n";
                }
                else{
                    cout << s.top() << "\n";
                    s.pop();
                }
            break;

            case 3:
                cout << s.size() << "\n";
            break;

            case 4:
                if (s.empty()) {
                    cout << 1 << "\n";
                }
                else
                    cout << 0 << "\n";
            break;

            case 5:
                if (s.empty()) {
                    cout << -1 << "\n";
                }
                else
                    cout << s.top() << "\n";
            break;

            default:
                cout << "1~5" << "\n";
            break;
        }
    }
}
