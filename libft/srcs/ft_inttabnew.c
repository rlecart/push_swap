/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inttabnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:27:39 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/11 15:50:18 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		**ft_inttabnew(int x, int y)
{
	int		i;
	int		**nbr;

	i = 0;
	nbr = ft_memalloc(sizeof(int*) * (x + 1));
	while (i < x)
		nbr[i++] = ft_intnew(y);
	nbr[i] = NULL;
	return (nbr);
}
