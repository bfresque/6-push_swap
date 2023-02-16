/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:05:43 by bfresque          #+#    #+#             */
/*   Updated: 2023/02/16 12:30:17 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_pile(t_pile *pile)
{
	while (pile)
	{
		ft_printf("%d\n", pile->data);
		pile = pile->next;
	}
}

void	printpiles(t_pile *pile)
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
	printf("%d", ft_last_cell_a(&pile));
	printpiles(&pile);
	if (ac < 5)
		ft_less_four_ac(&pile);
	if (ac == 5)
		ft_four_ac(&pile);
	if (ac == 6)
		ft_five_ac(&pile);
	printpiles(&pile);
	printf("Is sort ? = %d", ft_is_sort(&pile));
	ft_free_pile(pile.pile_a);
	ft_free_pile(pile.pile_b);
}
