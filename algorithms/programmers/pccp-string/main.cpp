//pccp에서 다른 부분은 원래 백준,프로그래머스 공부가 부족했어서 알고리즘을 잘 몰랐다고는 하지만,
//string 문자열 파싱 부분은 확실하게 알고 있었어야 했다;;;
//그러므로 다시한번 해보고 확실히 알아두자(그리고 ps에서는 \n으로 구분되는 문자열은 무조건 cin으로 받아야 한다 스페이스바는 stringstream)

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath> //distance 함수
#include <numeric> //accumulate 함수
#include <sstream>
using namespace std;

//주어지는 배열 3개(vector>
//참가자 ["KIM", "PARK", "LEE", "YOO", "BAE"]
//프로젝트 ["KIM PARK", "PARK LEE YOO", "BAE KIM", "BAE LEE PARK", "YOO LEE PARK", "KIM YOO"]
//연차 [90, 160, 160, 1000, 100]

// 프로젝트 한 원소에 들어가있는 " "로 구별된 사람들이 한 프로젝트에 들어가는 사람들.
// 참가자 배열의 인덱스0이 이전 팀장 경험 있는 사람
// 최종 팀장 배열은 프로젝트 배열의 길이와 같음

//최종 목표는 각 프로젝트별 

/*
팀장이 되는 우선순위
1순위. 이전 팀장 경험이 있는 사람
2순위. 이전 팀장 경험이 없으면 연차가 높은 사람
3순위. 연차가 같은 경우에는 이름의 사전순
*/


vector<string> solution(vector<string> member, vector<int> period, vector<string> project);
int find_member_name(const vector<string>& member, const string& name);

int main(){

    vector<string> member = {"KIM", "PARK", "LEE", "YOO", "BAE"};
    //팁1) 이렇게 바로 vector에 원소를 넣고 싶으면 {} 중괄호(스코프) 사용해야함
    vector<int> period = {90, 160, 160, 1000, 100};
    vector<string> project = {"KIM PARK", "PARK LEE YOO", "BAE KIM", "BAE LEE PARK", "YOO LEE PARK", "KIM YOO"};

    vector<string> temp = solution(member,period,project);

    for(const auto& lt : temp){
        cout << lt << " ";
    }


    // (오류 2) 범위기반 for문으로 2차원 배열 출력 안됨
    // for(const auto& lt : temp){
    //     for(const auto& at : lt){ // 아!!!! 이런 젠장!! 내가 여기서 실수한 거구나!!!!
    //         // 이렇게 범위기반으로 2차원 배열 출력할때는 외부는 lt : 배열, 내부는 at : lt(여기에 꼭 배열의 참조자 lt)
    //         cout << at << " ";
    //     }
    // }
    
}

vector<string> solution(vector<string> member, vector<int> period, vector<string> project){
    //pccp 시험장에서 내가 맞닥들인 오류
    //1. 배열 선언문제 --> resize() 메서드를 바보같이 써서 0,0으로 초기화해서 string에 int인 0이 들어가서 null이 되어 오류 발생 
    //2. 범위기반 for문으로 2차원 배열 출력 안됨 --> 그냥 이터레이터 잘못 씀 
                                                //외부for는 lt : 배열, 내부for는 at : lt
    //3. if문 논리적 오류

    /*(오류 1)벡터 선언에서 자꾸 문제 생김)
    vector<vector<string>> test; 
    test.resize(project.size(),vector<string>(0,0));
    */
    //(내가 틀린 부분)(오류)test.resize(project.size(),vector<string>(0,0));
    //내가 pccp에서 이 문제 해결 못한 이유 => resize 함수를 바보같이 씀
    //(--------------------문제점--------------------)
    //resize 함수를 이렇게 vector<string>(0,0) <-- 이 2번째 매개변수가 문제임 
    //이걸 넣어 버리면 string 타입에 0(정수)을 전달하면서 null 포인터나 빈 문자열 생성 시 문제가 발생
    //그래서 내가 원하듯이 그냥 빈 배열 생성하고 싶으면 
    
    //방법 1. (가장 간단하고 쉬움) vector<vector<string>> test(project.size());
    //방법 2. test.resize(project.size(), vector<string>()); 이런 방식으로 빈 벡터로 선언
    //방법 3. vector<vector<string>> test; 그냥 이 상태에서 push_back으로 백터를 원소로 넣음

    //방법 1. 
    // vector<vector<string>> test(project.size());
    // for(int i = 0; i < project.size(); ++i){
    //     stringstream ss(project[i]); // 그리고 이렇게 project[i] 받아와도 된다!!! 이건 꼭 기억하기
    //     string token;
    //     while(ss >> token){
    //         test[i].push_back(token);
    //     }
    // }

    //방법 2.
    // vector<vector<string>> test;
    // test.resize(project.size(), vector<string>());
    // for(int i = 0; i < project.size(); ++i){
    //     stringstream ss(project[i]); // 그리고 이렇게 project[i] 받아와도 된다!!! 이건 꼭 기억하기
    //     string token;
    //     while(ss >> token){
    //         test[i].push_back(token);
    //     }
    // }

    //방법 3.
    vector<vector<string>> test;
    for(int i = 0; i < project.size(); ++i){
        vector<string> test_row;
        stringstream ss(project[i]);
        string token;
        while(ss >> token){
            test_row.push_back(token);
        }
        test.push_back(test_row);
    }

    //이렇게도 되는데 추천 안함
    // int cnt=0;
    // for(auto& lt : project){
    //     stringstream ss(lt);
    //     string token;
    //     while(ss >> token){
    //         test[cnt].push_back(token);
    //     }
    // cnt++; // 내가 실수한 부분, 꼭 while문 밖에 있어야지!
    // }
    
    //팁2) 인덱스를 다루는 건 반드시 일반 for문으로 하자!!! (범위기반 for문 쓰면 가독성 떨어질 수 있음)

    vector<string> result;

    // 각 프로젝트(test의 각 `vector<string>`)별로 팀장 선정 로직 적용
    // 어쩌피 찾는건 find랑 find_if 사용할꺼임
    
    for (const auto& at : test) { // 원본 코드에서 `at`은 `vector<string>` 상태 (한 프로젝트의 참가자 리스트)
        string temp_leader = ""; //(이걸 생각을 못함)(이렇게 temp인 빈 string 두고 if문을 통해 결과 string만 뽑으면 됨) result에 넣어버릴 string을 대입하면 됨

        // 1. 1순위 규칙 적용: 이전 팀장 경험이 있는 사람(member[0]) 확인
        // find() 함수를 사용하여 member[0]이 현재 프로젝트(`at`)에 있는지 확인
        if (find(at.begin(), at.end(), member[0]) != at.end()) {
            temp_leader = member[0]; // member[0]이 있다면 그 사람이 팀장
        } else {
            // 2. member[0]이 없으면 2순위, 3순위 규칙 적용
            int maxPeriod = -1; // 현재 프로젝트 내 최고 연차

            vector<string> preleader_vec; // 2순위, 3순위에서 사용할 최고 연차 동점자(2순위)랑 사전순 정렬(3순위)된 나머지 멤버들까지 전부 저장할 벡터
            for (const string& project_elem : at) { // 현재 프로젝트(`at`) 내의 각 참가자(`project_elem`)에 대해
                int Idx = find_member_name(member, project_elem); // 전체 member 벡터에서 `project_elem`의 인덱스 찾기
                if (Idx != -1) { //이름 찾았을 경우 //근데 무조건 찾게 되어있긴 함
                    int currentMemberPeriod = period[Idx]; // 해당 참가자의 연차

                    if (currentMemberPeriod > maxPeriod) { //2순위 알고리즘
                        // 새로운 최고 연차를 찾았을 경우
                        maxPeriod = currentMemberPeriod;
                        preleader_vec.clear();          // 이전 후보들을 모두 지우고 //이 clear() 도 꼭 기억해두기
                        preleader_vec.push_back(project_elem); // 현재 참가자를 유일한 후보로 추가

                    } else if (currentMemberPeriod == maxPeriod) { 
                        // 기존 최고 연차와 같은 연차를 가진 참가자를 찾았을 경우 (동점)
                        preleader_vec.push_back(project_elem); // 후보 목록에 추가
                    }
                }
            }
            
            // 3순위. 모든 프로젝트 멤버를 확인한 후, 동점자가 있다면(preleader_vec 원소 2개 이상) 사전순 정렬** //
            //2순위에서 동점자 나왔는지 안나왔는지 어떻게 앎? --> preleader_vec가 1개여야지만 2순위 확정임, 2개 이상부터는 무조건 동점자 있단 소리거든 
            //2순위인 경우 = preleader_vec 원소 1개(clear함수때문에 무조건 원소 1개임)(아까 clear() 함수를 적용하고 추가한다는게 중요함)
            //3순위인 경우 = preleader_vec 원소 2개 이상 (동점자 있음)

            //그래서 preleader_vec.size()로 판별하면 된다.
            if (preleader_vec.size() > 1) { // 후보가 여러 명이면 (연차 동점)
                sort(preleader_vec.begin(), preleader_vec.end()); // 사전순으로 정렬
                temp_leader = preleader_vec[0]; // 정렬 후 첫 번째 사람이 팀장
            } else if (preleader_vec.size() == 1) { // 후보가 한 명이라면 (2순위에서 확정)
                temp_leader = preleader_vec[0]; // 그 한 명이 팀장
            }
        }
        //이제 최종으로 가려낸 프로젝트(at)에서의 팀장을 저장
        result.push_back(temp_leader); // 현재 프로젝트의 팀장을 결과(`result`)에 추가
    }
    return result;
}

int find_member_name(const vector<string>& member, const string& name) {
    for (int i = 0; i < member.size(); ++i) {
        if (member[i] == name) {
            return i;
        }
    }
    return -1; // 찾지 못했을 경우 -1 반환
}






/*
<bits/stdc++.h>

ios::sync_with_stdio(false);
cin.tie(0);

cin.ignore(); -->cin이랑 getline을 같이 쓸때는 반드시 해줘야 함

string line;
getline(cin, line);

stringstream ss(line);
int i;
while (ss >> i) {
	vec1.push_back(i);


이건 좀 제발 외워라


알파벳 찾을때는 isalpha사용하기


int isalpha (int c)
매개변수 : C언어에서 아스키 코드에 해당하는 문자들은 숫자로 표현이 되고, 
문자를 넣으면 자동으로 아스키 코드에 있는 숫자로 들어가기 때문에 int 타입이긴 하지만 'a', 'A', '1' 등을 집어 넣어도됩니다.
즉, 'a' 와 같이 char 타입으로 집어 넣어도 자동으로 int 타입으로 형변환 되어서 들어가게 됩니다. 
아스키 코드 표를 참고하면 'a'는 자동으로 숫자 97로 형변환되어 들어가게 됩니다.

반환형 : 매개변수로 들어온 인자가 알파벳이라면 0이 아닌 수를 반환하고 알파벳이 아니라면 0을 반환합니다.
더 정확하게 이야기하면 isalpha 함수는알파벳 대문자 "A-Z"는 1을 반환.알파벳 소문자 'a-z"는 2를 반환.
알파벳이 아닌것은 0을 반환합니다.한번더 이야기 하면 isalpha 함수의 매개변수로

(중요)
아스키 코드표에 'A-Z'에 해당하는 65번~90번의 값이 들어오면 1을 반환
아스키 코드표에 'a-z'에 해당하는 97번~122번의 값이 들어오면 2를 반환
그 이외의 값이 들어오면 0을 반환하는 함수 입니다.


람다함수 외부 변수 사용하기 위한 캡처
[=]	모든 람다 외 지역 변수들을 const로 복사한다.
[&]	모든 람다 외 지역 변수들을 참조한다.
[val1, &val2]	지역 변수 val1을 const로 복사하고 val2를 참조한다. (이렇게 특정 지역 변수만 취하는 것이 가능)
[this]	해당 클래스를 참조한다.
[*this]	C++17부터 지원. 해당 클래스를 복사한다.


아스키 소문자 a는 97
아스키 대문자 A는 65
각각 26개씩


배열 검사할때는 all_of랑 any_of 사용하기
    //https://0xffffffff.tistory.com/42
    //https://koreatopclass.tistory.com/15
    //배열 안을 검사할때는 항상 any_of 나 all_of를 사용한다
    //
    //all_of (시작, 끝, 람다함수(하나라도 틀린 부분이 있다면 false 그 이외에는 true, 그리고 empty일경우 false)) 
    //any_of  (이거는 조건에 하나라도 만족한다면 true, 그 외에는 false)



accumulate 함수는 numeric 함수다 조심하셈
*/