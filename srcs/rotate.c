/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:26:20 by bfresque          #+#    #+#             */
/*   Updated: 2023/02/16 13:32:08 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rotate_a(t_pile *pile)
{
	int		first_value;
	int		last_pos;
	t_pile	*free_pile;

	first_value = ft_first_cell(pile->pile_a);
	free_pile = pile->pile_a;
	pile->pile_a = pile->pile_a->next;
	last_pos = ft_pile_size(pile->pile_a);
	pile->pile_a = ft_add_at_pile(pile->pile_a, first_value, last_pos);
	ft_printf("ra \n");
	free(free_pile);
}

void	ft_rotate_b(t_pile *pile)
{
	int		first_value;
	int		last_pos;
	t_pile	*free_pile;

	first_value = ft_first_cell(pile->pile_b);
	free_pile = pile->pile_b;
	pile->pile_b = pile->pile_b->next;
	last_pos = ft_pile_size(pile->pile_b);
	pile->pile_b = ft_add_at_pile(pile->pile_b, first_value, last_pos);
	ft_printf("rb \n");
	free(free_pile);
}

void	ft_rr(t_pile *pile)
{
	ft_rotate_a(pile);
	ft_rotate_b(pile);
}
