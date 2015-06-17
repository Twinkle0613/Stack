#ifndef Stack_H
#define Stack_H









typedef struct StackElement StackElement;

struct StackElement{
	  struct StackElement *next;
		int value;
	};
	
typedef struct {
	
	 StackElement *head;
	 StackElement *tail;
	 int length;
	
}Stack;
	
Stack *stackCreate();
StackElement *stackElementCreate(int data);
 void stackAdd( Stack *stack , StackElement *elem);
StackElement *stackRemove(Stack *stack);
#endif // Stack_H
