#include <iostream>

int main()
{
	int* pData = new int;
	int* pNewData = new int(10);
	int* pArr = new int[5]; //인스턴스 5개(인스턴스 int 5개)가 생성될 것

	*pData = 5;
	for (int i = 0; i < 5; ++i)
		pArr[i] = (i + 1) * 10;

	std::cout << *pData << std::endl;
	std::cout << *pNewData << std::endl;
	for (int i = 0; i < 5; ++i)
		std::cout << pArr[i] << std::endl; 

	delete pData;
	delete pNewData;
	delete[] pArr; // 배열은 반드시 배열의 형태로 지워야 한다 ([]없으면 5개의 배열 중 1개만 삭제됨)
	//이게 클래스 인스턴스 5개를 동적할당 했는대 [] 기호를 빼먹는다면 클래스 인스턴스 4개가 소멸되지 않는 큰 문제가 발생함

	return 0;
}
