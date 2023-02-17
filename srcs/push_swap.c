/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:05:43 by bfresque          #+#    #+#             */
/*   Updated: 2023/02/17 13:15:50 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*
1- trouver mes valeurs de chunk (V)
2- verifier si il y a des nombre du chunck 1 dans a en partant du plus petit
3- chercher si il est plus facil de monter ou de descendre en calculant la mediane 

*/
int	ft_find_from_top(t_pile *pile)
{
	t_pile *tmp;
	int first_chunk;

	tmp = pile->pile_a;
	first_chunk = pile->smallest + pile->chunk_size;
	while (tmp)
	{
		if (tmp->data >= pile->smallest && tmp->data <= first_chunk)
		{
			printf("premier compris =  %ld\n", tmp->data);
			return (tmp->data);
		}
		tmp = tmp->next;
	}
	return (0);
}

// int	ft_find_from_bottom(t_pile *pile)
// {
// 	t_pile *tmp;
// 	int first_chunk;

// 	tmp = pile->pile_a;
// 	first_chunk = pile->smallest + pile->chunk_size;
// 	while (tmp)
// 	{
// 		if (tmp->data >= pile->smallest && tmp->data <= first_chunk)
// 		{
// 			printf("premier compris =  %ld\n", tmp->data);
// 			return (tmp->data);
// 		}
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }

void	ft_mediane_value(t_pile *pile)
{
	pile->mediane = ft_pile_size(pile->pile_a) / 2;
	printf("mediane  =  %d\n", pile->mediane);
}

void	chunk_value(t_pile *pile)
{
	int	diff;

	pile->smallest = ft_find_smallest(pile->pile_a);
	pile->biggest = ft_find_biggest(pile->pile_a);
	diff = pile->biggest - pile->smallest;
	pile->chunk_size = diff / 5;
	pile->left = diff - (pile->chunk_size * 5);
	
	printf("pile->smallest %d\n", pile->smallest);
	printf("pile->biggest %d\n", pile->biggest);
	printf("diff %d\n", diff);
	printf("pile->chunk_size %d\n", pile->chunk_size);
	printf("pile->left %d\n", pile->left);
}

int	ft_find_top_cell(t_pile *pile, int data)
{
	t_pile	*tmp;
	int		i;

	tmp = pile->pile_a;
	i = 0;
	while (tmp->data != data)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void print_pile_a_reverse(t_pile *pile)
{
    if (pile == NULL)
        return;
	print_pile_a_reverse(pile->next);
	printf("oooooooooooooooooooooooooooooo : %ld \n", pile->data);
}


//faire deux fonction une qui trouve le premeier contenue dans le chunk en partent du heut et lautre en partamt du bas

void	ft_less_hundred(t_pile *pile)
{
	int data_top;
	int position_top;
	// int data_bottom;
	int position_bottom;

	data_top = ft_find_from_top(pile);
	
	position_top = ft_find_top_cell(pile, data_top);
	// data_bottom = 
	//print_pile_a_reverse(pile);
	
	int	tmp;
	int		i;

	tmp = ft_last_cell_a(pile);
	printf("iiiiiiiiiiiiiiiicccccccccccciiiiiiiiiiiiiii  :  %ld\n", pile->pile_a->next->next->prev->data);
	
	ft_mediane_value(pile);
	if (pile->mediane >= position_top)
	{
		while (position_top != 0)
		{
			ft_rotate_a(pile);
			position_top = ft_find_top_cell(pile, data_top);
		}
		ft_push_a(pile);
	}
	else if (pile->mediane <= position_top)
	{
		while (position_top != 0)
		{
			ft_reverse_rotate_a(pile);
			position_top = ft_find_top_cell(pile, data_top);
		}
		ft_push_b(pile);
	}
	
}

void	ft_print_pile(t_pile *pile)
{
	while (pile)
	{
		ft_printf("%d\n", pile->data);
		pile = pile->next;
	}
}

void	printpiles(t_pile *pile) //suppri
{
	ft_printf("%s*****************%s\n", GREEN, RESET);
	printf(GREEN"Pile_A\n");
	ft_print_pile(pile->pile_a);
	printf("Pile_B\n");
	ft_print_pile(pile->pile_b);
	ft_printf("%s*****************%s\n", GREEN, RESET);
}

int	main(int ac, char **av)
{
	t_pile	pile;

	pile.pile_b = NULL;
	pile.pile_a = NULL;
	check_arg(ac, av);
	ft_put_in_pile(ac, av, &pile);
	if (ft_is_sort(&pile) == 1)
	{
		ft_printf ("\nError: Pile all-ready sort\n\n");
		ft_free_pile(pile.pile_a);
		exit(-1);
	}
	chunk_value(&pile);
	
	printpiles(&pile);
	// if (ac < 5)
	// 	ft_less_four_ac(&pile);
	// if (ac == 5)
	// 	ft_four_ac(&pile);
	// if (ac == 6)
	// 	ft_five_ac(&pile);

	ft_less_hundred(&pile);
	printpiles(&pile);
	
	ft_printf("Is sort ? = %d", ft_is_sort(&pile));
	ft_free_pile(pile.pile_a);
	ft_free_pile(pile.pile_b);
}
