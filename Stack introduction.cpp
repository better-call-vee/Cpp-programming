///STACK means pile of objects. eg: playing cards in a packet.
//We can take an object from the top of a stack and put an object on top of a stack
//Top element removal and addition.
//Stack[A,K,Q,J,10,9]. suppose this a stack of cards. here the top element is 9.
//we can remove it and we can add new element after 9.
//Stack[A,K,Q,J,10] top element 10 / Stack[A,K,Q,J,10,9,8] te 8

///WE COULD DO THIS USING ARRAY!! WHAT'S THE POINT DOING THIS WITH STACK?
//Stack do these works with O(1) time complexity. more efficiently
//Top element removal, Add a new top element, View top element -> O(1).

///CAN'T WE ACCESS OTHER ELEMENTS THAN TOP ELEMENT?
//yes, if you use array but not when you use linked list
//Using built in STL in c++, stack, you can't.

///WHICH PROBLEMS CAN WE SOLVE USING STACK IN REAL LIFE?
//in calculator, (1+2)*3+7/2
//here, for the valuation of the expression, operator needs stack.

///LAST IN, FIRST OUT.
//the program which will enter at last, will go out first.

//Stacks are used in a variety of applications, including:
//
//a) Evaluation of Arithmetic Expressions: Stacks can be used to evaluate
//arithmetic expressions written in postfix or prefix notation. In this
//application, operands are pushed onto the stack and operators are evaluated
//using the operands from the stack.
//
//b) Reverse a Data: Stacks can be used to reverse a data, for example, a string,
//by pushing the elements onto the stack and then popping them back in reverse
//order.
//
//c) Processing Function Calls: In the implementation of a computer program,
//stacks are used to keep track of the function calls made in a program. The
//program stores information about each function call in a stack data structure,
//which is used to keep track of the return addresses when a function returns.
