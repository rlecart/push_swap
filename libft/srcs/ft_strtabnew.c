/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:27:39 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/11 15:51:58 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**ft_strtabnew(int x, int y)
{
	int		i;
	char	**str;

	i = 0;
	str = ft_memalloc(sizeof(char*) * (x + 1));
	while (i < x)
		str[i++] = ft_strnew(y);
			return (NULL);
	str[i] = NULL;
	return (str);
}
