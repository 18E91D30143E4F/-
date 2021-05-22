#include <stdio.h>
#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY   -102

typedef int T;

typedef struct Node_tag
{
	T value;
	struct Node_tag* next;
} Node_t;


void push(Node_t** head, T value)
{
	Node_t* tmp = malloc(sizeof(Node_t));
	if (tmp == NULL)
	{
		exit(STACK_OVERFLOW);
	}
	tmp->next = *head;
	tmp->value = value;
	*head = tmp;
}


Node_t* pop1(Node_t** head)
{
	Node_t* out;
	if ((*head) == NULL)
	{
		exit(STACK_UNDERFLOW);
	}
	out = *head;
	*head = (*head)->next;
	return out;
}


void printStack(const Node_t* head)
{
	printf("stack > ");
	while (head) {
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");
}


Node_t* dltNegativeElems(Node_t* head)
{
	Node_t* temp = head;
	Node_t* prev = temp;

	while (temp)
	{
		if (temp->value < 0)
		{
			if (temp == head)
			{
				head = head->next;
				Node_t* del = temp;
				temp = temp->next;
				free(del);
				continue;
			}
			else
			{
				prev->next = temp->next;
				Node_t* del = temp;
				temp = prev;
				free(del);
			}
		}
		prev = temp;
		temp = temp->next;
	}
	return head;
}


size_t getSize(const Node_t* head)
{
	size_t size = 0;
	while (head)
	{
		size++;
		head = head->next;
	}
	return size;
}


int main()
{
	Node_t* head = NULL;
	char command = '\\';
	int value;

	puts(" 1 - Push\n 2 - Pop\n 3 - Print\n 4 - Delete negative elements\n 5 - Exit");

	while (command != '5')
	{
		scanf_s("%1c", &command);

		switch (command)
		{
		case '1':
			puts("Input value");
			scanf_s("%4d", &value);
			push(&head, value);
			break;
		case '2':
			printf("%d\n", pop1(&head));
			break;
		case '3':
			printStack(head);
			break;
		case '4':
			head = dltNegativeElems(head);
			printStack(head);
			break;

		default:
			break;
		}
	}

	puts("Press any key to continue...");
	getch();

	return 0;
}