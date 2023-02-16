/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:22:19 by bfresque          #+#    #+#             */
/*   Updated: 2023/02/16 12:29:11 by bfresque         ###   ########.fr       */
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

long	ft_first_cell(t_pile *pile)
{
	if (pile == NULL)
		return (0);
	return (pile->data);
}

long	ft_last_cell_a(t_pile *pile)
{
	t_pile	*temp;

	temp = pile->pile_a;
	if (temp == NULL)
		return (0);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp->data);
}

long	ft_last_cell_b(t_pile *pile)
{
	t_pile	*temp;

	temp = pile->pile_b;
	if (temp == NULL)
		return (0);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp->data);
}

int	ft_is_empty_pile(t_pile *pile)
{
	return (pile == NULL);
}
