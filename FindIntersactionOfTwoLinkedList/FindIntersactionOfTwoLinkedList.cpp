#include <iostream>
#include <cmath>
#include <stack>

class Node {
public:
    int data;
    Node* next;
};

Node *head = new Node;
Node *second = new Node;

void create(int A[], int n)
{
    Node* temp;
    Node* tail;

    head->data = A[0];
    head->next = NULL;
    tail = head;

    for (int i=1; i<n; i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }
}

void createSecond(int A[], int n, Node* p)
{
    Node* temp;
    Node* tail;

    second->data = A[0];
    second->next = NULL;
    tail = second;

    for (int i=1; i<n; i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }
    tail->next = p;
}

void intersection(Node* p, Node* q)
{
    std::stack<Node*> stk1;
    while(p != NULL)
    {
        stk1.push(p);
        p = p->next;
    }
    std::stack<Node*> stk2;
    while(q != NULL)
    {
        stk2.push(q);
        q = q->next;
    }

    Node* r;
    while(stk1.top() == stk2.top())
    {
        std::cout << "top1 : " << stk1.top() << " top2 : " << stk2.top() << std::endl;
        r = stk1.top();
        stk1.pop();
        stk2.pop();
    }
    std::cout << "Intersecting Node: " << r->data << std::endl;
}

int main()
{
    int A[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    create(A, sizeof(A)/sizeof(A[0]));

    Node* temp = head;
    int i = 5;
    while (i>0)
    {
        temp = temp->next;
        i--;
    }
    std::cout << temp->data << std::endl;

    int B[] = {2, 4, 6, 8, 10};
    createSecond(B, sizeof(B)/sizeof(B[0]), temp);

    intersection(head,second);

    return 0;
}