/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 20:31:23 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/18 02:13:35 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/includes/libft.h"

typedef struct		s_stack
{
	int				nb;
	int				empty;
	struct s_stack	*first;
	struct s_stack	*before;
	struct s_stack	*next;
	struct s_stack	*last;
}					t_stack;

#endif
