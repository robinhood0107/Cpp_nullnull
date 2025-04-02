//
// Created by pjjpj on 25. 4. 1.
//
// enum alpa {A,B,C}; 열거형 선언은 이렇게 한다(일종의 자료형이다!!!)
// 열거형을 사용할때는 구조체처럼 자료형처럼 사용해버리면 됨 alpa a = A; 이렇게
// 열거형 switch문은 걍 싹 외워버리면 됨

//switch나오면 무조건 break 생각해라(default는 해당없을때)
#include <iostream>
using namespace std;

int main(){
    enum Color {RED,GREEN,BLUE};
    int n;
    cin >> n;

    //그냥 열거형은 이렇게 강제 형변환 대입 가능, enum class는 안된다.
    Color color = static_cast<Color> (n);
    switch(color){
    case RED:
      break;
    case GREEN:
      break;
    case BLUE:
      break;
    default:
    }
}
