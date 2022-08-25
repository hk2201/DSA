#include <iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    int *arr;
};

/*

.first we chck if the stack is full or noe
.then first we increase the size of the stack and then add the value(p ka jo arr hai fir usme p ka jo top ka location hai waha pe woh value like we declared top -1 so -1 +1 = 0 so at o location)



*/
void push(struct stack *p, int val)
{
    if (p->top == p->size - 1)
    {
        cout << "stack Overflow" << endl;
    }
    else
    {
        p->top = p->top + 1;
        p->arr[p->top] = val;
    }

    
}

// peeking using the index of the element
// int peek(struct stack* ptr,int index){
//     if(index > ptr->size){
//         cout<<"Please enter valid number"<<endl;

//     }
//     else{
//         while(ptr->top!=index){
//             ptr->top++;
//         }
//         int val = ptr->arr[ptr->top];
//         return val;
//     }
// }

// peeking using the position of the index
int peek(struct stack *ptr, int i)
{
    int position = ptr->top - i + 1;
    if (position <= 0)
    {
        cout << "Énter Valid Position" << endl;
    }
    else
    {
        return ptr->arr[position];
    }
}

/*

.here alos we first check
.then first we store the vvalue at top positon in int val and then reduce the size of stack and return val.


*/

int pop(struct stack *p)
{
    if (p->top == -1)
    {
        cout << "Stack is Empty" << endl;

        return -1;
    }
    else
    {
        int val = p->arr[p->top];
        p->top = p->top - 1;
        return val;
    }
}

int main()
{
    // struct stack s;
    // s.size = 10;
    // s.top = -1;
    // s.arr = new int[s.size];

    struct stack *s = new stack;
    s->size = 10;
    s->top = -1;
    s->arr = new int[s->size];

    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);

    cout << "The value at particular position is " << peek(s, 2) << endl;

    // cout << "The element that is popped is " << pop(s) << endl;
    // cout << "The element that is popped is " << pop(s) << endl;

    return 0;
}