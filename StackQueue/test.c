#include "Stack.h"
#include"queue.h"
void TestStack()
{
	ST st;
	StackInit(&st);
	StackPush(&st,1);
	StackPush(&st,2 );
	StackPush(&st,3 );
	StackPush(&st,4);

	while (!StackEmpty(&st)) {
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	StackDestory(&st);
}

void testqueue1()
{
	Queue q;
	QueueInit(&q);
}

int main() {
	TestStack();
	return 0;
}