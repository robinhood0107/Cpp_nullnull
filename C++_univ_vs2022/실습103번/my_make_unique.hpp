#include <memory>
#include <string>
// Implement your code

template<typename T, typename... Args> 
std::unique_ptr<T> my_make_unique(Args&&... args){
    return std::unique_ptr<T> (new T (std::forward<Args>(args)...)); //(args...)이렇게 쓰면 안된다.((args)...)을 써야 함(recursion을 계속 forward를 하나씩 괄호를 풀면서 .을 하나씩 해결해 나아간다고 생각)
}
//rvalue는 주소가 없는 것을 말함(바로 집어넣기)
//lvalue는 주소가 있는것 (변수같은 것)(a=5에서 a)

//파라미터가 그대로 안집어넣어져서 만든게 std::forward

template<typename... Args>
int sum(Args... args) {
    return (args + ...); // sums all arguments
}