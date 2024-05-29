/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:20:48 by bfresque          #+#    #+#             */
/*   Updated: 2023/03/15 11:05:55 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../includes/get_next_line.h"
# include "../includes/libft.h"
# include "../includes/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define RESET "\033[0m"
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"

typedef struct s_pile
{
	long			data;
	int				size;
	int				chunk_size;
	int				left;
	int				smallest;
	int				biggest;
	int				min_chunk;
	int				max_chunk;
	int				mediane_a;
	int				mediane_b;
	struct s_pile	*next;
	struct s_pile	*prev;
	struct s_pile	*pile_a;
	struct s_pile	*pile_b;
}				t_pile;

/*********************	check_argc.c ********************************/
int		ft_is_sort(t_pile *pile);
void	check_arg(int ac, char **av);
void	check_nb_argc(char **av);
void	check_args(t_pile *pile);
void	check_int(t_pile *pile);

/*********************	ft_find_top_and_data.c **********************/
int		ft_find_from_top(t_pile *pile);
int		ft_find_from_bottom(t_pile *pile);
int		ft_find_position_cell(t_pile *pile, int data);

/*********************	hundred_argc.c ******************************/
void	find_near_less(t_pile *pile);
void	push_near(t_pile *pile);
void	ft_for_hundred(t_pile *pile);

/*********************	init_add_pile.c *****************************/
t_pile	*ft_new_cell(long data);
t_pile	*ft_add_at_pile(t_pile *pile, long data, int pos);
void	ft_put_in_pile(int ac, char **av, t_pile *pile);
t_pile	*ft_delete_last_cell(t_pile *pile);

/*********************	less_five.c *********************************/
int		ft_find_smallest(t_pile *pile);
int		ft_find_biggest(t_pile *pile);
void	ft_less_four_ac(t_pile *pile);
void	ft_four_ac(t_pile *pile);
void	ft_five_ac(t_pile *pile);

/*********************	push_swap.c *********************************/
void	ft_len_argc(int ac, char **av);
void	ft_nb_ac_for_fonction(t_pile *pile, int ac);

/*********************	push.c **************************************/
void	ft_push_a_to_b(t_pile *pile);
void	ft_push_b_to_a(t_pile *pile);

/*********************	rotate_inv.c ********************************/
void	ft_reverse_rotate_a(t_pile *pile);
void	ft_reverse_rotate_b(t_pile *pile);
void	ft_rrr(t_pile *pile);

/*********************	rotate.c ************************************/
void	ft_rotate_a(t_pile *pile);
void	ft_rotate_b(t_pile *pile);
void	ft_rr(t_pile *pile);

/*********************	swap.c **************************************/
void	ft_swap_a(t_pile *pile);
void	ft_swap_b(t_pile *pile);
void	ft_ss(t_pile *pile);

/*********************	utils_hundred_argc.c ************************/
void	ft_minus(t_pile *pile, int position_top, int data_top);
void	ft_plus(t_pile *pile, int position_bottom, int data_bottom);
void	push_near_utils_one(t_pile *pile, int highest_in_b);
void	push_near_utils_two(t_pile *pile, int highest_in_b);

/*********************	utils_two.c *********************************/
void	ft_mediane_value(t_pile *pile);
void	ft_mediane_b_value(t_pile *pile);
void	ft_free_pile(t_pile *pile);
void	chunk_value(t_pile *pile);
void	chunk_value_two(t_pile *pile);

/*********************	utils.c *************************************/
int		ft_pile_size(t_pile *pile);
long	ft_first_cell(t_pile *pile);
long	ft_last_cell_a(t_pile *pile);
long	ft_last_cell_b(t_pile *pile);
int		ft_is_empty_pile(t_pile *pile);

#endif