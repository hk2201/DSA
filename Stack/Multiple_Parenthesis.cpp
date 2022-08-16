#include <iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    char *arr;
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
    if (ptr->top >= ptr->size - 1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        cout << "Stack is full" << endl;
    }
    else
    {
        ptr->top = ptr->top + 1;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top = ptr->top - 1;
        return val;
    }
}

char match(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}

int parenthesisMatch(char *exp)

{
    // char naap = sizeof(exp) / sizeof(char);
    struct stack *p = new stack;
    p->size = 100;
    p->top = -1;
    p->arr = new char[p->size];
    char popped_char;
    for (int i = 0; exp[i] != '\0'; i++) // "\0" is end of expression
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(p, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(p))
            {
                return 0;
            }
            popped_char = pop(p);
            if (!match(popped_char, exp[i]))
            {
                return 0;
            }
        }
    }
    if (isEmpty(p)) // this is boolean 1 is true
    {
        return 1;
    }
    return 0;
}

int main()
{
    char *exp = "((((((){})))";
    if (parenthesisMatch(exp))
    { // check if bool is true that is 1.
        cout << "Matchin parent" << endl;
    }
    else
    {
        cout << "Not matching" << endl;
    }

    return 0;
}
