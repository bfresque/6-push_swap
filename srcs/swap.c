/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:55:21 by bfresque          #+#    #+#             */
/*   Updated: 2023/02/10 15:00:42 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list2	*swap_a(t_list2 *L)
{
	t_list2 *tmp = NULL;

	tmp = L->next;
	L->next = tmp->next;
	tmp->next = L;

	return (tmp);
}

t_list2	*ft_first_cell(t_list2 *pile)
{
	t_list2 *head = pile;
	int first_data;

	first_data = head->data;

	return (first_data);
}

t_list2	*ft_free_at_pos(t_list2 *list, int pos)
{
	t_list2	*position = list;
	list = list->next;
	free(position);
	return (list);
}

t_list2	*ft_push_a_to_b(t_list2 *pile_a, t_list2 *pile_b)
{
	int tmp = ft_first_cell(pile_a);
	pile_b = addAtList(pile_a, tmp, 0);
	pile_a = ft_free_at_pos(pile_a, 0);
}

// t_list2	*ft_push_a_to_b(t_list2 *origin, t_list2 *destination)
// {
// 	int tmp = ft_first_cell(origin);
// 	destination = addAtList(destination, tmp, 0);
// 	return(destination);
// }