/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:05:43 by bfresque          #+#    #+#             */
/*   Updated: 2023/02/11 10:59:36 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int isEmptyList(t_pile *pile)
{
	return (pile == NULL);
}

void	printList(t_pile *pile)   //fait
{
	while (pile)
	{
		ft_printf("%d\n", pile->data);
		pile = pile->next;
	}
}

t_pile *addAtList(t_pile *pile, int data, int pos)
{
	int i;
	t_pile *precedent;
	t_pile *current;
	t_pile *cell;

	precedent = pile;
	current = pile;
	cell = ft_lstnew(data);
	i = 0;
	if(isEmptyList(pile))
		return (cell);
	if(pos == 0)
	{
		cell->next = pile;
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
	return (pile);
}

int	ft_first_cell(t_pile *pile)
{
	t_pile *head = pile;
	int first_data;
	first_data = head->data;
	return (first_data);
}

// void	ft_free_at_pos(t_pile *pile, int pos)
// {
// 	t_pile	*position = pile;
// 	pile = pile->next;
// 	free(position);
// }

void	ft_put_in_pile(int ac, char **av, t_pile *pile)   //fait
{
	int i = 1;
	int j = 0;
	int cur = 0;
	while (i < ac)
	{
		cur = atoi(av[i]);
		pile->pile_a = addAtList(pile->pile_a, cur, j);
		i++;
		j++;
	}
}

void freeList(t_pile *pile)
{
	t_pile *tmp = NULL;
	while(pile)
	{
		tmp = pile->next;
		free(pile);
		pile = tmp;
	}
	printList(pile);
}

void	pb(t_pile *pile)
{
	int tmp;
	t_pile	*position = NULL;

	position = pile->pile_a;
	tmp = ft_first_cell(pile->pile_a);
	pile->pile_b = addAtList(pile->pile_b, tmp, 0);
	pile->pile_a = pile->pile_a->next;
	free(position);
}

void	pa(t_pile *pile)
{
	int tmp;
	t_pile	*position = NULL;

	position = pile->pile_b;
	tmp = ft_first_cell(pile->pile_b);
	pile->pile_a = addAtList(pile->pile_a, tmp, 0);
	pile->pile_b = pile->pile_b->next;
	free(position);
}

void	sa(t_pile *pile)
{
	t_pile *tmp = NULL;

	tmp = pile->pile_a;
	pile->pile_a = tmp->next;
	tmp->next = pile->pile_a->next;
	pile->pile_a->next = tmp;
}

void	sb(t_pile *pile)
{
	t_pile *tmp = NULL;

	tmp = pile->pile_b;
	pile->pile_b = tmp->next;
	tmp->next = pile->pile_b->next;
	pile->pile_b->next = tmp;
}


int main(int ac, char **av)
{
	t_pile pile;
	pile.pile_b = NULL;
	pile.pile_a = NULL;

	ft_put_in_pile(ac, av, &pile);

	pb(&pile);
	// sa(&pile);
	pb(&pile);
	// sb(&pile);
	pa(&pile);
	pa(&pile);
	
	printf("Pile_a a la fin\n");
	printList(pile.pile_a);
	printf("Pile_b a la fin\n");
	printList(pile.pile_b);

	freeList(pile.pile_a);
	freeList(pile.pile_b);
}
