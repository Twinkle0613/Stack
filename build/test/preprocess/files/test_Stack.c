#include "Stack.h"
#include "unity.h"


void setUp(void){}



void tearDown(void){}

void test_stackCreate_Should_return_head_and_tail_equal_NULL(void){





 Stack *stack = stackCreate();



 if ((((stack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)23);;};

 if ((((stack->head)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)24);;};

 if ((((stack->tail)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)25);;};

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((stack->length)), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_INT);



}

void test_stackElementCreate_should_equal_NOT_NULL(void){





 StackElement *SElem = stackElementCreate(4);



 if ((((SElem)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)47);;};

 UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((SElem->value)), (((void *)0)), (_U_UINT)48, UNITY_DISPLAY_STYLE_INT);

 if ((((SElem->next)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)49);;};



}

void test_stackAdd_should_add_Element_to_Stack(void){



  Stack *stack = stackCreate();

  if ((((stack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)72);;};



  StackElement *SElem1 = stackElementCreate(4);

  StackElement *SElem2 = stackElementCreate(5);

  if ((((SElem1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)76);;};

  if ((((SElem2)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)77);;};



  stackAdd(stack,SElem1);

  printf("[%d],[%d]\n",stack->head->value,stack->tail->value);



  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((stack->head->value)), (((void *)0)), (_U_UINT)82, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((stack->tail->value)), (((void *)0)), (_U_UINT)83, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((stack->length)), (((void *)0)), (_U_UINT)84, UNITY_DISPLAY_STYLE_INT);

  if ((((stack->tail->next)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)85);;};

  if ((((stack->head)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)86);;};





  stackAdd(stack,SElem2);

  printf("[%d],[%d]\n",stack->head->value,stack->tail->value);



  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((stack->head->value)), (((void *)0)), (_U_UINT)92, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((stack->tail->value)), (((void *)0)), (_U_UINT)93, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((stack->length)), (((void *)0)), (_U_UINT)94, UNITY_DISPLAY_STYLE_INT);

  if ((((stack->tail->next)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)95);;};







}

void test_stackRemove_should_return_the_value_inside_the_stack(void){





  Stack *stack = stackCreate();

  if ((((stack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)120);;};



  StackElement *SElem1 = stackElementCreate(4);

  StackElement *SElem2 = stackElementCreate(5);

  if ((((SElem1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)124);;};

  if ((((SElem2)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)125);;};





  stackAdd(stack,SElem1);

  printf("[%d],[%d]\n",stack->head->value,stack->tail->value);

  stackAdd(stack,SElem2);

  printf("[%d],[%d]\n",stack->head->value,stack->tail->value);





  StackElement *X = malloc(sizeof(StackElement));



  X = stackRemove(stack);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((X->value)), (((void *)0)), (_U_UINT)137, UNITY_DISPLAY_STYLE_INT);

   UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((stack->length)), (((void *)0)), (_U_UINT)138, UNITY_DISPLAY_STYLE_INT);

  printf("remove = %d\n", X->value);



  X = stackRemove(stack);

  UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((X->value)), (((void *)0)), (_U_UINT)142, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((stack->length)), (((void *)0)), (_U_UINT)143, UNITY_DISPLAY_STYLE_INT);

  printf("remove = %d\n", X->value);



  X = stackRemove(stack);

  if ((((X)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)147);;};

  if ((((stack->head)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)148);;};

  if ((((stack->tail)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)149);;};





}



void test_stackAdd_the_Stack_is_NULL(void){



  Stack *stack = ((void *)0);

  if ((((stack)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)157);;};

  StackElement *SElem1 = stackElementCreate(4);

  stackAdd(stack,SElem1);

  if ((((stack)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)160);;};





}





void test_stackAdd_the_element_is_NULL(void){



  Stack *stack = stackCreate();

  StackElement *SElem1 = stackElementCreate(4);

  if ((((SElem1)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)170);;};

  if ((((stack)) != ((void *)0))) {} else {UnityFail( (" Expected Non-NULL"), (_U_UINT)(_U_UINT)(_U_UINT)171);;};



  stackAdd(stack,SElem1);

   UnityAssertEqualNumber((_U_SINT)((4)), (_U_SINT)((stack->head->value)), (((void *)0)), (_U_UINT)174, UNITY_DISPLAY_STYLE_INT);

  printf("[%d],[%d]\n",stack->head->value,stack->tail->value);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((stack->length)), (((void *)0)), (_U_UINT)176, UNITY_DISPLAY_STYLE_INT);





  StackElement *SElem2 = ((void *)0);

  if ((((SElem2)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)180);;};

  stackAdd(stack,SElem2);

  UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((stack->length)), (((void *)0)), (_U_UINT)182, UNITY_DISPLAY_STYLE_INT);





}



void test_stackRemove_the_Stack_is_NULL(void){







  Stack *stack = ((void *)0);

  if ((((stack)) == ((void *)0))) {} else {UnityFail( (" Expected NULL"), (_U_UINT)(_U_UINT)(_U_UINT)192);;};





  StackElement *X = malloc(sizeof(StackElement));



  X = stackRemove(stack);





}
