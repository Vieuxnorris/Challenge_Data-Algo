#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int Data;
    struct Node *Next;
}*first=NULL, *last=NULL;

void create(int A[], int n)
{
        int i;
        struct Node *t;
        first=(struct Node *)malloc(sizeof(struct Node));
        last=(struct Node *)malloc(sizeof(struct Node));
        first->Data = A[0];
        first->Next = NULL;
        last = first;

        for(i=1;i<n;i++)
        {
                t = (struct Node *)malloc(sizeof(struct Node));
                t->Data = A[i];
                t->Next = NULL;
                last->Next = t;
                last = t;
        }
}

void Finding_Middle()
{
    struct Node *p,*q;
    p = q = first;
    while(q)
    {
        q = q->Next;
        if (q) q = q->Next;
        if (q) p = p->Next;
    }
    printf("Middle Element : %d", p->Data);
}

int main()
{
    int A[] = {2,3,4,5,6};
    create(A, 5);
    Finding_Middle();
    return 0;
}