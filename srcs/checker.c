/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 20:06:06 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/18 03:18:19 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	ft_error(void)
{
	ft_putstr_fd("ERROR\n", 2);
	exit(-1);
}

t_stack		*malstack(char *str, int bol)
{
	t_stack		*ret;

	ret = ft_memalloc(sizeof(t_stack*));
	ret->nb = ft_atoi(str);
	if (!bol)
		ret->empty = 0;
	else
		ret->empty = 1;
	ret->first = NULL;
	ret->before = NULL;
	ret->next = NULL;
	ret->last = NULL;
	return (ret);
}

void	checker(int argc, char **argv)
{
	int			i;
	t_stack		*a;
	t_stack		*b;
	t_stack		*a_tmp;
	t_stack		*b_tmp;
	t_stack		*a_last;
	t_stack		*b_last;
	t_stack		*a_first;
	t_stack		*b_first;

	i = 0;
	a = NULL;
	b = NULL;
	a_first = NULL;
	b_first = NULL;
	while (argv && i < argc)
	{
		a_tmp = a;
		b_tmp = b;
		a = malstack(argv[i], 0);
		b = malstack(argv[i], 1);
	write(1, "BONJOUR\n", 8);
		if (!a_first && !b_first)
		{
			a_first = a;
			b_first = b;
		}
		a->before = a_tmp;
		b->before = b_tmp;
		i++;
		if (i < argc)
		{
			a = a->next;
			b = b->next;
		}
	}
	a_last = a;
	b_last = b;
	while (a->before && b->before)
	{
		a->first = a_first;
		b->first = b_first;
		a->last = a_last;
		b->last = b_last;
		a = a->before;
		b = b->before;
	}
	while (a->next && b->next)
	{
		printf("|%d|\t|%d|\n", a->nb, b->nb);
		printf("|%d|\t|%d|\n", a->empty, b->empty);
		printf("|%p|\t|%p|\n", a->first, b->first);
		printf("|%p|\t|%p|\n", a->before, b->before);
		printf("|%p|\t|%p|\n", a->next, b->next);
		printf("|%p|\t|%p|\n", a->last, b->last);
		a = a->next;
		b = b->next;
	}
	printf("a = %p\n", a);
	printf("b = %p\n", b);
}

int		isvalid(int argc, char **argv)
{
	int		i;
	int		j;
	int		isneg;

	i = -1;
	j = -1;
	isneg = 0;
	while (++i < argc)
	{
		while (argv[i][++j])
		{
			if (argv[i][j] == '-' && isneg == 0)
			{
				isneg = 1;
				j++;
			}
			if (!ft_isdigit(argv[i][j]) || (argv[i][j] == '-' && isneg == 1))
				ft_error();
		}
		isneg = 0;
		j = -1;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (!(isvalid(argc - 1, argv + 1)))
			checker(argc - 1, argv + 1);
		else
			ft_error();
	}
	else
		ft_error();
	return (0);
}
