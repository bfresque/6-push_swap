/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:05:43 by bfresque          #+#    #+#             */
/*   Updated: 2023/02/13 15:14:47 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int ac, char **av)
{
	t_pile pile;
	pile.pile_b = NULL;
	pile.pile_a = NULL;

	ft_put_in_pile(ac, av, &pile);


	
	ft_reverse_rotate_a(&pile);
	printf(CYAN"Pile_A\n");
	ft_print_pile(pile.pile_a);
	printf("Pile_B\n");
	ft_print_pile(pile.pile_b);

	ft_push_a(&pile);
	ft_printf("%s***PUSH A TO B***%s\n", RED, RESET);
	printf(RED"Pile_A\n");
	ft_print_pile(pile.pile_a);
	printf("Pile_B\n");
	ft_print_pile(pile.pile_b);
	ft_printf("%s*****************%s\n", RED, RESET);

		ft_push_a(&pile);
	ft_printf("%s***PUSH A TO B***%s\n", RED, RESET);
	printf(RED"Pile_A\n");
	ft_print_pile(pile.pile_a);
	printf("Pile_B\n");
	ft_print_pile(pile.pile_b);
	ft_printf("%s*****************%s\n", RED, RESET);


		ft_push_a(&pile);
	ft_printf("%s***PUSH A TO B***%s\n", RED, RESET);
	printf(RED"Pile_A\n");
	ft_print_pile(pile.pile_a);
	printf("Pile_B\n");
	ft_print_pile(pile.pile_b);
	ft_printf("%s*****************%s\n", RED, RESET);
	
		ft_push_a(&pile);
	ft_printf("%s***PUSH A TO B***%s\n", RED, RESET);
	printf(RED"Pile_A\n");
	ft_print_pile(pile.pile_a);
	printf("Pile_B\n");
	ft_print_pile(pile.pile_b);
	ft_printf("%s*****************%s\n", RED, RESET);

	ft_reverse_rotate_b(&pile);
	printf(CYAN"Pile_A\n");
	ft_print_pile(pile.pile_a);
	printf("Pile_B\n");
	ft_print_pile(pile.pile_b);

	// ft_rotate_b(&pile);
	// ft_printf("%s******ROTATE_B******%s\n", CYAN, RESET);
	// printf(CYAN"Pile_A\n");
	// ft_print_pile(pile.pile_a);
	// printf("Pile_B\n");
	// ft_print_pile(pile.pile_b);
	// ft_printf("%s*****************%s\n", CYAN, RESET);

	
	// ft_swap_a(&pile);
	// ft_printf("%s******SWAP_A******%s\n", GREEN, RESET);
	// printf(GREEN"Pile_A\n");
	// ft_print_pile(pile.pile_a);
	// printf("Pile_B\n");
	// ft_print_pile(pile.pile_b);
	// ft_printf("%s*****************%s\n", GREEN, RESET);


	// ft_rotate_a(&pile);
	// ft_printf("%s******ROTATE_A******%s\n", CYAN, RESET);
	// printf(CYAN"Pile_A\n");
	// ft_print_pile(pile.pile_a);
	// printf("Pile_B\n");
	// ft_print_pile(pile.pile_b);
	// ft_printf("%s*****************%s\n", CYAN, RESET);

	// ft_push_a(&pile);
	// ft_printf("%s***PUSH A TO B***%s\n", RED, RESET);
	// printf(RED"Pile_A\n");
	// ft_print_pile(pile.pile_a);
	// printf("Pile_B\n");
	// ft_print_pile(pile.pile_b);
	// ft_printf("%s*****************%s\n", RED, RESET);

	// ft_swap_b(&pile);
	// ft_printf("%s******SWAP_B******%s\n", BLUE, RESET);
	// printf(BLUE"Pile_A\n");
	// ft_print_pile(pile.pile_a);
	// printf("Pile_B\n");
	// ft_print_pile(pile.pile_b);
	// ft_printf("%s*****************%s\n", BLUE, RESET);

	// ft_push_b(&pile);
	// ft_printf("%s***PUSH B TO A***%s\n", YELLOW, RESET);
	// printf(YELLOW"Pile_A\n");
	// ft_print_pile(pile.pile_a);
	// printf("Pile_B\n");
	// ft_print_pile(pile.pile_b);
	// ft_printf("%s*****************%s\n", YELLOW, RESET);

	// ft_push_b(&pile);
	// ft_printf("%s***PUSH B TO A***%s\n", YELLOW, RESET);
	// printf(YELLOW"Pile_A\n");
	// ft_print_pile(pile.pile_a);
	// printf("Pile_B\n");
	// ft_print_pile(pile.pile_b);
	// ft_printf("%s*****************%s\n", YELLOW, RESET);

	ft_free_pile(pile.pile_a);
	ft_free_pile(pile.pile_b);
}
