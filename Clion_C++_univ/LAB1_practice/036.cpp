




// <map> ?ㅻ뜑 ?꾩슂??
//map ?좎뼵踰?瑗??쒕?濡??뚯븘?щ씪
//map? key value?닿퀬 {key,value}??pair濡?媛믪씠 ?ㅼ뼱媛꾨떎.
//pair 媛믪쓣 諛섎뱶??.insert()濡??ｌ뼱????
//map<string,string> A; ?쇰븣 A[key] = value; ?닿쾶 媛?ν븯??
//A[key] = value;
//A.insert({key,value});
//map? 以묐났 ?덉슜 ?덊븯怨?諛섎났臾몄쑝濡??쒗쉶 媛??!!(踰붿쐞吏?뺤씠嫄??몄썙媛)

//留ㅼ슦留ㅼ슦留ㅼ슦留ㅼ슦 以묒슂
//while(cin >> M && M != "QUIT") ?대젃寃??낅젰?대옉 醫낅즺 ?숈떆??諛쏅뒗嫄?諛섎뱶???몄썙媛??

//+++留ㅼ슦留ㅼ슦留ㅼ슦留ㅼ슦 以묒슂
//find()?⑥닔濡?李얠쑝硫??대떦媛믪쓽 "諛섎났?? 諛섑솚??洹몃━怨?李얠? 紐삵븯硫?end() 諛섑솚
//洹몃옒??find濡?李얠?嫄곕뒗  ->  硫ㅻ쾭?ъ씤?몄젒洹쇳빐???쒕떎!!!!!!!!!!

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
  int N;
  cin >>N;
  string name;
  string number;
  map<string,string> phonebook;
  for(int i =0; i<N;i++){
      cin >> name >> number;
      phonebook[name] = number;
    }

  string M;
  while(cin >> M && M != "QUIT"){
      auto find = phonebook.find(M);
      if(find != phonebook.end())
        cout << find->second << endl;
      else
        cout << "NOT FOUND";
  }
}
