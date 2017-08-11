/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 08:05:54 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/11 15:47:48 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memalloc(size_t size)
{
	void	*alloc;

	if (!(alloc = malloc(size)))
		exit(-1);
	ft_memset(alloc, 0, size);
	return (alloc);
}
