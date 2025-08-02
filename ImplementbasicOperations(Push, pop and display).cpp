/*
Implement basic Operations(Push(), pop() and display()) of stack using linked list.

Input Format

Input describe the choices and values for different operations.
1 for Push the element(value must be given with this choice to insert)
2 for Pop the topmost element
3 for Display the contents of stack, starting from topmost element.
0 for exit (0 must be given at end of the input)
Constraints

-

Output Format

Display the contents of stack, starting from topmost element.
While trying to pop the element when stack is empty, message "underflow" must be printed.
Sample Input 0

1
15
1
60
1
25
3
0
Sample Output 0

25 60 15
Sample Input 1

1
45
3
2
2
0
Sample Output 1

45
underflow
Sample Input 2

1
45
1
46
1
89
3
2
2
3
1
49
2
3
0
Sample Output 2

89 46 45
45
45
*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *top = NULL;

void push(int x)
{
    Node *newNode = new Node();
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

void pop()
{
    if (top == nullptr)
    {
        cout << "underflow" << endl;
    }
    else
    {
        Node *temp = top;
        top = top->next;
        delete temp;
    }
}

void display()
{
    Node *temp = top;
    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
        if (temp != NULL)
            cout << " ";
    }
    if (top != NULL)
        cout << endl;
}

int main()
{
    int choice, value;
    while (cin >> choice)
    {
        if (choice == 0)
            break;
        switch (choice)
        {
            case 1:
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
        }
    }
    return 0;
}

