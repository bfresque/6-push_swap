/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_argc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:57:46 by bfresque          #+#    #+#             */
/*   Updated: 2023/03/08 17:17:58 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_near_less(t_pile *pile)
{
	t_pile	*tmp;
	long	template;
	long	yes;

	template = pile->pile_a->data;
	yes = -2147483648;
	while (yes == -2147483648)
	{
		tmp = pile->pile_b;
		template = template - 1;
		while (tmp)
		{
			if (template == tmp->data)
				yes = tmp->data;
			tmp = tmp->next;
		}
	}
	while (ft_find_position_cell(pile->pile_b, yes) != 0)
	{
		if (pile->mediane_b >= ft_find_position_cell(pile->pile_b, yes))
			ft_rotate_b(pile);
		else
			ft_reverse_rotate_b(pile);
	}
}

void	push_near(t_pile *pile)
{
	int	highest_in_b;
	int	smallest_in_b;

	ft_mediane_b_value(pile);
	highest_in_b = ft_find_biggest(pile->pile_b);
	smallest_in_b = ft_find_smallest(pile->pile_b);
	if (ft_first_cell(pile->pile_a) > highest_in_b)
		push_near_utils_one(pile, highest_in_b);
	else if (ft_first_cell(pile->pile_a) < smallest_in_b)
		push_near_utils_two(pile, highest_in_b);
	else if (ft_first_cell(pile->pile_a) > smallest_in_b
		&& ft_first_cell(pile->pile_a) < highest_in_b)
		find_near_less(pile);
	ft_push_a_to_b(pile);
}

void	ft_for_hundred(t_pile *pile)
{
	int	data_top;
	int	position_top;
	int	data_bottom;
	int	position_bottom;
	int	difference;

	while (pile->pile_a)
	{
		data_top = ft_find_from_top(pile);
		position_top = ft_find_position_cell(pile->pile_a, data_top);
		data_bottom = ft_find_from_bottom(pile);
		position_bottom = ft_find_position_cell(pile->pile_a, data_bottom);
		difference = pile->size - position_bottom;
		ft_mediane_value(pile);
		if (position_top <= difference)
			ft_minus(pile, position_top, data_top);
		else if (position_top > difference)
			ft_plus(pile, position_bottom, data_bottom);
		if (pile->pile_a->next == NULL)
			push_near(pile);
	}
	while (ft_first_cell(pile->pile_b) != ft_find_biggest(pile->pile_b))
		ft_reverse_rotate_b(pile);
	while (pile->pile_b)
		ft_push_b_to_a(pile);
}
