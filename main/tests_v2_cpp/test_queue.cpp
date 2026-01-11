/* test_stack.cpp */
#include <gtest/gtest.h>

extern "C" {
    #include "utils/Queue.h"
}

TEST(QueueTest, Create) { // OK
    int* val = (int*)malloc(sizeof(int));
    *val = 33;

    Queue* q = qu_create(val);

    ASSERT_NE(q, nullptr); // stack créée
    EXPECT_EQ(q->qu_size, 1); // 1 élément
    ASSERT_NE(q->qu_last, nullptr); // premier node existe
    EXPECT_EQ(q->qu_head->q, val); // data correcte
    EXPECT_EQ(q->qu_head->qn_next, nullptr); // pas de suivant

    qu_remove(q);
    free(val);
}


TEST(StackTest, Push) {
    int* val = (int*)malloc(sizeof(int));
    *val = 33;
    Stack* s = sk_create(val);

    int* pushed_value = (int*)malloc(sizeof(int));
    *pushed_value = 42;

    sk_push(s, pushed_value);

    sk_destroy(s); // libère uniquement la pile
    free(val);
    free(pushed_value);
}

TEST(StackTest, Pop) {
    int* val = (int*)malloc(sizeof(int));
    *val = 33;
    Stack* s = sk_create(val);

    int* pushed_value = (int*)malloc(sizeof(int));
    *pushed_value = 42;

    sk_push(s, pushed_value);

    int* popped = (int*)sk_pop(s);
    EXPECT_EQ(*popped, 42);

    sk_destroy(s); // libère uniquement la pile
    free(val);
    free(pushed_value);
}
// end page
