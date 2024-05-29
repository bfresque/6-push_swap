/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:05:43 by bfresque          #+#    #+#             */
/*   Updated: 2023/03/15 11:06:30 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_len_argc(int ac, char **av)
{
	int	i;
	int	len;

	i = 0;
	while (i < ac)
	{
		len = ft_strlen(av[i]);
		if (len > 18)
		{
			ft_printf ("Error\n");
			exit(0);
		}
		i++;
	}
}

void	ft_nb_ac_for_fonction(t_pile *pile, int ac)
{
	if (ac < 5)
		ft_less_four_ac(pile);
	if (ac == 5)
		ft_four_ac(pile);
	if (ac == 6)
		ft_five_ac(pile);
	if (ac > 6)
	{
		chunk_value(pile);
		ft_for_hundred(pile);
	}
}

int	main(int ac, char **av)
{
	t_pile	pile;

	pile.pile_b = NULL;
	pile.pile_a = NULL;
	ft_len_argc(ac, av);
	check_arg(ac, av);
	ft_put_in_pile(ac, av, &pile);
	check_args(&pile);
	if (ft_is_sort(&pile) == 1)
	{
		ft_free_pile(pile.pile_a);
		exit(0);
	}
	pile.size = ft_pile_size(pile.pile_a);
	ft_mediane_value(&pile);
	ft_nb_ac_for_fonction(&pile, ac);
	ft_free_pile(pile.pile_a);
	ft_free_pile(pile.pile_b);
}
