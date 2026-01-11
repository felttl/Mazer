/* test_stack.cpp */
#include <gtest/gtest.h>

extern "C" {
    #include "utils/Stack.h"
}

TEST(StackTest, Create) { // OK
    int* val = (int*)malloc(sizeof(int));
    *val = 33;

    Stack* s = sk_create(val);

    ASSERT_NE(s, nullptr); // stack créée
    EXPECT_EQ(s->sk_size, 1); // 1 élément
    ASSERT_NE(s->sk_last, nullptr); // premier node existe
    EXPECT_EQ(s->sk_last->n_data, val); // data correcte
    EXPECT_EQ(s->sk_last->n_next, nullptr); // pas de suivant

    sk_destroy(s);
}


TEST(StackTest, Push) {
    int* val = (int*)malloc(sizeof(int));
    *val = 330;
    Stack* s = sk_create(val);

    int* pushed_value = (int*)malloc(sizeof(int));
    *pushed_value = -42;

    sk_push(s, pushed_value);

    EXPECT_NE(s, nullptr); // stack not destroyed after push
    EXPECT_EQ(s->sk_size, 2); // 2 items
    ASSERT_NE(s->sk_last, nullptr); // first node exist
    EXPECT_EQ(s->sk_last->n_data, pushed_value); // data correct

    // second layer
    EXPECT_NE(s->sk_last->n_next, nullptr); // exactly on next exist
    EXPECT_EQ(s->sk_last->n_next->n_data, val); // exact match value
    EXPECT_EQ(s->sk_last->n_next->n_next, nullptr); // only 2 items

    //WARNING: this part not checked yet (tested later)
    sk_destroy(s); // free the wole stack
}

TEST(StackTest, Pop) {
    int* val = (int*)malloc(sizeof(int));
    *val = 25;
    Stack* s = sk_create(val);

    int* pushed_value = (int*)malloc(sizeof(int));
    *pushed_value = 78;

    sk_push(s, pushed_value);

    EXPECT_EQ(s->sk_size, 2); // 2 items

    int* popped = (int*)sk_pop(s);

    EXPECT_EQ(s->sk_size, 1); // 1 item
    EXPECT_EQ(*popped, 78); // pop must return content

    ASSERT_NE(s->sk_last, nullptr); // first node exist  

    EXPECT_NE(s->sk_last->n_next, nullptr); // last item deleted well
    EXPECT_EQ(s->sk_last->n_data, val); // data still there

    //WARNING: this part not checked yet
    sk_destroy(s); // free the wole stack
}

TEST(StackTest, Destroy) {
    int* val = (int*)malloc(sizeof(int));
    *val = 33;
    Stack* s = sk_create(val);

    int* pushed_value = (int*)malloc(sizeof(int));
    *pushed_value = 24;
    int* pushed_value1 = (int*)malloc(sizeof(int));
    *pushed_value1 = 82;
    int* pushed_value2 = (int*)malloc(sizeof(int));
    *pushed_value2 = -18;

    sk_push(s, pushed_value);
    sk_push(s, pushed_value1);
    sk_push(s, pushed_value2);

    EXPECT_EQ(s->sk_size, 4);

    sk_destroy(s); // free the wole stack
    sk_destroy(NULL); // must be safe

    // how to test here ?
    // > impossible : use Valgrind or LLDB to see memory leaks

}
// end page
