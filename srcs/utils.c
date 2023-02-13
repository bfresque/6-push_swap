/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:22:19 by bfresque          #+#    #+#             */
/*   Updated: 2023/02/13 14:35:46 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_pile_size(t_pile *pile)
{
	int	i;

	i = 0;
	while (pile)
	{
		pile = pile->next;
		i++;
	}
	return (i);
}

int	ft_first_cell(t_pile *pile)
{
	if (pile == NULL)
		return (0);
	return (pile->data);
}

int ft_last_cell(t_pile *pile)
{
	if (pile == NULL)
		return 0;
	while (pile->next != NULL)
	{
		pile = pile->next;
	}
	return (pile->data);
}

int	ft_is_empty_pile(t_pile *pile)
{
	return (pile == NULL);
}

void	ft_print_pile(t_pile *pile)
{
	while (pile)
	{
		ft_printf("%d\n", pile->data);
		pile = pile->next;
	}
}
