/* test_stack.cpp */
#include <gtest/gtest.h>

extern "C" {
    #include "utils/Stack.h"
    #include "utils/err_manager.h"
}

TEST(StackTest, Push) {
    int* val = (int*)malloc(sizeof(int));
    *val = 33;
    Stack* s = sk_create(val);

    int* pushed_value = (int*)malloc(sizeof(int));
    *pushed_value = 42;

    sk_push(s, pushed_value);

    int* popped = (int*)sk_pop(s);
    EXPECT_EQ(*popped, 42);

    sk_remove(s);      // libère uniquement la pile
    free(val);
    free(pushed_value);
}


// end page
