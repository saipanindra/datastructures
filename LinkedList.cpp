// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


typedef struct IntElement {
	struct IntElement *next;
	int data;
} IntElement;

bool deleteElement(IntElement **head, int data)
{
	IntElement *nextElement;
	if ((*head)->data == data)
	{
		nextElement = (*head)->next;
		delete (*head);
		(*head) = nextElement;
		return true;
	}
	nextElement = (*head)->next;
	IntElement *currentElement = *head;
	while (nextElement && nextElement->data != data)
	{
		currentElement = nextElement;
		nextElement = nextElement->next;
	}
	if (!nextElement) return false;
	currentElement->next = nextElement->next;
	delete nextElement;
	return true;
}
bool insertInFront(IntElement **head, int data)
{
	if (!*head)
	{
		*head = new IntElement;
		(*head)->data = data;
		(*head)->next = NULL;
		return true;
	}
	IntElement *newElement = new IntElement;
	if (!newElement) return false;
	newElement->next = *head;
	newElement->data = data;
	*head = newElement;
	return true;
}

IntElement* find(IntElement *head, int data)
{
	IntElement *iter = head;
	while (iter)
	{
		if (iter->data == data) return iter;
		iter = iter->next;
	}
	return NULL;
}

void print(IntElement *head)
{
	if (!head) return;
	IntElement *iter = head;
	while (iter)
	{
		printf("%d ", iter->data);
		iter = iter->next;
	}
	printf("\n");
}


int _tmain(int argc, _TCHAR* argv[])
{
	IntElement *list = NULL;
	while (true)
	{
		int data;
		int choice;
		printf("1: Insert element in list\n2: Find element in list\n3: Print list\n4: Delete element\n5:Exit\n");
		scanf_s("%d", &choice);
		if (choice >= 5 || choice < 1) break;
		if (choice == 1)
		{
			printf("Enter the data to be inserted\n"); scanf_s("%d", &data);
			insertInFront(&list, data);
		}
		if (choice == 2)
		{
			printf("Enter the data to be searched\n"); scanf_s("%d", &data);
			IntElement *foundElement = find(list, data);
			if (foundElement)
				printf("Element %d found in the list", foundElement->data);
			else
				printf("Element %d not found in the list", data);
		}
		if (choice == 3)
		{
			print(list);
		}
		if (choice == 4)
		{
			printf("Enter element to be deleted\n");
			scanf_s("%d", &data);
			if (deleteElement(&list, data))
				printf("Element %d is deleted from the list\n", data);
			else
				printf("Element %d is not found in the list\n", data);
		}

	}
	getchar();
}






