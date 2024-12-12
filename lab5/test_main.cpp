#include <gtest/gtest.h>
#include "src/custom_memory_resource.h"
#include "src/stack.h"

struct ComplexType {
    int id;
    std::string name;

    bool operator==(const ComplexType& other) const {
        return id == other.id && name == other.name;
    }
};

TEST(StackTest, BasicOperations) {
    CustomMemoryResource memoryResource;
    Stack<int64_t> stack(&memoryResource);

    EXPECT_TRUE(stack.empty());

    stack.push(1);
    stack.push(2);
    stack.push(3);

    EXPECT_FALSE(stack.empty());
    EXPECT_EQ(stack.top(), 3);

    stack.pop();
    EXPECT_EQ(stack.top(), 2);

    stack.pop();
    EXPECT_EQ(stack.top(), 1);

    stack.pop();
    EXPECT_TRUE(stack.empty());
}

TEST(StackTest, ComplexTypeOperations) {
    CustomMemoryResource memoryResource;
    Stack<ComplexType> stack(&memoryResource);

    stack.push({1, "Alice"});
    stack.push({2, "Bob"});
    stack.push({3, "Charlie"});

    EXPECT_EQ(stack.top(), (ComplexType{3, "Charlie"}));

    stack.pop();
    EXPECT_EQ(stack.top(), (ComplexType{2, "Bob"}));

    stack.pop();
    EXPECT_EQ(stack.top(), (ComplexType{1, "Alice"}));
}

TEST(StackTest, EmptyStackBehavior) {
    CustomMemoryResource memoryResource;
    Stack<int> stack(&memoryResource);

    EXPECT_TRUE(stack.empty());

    EXPECT_THROW(stack.top(), std::runtime_error);
    EXPECT_NO_THROW(stack.pop()); 
}

TEST(StackTest, IteratorTest) {
    CustomMemoryResource memoryResource;
    Stack<int> stack(&memoryResource);

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::vector<int> expected = {3, 2, 1};
    std::vector<int> result;

    for (auto it = stack.begin(); it != stack.end(); ++it) {
        result.push_back(*it);
    }

    EXPECT_EQ(result, expected);
}
