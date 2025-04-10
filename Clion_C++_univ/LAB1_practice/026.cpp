//
// Created by pjjpj on 25. 4. 2.
//
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main(){
  int n=0;
  cin >> n;
  cin.ignore();
  string line;
  getline(cin,line);
  stringstream ss(line);
  string token;
  vector<int> vec;
  while (ss >> token){
    vec.push_back(stoi(token));
    }
  int M=0;
  cin >> M;
  //auto start = vec.begin();
  vec.erase(vec.begin()+M);
  int F=0;
  cin >> F;
  vec.erase(remove(vec.begin(),vec.end(),F),vec.end());
  cout << vec.size() << endl;
  for(const auto& lt :vec){
    cout << lt << " ";
    }

  }
