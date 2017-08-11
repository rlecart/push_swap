/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 20:06:06 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/11 16:37:50 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	ft_error(void)
{
	ft_putstr_fd("ERROR\n", 2);
	exit(-1);
}

void	malstack(t_stack **a, t_stack **b, char *str)
{
	int		nb;

	nb = ft_atoi(str);
	*a = ft_memalloc(sizeof(t_stack*));
	(*a)->nb = nb;
	(*a)->isempty = 0;
	(*a)->first = NULL;
	(*a)->before = NULL;
	(*a)->next = NULL;
	(*a)->last = NULL;
	*b = ft_memalloc(sizeof(t_stack*));
	(*b)->nb = 0;
	(*b)->isempty = 1;
	(*b)->first = NULL;
	(*b)->before = NULL;
	(*b)->next = NULL;
	(*b)->last = NULL;
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
	while (i < argc)
	{
		a_tmp = a;
		b_tmp = b;
		malstack(&a, &b, argv[i]);
		if (!a_first && !b_first)
		{
			a_first = a;
			b_first = b;
		}
		a->before = a_tmp;
		b->before = b_tmp;
		a = a->next;
		b = b->next;
		i++;
	}
	//a = a_tmp;
	//b = b_tmp;
	a_last = a;
	b_last = b;
	while (a->before && b->before)
	{
		a = a->before;
		b = b->before;
	}
	while (a->next && b->next)
	{
		a->first = a_first;
		b->first = b_first;
		a->last = a_last;
		b->last = b_last;
		a = a->next;
		b = b->next;
	}




	a = a->first;
	b = b->first;
	while (a->next && b->next)
	{
		printf("|%d|\t|%d|\n", a->nb, b->nb);
		printf("|%d|\t|%d|\n", a->isempty, b->isempty);
		printf("|%p|\t|%p|\n", a->first, b->first);
		printf("|%p|\t|%p|\n", a->before, b->before);
		printf("|%p|\t|%p|\n", a->next, b->next);
		printf("|%p|\t|%p|\n", a->last, b->last);
		a = a->next;
		b = b->next;
	}
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
