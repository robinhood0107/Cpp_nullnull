실습 091 - inheritance
Requested files: main.cpp (다운로드)
업로드 가능한 파일 수: 2
제출 방식: 개인


목적

이 실습은 클래스를 상속하는 연습을 합니다. 





설명
매력적인 클래스가 있습니다. 가져다 쓰고 싶은데, 소스코드를 복사해서 고쳐볼까도 생각해 보지만, 관련된 소스코드(클래스)가 30개정도 돼서 엄두가 나지 않습니다.

안드로이드 앱을 개발하려면 Activity 클래스를 상속 받아 나만의 액티비티를 만드는 것에서부터 프로그램이 시작합니다.

게임을 만들고 싶어 SFML 라이브러리를 다운로드 받았습니다. 

시작하려고 하니 기본적으로 제공하는 그림 그리는 클래스, 텍스트 그려주는 클래스, 사용자 입력 받아서 전달하는 클래스 등 

나만의 게임을 만드는데 사용하고 싶은 클래스가 너무 너무도 많습니다.





환영합니다. 여러분은 객체지향의 세계로 강제로 소환당하셨습니다. 

당장 유명한 객체지향 프레임워크를 사용하고 싶지만, 천리길도 한걸음부터라고, 간단한 클래스 상속부터 연습해 보겠습니다. 

상속 받아보자고 안드로이드 프레임워크를 사용하는 것은 배고다 배꼽이 더 크므로, 강의 교재의 Person 과 Student를 만들어서 연습해 봅시다.





문제
주어진 메인함수를 실행하여 원하는 출력하는 프로그램을 작성하시오.

Person 클래스와 Student 클래스를 정의하고, Student 클래스가 Person 클래스를 상속받도록 구현하시오.

단,  생성자에는 멤버 초기화 목록 방식을 이용해서 객체를 초기화 하시오.



참고: C++ pass-by-value + std::move 패턴

Person(string&& name) : name(std::move(name)) {}





입력
없음



출력
Person is constructed!

Person Name: Park

Person is constructed!

Student is constructed!

Person Name: Kim

School Name: PNU

Student is destructed!

Person is destructed!

Person is destructed!





제출파일
main.cpp

