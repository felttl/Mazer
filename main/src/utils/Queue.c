/* queue.c */
#include "../../include/utils/Queue.h"
#include "../../include/utils/err_manager.h"

#include <stdlib.h>


Queue* qu_create(void* data){
    Queue* res = malloc(sizeof(Queue));
    ChainedNode* link = malloc(sizeof(ChainedNode));
    link->cn_data = data;
    link->cn_next = NULL;
    res->qu_head = link;
    res->qu_size = 1;
    res->qu_tail = link;
    return res;
}

void qu_push(Queue* q, ChainedNode* to_add){
    if (q == NULL) ERR_TERROR("q is null in qu_push() arg 1");
    if (to_add == NULL) ERR_TERROR("to_add is null in qu_push() arg 2");
    to_add->cn_next = NULL;
    q->qu_tail->cn_next = to_add;
    q->qu_tail = to_add;
    q->qu_size++;
}

void* qu_pop(Queue* q){
    ChainedNode* to_remove = q->qu_head;
    void* data = to_remove->cn_data;
    q->qu_head = to_remove->cn_next;
    q->qu_size--;
    free(to_remove);
    return data;
}

static void _p_qu_destroy_rec(){ // private

}

void qu_destroy(Queue* q){
    // us this to remove chain reccursively
    // _p_qu_destroy_rec
    if(!q) return;
    while (q->qu_size > 0)
        qu_pop(q);
    if (q->qu_tail != NULL) // not sure
        cn_destroy(q->qu_tail);
    free(q);
}

// end page
