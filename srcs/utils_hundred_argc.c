/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hundred_argc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:56:37 by bfresque          #+#    #+#             */
/*   Updated: 2023/03/08 17:17:03 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_minus(t_pile *pile, int position_top, int data_top)
{
	while (position_top != 0)
	{
		ft_rotate_a(pile);
		position_top = ft_find_position_cell(pile->pile_a, data_top);
	}
	if (pile->pile_b)
		push_near(pile);
	else
		ft_push_a_to_b(pile);
}

void	ft_plus(t_pile *pile, int position_bottom, int data_bottom)
{
	while (position_bottom != 0)
	{
		ft_reverse_rotate_a(pile);
		position_bottom = ft_find_position_cell(pile->pile_a, data_bottom);
	}
	if (pile->pile_b)
		push_near(pile);
	else
		ft_push_a_to_b(pile);
}

void	push_near_utils_one(t_pile *pile, int highest_in_b)
{
	while (ft_first_cell(pile->pile_b) != highest_in_b)
	{
		if (pile->mediane_b
			>= ft_find_position_cell(pile->pile_b, highest_in_b))
			ft_rotate_b(pile);
		else
			ft_reverse_rotate_b(pile);
	}
}

void	push_near_utils_two(t_pile *pile, int highest_in_b)
{
	while (ft_first_cell(pile->pile_b) != highest_in_b)
	{
		if (pile->mediane_b
			>= ft_find_position_cell(pile->pile_b, highest_in_b))
			ft_rotate_b(pile);
		else
			ft_reverse_rotate_b(pile);
	}
}
