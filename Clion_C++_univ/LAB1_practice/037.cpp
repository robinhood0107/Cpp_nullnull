//
// Created by pjjpj on 25. 4. 2.
//


//??2媛??꾨? ??iterator???ъ슜??

//istream_iterator ostream_iterator 瑗??붽린?섍린

//istream_iterator<int> cin_iter(cin); ?대젃寃??좎뼵?섍퀬 (?닿굅 洹몃?濡??붽린)
//istream_iterator<int> eos; //?앹쓣 泥댄겕?섎뒗 ?⑸룄濡?eos留뚮뱾湲?

//vector???낅젰諛쏅뒗踰?
//copy()?⑥닔瑜??ъ슜?쒕떎
//copy(cin_iter,eos,back_inserter(vec))
//back_inserter瑜??듯빐???쒖감?곸쑝濡?vec ?앹뿉 ?뺤닔瑜?異붽??쒕떎.



//ostream_iterator cout_iter(cout," ") ?대젃寃??좎뼵??(?닿굅 洹몃?濡??붽린

//異쒕젰? copy()濡??쒕떎. copy(vec.begin(),vec.end(),cout_iter) ?대젃寃??섎㈃ ?쒕떎.
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;


int main(){
      istream_iterator<int> cin_iter(cin);
      istream_iterator<int> eos;
      vector<int> vec = {};

      copy(cin_iter,eos,back_inserter(vec));
      sort(vec.begin(),vec.end());

      ostream_iterator<int> cout_iter(cout);
      copy(vec.begin(),vec.end(),cout_iter);
}
