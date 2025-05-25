// Implement your code
#include <iostream>
#include <sstream>
#include <vector>
#include <string> //string 쓸꺼니까 추가
using namespace std;// 그리고 실습 52번 같은 곳에서 namespace 있으면 using 이거 쓰면 안됨

enum class Command {
    CREATE,
    PRINT,
    DELETE,
    QUIT,
    UNKNOWN
};

Command parseCommand(const std::string& cmdStr) {
    //이거 바로 봤을 때 망설임없이 if문으로 가야 된다(str은 if문만 이라 생각해)
    if (cmdStr == "CREATE") {
        return Command::CREATE;
    }
    else if (cmdStr == "PRINT") {
        return Command::PRINT;
    }
    else if (cmdStr == "DELETE") {
        return Command::DELETE;
    }
    else if (cmdStr == "QUIT") {
        return Command::QUIT;
    }
    else {
        return Command::UNKNOWN;
    }
}

bool processCreateCommand(std::vector<int>& bmis, std::istringstream& iss) {
    // iss가 파라미터로 들어오면 파싱되서 문자열이 들어오는 것
    // 이걸 반복문으로 if문에 iss > a > b; 이렇게 파싱해서 넣어주기
    int cnt, weight, height;
    if (!(iss >> count)) {
        return false;
    }
    // 이거 예외처리 꼭 해주기

    for (int i=0; i<count; ++i) {
        if (!(iss >> cnt >> weight >> height)) {
            return false;
        }
        addBMI(bmis,weight,height);
    }
    //그냥 이 반복문은 좀 외우자

    //입력 받아서 addBMI로 넘겨주는 함수
    //addBMI가 map에다가 요소 추가


}

bool processDeleteCommand(std::vector<int>& bmis, std::istringstream& iss) {
    int del;
    // 명령어로 count는 이미 파싱 되어서 del만 받으면 됨
    if (!(iss >> del)) {
        return false;
    }
    iss >> del;
    deleteByValue(bmis,del);
    return 1;
}

bool processCommand(std::vector<int>& bmis, const std::string& commandLine) {
    // 주의
    // 여기에도 iss로 파싱해서 넘겨줘야 함!!!!
    string s;
    istringstream iss(commandLine);
    // enum이니까 switch 사용함
    switch (parseCommand(commandLine)) {
        case Command::CREATE:
            processCreateCommand(bmis,iss); //여기서 이렇게 iss 넘겨줘야 함
            return true;
            break;
        case Command::DELETE:
            processCreateCommand(bmis,iss);
            return true;
            break;
        case Command::PRINT:
            return true;
            break;
        case Command::QUIT:
            cout << "Bye!" << endl;
            return false;
            break;
        case Command::UNKNOWN:
            return false;
            break;
    }
}