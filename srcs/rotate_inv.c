/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_inv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:26:27 by bfresque          #+#    #+#             */
/*   Updated: 2023/02/20 18:01:27 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_reverse_rotate_a(t_pile *pile)
{
	int	last_value;

	last_value = ft_last_cell_a(pile);
	pile->pile_a = ft_add_at_pile(pile->pile_a, last_value, 0);
	pile->pile_a = ft_delete_last_cell(pile->pile_a);
	ft_printf("rra\n");
}

void	ft_reverse_rotate_b(t_pile *pile)
{
	int	last_value;

	last_value = ft_last_cell_b(pile);
	pile->pile_b = ft_add_at_pile(pile->pile_b, last_value, 0);
	pile->pile_b = ft_delete_last_cell(pile->pile_b);
	ft_printf("rrb\n");
}

void	ft_rrr(t_pile *pile)
{
	ft_reverse_rotate_a(pile);
	ft_reverse_rotate_b(pile);
}
