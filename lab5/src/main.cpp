#include <iostream>
#include <string>
#include "custom_memory_resource.h"
#include "stack.h"

struct ComplexType {
    int64_t id;
    std::string name;
};

int main() {
    CustomMemoryResource memoryResource;

    Stack<int> stack_int(&memoryResource);

    Stack<ComplexType> stack(&memoryResource);


    stack_int.push(10);
    stack_int.push(20);
    stack_int.push(30);

    for (auto& it : stack_int){
        std::cout<<it<<std::endl;
    }
    std::cout<<std::endl;

    stack.push({1, "Alice"});
    stack.push({2, "Bob"});
    stack.push({3, "Charlie"});

    
    while (!stack.empty()) {
        const auto& top = stack.top();
        std::cout << "ID: " << top.id << ", Name: " << top.name << '\n';
        stack.pop();
    }

    return 0;
}
