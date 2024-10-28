/*

 Task 1. Design and implement your stack data structure.
 ● Implement a stack data structure with the following operations 
   (1) CREATE(S), (2) PUSH(S, elem),
   (3) elem = POP(S),(4)elem = TOP(S),(5)ISFULL(S)and(6)ISEMPTY(S).
 ● VERY IMPORTANT: Implement as an additional stack operation elem = NEXT-TO-TOP(S) 
   which will return the element below the top element. For example: create a stack S. Then push 10, then push 20, 
   and then push 30. TOP(S) will return 30. NEXT-TO-TOP(S) will return 20.
 ● You have to decide on your own if you would like to represent the stack using an array or a linked list.
 ● STRICTREQUIREMENT#3 : make sure that your stack can store up to a maximum of n = 2^15 =32768 elements.
 ● Practice modular programming. That is, compartmentalize the data structures and operations by storing the
   implementation codes in separate source code files. For example, the codes for stack data structure are stored
   in the source files stack.h and stack.c

*/

#include <stdio.h>
#include <stdlib.h>


#define MAX 32768 // maximum number of elements in the stack


typedef struct {
    double x;
    double y;
} Point;


typedef struct Stack {
    int top;
    Point points [MAX];
} Stack;


// Function to create a Stack
void CREATE(Stack *S){
    S -> top = -1;
}


// Function to check if the stack is full
int ISFULL(Stack *S){
    return S -> top == MAX - 1;
}


// Function to check if the stack is empty
int ISEMPTY(Stack *S){
    return S -> top == -1;
}


// Function to push a point onto the stack
void PUSH(Stack *S, double x, double y){
    if (ISFULL(S)) {
        printf("Error: Overflow. Stack is already full!\n");
    }
    else {
        S -> top++;
        S -> points [S -> top].x = x;
        S -> points [S -> top].y = y;
    }
}


// Function to pop a point from the stack
Point POP(Stack *S){
    Point empty = {.x = -9999, .y = -9999};

    if (ISEMPTY(S)) {
        printf("Error: Underflow. Stack is empty!\n");
        return empty;
    }
    else {
        return S -> points [S -> top--];
    }
}


// Function to get the top point of the stack
Point TOP(Stack *S){
    Point empty = {.x = -9999, .y = -9999};

    if (ISEMPTY(S)) {
        printf("Error: Underflow. Stack is empty!\n");
        return empty;
    }
    else {
        return S -> points [S -> top];
    }
}


// Function to get the next-to-top point of the stack 
Point NEXT_TO_TOP(Stack *S){
    Point empty = {.x = -9999, .y = -9999};

    if (S -> top < 1) {
        printf("Error: Stack doesn't have enough elements!\n");
        return empty;
    }
    else {
        return S -> points [S -> top - 1];
    }
}

/*
void testStackFunctions() {
    Stack stack;
    CREATE(&stack);

    printf("Testing PUSH function:\n");
    PUSH(&stack, 1.0, 2.0);   // Push (1.0, 2.0)
    PUSH(&stack, 3.0, 4.0);   // Push (3.0, 4.0)
    PUSH(&stack, -5.0, -6.0);  // Push (-5.0, -6.0)
    
    // Display the current stack
    printf("Current Stack Top after pushes: (%.2f, %.2f)\n", TOP(&stack).x, TOP(&stack).y);

    printf("\nTesting POP function:\n");
    Point poppedPoint = POP(&stack);
    printf("Popped point: (%.2f, %.2f)\n", poppedPoint.x, poppedPoint.y); // Should be (-5.0, -6.0)

    printf("\nTesting NEXT_TO_TOP function:\n");
    Point nextToTopPoint = NEXT_TO_TOP(&stack);
    printf("Next to top point: (%.2f, %.2f)\n", nextToTopPoint.x, nextToTopPoint.y); // Should be (3.0, 4.0)

    // Pop remaining points
    printf("\nPopping remaining points:\n");
    poppedPoint = POP(&stack); // Should remove (3.0, 4.0)
    printf("Popped point: (%.2f, %.2f)\n", poppedPoint.x, poppedPoint.y);
    
    poppedPoint = POP(&stack); // Should remove (1.0, 2.0)
    printf("Popped point: (%.2f, %.2f)\n", poppedPoint.x, poppedPoint.y);

    // Attempt to pop from an empty stack
    printf("\nAttempting to pop from an empty stack:\n");
    poppedPoint = POP(&stack); // Should trigger underflow message

    printf("\nTesting TOP function on empty stack:\n");
    Point topPoint = TOP(&stack); // Should trigger underflow message

    printf("\nTesting NEXT_TO_TOP function on empty stack:\n");
    Point nextToTopPointEmpty = NEXT_TO_TOP(&stack); // Should trigger error for not enough elements
}

int main() {
    
    testStackFunctions();

    return 0;
}
*/