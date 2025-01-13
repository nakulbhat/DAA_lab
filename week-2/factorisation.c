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
        while (a % i == 0)
        {
            addToList(*root, i);
            a = a / i;
            opcount++;  
        }
    }
    if (a > 2)
    {
        addToList(*root, a);
        opcount++;  
    }
    return opcount;  
}

void printList(Node *root)
{
    Node *current = root;
    while (current)
    {
        printf("%d  ", current->data);
        current = current->next;
    }
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

    printf("%d\t%d\n", a+b, opcount);
    return gcd;
}

int main(int argc, char const *argv[])
{
	int a[] = {1338, 3395, 3601, 5496, 6839, 7638, 10193, 12745, 12952, 12961, 12993, 13198, 15133, 17233, 17618, 17657, 18234, 18253, 18930, 19305};
	int b[] = {235, 330, 759, 1796, 4340, 4571, 4782, 7619, 8491, 9409, 9718, 10171, 10232, 11834, 12340, 13224, 14773, 15227, 15467, 17261};

    for (int i = 0; i < 20; ++i)
    {
        findGCD(a[i], b[i]);
    }

    return 0;
}
