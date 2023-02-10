/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:20:48 by bfresque          #+#    #+#             */
/*   Updated: 2023/02/10 11:48:08 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../includes/get_next_line.h"
# include "../includes/libft.h"
# include "../includes/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list2
{
	int 			data;
	struct s_list2	*next;
	// struct s_list2	*before;
	struct s_list2	*a;
	struct s_list2	*b;
}				t_list2;


/*********************	ft_base_lst.c	********************/

int isEmptyList(t_list2 *L);
int getAt(t_list2 *L, int pos);
t_list2 *addAtList(t_list2 *L, int data, int pos);
void printList(t_list2 *L);
void setAt(t_list2 *L, int data, int pos);
t_list2 *freeList(t_list2 *L);                  //ft_lstclear

t_list2 *swap_a(t_list2 *L);
t_list2 *ft_push_a_to_b(t_list2 *one, t_list2 *two);
t_list2	*ft_free_at_pos(t_list2 *list, int pos);


#endif