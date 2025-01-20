#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addToList(Node *root, int data)
{
    Node *current = root;
    while (current->next)
    {
        current = current->next;
    }
    current->next = createNode(data);
}

int findFactors(int a, Node **root)
{
    int opcount = 0;
    *root = createNode(0);
    while (a % 2 == 0)
    {
        addToList(*root, 2);
        a = a / 2;
        opcount++;
    }
    for (int i = 3; i * i <= a; i += 2)
    {
        opcount++;
        while (a % i == 0)
        {
            addToList(*root, i);
            a = a / i;
        }
    }
    if (a > 2)
    {
        addToList(*root, a);
        opcount++;
    }
    return opcount;
}

int findGCD(int a, int b)
{
    Node *roota = NULL, *rootb = NULL;
    int opcount = 0;

    opcount += findFactors(a, &roota);
    opcount += findFactors(b, &rootb);

    Node *currenta = roota->next;
    Node *currentb = rootb->next;
    int gcd = 1;

    while (currenta && currentb)
    {
        opcount++;
        if (currenta->data == currentb->data)
        {
            gcd *= currenta->data;
            currenta = currenta->next;
            currentb = currentb->next;
        }
        else if (currenta->data < currentb->data)
        {
            currenta = currenta->next;
        }
        else
        {
            currentb = currentb->next;
        }
    }

    printf("%d\t%d\n", a + b, opcount);
    return gcd;
}

int main(int argc, char const *argv[])
{
    int a[20], b[20];

    // Generate arrays programmatically
    for (int i = 0; i < 20; ++i)
    {
        a[i] = 1000 + (i * i * 3); // Example formula for array 'a'
        b[i] = 200 + (i * 165);    // Example formula for array 'b'
    }

    for (int i = 0; i < 20; ++i)
    {
        findGCD(a[i], b[i]);
    }

    return 0;
}
