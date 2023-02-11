/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:20:48 by bfresque          #+#    #+#             */
/*   Updated: 2023/02/10 19:58:51 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../includes/get_next_line.h"
# include "../includes/libft.h"
# include "../includes/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_pile
{
	int 			data;
	struct s_pile	*next;
	struct s_pile	*pile_a;
	struct s_pile	*pile_b;
}				t_pile;


/*********************	ft_base_lst.c	********************/




#endif