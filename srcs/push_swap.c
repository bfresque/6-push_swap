/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:05:43 by bfresque          #+#    #+#             */
/*   Updated: 2023/02/21 09:41:05 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*
1- trouver mes valeurs de chunk (V)
2- verifier si il y a des nombre du chunck 1 dans a en partant du plus petit
3- chercher si il est plus facil de monter ou de descendre en calculant la mediane 

*/

// void	ft_print_pile(t_pile *pile) //suppr
// {
// 	while (pile)
// 	{
// 		ft_printf("%d\n", pile->data);
// 		pile = pile->next;
// 	}
// }

// void	printpiles(t_pile *pile) //suppr
// {
// 	if (pile->pile_a != NULL)
// 	{
// 		ft_printf("%s*****************\n", BLUE);
// 		ft_print_pile(pile->pile_a);
// 		ft_printf("%s****** a ********%s\n", BLUE, RESET);
// 	}
// 	if (pile->pile_b != NULL)
// 	{
// 	ft_printf("%s*****************\n", MAGENTA);
// 	ft_print_pile(pile->pile_b);
// 	ft_printf("%s****** b ********%s\n", MAGENTA, RESET);
// 	}
// }

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
	pile.size = ft_pile_size(pile.pile_a);
	
	ft_mediane_value(&pile);
	if (ac < 5)
		ft_less_four_ac(&pile);
	if (ac == 5)
		ft_four_ac(&pile);
	if (ac == 6)
		ft_five_ac(&pile);
	if (ac > 6)
		ft_less_hundred(&pile);
	
	// ft_printf("Is sort ? = %d", ft_is_sort(&pile));
	ft_free_pile(pile.pile_a);
	ft_free_pile(pile.pile_b);
}
