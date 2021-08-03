#include <iostream>
#include <cmath>
#include <stack>

class Node{
public:
    int data;
    Node* next;
};

Node * Head = new Node;

void create(int A[], int n)
{
    Node* temp;
    Node* tail;

    Head->data = A[0];
    Head->next = NULL;
    tail = Head;

    for (int i=1; i<n;i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }
}

void middleNode1(Node* p)
{
    int length = 0;
    while(p)
    {
        length++;
        p = p->next;
    }

    int index = (int)ceil(length/2.0);
    Node* q = Head;
    for(int i=0; i<index-1; i++)
        q = q->next;
    std::cout << "Middle Element (Method-I): " << q->data << std::endl;
}

void middleNode2(Node* p)
{
    Node* q = p;
    while(q)
    {
        q = q->next;
        if (q) q = q->next;
        if (q) p = p->next;
    }
    std::cout << "Middle Element (Method-II): " << p->data << std::endl;
}

void middleNode3(Node* p)
{
    std::stack<Node*> s;
    while(p)
    {
        s.push(p);
        p = p->next;
    }
    int length = s.size();
    int poplength = (int)(floor(length/2.0));
    while (poplength)
    {
        s.pop();
        poplength--;
    }
    std::cout << "Middle Element (Method-III): " << s.top()->data << std::endl;
}

int main() {
 
    int A[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21};
    create(A, sizeof(A)/sizeof(A[0]));
 
    std::cout << std::endl;
    middleNode1(Head);
    middleNode2(Head);
    middleNode3(Head);
 
    return 0;
}