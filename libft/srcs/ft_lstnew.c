/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:31:23 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/11 15:51:11 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*ptr;

	ptr = NULL;
	ptr = (t_list*)ft_memalloc(sizeof(t_list));
	ptr->next = NULL;
	if (!(content))
	{
		ptr->content = NULL;
		ptr->content_size = 0;
		return (ptr);
	}
	ptr->content = ft_memalloc(sizeof(content_size));
	ft_memmove(ptr->content, content, content_size);
	ptr->content_size = content_size;
	return (ptr);
}
