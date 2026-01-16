/* test_stack.cpp */
#include <gtest/gtest.h>

extern "C" {
    #include "utils/Queue.h"
}

TEST(QueueTest, Create) { // OK
    int* val = (int*)malloc(sizeof(int));
    *val = 89;

    Queue* q = qu_create(val);

    ASSERT_NE(q, nullptr); // stack créée
    EXPECT_EQ(q->qu_size, 1); // 1 élément
    ASSERT_NE(q->qu_head, nullptr); // premier node existe
    EXPECT_EQ(q->qu_head->cn_data, val); // data correcte
    EXPECT_EQ(q->qu_head->cn_next, nullptr); // pas de suivant

    qu_destroy(q);
    free(val);
}


TEST(QueueTest, Push) {
    int* val = (int*)malloc(sizeof(int));
    *val = 126;
    Queue* q = qu_create(val);

    int* pushed_value = (int*)malloc(sizeof(int));
    *pushed_value = 13;

    // on devrait surement créer des functions
    // pou créer et supprimer des nodes
    // pour mermettre une mailleurs réutilisation pas les autres
    // structures plus grandes (Stack, Queue, Graphs, ...)
    ChainedNode* node= cn_create(pushed_value);
    qu_push(q, node);

    // a remplacer dans les premiers tests car 
    // on est pas encore sur de son fonctionnement
    // (sera testé plus tard)
    qu_destroy(q); // libère toutes la file donc pas besoin de faire de free après
    free(val);
    free(pushed_value);
}

TEST(StackTest, Pop) {
    int* val = (int*)malloc(sizeof(int));
    *val = 33;
    Queue* q = qu_create(val);

    int* pushed_value = (int*)malloc(sizeof(int));
    int value = 49;
    *pushed_value = value;

    ChainedNode* node= cn_create(pushed_value);
    qu_push(q, node);

    int* popped = (int*)qu_pop(q);
    EXPECT_EQ(*popped, value);

    // éviter d'utiliser "qu_destroy()"  
    // avant d'avoir fait le test
    // dans un test dédié
    qu_destroy(q); // libère uniquement la pile
    free(val);
    free(pushed_value);
}

TEST(StackTest, Destroy) {
    int* val = (int*)malloc(sizeof(int));
    *val = 33;
    Queue* q = qu_create(val);

    int* pushed_value = (int*)malloc(sizeof(int));
    *pushed_value = 42;

    ChainedNode* node= cn_create(pushed_value);
    qu_push(q, node);
    *pushed_value = 29;
    node= cn_create(pushed_value);
    qu_push(q, node);
    *pushed_value = 280;
    node= cn_create(pushed_value);
    qu_push(q, node);

    // on test ici
    qu_destroy(q); // free the whole queue
    qu_destroy(NULL); // safe

    // no more free if everything is done correctly
}
// end page
