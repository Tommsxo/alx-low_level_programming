#include "lists.h"

/**
 * free_listp2 - frees a linked list
 * @head: head of a list.
 *
 * Return: no return.
 */
void free_listp2(listp_t **head)
{
	listp_t *temp;
	listp_t *curren;

	if (head != NULL)
	{
		curren = *head;
		while ((temp = curren) != NULL)
		{
			curren = curren->next;
			free(temp);
		}
		*head = NULL;
	}
}

/**
 * free_listint_safe - frees a linked list.
 * @h: head of a list.
 *
 * Return: size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t amount_of_nodes = 0;
	listp_t *headptr, *new, *add;
	listint_t *curren;

	headptr = NULL;
	while (*h != NULL)
	{
		new = malloc(sizeof(listp_t));

		if (new == NULL)
			exit(98);

		new->p = (void *)*h;
		new->next = headptr;
		headptr = new;

		add = headptr;

		while (add->next != NULL)
		{
			add = add->next;
			if (*h == add->p)
			{
				*h = NULL;
				free_listp2(&headptr);
				return (amount_of_nodes);
			}
		}

		curren = *h;
		*h = (*h)->next;
		free(curren);
		amount_of_nodes++;
	}

	*h = NULL;
	free_listp2(&headptr);
	return (amount_of_nodes);
}
