/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:36:10 by bfresque          #+#    #+#             */
/*   Updated: 2023/03/10 10:59:17 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_sort(t_pile *pile)
{
	t_pile	*temp;
	int		i;
	int		size;

	i = 0;
	temp = pile->pile_a;
	size = ft_pile_size(pile->pile_a);
	if (size == 1)
	{
		// ft_printf("Error\n");
		ft_free_pile(pile->pile_a);
		exit(-1);
	}
	while (temp->next)
	{
		if (temp->data < temp->next->data)
			i++;
		temp = temp->next;
	}
	if (i == size - 1)
		return (1);
	else
		return (0);
}

void	check_nb_argc(int ac)
{
	if (ac == 1)
	{
		// ft_printf("Error\n");
		exit(-1);
	}
}

void	check_arg(int ac, char **av)
{
	int		i;
	int		j;
	int		larg;
	char	*arg;

	i = 1;
	check_nb_argc(ac);
	while (i < ac)
	{
		arg = av[i];
		j = 0;
		larg = ft_strlen(arg);
		while (j < larg)
		{
			if (ft_isdigit(arg[j]) == 0 && (arg[j] != '-')
				&& (arg[j] != '"') && (arg[j] != '+'))
			{
				ft_printf("Error\n");
				exit(-1);
			}
			j++;
		}
		i++;
	}
	check_args(ac, av, 1);
}

void	check_args(int ac, char **av, int j)
{
	char	*cur;
	int		i;

	if (j >= ac)
	{
		return ;
	}
	i = 0;
	cur = av[j];
	while (i < j)
	{
		if (ft_strcmp(cur, av[i]) == 0)
		{
			ft_printf("Error\n");
			exit(-1);
		}
		i++;
	}
	check_args(ac, av, j + 1);
}

void	check_int(t_pile *pile)
{
	t_pile	*temp;

	temp = pile->pile_a;
	while (temp)
	{
		if ((temp->data > 2147483647) || (temp->data < -2147483648))
		{
			ft_printf ("Error\n");
			ft_free_pile(pile->pile_a);
			exit(-1);
		}
		temp = temp->next;
	}
}
