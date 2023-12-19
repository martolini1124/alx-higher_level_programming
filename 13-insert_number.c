#include "lists.h"

/*
 * insert_node - Inserts a number into a sorted singly-linked list.
 * @head: A pointer to the head of the linked list.
 * @number: The number to insert.
 *
 * Description: This function inserts a new node with the given number
 *              into a sorted singly-linked list, maintaining the list's
 *              ascending order.
 *
 * Return: If the function fails to allocate memory for the new node - NULL.
 *         Otherwise - a pointer to the new node.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node = *head, *new;

	/* Allocate memory for the new node */
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	/* Set the value of the new node */
	new->n = number;

	/*
	 * If the list is empty or the new node should be inserted at the beginning,
	 * update the head and return the new node.
	 */
	if (node == NULL || node->n >= number)
	{
		new->next = node;
		*head = new;
		return (new);
	}

	/*
	 * Traverse the list to find the appropriate position for the new node
	 * based on the ascending order of the list.
	 */
	while (node && node->next && node->next->n < number)
		node = node->next;

	/*
	 * Insert the new node into the sorted position, updating the pointers
	 * to maintain the ascending order of the list.
	 */
	new->next = node->next;
	node->next = new;

	return (new);
}
