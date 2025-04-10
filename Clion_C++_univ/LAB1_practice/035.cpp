//
// Created by pjjpj on 25. 4. 1.
//


//諛섎뱶???뚯븘???섎뒗 ?ы빆 = (cin >> ) ?곗궛??寃쎌슦 EOF(\0)???좏슚?섏? ?딆? ?낅젰??留뚮굹硫?false 諛섑솚
//?대옒??while 議곌굔臾??덉뿉 ?????덈뒗嫄곗엫(while ?숈븞 EOF???좏슚?쒓굅留뚮굹硫?false?대땲源?
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  string line;
  vector<int> vec;
  while(cin >> line){
    getline(cin,line);
    stringstream ss(line);
    string i=0;
    int veclen=0;
    while(ss>>i){
      vec.push_back(stoi(i));
      veclen++;
    }
    /*
    string token;
    int veclen;
    while(getline(ss,token,' ')){
      if(token != ""){
      vec.push_back(stoi(token));
      veclen++;}
    }
     */
    //援됱옣??踰덇굅濡?퀬 ?대젮??肄붾뱶?덇퉴 嫄?ss >> i ?⑤씪.
    cout << veclen << " "<< *min_element(vec.begin(),vec.end()) << " "<< *max_element(vec.begin(),vec.end());
    //min max????2媛쒖쓽 媛믪씠??pair 媛믩쭔 鍮꾧탳 媛??
    //vector??min_element ?⑥빞 ?? 洹쇰뜲 諛섎났?먮? 諛섑솚?섎땲源?* ??갭議??댁꽌 瑗??붿냼 異쒕젰?섍린)


  }
}
