#include <bits/stdc++.h>

int solution3(int arr[]) {
	return *max_element(arr, arr + 4);
}

//! C++ 할때 
/*
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <functional>
#include <algorithm>
이랑

#include <bits/stdc++.h>
이랑 같은 것이다
(bits 폴더의 모든 C++헤더를 전부 include하는 코드임)

이 헤더는 주의점이 gcc에는 있는데 msvc는 없음 그래서 vs2017/2019쓰면 bits/stdc++.h 꼭 추가해둬라
근데 다른 코테에서는 이 헤더 못쓰게 하니까
algorithm, vector, stack과 같은 저 위에있는 헤더들은 전부 외워두기

참고로 바킹독 공부하면서 c++을 당연히 주력으로 갈꺼고 모르는 건 걍 그때그때 찾아라
cin()이 printf역할이고
cout()이 scanf역할임
*/