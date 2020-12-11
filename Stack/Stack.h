/*****************************************************************//**
 * \file   Stack.h
 * \brief  Header of the library allowing the management of Stack.
 * 
 * \author Vincent Eung and Ralys LALLALI
 * \date   December 2020
 *********************************************************************/

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED


/**
 * \typedef struct list_node
 * \brief A list_node is a linked list wich only contains an int and his next pointer, it's created to be used in the structure lStack.
 */
typedef struct list_node
{
    int n;/**< a value used to stock a data */
    struct list_node *succ;/**< pointer on the next element */
}list_node;
typedef list_node* List_tree;



/**stack's structure made with a linked list wich the header is the top **/
/**
 * \typedef struct lStack
 * \brief A lStack is a stack structure which contains a depth and a normal stack.
 */
typedef struct lStack
{
    List_tree top;/**< a normal stack */
    int depth;/**< the depth of the stack*/
}stack;


stack *newEmptyStack();
/**
 * \brief Function to create an empty stack.
 *      \n Example :
 *      \code{.c}
 * stack* NewStack = newEmptyStack();
 *      \endcode
 * \return a new empty stack which is ready to be used.
 */


int isEmptyStack(stack ps);
/**
 * \brief Function to check if a list is empty or not.
 *      \n Example :
 *      \code{/c}
 * int value = isEmptyStack(aRandomStack);
 *      \endcode
 *\return the state of the value \c depth in the stack.
 *\return \c 1, if the stack is empty or \c 0, if it's not.
 */

void sPush(int n, stack *ps); //stack's add
/**
 * \brief push in stack
 * \param n -> element we send to the stack
 * \param ps -> stack
 */

int sPop(stack *ps); //stack's remove
/**
 * \brief stack removal
 * \param ps -> ps
 * return n -> show element that comes out of the stack
 */


#endif // STACK_H_INCLUDED
