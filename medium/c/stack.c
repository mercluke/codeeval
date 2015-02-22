#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	struct Node *next;
	int val;
}Node;

typedef struct{
	Node *head;
	int count;
}List;

List* newList(void);
Node* newNode(void);
Node* newNode_v(int val);
void freeList(List *theList);
void push(List *theList, int val);
int pop(List *theList);

int main(int argc, char** argv)
{
	List *list;
	FILE *fp;
	int c;

	fp = fopen(argv[1], "r");

	while((c = fgetc(fp)) != EOF)
	{
		int odd = 1;

		fseek(fp, -1, SEEK_CUR);

		list = newList();

		while((c = fgetc(fp)) != EOF && c != '\n')
		{

			int val;

			fseek(fp, -1, SEEK_CUR);
			fscanf(fp, "%i", &val);
			push(list, val);
		}

		while(list->head)
		{
			int val = pop(list);
			if(odd)
			{
				printf("%i ", val);
			}
			odd = 1 - odd;
		}
		putchar('\n');
		freeList(list);
	}

	fclose(fp);

	return 0;
}

List* newList(void)
{
	List *ret;

	ret = malloc(sizeof(List));
	ret->head = NULL;
	ret->count = 0;

	return ret;
}

Node* newNode(void)
{
	Node *ret;

	ret = malloc(sizeof(Node));
	ret->next = NULL;

	return ret;
}

Node* newNode_v(int val)
{
	Node *ret;

	ret = newNode();
	ret->val = val;

	return ret;
}

void freeList(List *theList)
{
	Node *next, *curr = theList->head;

	while(curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}

	free(theList);
}

void push(List *theList, int val)
{
	Node *new = newNode_v(val);
	new->next = theList->head;
	theList->head = new;
}

int pop(List *theList)
{
	int ret = theList->head->val;
	Node *newHead = theList->head->next;

	free(theList->head);
	theList->head = newHead;

	return ret;
}
