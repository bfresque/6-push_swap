/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:05:43 by bfresque          #+#    #+#             */
/*   Updated: 2023/02/15 15:37:20 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	printpiles(t_pile *pile)
{
	ft_printf("%s*****************%s\n", GREEN, RESET);
	printf(GREEN"Pile_A\n");
	ft_print_pile(pile->pile_a);
	printf("Pile_B\n");
	ft_print_pile(pile->pile_b);
	ft_printf("%s*****************%s\n", GREEN, RESET);
}

int ft_is_sort(t_pile *pile)
{
	t_pile *temp;
	int i ;
	int size;

	i = 0;
	temp = pile->pile_a;
	size = ft_pile_size(pile->pile_a);
	while (temp->next)
	{
		if (temp->data < temp->next->data)
			i++;
		temp = temp->next;
	}
	if (i == size - 1)
		return 1;
	else
		return 0;
}

int ft_find_smallest(t_pile *pile)
{
	int smallest = ft_first_cell(pile);
	t_pile *temp = pile->next;
	
	while (temp)
	{
		if (temp->data < smallest)
			smallest = temp->data;
		temp = temp->next;
	}
	return (smallest);
}

void ft_ac_less_five(t_pile *pile)
{
	int smallest;
	int i = 0;

	while (i != 2)
	{
		smallest = ft_find_smallest(pile->pile_a);
		if (ft_first_cell(pile->pile_a) != smallest)
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

int check_arg(int ac, char **av)
{
	int i;
	int j;
	int larg;
	char *arg;

	i = 1;
	while (i < ac)
	{
		arg = av[i];
		j = 0;
		larg = ft_strlen(arg);
		while (j < larg)
		{
			if (ft_isdigit(arg[j]) == 0 && (arg[j] != '-')
				&& (arg[j] != '"'))
			{
				ft_printf("Error : Arguments must be digit\n");
				exit(-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void check_args(int ac, char **av, int j)
{
	if (j >= ac)
	{
		return;
	}
	int i = 0;
	char *cur = av[j];

	while (i < j)
	{
		if (ft_strcmp(cur, av[i]) == 0)
		{
			ft_printf("Error : Argument ''%s'' repeats.\n", cur);
			exit(-1);
		}
		i++;
	}
	check_args(ac, av, j + 1);
}

int main(int ac, char **av)
{
	t_pile pile;
	pile.pile_b = NULL;
	pile.pile_a = NULL;

	check_arg(ac, av);
	check_args(ac, av, 1);
	ft_put_in_pile(ac, av, &pile);
	if (ft_is_sort(&pile) == 1)
	{
		ft_free_pile(pile.pile_a);
		exit(-1);
	}
	printpiles(&pile); //print
	if	(ac <= 6)
		ft_ac_less_five(&pile); //tri
	printpiles(&pile); //print

	printf("Is sort ? = %d", ft_is_sort(&pile));// verif

	ft_free_pile(pile.pile_a);
	ft_free_pile(pile.pile_b);
}

