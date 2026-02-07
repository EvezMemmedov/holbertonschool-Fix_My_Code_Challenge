int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp;
	unsigned int i = 0;

	if (!head || !*head)
		return (-1);

	tmp = *head;

	/* index 0 */
	if (index == 0)
	{
		*head = tmp->next;
		if (*head)
			(*head)->prev = NULL;
		free(tmp);
		return (1);
	}

	while (tmp && i < index)
	{
		tmp = tmp->next;
		i++;
	}

	if (!tmp)
		return (-1);

	tmp->prev->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = tmp->prev;

	free(tmp);
	return (1);
}