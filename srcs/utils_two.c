/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:03:01 by bfresque          #+#    #+#             */
/*   Updated: 2023/03/08 17:17:37 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_mediane_value(t_pile *pile)
{
	if (ft_pile_size(pile->pile_a) >= 2)
		pile->mediane_a = ft_pile_size(pile->pile_a) / 2;
	else
		pile->mediane_a = 0;
}

void	ft_mediane_b_value(t_pile *pile)
{
	if (ft_pile_size(pile->pile_b) >= 2)
		pile->mediane_b = ft_pile_size(pile->pile_b) / 2;
	else
		pile->mediane_a = 0;
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
}

void	chunk_value(t_pile *pile)
{
	int	chunk;

	chunk = 0;
	pile->smallest = ft_find_smallest(pile->pile_a);
	pile->biggest = ft_find_biggest(pile->pile_a);
	if (pile->size <= 10)
		chunk = 2;
	else if (pile->size <= 150)
		chunk = 4;
	else
		chunk = 10;
	pile->chunk_size = (pile->size / chunk);
	pile->min_chunk = pile->smallest;
	pile->max_chunk = pile->min_chunk + pile->chunk_size;
}
