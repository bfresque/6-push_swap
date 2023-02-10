/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:05:43 by bfresque          #+#    #+#             */
/*   Updated: 2023/02/10 14:59:47 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
			if (ft_isdigit(arg[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	t_list2 *pile_a = NULL;
	t_list2 *pile_b = NULL;

	int i = 1;
	int j = 0;
	int cur = 0;
	if (check_arg(ac, av) == 0)
	{
		ft_printf("Error : Arguments aren't some numbers");
		return(0);
	}
	while (i < ac)
	{
		cur = atoi(av[i]);
		pile_a = addAtList(pile_a, cur, j);
		i++;
		j++;
	}
	if (isEmptyList(pile_a) == 1)
	{
		ft_printf("Error : List empty");
		return(0);
	}
	ft_printf("\n----------debut pile a-----------\n");
	printList(pile_a);
	ft_printf("-----------fin pile a------------\n\n");
	// printf("\nIl y a : %d éléments dans la liste chainée\n\n", ft_lstsize(pile_a));
	ft_push_a_to_b(pile_a, pile_b);
	// pile_a = ft_free_at_pos(pile_a, 0);
	// setAt(list, 150, 1);
	// printf("L'élément position 1 sera dorénavant : %d \n\n", getAt(list, 1));
	
	ft_printf("\n----------debut pile b-----------\n");
	printList(pile_b);
	ft_printf("-----------fin pile b------------\n\n");
	
	
	ft_printf("\n----------debut swap a-----------\n");
	pile_a = swap_a(pile_a);
	ft_printf("\npile a : \n");
	printList(pile_a);
	ft_printf("\npile b : \n");
	printList(pile_b);
	ft_printf("-----------fin swap a------------\n\n");
	

	pile_b = freeList(pile_b);
	pile_a = freeList(pile_a);
}

/*int main(int ac, char **av)
{
	t_list2 *a = NULL;
	list->b = NULL;

	int i = 1;
	int j = 0;
	int cur = 0;
	if (check_arg(ac, av) == 0)
	{
		ft_printf("Error : Arguments aren't some numbers");
		return(0);
	}
	while (i < ac)
	{
		cur = atoi(av[i]);
		list->a = addAtList(list->a, cur, j);
		i++;
		j++;
	}
	if (isEmptyList(list->a) == 1)
	{
		ft_printf("Error : List empty");
		return(0);
	}
	printList(list->a);
	printf("\nIl y a : %d éléments dans la liste chainée\n\n", ft_lstsize(list->a));
	// setAt(list, 150, 1);
	// printf("L'élément position 1 sera dorénavant : %d \n\n", getAt(list, 1));
	// printList(list);
	list->a = swap_a(list->a);
	printList(list->a);
	list->a = freeList(list->a);
}*/