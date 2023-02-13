/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_add_pile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:33:00 by bfresque          #+#    #+#             */
/*   Updated: 2023/02/13 13:44:56 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_pile	*ft_new_cell(int data)
{
	t_pile	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

t_pile	*ft_add_at_pile(t_pile *pile, int data, int pos)
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
	i = 0;
	while (i < pos)
	{
		i++;
		precedent = current;
		current = current->next;
	}
	precedent->next = cell;
	cell->next = current;
	return (pile);
}

void	ft_put_in_pile(int ac, char **av, t_pile *pile)
{
	int	i;
	int	j;
	int	cur;

	i = 1;
	j = 0;
	cur = 0;
	while (i < ac)
	{
		cur = atoi(av[i]);
		pile->pile_a = ft_add_at_pile(pile->pile_a, cur, j);
		i++;
		j++;
	}
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
