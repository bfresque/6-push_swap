/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:20:48 by bfresque          #+#    #+#             */
/*   Updated: 2023/02/13 15:13:43 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../includes/get_next_line.h"
# include "../includes/libft.h"
# include "../includes/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

typedef struct s_pile
{
	int 			data;
	struct s_pile	*next;
	struct s_pile	*before;
	struct s_pile	*pile_a;
	struct s_pile	*pile_b;
}				t_pile;

/*********************	init_add_pile.c	********************/
t_pile	*ft_new_cell(int data);
t_pile	*ft_add_at_pile(t_pile *pile, int data, int pos);
void	ft_put_in_pile(int ac, char **av, t_pile *pile);
void	ft_free_pile(t_pile *pile);
t_pile	*ft_delete_last_cell(t_pile *pile);


/*********************	push_swap.c	********************/

/*********************	push.c	********************/
void	ft_push_a(t_pile *pile);
void	ft_push_b(t_pile *pile);
void	ft_ss(t_pile *pile);


/*********************	rotate_inv.c	********************/
void	ft_reverse_rotate_a(t_pile *pile);
void	ft_reverse_rotate_b(t_pile *pile);
void	ft_rrr(t_pile *pile);

/*********************	rotate.c	********************/
void	ft_rotate_a(t_pile *pile);
void	ft_rotate_b(t_pile *pile);
void	ft_rr(t_pile *pile);

/*********************	swap.c	********************/
void	ft_swap_a(t_pile *pile);
void	ft_swap_b(t_pile *pile);

/*********************	utils.c	********************/
int		ft_pile_size(t_pile *pile);
int		ft_first_cell(t_pile *pile);
int		ft_last_cell(t_pile *pile);
int		ft_is_empty_pile(t_pile *pile);
void	ft_print_pile(t_pile *pile);

#endif