/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:03:01 by bfresque          #+#    #+#             */
/*   Updated: 2023/02/23 16:45:50 by bfresque         ###   ########.fr       */
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

// void	chunk_value(t_pile *pile)
// {
// 	int	chunk;

// 	pile->smallest = ft_find_smallest(pile->pile_a);
// 	pile->biggest = ft_find_biggest(pile->pile_a);
// 	printf("size : %d\n", pile->size);
// 	if (pile->size <= 10)
// 		chunk = 2;
// 	else if (pile->size <= 150)
// 		chunk = 4;
// 	else
// 		chunk = 10;
// 	printf("chunk : %d\n", chunk);
	
// 	pile->chunk_size = ((pile->biggest - pile->biggest) / 4);
// 	printf("pile->chunk_size : %d\n", pile->chunk_size);
// 	pile->min_chunk = pile->smallest;
// 	pile->max_chunk = pile->smallest + pile->chunk_size;
// }

void	chunk_value(t_pile *pile)
{
	int chunk;

	chunk = 0;
	pile->smallest = ft_find_smallest(pile->pile_a);
	pile->biggest = ft_find_biggest(pile->pile_a);
	// printf("size : %d\n", pile->size);
	if (pile->size <= 10)
		chunk = 2;
	else if (pile->size <= 150)
		chunk = 4;
	else
		chunk = 10;
	// printf("chunk : %d\n", chunk);
	pile->chunk_size = (pile->size / chunk);
	// printf("pile->chunk_size : %d\n", pile->chunk_size);
	pile->min_chunk = pile->smallest;
	pile->max_chunk = pile->smallest + pile->chunk_size;
}

// void	chunk_value(t_pile *pile)
// {
// 	pile->smallest = ft_find_smallest(pile->pile_a);
// 	pile->biggest = ft_find_biggest(pile->pile_a);
// 	pile->chunk_size = ((pile->biggest - pile->smallest) / 4);
// 	pile->min_chunk = pile->smallest;
// 	pile->max_chunk = pile->smallest + pile->chunk_size + pile->chunk_size;
// }
