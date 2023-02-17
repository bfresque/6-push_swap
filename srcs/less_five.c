/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:22:47 by bfresque          #+#    #+#             */
/*   Updated: 2023/02/16 16:05:24 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_find_smallest(t_pile *pile)
{
	t_pile	*temp;
	int		smallest;

	temp = pile->next;
	smallest = ft_first_cell(pile);
	while (temp)
	{
		if (temp->data < smallest)
			smallest = temp->data;
		temp = temp->next;
	}
	return (smallest);
}

int	ft_find_biggest(t_pile *pile)
{
	t_pile	*temp;
	int		biggest;

	temp = pile->next;
	biggest = ft_first_cell(pile);
	while (temp)
	{
		if (temp->data > biggest)
			biggest = temp->data;
		temp = temp->next;
	}
	return (biggest);
}

void	ft_less_four_ac(t_pile *pile)
{
	if (pile->pile_a->next)
	{
		if (pile->pile_a->data > pile->pile_a->next->data)
			ft_swap_a(pile);
	}
	if (pile->pile_a->next->next)
	{
		if (pile->pile_a->data > pile->pile_a->next->next->data)
			ft_reverse_rotate_a(pile);
	}
	if (pile->pile_a->next->next)
	{
		if (pile->pile_a->next->data > pile->pile_a->next->next->data)
			ft_reverse_rotate_a(pile);
	}
	if (pile->pile_a->next)
	{
		if (pile->pile_a->data > pile->pile_a->next->data)
			ft_swap_a(pile);
	}
}

void	ft_four_ac(t_pile *pile)
{
	int	i;

	i = 0;
	while (i == 0)
	{
		pile->smallest = ft_find_smallest(pile->pile_a);
		if (ft_first_cell(pile->pile_a) != pile->smallest)
			ft_reverse_rotate_a(pile);
		else
		{
			ft_push_a(pile);
			i++;
		}
	}
	if (pile->pile_a->data > pile->pile_a->next->data)
		ft_swap_a(pile);
	if (pile->pile_a->data > pile->pile_a->next->next->data)
		ft_reverse_rotate_a(pile);
	if (pile->pile_a->next->data > pile->pile_a->next->next->data)
		ft_reverse_rotate_a(pile);
	if (pile->pile_a->data > pile->pile_a->next->data)
		ft_swap_a(pile);
	while (pile->pile_b)
		ft_push_b(pile);
}

void	ft_five_ac(t_pile *pile)
{
	int	i;

	i = 0;
	while (i != 2)
	{
		pile->smallest = ft_find_smallest(pile->pile_a);
		if (ft_first_cell(pile->pile_a) != pile->smallest)
			ft_reverse_rotate_a(pile);
		else
		{
			ft_push_a(pile);
			i++;
		}
	}
	if (pile->pile_a->data > pile->pile_a->next->data)
		ft_swap_a(pile);
	if (pile->pile_a->data > pile->pile_a->next->next->data)
		ft_reverse_rotate_a(pile);
	if (pile->pile_a->next->data > pile->pile_a->next->next->data)
		ft_reverse_rotate_a(pile);
	if (pile->pile_a->data > pile->pile_a->next->data)
		ft_swap_a(pile);
	while (pile->pile_b)
		ft_push_b(pile);
}
