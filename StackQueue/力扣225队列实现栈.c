#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

typedef int QDatatype;

typedef struct QueueNode
{
    struct QueueNode* next;
    QDatatype data;
} QNode;

typedef struct Queue
{
    QNode* head;
    QNode* tail;
} Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);

// 队尾入
void QueuePush(Queue* pq, QDatatype x);
// 队头出
void QueuePop(Queue* pq);
QDatatype QueueFront(Queue* pq);
QDatatype QueueBack(Queue* pq);
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);

void QueueInit(Queue* pq)
{
    assert(pq);
    pq->head = NULL;
    pq->tail = NULL;
}

void QueueDestroy(Queue* pq)
{
    assert(pq);
    QNode* cur = pq->head;
    while (cur != NULL)
    {
        QNode* next = cur->next;
        free(cur);
        cur = next;
    }
    pq->head = pq->tail = NULL;
}

void QueuePush(Queue* pq, QDatatype x)
{
    assert(pq);
    QNode* newnode = (QNode*)malloc(sizeof(QNode));
    newnode->data = x;
    newnode->next = NULL;

    if (pq->head == NULL)
    {
        pq->head = pq->tail = newnode;
    }
    else
    {
        pq->tail->next = newnode;
        pq->tail = newnode;
    }
}

void QueuePop(Queue* pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    QNode* newnode = pq->head->next;
    free(pq->head);
    pq->head = newnode;
    if (pq->head == NULL)
    {
        pq->tail = NULL;
    }
}

QDatatype QueueFront(Queue* pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    return pq->head->data;
}

QDatatype QueueBack(Queue* pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    return pq->tail->data;
}

int QueueSize(Queue* pq)
{
    assert(pq);
    int n = 0;
    QNode* cur = pq->head;
    while (cur)
    {
        ++n;
        cur = cur->next;
    }
    return n;
}

bool QueueEmpty(Queue* pq)
{
    assert(pq);
    return pq->head == NULL;
}

typedef struct
{
    Queue q1;
    Queue q2;
} MyStack;

MyStack* myStackCreate()
{
    MyStack* st = (MyStack*)malloc(sizeof(MyStack));
    QueueInit(&st->q1);
    QueueInit(&st->q2);
    return st;
}

void myStackPush(MyStack* obj, int x)
{
    if (QueueEmpty(&obj->q1))
    {
        QueuePush(&obj->q1, x);
    }
    else
    {
        QueuePush(&obj->q2, x);
    }
}

int myStackPop(MyStack* obj)
{
    Queue* emptyQ = &obj->q1;
    Queue* noemptyQ = &obj->q2;
    if (!QueueEmpty(&obj->q1))
    {
        emptyQ = &obj->q2;
        noemptyQ = &obj->q1;
    }
    while (QueueSize(noemptyQ) > 1)
    {
        QueuePush(emptyQ, QueueFront(noemptyQ));
        QueuePop(noemptyQ);
    }
    int top = QueueFront(noemptyQ);
    QueuePop(noemptyQ);
    return top;
}

int myStackTop(MyStack* obj)
{
    if (!QueueEmpty(&obj->q1))
    {
        return QueueBack(&obj->q1);
    }
    else
    {
        return QueueBack(&obj->q2);
    }
}

bool myStackEmpty(MyStack* obj)
{
    return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj)
{
    QueueDestroy(&obj->q1);
    QueueDestroy(&obj->q2);
    free(obj);
}

int main()
{
    MyStack* myStack = myStackCreate();
    myStackPush(myStack, 1);
    myStackPush(myStack, 2);
    printf("%d\n", myStackTop(myStack)); // 输出 2
    printf("%d\n", myStackPop(myStack)); // 输出 2
    printf("%s\n", myStackEmpty(myStack) ? "True" : "False"); // 输出 False

    myStackFree(myStack);

    return 0;
}

