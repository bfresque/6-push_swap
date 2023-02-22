/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_top_and_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:53:45 by bfresque          #+#    #+#             */
/*   Updated: 2023/02/22 16:35:30 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_mediane_value(t_pile *pile)
{
	pile->mediane_a = ft_pile_size(pile->pile_a) / 2;
}
void	ft_mediane_b_value(t_pile *pile)
{
	pile->mediane_b = ft_pile_size(pile->pile_b) / 2;
}

int	ft_find_from_top(t_pile *pile)
{
	t_pile *tmp;

	tmp = pile->pile_a;
	while ((pile->min_chunk + pile->chunk_size) < pile->biggest)
	{
		while (tmp)
		{
			if (tmp->data >= pile->min_chunk && tmp->data <= pile->max_chunk)
				return (tmp->data);
			tmp = tmp->next;
		}
		pile->min_chunk = pile->min_chunk + pile->chunk_size;
		pile->max_chunk = pile->max_chunk + pile->chunk_size;
		tmp = pile->pile_a;

	}
	return (0);
}

int	ft_find_from_bottom(t_pile *pile)
{
	t_pile	*tmp;

	tmp = pile->pile_a;
	while (tmp->next)
		tmp = tmp->next;
	
	while ((pile->min_chunk + pile->chunk_size) < pile->biggest)
	{
		while (tmp)
		{
			if (tmp->data >= pile->min_chunk && tmp->data <= pile->max_chunk)
				return (tmp->data);
			tmp = tmp->prev;
		}
		pile->min_chunk = pile->min_chunk + pile->chunk_size;
		pile->max_chunk = pile->max_chunk + pile->chunk_size;
		tmp = pile->pile_a;
	}
	return (0);
}

void	chunk_value(t_pile *pile)
{
	pile->smallest = ft_find_smallest(pile->pile_a);
	pile->biggest = ft_find_biggest(pile->pile_a);
	pile->chunk_size = ((pile->biggest - pile->smallest) / 6);
	pile->min_chunk = pile->smallest;
	pile->max_chunk = pile->smallest + pile->chunk_size + pile->chunk_size;
}

int	ft_find_top_cell(t_pile *pile, int data)
{
	t_pile	*tmp;
	int		i;

	tmp = pile->pile_a;
	i = 0;
	while (tmp->data != data)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	ft_find_bottom_cell(t_pile *pile, int data)
{
	t_pile	*tmp;
	int		i;

	tmp = pile->pile_a;
	i = 0;
	while (tmp->data != data)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
