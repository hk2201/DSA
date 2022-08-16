#include <iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    char *exp;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

int stackTop(struct stack *ptr)
{
    return ptr->exp[ptr->top];
}

struct stack *push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        cout << "Stack is full";
    }
    else
    {
        ptr->top = ptr->top + 1;
        ptr->exp[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack is Empty";
    }
    else
    {
        int val = ptr->exp[ptr->top];
        ptr->top = ptr->top - 1;
        return val;
    }
}

int isoperator(char exp)
{
    if (exp == '*' || exp == '/' || exp == '+' || exp == '-')
    {
        return 1;
    }
    return 0;
}

int precedence(char exp)
{
    if (exp == '*' || exp == '/')
    {
        return 3;
    }
    else if (exp == '+' || exp == '-')
    {
        return 2;
    }
    return 0;
}

char *infixTopostfix(char *infix)
{
    int lenth = sizeof(infix) / sizeof(char);
    struct stack *sp = new stack;
    sp->size = 100;
    sp->top = -1;
    sp->exp = new char[sp->size];    // here we'll be adding the operators
    char *postfix = new char[lenth]; // here we'll be adding whole exp
    int i = 0;                       // for keeping the count of infix
    int j = 0;                       // for tracking postfix exp
    while (infix[i] != '\0')         // we'll continue this loop till the end of exp.
    {
        if (!isoperator(infix[i])) // agar operator nhi hai toh postfix me infix ka element dal denge
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            // prec jyada hai toh push in stack or pop and add in postfix.
            if (precedence(infix[i]) > precedence(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    // finalyy remaining operator in stack will be put in postfix
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    // We do this because the last element should be NUll or else while printing without adding this well get garbage values.
    return postfix;
}

int main()
{
    char *infix = "x-y/z-k*d";
    cout << "The postfix to infix is " << infixTopostfix(infix);

    return 0;
}