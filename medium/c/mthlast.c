#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	struct Node *next;
	char c;
}Node;

int main(int argc, char **argv)
{
	FILE *fp;

	fp = fopen(argv[1], "r");

	while(fgetc(fp) != EOF)
	{
		Node *head = NULL;
		Node *mthlast;
		int c;
		int count = 0;
		int m;
		int ii;

		fseek(fp, -1, SEEK_CUR);

		head = NULL;

		while((c = fgetc(fp)) < '0' || c > '9')
		{
			
			Node *new = malloc(sizeof(Node));

			new->next = head;
			new->c = c;
			head = new;

			count++;

			fgetc(fp);
		}
		fseek(fp, -1, SEEK_CUR);
		fscanf(fp, "%i\n", &m);

		mthlast = head;

		if(count >= m)
		{
			for(ii = 1; ii < m; ii++)
			{
				mthlast = mthlast->next;
			}

			printf("%c\n", mthlast->c);
		}

		while(head)
		{
			Node *next = head->next;
			free(head);
			head = next;
		}

	}

	fclose(fp);

	return 0;
}