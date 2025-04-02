
// 이 문제 fixed랑 setprecision 알고있냐 마냐다. 반드시 외우고 가
// 솔직히 보자마자 기억 안남 코드 외우고 가라
// #include <iomanip> 이거 반드시 외워라 이거 모르고 있었음

//내가 틀린 부분 : setprecision <- 쓰는 법이랑 철자 똑바로 외워라라, #include <iomanip> 이거 반드시 외워라
/**/
#include <iostream>
#include <iomanip>
using namespace std;

int p013() {
    float a1;
    float a2;

    cin >> a1 >> a2;

    cout << fixed << setprecision(2) << a1 << " + " << a2 << " = " << a1 + a2 << "\n";
    cout << fixed << setprecision(2) << a1 << " - " << a2 << " = " << a1 - a2 << "\n";
    cout << fixed << setprecision(2) << a1 << " * " << a2 << " = " << a1 * a2 << "\n";
    cout << fixed << setprecision(2) << a1 << " / " << a2 << " = " << a1 / a2 << "\n";

    return 0;
}