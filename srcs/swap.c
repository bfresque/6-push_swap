/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:55:21 by bfresque          #+#    #+#             */
/*   Updated: 2023/02/20 18:01:42 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap_a(t_pile *pile)
{
	t_pile	*tmp;

	tmp = NULL;
	tmp = pile->pile_a;
	pile->pile_a = tmp->next;
	tmp->next = pile->pile_a->next;
	pile->pile_a->next = tmp;
	ft_printf("sa\n");
}

void	ft_swap_b(t_pile *pile)
{
	t_pile	*tmp;

	tmp = NULL;
	tmp = pile->pile_b;
	pile->pile_b = tmp->next;
	tmp->next = pile->pile_b->next;
	pile->pile_b->next = tmp;
	ft_printf("sb\n");
}

void	ft_ss(t_pile *pile)
{
	ft_swap_a(pile);
	ft_swap_b(pile);
}
