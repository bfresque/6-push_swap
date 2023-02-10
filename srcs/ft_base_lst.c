/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:33:00 by bfresque          #+#    #+#             */
/*   Updated: 2023/02/10 11:44:58 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int isEmptyList(t_list2 *L)
{
	return (L == NULL);
}

int getAt(t_list2 *L, int pos)
{
	int i;

	i = 0;
	if(isEmptyList(L))
	{
		ft_printf("Liste vide");
		return (-1);
	}
	while (i < pos)
	{
		i++;
		L = L->next;
	}
	return (L->data);
}

t_list2 *addAtList(t_list2 *L, int data, int pos)
{
	int i;
	t_list2 *precedent;
	t_list2 *current;
	t_list2 *cell;

	precedent = L;
	current = L;
	cell = ft_lstnew(data);
	i = 0;
	if(isEmptyList(L))
		return (cell);
	if(pos == 0)
	{
		cell->next = L;
		return (cell);
	}
	i = 0;
	while (i < pos)
	{
		i++;
		precedent = current;
		current = current->next;
	}
	precedent->next = cell;
	cell->next = current;
	return (L);
}

void printList(t_list2 *L)
{
	while (L)
	{
		ft_printf("%d\n", L->data);
		L = L->next;
	}
}

void setAt(t_list2 *L, int data, int pos)
{
	int i;

	i = 0;
	if(isEmptyList(L))
	{
		ft_printf("Liste vide");
		return ;
	}
	while(i < pos)
	{
		i++;
		L = L->next;
	}
	L->data = data;
}

t_list2 *freeList(t_list2 *L)     //ft_lstclear
{
	t_list2 *tmp = NULL;
	while(L)
	{
		tmp = L->next;
		free(L);
		L = tmp;
	}
	return (L);
}