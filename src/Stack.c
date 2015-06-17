#include "Stack.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>


// Stack *stackCreate();
// StackElement *stackElementCreate(int data);
// void stackAdd( Stack *stack , StackElement *elem);
// StackElement *stackRemove(Stack *stack);


Stack *stackCreate(){
	
	Stack *S = malloc(sizeof(Stack));
	assert( S != NULL);
	
	S->head = NULL;
	S->tail = NULL;
	S->length = 0;
	
	return S;
}

StackElement *stackElementCreate(int data){
	
	StackElement *elem = malloc(sizeof(StackElement));
	assert( elem != NULL);
	
	elem->value = data;
	elem->next = NULL;
	
	return elem;
}




void stackAdd( Stack *stack , StackElement *elem){
	 
	 if(elem == NULL){
		
		printf("ERROR:The Stack Element is NULL"); 

	 }else if(stack == NULL)
		 {
			 printf("ERROR:The Stack is NULL"); 
			 
		 }else{
		 
		 elem->next = stack->head;
		 stack->head = elem;
		 (stack->length)++;

			for(stack->tail = stack->head ; stack->tail->next!=NULL ; stack->tail = stack->tail->next);
		 
		 }
		 
		 
	 }
	 
	 
 
 
StackElement *stackRemove(Stack *stack){
	
	// printf("[%d],[%d]\n",stack->head->value,stack->tail->value);

	StackElement *remove = malloc(sizeof(StackElement));
	StackElement *Storedata = malloc(sizeof(StackElement));
	if(stack == NULL){
		
		printf("ERROR:The Stack is NULL");
		 return NULL;
		
	}else if(stack->head == NULL ){
		 
		 printf("ERROR:The Stack is Empty");
		 return NULL;
		 
	 }else{
			
			remove = stack->head;
		 // printf("remove->value = %d",remove->value);
			Storedata->value = remove->value;
			Storedata->next = NULL;
			stack->head = stack->head->next;
			(stack->length)--;
			if(stack->length == 0){
				stack->tail = stack->tail->next;
			}
			free(remove);
			

		 	return Storedata;
	 }
	 
 }
 