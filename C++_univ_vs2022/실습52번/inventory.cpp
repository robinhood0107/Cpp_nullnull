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

// Implement your code
void create_item(const std::string& name, double price, int qty) {
    Item item;
    int len = generate_next_id();
    item.id = len;
    item.name = name;
    item.price = price;
    item.qty = qty;
    data.push_back(item);
}
const inventory get_inventory() {
    //원래는 const Item& a, const Item& b가 인자로들어가는데 auto 쓰면 된다.
    //a>b 이게 오름차순인거 기억.
    std::sort(data.begin(), data.end(), [](auto a, auto b) {return a.price < b.price; });
    return data;
}

bool find_item(int id, Item& found_item) {
    auto it = std::find_if(data.begin(), data.end(), [&id](auto x) {return x.id == id; });
    if (it != data.end()) {
        //못찾으면 end반환 꼭 기억
        found_item.id = it->id;
        found_item.price = it->price;
        found_item.qty = it->qty;
        return true;
    }
    else {
        return false;
    }


}

bool update_item(int id, double new_price, int new_qty) {
    auto it = std::find_if(data.begin(), data.end(), [&id](auto x) {return x.id == id; });
    if (it != data.end()) {
        it->price = new_price;
        it->qty = new_qty;
        return true;
    }
    else
        return false;
}

bool delete_item(int id) {
    if (std::find_if(data.begin(), data.end(), [&id](auto x) {return x.id == id; }) != data.end()) {
        std::remove_if(data.begin(), data.end(), [&id](auto x) {return x.id == id; });
        return true;
    }
    else
        return false;
}


int generate_next_id() {
    int id = 0;
    auto it = std::find_if(data.begin(), data.end(), [&id](auto x) {return x.id == id; });
    int len = data.size();
    if (it == data.end()) {
        return 1;
    }
    else {
        return len + 1;
    }

}

double calculate_total_value() {
    double sum = 0;
    std::vector<double> vec = {};
    for (auto& it : data) {
        vec.push_back(it.price * it.qty);
    }
    sum = accumulate(vec.begin(), vec.end(), 0);
    return sum;
}