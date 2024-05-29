/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:36:10 by bfresque          #+#    #+#             */
/*   Updated: 2023/03/15 11:06:58 by bfresque         ###   ########.fr       */
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
		ft_free_pile(pile->pile_a);
		exit(0);
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

void	check_nb_argc(char **av)
{
	if (av[1] == NULL)
		exit(0);
}

void	check_arg(int ac, char **av)
{
	int		i;
	int		j;
	int		larg;
	char	*arg;

	i = 1;
	check_nb_argc(av);
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
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	check_args(t_pile *pile)
{
	t_pile	*temp1;
	t_pile	*temp2;

	temp1 = pile->pile_a;
	while (temp1)
	{
		temp2 = temp1->next;
		while (temp2)
		{
			if (temp1->data == temp2->data)
			{
				ft_printf("Error\n");
				ft_free_pile(pile->pile_a);
				exit(0);
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
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
			exit(0);
		}
		temp = temp->next;
	}
}
