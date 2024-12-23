/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_top_and_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:53:45 by bfresque          #+#    #+#             */
/*   Updated: 2023/03/08 17:13:29 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_find_from_top(t_pile *pile)
{
	t_pile	*tmp;

	while (pile->pile_a)
	{
		tmp = pile->pile_a;
		while (tmp)
		{
			if (tmp->data >= pile->min_chunk && tmp->data <= pile->max_chunk)
				return (tmp->data);
			tmp = tmp->next;
		}
		pile->min_chunk += pile->chunk_size;
		pile->max_chunk += pile->chunk_size;
	}
	return (0);
}

int	ft_find_from_bottom(t_pile *pile)
{
	t_pile	*tmp;

	while (pile->pile_a)
	{
		tmp = pile->pile_a;
		while (tmp->next)
			tmp = tmp->next;
		while (tmp)
		{
			if (tmp->data >= pile->min_chunk && tmp->data <= pile->max_chunk)
				return (tmp->data);
			tmp = tmp->prev;
		}
		pile->min_chunk += pile->chunk_size;
		pile->max_chunk += pile->chunk_size;
	}
	return (0);
}

int	ft_find_position_cell(t_pile *pile, int data)
{
	t_pile	*tmp;
	int		i;

	tmp = pile;
	i = 0;
	while (tmp->data != data)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
