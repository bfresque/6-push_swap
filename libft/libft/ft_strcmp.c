/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:24:06 by bfresque          #+#    #+#             */
/*   Updated: 2023/02/15 15:32:18 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2)) {
		s1++;
		s2++;
	}
	return (int)(*s1 - *s2);
}

