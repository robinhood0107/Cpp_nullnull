#include "inventory.h"
#include <algorithm>
#include <numeric>

namespace {
    inventory data = {
        {1, "iPhone 16 Pro", 999.99, 15},
        {2, "AirPods Pro 3", 249.99, 30},
        {3, "MacBook Pro M4", 1599.99, 8},
        {4, "iPad Pro M4", 799.99, 12},
        {5, "Apple Watch Ultra 3", 849.99, 20},
        {6, "PlayStation 5 Pro", 699.99, 10}
    };
}

// 네임스페이스 있으면 std namespace사용 못한다 std:: 붙여
//inventory는 백터처럼 쓰임(2차원 배열임)

// Implement your code

void create_item(const std::string& name, double price, int qty){
    Item item;
    int len = generate_next_id();
    item.id=len;
    item.name=name;
    item.price=price;
    item.qty=qty;
    data.push_back(item);
}

const inventory get_inventory(){
    //원래는 const Item& a, const Item& b가 인자로들어가는데 auto 쓰면 된다.
    //a<b 이게 오름차순인거 기억.
    // 자연스러운 a<b가 오름차순이다
    std::sort(data.begin(),data.end(),[](auto a, auto b) {return a.price < b.price;});
    return data;
}

bool find_item(int id, Item& found_item){
    auto it = std::find_if(data.begin(),data.end(),[&id](auto x) {return x.id == id;});
    if(it != data.end()){
        //못찾으면 end반환 꼭 기억
        found_item.id = it->id;
        found_item.name = it->name;
        found_item.price = it->price;
        found_item.qty = it->qty;
        return true;
    }
    else{
        return false;
    }


}


bool update_item(int id, double new_price, int new_qty){
    auto it = std::find_if(data.begin(),data.end(),[&id](auto x) {return x.id == id;});
    if(it != data.end()){
        it->price = new_price;
        it->qty = new_qty;
        return true;
    }
    else
        return false;
}

bool delete_item(int id){
    if(std::find_if(data.begin(),data.end(),[&id](auto x) {return x.id == id;}) != data.end()){
        data.erase(std::remove_if(data.begin(),data.end(),[&id](auto x) {return x.id == id;}),data.end());
        //erase안에 remove_if 들어가서 x.id == id인지 확인
        return true;
    }
    else
        return false;
}

int generate_next_id(){
    ///이게 중요함
    ///datalt를 max_element를 이용해서 오름차순으로 제일 높은 것 구한다.
    // data.empty()는 비엇다는 것
    auto datalt = max_element(data.begin(),data.end(),[](auto x, auto y) {return x.id < y.id;});//이거 꼭 max_element로 해라! size 절대 안됨!
    int len = datalt->id+1; //자꾸 까먹는다 반드시 이터레이터(참조자)는 ->로 멤버 참조!!!!
    if(data.empty()){ //vector의 empty는 백터가 비엇다는 것 empty 잘 쓰자! 기억해라 이건
        return 1;
    }
    else{
        return len;
    }

}