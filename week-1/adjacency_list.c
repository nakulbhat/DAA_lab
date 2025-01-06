#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}Node;

Node* createNode(int data){
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = data;
	return newNode;
}

void printAdjacencyList(Node** array, int N){
	for (int i = 0; i < N; ++i)
	{
		printf("%d | ", array[i]->data);
		Node* current = array[i]->next;
		while(current){
			printf("%d ", current->data);
			current = current->next;
		}
		printf("\n");
	}
}

void addToEndAdjacencyList(Node* root, int data){
	Node* current = root;
	while(current->next != NULL){
		current = current->next;
	}
	current->next = createNode(data);
}

void takeInputAdjacencyList(Node** array, int N){
		for (int i = 0; i < N; ++i){
			printf("Enter the vertices connected to vertex %d\n Enter 0 to break\n", array[i]->data);
			int connection = 1;
			while (connection!=0){
				printf("Enter vertex\n");
				scanf("%d", &connection);
				if(connection>N){
					printf("Vertex incorrect");
				}
				else{
					addToEndAdjacencyList(array[i], connection);
				}
			}
		}
}


int main(int argc, char const *argv[])
{
	int N;
	printf("Enter Number of Vertices\n");
	scanf("%d", &N);
	Node* array[N];
	for (int i = 0; i < N; ++i)
	{	
		array[i] = createNode(i+1);
	}
	takeInputAdjacencyList(array, N);	
	printAdjacencyList(array, N);
	return 0;
}