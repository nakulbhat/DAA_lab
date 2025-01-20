#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	struct node *left;
	struct node *right;
	int data;
} Node;

void inorder(Node *root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}
void postorder(Node *root)
{
	if (root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->data);
}
void preorder(Node *root)
{
	if (root == NULL)
		return;
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}
Node *createNode(int data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	return newNode;
}

Node *insert(int data, Node *root)
{
	printf("Inserting %d\n", data);
	Node *newNode = createNode(data);
	if (root == NULL)
	{
		return newNode;
	}
	Node *current = root;
	Node *parent = root;
	while (current != NULL)
	{
		parent = current;
		if (data == parent->data)
		{
			printf("Duplicate found (%d)\n", data);
			return root;
		}
		if (data < parent->data)
		{
			current = current->left;
		}
		if (data > parent->data)
		{
			current = current->right;
		}
	}
	if (data < parent->data)
	{
		parent->left = newNode;
		return root;
	}
	else
	{
		parent->right = newNode;
		return root;
	}
}

int main(int argc, char const *argv[])
{
	Node *root = insert(5, NULL);
	insert(12, root);
	insert(14, root);
	insert(14, root);
	insert(15, root);
	insert(3, root);
	printf("\n*****Inorder*****\n");
	inorder(root);
	printf("\n*****Preorder*****\n");
	preorder(root);
	printf("\n*****Postorder*****\n");
	postorder(root);
	return 0;
}