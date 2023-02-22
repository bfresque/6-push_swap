/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_argc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:57:46 by bfresque          #+#    #+#             */
/*   Updated: 2023/02/22 16:32:33 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_find_in_b(t_pile *pile, int data)
{
	t_pile	*tmp;
	int		i;

	tmp = pile->pile_b;
	i = 0;
	while (tmp->data != data)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	find_near_less(t_pile *pile)
{
	t_pile	*tmp;
	long	template;
	long	yes;

	template = pile->pile_a->data;
	yes = 0;
	while(yes == 0)
	{
		tmp = pile->pile_b;
		template = template - 1;
		while (tmp)
		{
			if (template == tmp->data)
			{
				yes = tmp->data;
				break ;
			}
			tmp = tmp->next;
		}
	}
	while (ft_find_in_b(pile, yes) != 0)
	{
		if (pile->mediane_b >= ft_find_in_b(pile, yes))
			ft_rotate_b(pile);
		else
			ft_reverse_rotate_b(pile);
	}
}

void	push_near(t_pile *pile)
{
	int		highest_in_b;
	int		smallest_in_b;
	
	if (ft_pile_size(pile->pile_b) >= 2)
		ft_mediane_b_value(pile);
	highest_in_b = ft_find_biggest(pile->pile_b);
	smallest_in_b = ft_find_smallest(pile->pile_b);
	if (ft_first_cell(pile->pile_a) >= highest_in_b)
	{
		while (ft_first_cell(pile->pile_b) != highest_in_b)
		{
			if (pile->mediane_b >= ft_find_in_b(pile, highest_in_b))
				ft_rotate_b(pile);
			else
				ft_reverse_rotate_b(pile);
		}
	}
	else if (ft_first_cell(pile->pile_a) < smallest_in_b)
	{
		while (ft_first_cell(pile->pile_b) != highest_in_b)
		{
			if (pile->mediane_b >= ft_find_in_b(pile, highest_in_b))
				ft_rotate_b(pile);
			else
				ft_reverse_rotate_b(pile);
		}
	}
	else if (ft_first_cell(pile->pile_a) > smallest_in_b && ft_first_cell(pile->pile_a) < highest_in_b)
		find_near_less(pile);
	ft_push_a(pile);
}

void	ft_less_hundred(t_pile *pile)
{
	int	data_top;
	int	position_top;
	int	data_bottom;
	int	position_bottom;
	int	difference;

	while (pile->pile_a)
	{
		data_top = ft_find_from_top(pile);
		position_top = ft_find_top_cell(pile, data_top);
		data_bottom = ft_find_from_bottom(pile);
		position_bottom = ft_find_bottom_cell(pile, data_bottom);
		difference = pile->size - position_bottom;
		ft_mediane_value(pile);
		if (position_top <= difference)
		{
				while (position_top != 0)
				{
					ft_rotate_a(pile);
					position_top = ft_find_top_cell(pile, data_top);
				}
				if (pile->pile_b)
					push_near(pile);
				else
					ft_push_a(pile);
		}
		else if (position_top > difference)
		{
				while (position_bottom != 0)
				{
					ft_reverse_rotate_a(pile);
					position_bottom = ft_find_bottom_cell(pile, data_bottom);
				}
				if (pile->pile_b)
					push_near(pile);
				else
					ft_push_a(pile);
		}
		if (pile->pile_a->next == NULL)
			push_near(pile);
		// printpiles(pile);
	}
	while (ft_first_cell(pile->pile_b) != ft_find_biggest(pile->pile_b))
	{
		ft_rotate_b(pile);
	}
	while (pile->pile_b)
		ft_push_b(pile);
	// printpiles(pile);
}
