#include"queue.h"
void QueueInit(Queue* pq) {   //³õÊ¼»¯
	assert(pq);
	pq->head = NULL;
	pq->tail = NULL;

}

void QueueDestory(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur != NULL) {
		QNode* next = cur->next;
		free(cur);
		cur = next;

	}
	pq->head = pq->tail = NULL;
}

void QueuePush(Queue* pq, QDatatype x) {
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	newnode->data = x;
	newnode->next = NULL;

	if (pq->head == NULL) {
		pq->head = pq->tail = newnode;
	}
	else {
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}
void QueuePop(Queue* pq) {
	assert(pq);
	assert(!QueueEmpty(pq));
	QNode* newnode = pq->head->next;
	free(pq->head);
	pq->head = newnode;
	if (pq->head == NULL) {
		pq->tail - NULL;
	}
}

QDatatype* QueueFront(Queue* pq) {
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}
QDatatype QueueBack(Queue* pq) {
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}
int QueueSize(Queue* pq) {
	assert(pq);
	int n = 0;
	QNode* cur = pq->head;
	while (cur) {
		++n;
		cur = cur->next;
	}
	return n;
}
bool QueueEmpty(Queue* pq) {
	assret(pq);
	return pq->head == NULL;
}