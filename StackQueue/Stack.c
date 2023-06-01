#include "Stack.h"
void StackInit(ST* ps) {
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;

}

void StackDestory(ST* ps) {
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

void StackPush(ST* ps, STDataType x) {
	assert(ps);
	if (ps->top == ps->capacity) {
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = realloc(ps->a, sizeof(STDataType) * newcapacity);
		if (tmp == NULL){
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

void StackPop(ST* ps) {
	assert(ps);
	assert(ps->top > 0);

	ps->top--;
}

STDataType StackTop(ST* ps) {
	assert(ps);
	assert(!StackEmpty(ps));

	return ps->a[ps->top - 1];
}

bool StackEmpty(ST* ps) {
	
		return ps->top == 0;
}

int StackSize(ST* ps) {
	assert(ps);
	return ps->top;
}