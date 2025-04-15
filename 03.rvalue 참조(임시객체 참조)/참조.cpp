#include <iostream>

int testFunc(int param)
{	
	//이름이 없는 임시객체가 만들어지는 경우는 여러가지가 있다
	//1. 연산하다가 생김
	//2. 값을 반환할 때 ( 뭔가 값을 반환할때 그 반환값은 임시객체임)
	int result = param * 2; 
	return result; //임시객체값 20을 반환함(return result;)
}

int main()
{
	int input = 0;

	std::cout << "Input number: ";
	std::cin >> input;

	int&& rData = (input + 5);
	std::cout << rData << std::endl;

	int&& result = testFunc(10); //rvalue 참조형 선언 및 초기화
	// testFunc함수는 10을 받으면 2랑 곱해서 20이라는 임시객체를 만들고 이걸 result라는 이름의 rvalue 참조형에 저장함.

	//원래는 20이란 반환값(임시객체)는 대입후 사라질 껀데 result 라는 이름을 붙여준 것

	//+ 추가적으로 result(rvalue참조형)은 lvalue에 쓰일수 있다!!(참조형이니까 쓸 수 있어! 이래서 쓰는가보다 싶다)
	result += 10;
	std::cout << result << std::endl;

	return 0;
}