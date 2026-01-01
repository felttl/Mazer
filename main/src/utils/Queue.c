/* queue.c */
#include "../../include/utils/Queue.h"
#include "../../include/utils/err_manager.h"

#include <stdlib.h>


Queue* qu_create(void* data){
    Queue* res = malloc(sizeof(Queue));
    QueueNode* link = malloc(sizeof(QueueNode));
    link->qn_data = data;
    link->qn_next = NULL;
    res->qu_head = link;
    res->qu_size = 1;
    res->qu_tail = link;
    return res;
}

void qu_push(Queue* q, QueueNode* to_add){
    if (q == NULL) terror("q is null in qu_push() arg 1");
    if (to_add == NULL) terror("to_add is null in qu_push() arg 2");
    to_add->qn_next = NULL;
    q->qu_tail->qn_next = to_add;
    q->qu_tail = to_add;
    q->qu_size++;
}

void* qu_pop(Queue* q){
    QueueNode* to_remove = q->qu_head;
    void* data = to_remove->qn_data;
    q->qu_head = to_remove->qn_next;
    q->qu_size--;
    free(to_remove);
    return data;
}

static void _p_qu_destroy_rec(){ // private

}

void qu_destroy(Queue* q){
    // us this to remove chain reccursively
    // _p_qu_destroy_rec
}

// end page
