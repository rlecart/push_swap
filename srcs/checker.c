/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 20:06:06 by rlecart           #+#    #+#             */
/*   Updated: 2017/08/10 21:10:35 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	ft_error(void)
{
	ft_putstr_fd("ERROR\n", 2);
	exit(-1);
}

void	checker(int argc, char **argv)
{
	(void)argc;
	(void)argv;
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
