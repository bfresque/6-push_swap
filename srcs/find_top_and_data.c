/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_top_and_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:53:45 by bfresque          #+#    #+#             */
/*   Updated: 2023/02/20 18:00:36 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_mediane_value(t_pile *pile)
{
	pile->mediane = ft_pile_size(pile->pile_a) / 2;
	// printf("mediane  =  %d\n", pile->mediane);
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
			{
				// printf("premier compris =  %ld\n", tmp->data);
				return (tmp->data);
			}
			tmp = tmp->next;
		}
		tmp = pile->pile_a;
		pile->min_chunk = pile->min_chunk + pile->chunk_size;
		pile->max_chunk = pile->max_chunk + pile->chunk_size;
	}
	return (0);
}

int	ft_find_from_bottom(t_pile *pile)
{
	t_pile *tmp;

	tmp = pile->pile_a;
	while (tmp->next)
		tmp = tmp->next;
	
	while ((pile->min_chunk + pile->chunk_size) < pile->biggest)
	{
		while (tmp)
		{
			if (tmp->data >= pile->min_chunk && tmp->data <= pile->max_chunk)
			{
				// printf("premier compris =  %ld\n", tmp->data);
				return (tmp->data);
			}
			tmp = tmp->prev;
		}
		tmp = pile->pile_a;
		pile->min_chunk = pile->min_chunk + pile->chunk_size;
		pile->max_chunk = pile->max_chunk + pile->chunk_size;
	}
	return (0);
}

void	chunk_value(t_pile *pile)
{
	int	diff;

	pile->smallest = ft_find_smallest(pile->pile_a);
	pile->biggest = ft_find_biggest(pile->pile_a);
	diff = pile->biggest - pile->smallest;
	pile->chunk_size = diff / 5;
	pile->left = diff - (pile->chunk_size * 5);
	pile->min_chunk = pile->smallest;
	pile->max_chunk = pile->smallest + pile->chunk_size;
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
