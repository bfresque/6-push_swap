/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_add_pile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:33:00 by bfresque          #+#    #+#             */
/*   Updated: 2023/02/16 16:00:50 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_pile	*ft_new_cell(long data)
{
	t_pile	*new;

	new = malloc(sizeof(t_pile));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

t_pile	*ft_add_at_pile(t_pile *pile, long data, int pos)
{
	int		i;
	t_pile	*precedent;
	t_pile	*current;
	t_pile	*cell;

	i = 0;
	precedent = pile;
	current = pile;
	cell = ft_new_cell(data);
	if (ft_is_empty_pile(pile))
		return (cell);
	if (pos == 0)
	{
		cell->next = pile;
		return (cell);
	}
	while (i < pos)
	{
		precedent = current;
		current = current->next;
		i++;
	}
	precedent->next = cell;
	cell->next = current;
	return (pile);
}

void	ft_put_in_pile(int ac, char **av, t_pile *pile)
{
	int		i;
	int		j;
	long	cur;

	i = 1;
	j = 0;
	cur = 0;
	while (i < ac)
	{
		cur = ft_atoi(av[i]);
		pile->pile_a = ft_add_at_pile(pile->pile_a, cur, j);
		i++;
		j++;
	}
	check_int(pile);
}

void	ft_free_pile(t_pile *pile)
{
	t_pile	*tmp;

	tmp = NULL;
	while (pile)
	{
		tmp = pile->next;
		free(pile);
		pile = tmp;
	}
	ft_print_pile(pile);
}

t_pile	*ft_delete_last_cell(t_pile *pile)
{
	t_pile	*prev;
	t_pile	*curr;

	if (ft_is_empty_pile(pile))
		return (NULL);
	if (pile->next == NULL)
	{
		free(pile);
		return (NULL);
	}
	prev = NULL;
	curr = pile;
	while (curr->next != NULL)
	{
		prev = curr;
		curr = curr->next;
	}
	free(curr);
	prev->next = NULL;
	return (pile);
}
