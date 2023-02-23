/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:25:35 by bfresque          #+#    #+#             */
/*   Updated: 2023/02/23 10:27:50 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_a_to_b(t_pile *pile)
{
	int		tmp;
	t_pile	*position;

	position = NULL;
	position = pile->pile_a;
	tmp = ft_first_cell(pile->pile_a);
	pile->pile_b = ft_add_at_pile(pile->pile_b, tmp, 0);
	pile->pile_a = pile->pile_a->next;
	ft_printf("pb\n");
	free(position);
}

void	ft_push_b_to_a(t_pile *pile)
{
	int		tmp;
	t_pile	*position;

	position = NULL;
	position = pile->pile_b;
	tmp = ft_first_cell(pile->pile_b);
	pile->pile_a = ft_add_at_pile(pile->pile_a, tmp, 0);
	pile->pile_b = pile->pile_b->next;
	ft_printf("pa\n");
	free(position);
}
