#include "my_vector.hpp"
#include <iostream>

int main() {
    using namespace std;
    my_vector<int> vec = {1, 2, 3, 4, 5};
    my_vector<int> vec2(vec);
    vec2[4] = 10;

    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i] << ' ';
    cout << '\n';

    for (int i = 0; i < vec2.size(); ++i)
        cout << vec2[i] << ' ';
    cout << '\n';
}
