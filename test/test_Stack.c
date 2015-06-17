#include "unity.h"
#include "Stack.h"
#include <malloc.h>

void setUp(void){}

void tearDown(void){}

/*
			stack
			head--------
								 |
			tail-------|
								 |
							(NULL)
			length = 0
*/
void test_stackCreate_Should_return_head_and_tail_equal_NULL(void){
	

	Stack *stack = stackCreate();
	
	TEST_ASSERT_NOT_NULL(stack);
	TEST_ASSERT_NULL(stack->head);
	TEST_ASSERT_NULL(stack->tail);
	TEST_ASSERT_EQUAL(0,stack->length);
	
}

/*
			SElem------
                |
             -------
						|   4  |
						-------
					 | NEXT |-------
           -------       |
                       (NULL)
											 
*/

void test_stackElementCreate_should_equal_NOT_NULL(void){
	
	
	StackElement *SElem = stackElementCreate(4);
	
	TEST_ASSERT_NOT_NULL(SElem);
	TEST_ASSERT_EQUAL(4,SElem->value);
	TEST_ASSERT_NULL(SElem->next);
	
}

// void stackAdd( Stack *stack , StackElement *elem);
/*  


			Stack
			
			head---------							head---------         head-------        tail---
									|          								|                   |              |
					        |        =>            -------   =>       --------      --------
			tail------> |             tail--->|  4   |           |   5   |---->|   4   |------
								 (NULL)                 -------            --------      --------      |
                                                                                     (NULL)
			length = 0                  length = 1                      length = 2

*/

void test_stackAdd_should_add_Element_to_Stack(void){
	
		Stack *stack = stackCreate();
		TEST_ASSERT_NOT_NULL(stack);

		StackElement *SElem1 = stackElementCreate(4);
		StackElement *SElem2 = stackElementCreate(5);
		TEST_ASSERT_NOT_NULL(SElem1);
		TEST_ASSERT_NOT_NULL(SElem2);

		stackAdd(stack,SElem1);
		printf("[%d],[%d]\n",stack->head->value,stack->tail->value);

		TEST_ASSERT_EQUAL(4,stack->head->value);
	  TEST_ASSERT_EQUAL(4,stack->tail->value);
		TEST_ASSERT_EQUAL(1,stack->length);
		TEST_ASSERT_NULL(stack->tail->next);
		TEST_ASSERT_NOT_NULL (stack->head);
		 
		 
		stackAdd(stack,SElem2);
		printf("[%d],[%d]\n",stack->head->value,stack->tail->value);

		TEST_ASSERT_EQUAL(5,stack->head->value);
		TEST_ASSERT_EQUAL(4,stack->tail->value);
		TEST_ASSERT_EQUAL(2,stack->length);
		TEST_ASSERT_NULL(stack->tail->next);

			
		
}



// StackElement *stackRemove(Stack *stack);
/*

		       head-------        tail---                                  tail----                 tail----
    	                |              |                                        |                        |               tail------
		     	        --------      --------           =>      --------        --------                --------                     |
                 |   5   |---->|   4   |------            |   5   | ----->|   4   |-----     =>   |   4   |-----    => head---- |
                 --------      --------      |            --------        --------     |          --------     |                |     
                     |                     (NULL)             |               |      (NULL)           |      (NULL)          (NULL)
           remove----                               remove----          head--                  head--
					length = 2                                      length = 2                            length = 1              length = 0

*/
void test_stackRemove_should_return_the_value_inside_the_stack(void){
	
	
		Stack *stack = stackCreate();
		TEST_ASSERT_NOT_NULL(stack);
		
		StackElement *SElem1 = stackElementCreate(4);
		StackElement *SElem2 = stackElementCreate(5);
		TEST_ASSERT_NOT_NULL(SElem1);
		TEST_ASSERT_NOT_NULL(SElem2);

		
		stackAdd(stack,SElem1);
		printf("[%d],[%d]\n",stack->head->value,stack->tail->value);
		stackAdd(stack,SElem2);
		printf("[%d],[%d]\n",stack->head->value,stack->tail->value);
		
		
		StackElement *X = malloc(sizeof(StackElement));
		
		X = stackRemove(stack);
		TEST_ASSERT_EQUAL(5,X->value);
	  TEST_ASSERT_EQUAL(1,stack->length);
		printf("remove = %d\n", X->value);
		
		X = stackRemove(stack);
		TEST_ASSERT_EQUAL(4,X->value);
		TEST_ASSERT_EQUAL(0,stack->length);
		printf("remove = %d\n", X->value);

		X = stackRemove(stack);
		TEST_ASSERT_NULL(X);
		TEST_ASSERT_NULL(stack->head);
		TEST_ASSERT_NULL(stack->tail);
		

}

void test_stackAdd_the_Stack_is_NULL(void){
	// stackAdd(NULL,elem)
		Stack *stack = NULL;
		TEST_ASSERT_NULL(stack);
		StackElement *SElem1 = stackElementCreate(4);
		stackAdd(stack,SElem1);
		TEST_ASSERT_NULL(stack);

	
}


void test_stackAdd_the_element_is_NULL(void){
		
		Stack *stack = stackCreate();
		StackElement *SElem1 = stackElementCreate(4);
		TEST_ASSERT_NOT_NULL(SElem1);
		TEST_ASSERT_NOT_NULL(stack);

		stackAdd(stack,SElem1);
	 	TEST_ASSERT_EQUAL(4,stack->head->value);
		printf("[%d],[%d]\n",stack->head->value,stack->tail->value);
		TEST_ASSERT_EQUAL(1,stack->length);


		StackElement *SElem2 = NULL;
		TEST_ASSERT_NULL(SElem2);
		stackAdd(stack,SElem2);
		TEST_ASSERT_EQUAL(1,stack->length);
		

}

void test_stackRemove_the_Stack_is_NULL(void){
	
	
	
		Stack *stack = NULL;
		TEST_ASSERT_NULL(stack);
			
	
		StackElement *X = malloc(sizeof(StackElement));
		
		X = stackRemove(stack);
		//	TEST_ASSERT_NULL(stack);

}


