#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int N;
    cin >> N;
    deque<pair<int,int>> dq;
    int m;
    for (int i=0;i<N;i++)
    {
        cin >> m;
        pair<int,int> p = {m,i+1};
        dq.push_back(p);
    }

    int now = dq.front().first;
    cout << dq.front().second <<" ";
    dq.pop_front();


    while (dq.empty() == 0)
    {
        if (dq.empty())
        {
            break;
        }
        else if (now < 0)
        {
            for (int i=0;i > now+1; i--)
            {
                //음수니까 반대로 카운팅하면서 뒤에서 앞으로 이동
                dq.push_front(dq.back());
                dq.pop_back();
            }
            now = dq.back().first;
            cout << dq.back().second <<" ";
            dq.pop_back();
        }
        else if (now > 0)
        {
            //이미 출력하고 지웠음(하나 줄여)
            for (int i=0;i< now-1; i++)
            {
                dq.push_back(dq.front());//pair 넣어주기
                dq.pop_front();
                // (now에서 읽은 만큼 이동)
            }
            now = dq.front().first;
            cout << dq.front().second <<" ";
            dq.pop_front();
        }
    }

}