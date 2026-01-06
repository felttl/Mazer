/* test_stack.cpp */
#include <gtest/gtest.h>

extern "C" {
    #include "utils/Stack.h"
}

TEST(StackTest, Push) {
    int val = 33;
    Stack* s = sk_create(&val); // ptr addr
    ASSERT_NE(s, nullptr);

    int pushed_value = 42;
    Stack* astk = sk_create(&pushed_value);

    sk_push(s, astk);
    EXPECT_EQ(sk_pop(s), 1);
    sk_remove(s);
}

TEST(StackTest, Pop) {
    int val = 33;
    Stack* s = sk_create(&val); // ptr addr
    ASSERT_NE(s, nullptr);

    int pushed_value = 42;
    Stack* astk = sk_create(&pushed_value);

    sk_push(s, astk);
    EXPECT_EQ(sk_pop(s), 1);
    sk_remove(s);
}

// end page
