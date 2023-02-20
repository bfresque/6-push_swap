/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_argc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:57:46 by bfresque          #+#    #+#             */
/*   Updated: 2023/02/20 18:00:49 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"



void	ft_less_hundred(t_pile *pile)
{
	int data_top;
	int position_top;
	int data_bottom;
	int position_bottom;
	int difference;

	data_top = ft_find_from_top(pile);
	position_top = ft_find_top_cell(pile, data_top);
	data_bottom = ft_find_from_bottom(pile);
	position_bottom = ft_find_bottom_cell(pile, data_bottom);
	difference = pile->size - position_bottom;
	ft_mediane_value(pile);

	while (pile->pile_a)
	{
		// printpiles(pile);
		data_top = ft_find_from_top(pile);
		position_top = ft_find_top_cell(pile, data_top);
		data_bottom = ft_find_from_bottom(pile);
		position_bottom = ft_find_bottom_cell(pile, data_bottom);
		difference = pile->size - position_bottom;
		ft_mediane_value(pile);
		if (position_top <= difference)
		{
			if (pile->mediane >= position_top)
			{
				while (position_top != 0)
				{
					ft_rotate_a(pile);
					position_top = ft_find_top_cell(pile, data_top);
				}
				ft_push_a(pile);
			}
		}
		else if (position_top > difference)
		{
			if (pile->mediane <= position_bottom)
			{
				while (position_bottom != 0)
				{
					ft_reverse_rotate_a(pile);
					position_bottom = ft_find_bottom_cell(pile, data_bottom);
				}
				ft_push_a(pile);
			}
		}
		if (pile->pile_a->next == NULL)
		{
			ft_push_a(pile);
			// printpiles(pile);
			exit (0);
		}
	}
}