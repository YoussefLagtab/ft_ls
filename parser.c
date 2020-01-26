/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 10:23:55 by ylagtab           #+#    #+#             */
/*   Updated: 2020/01/26 21:43:00 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	parse_opt(t_args *ls_args, char *opt_str)
{
	while (*opt_str)
	{
		if (*opt_str == 'a')
			F_SET(ls_args->options, OPT_A);
		else if (*opt_str == 'l')
			F_SET(ls_args->options, OPT_L);
		else if (*opt_str == 'r')
			F_SET(ls_args->options, OPT_R);
		else if (*opt_str == 'R')
			F_SET(ls_args->options, OPT_CAP_R);
		else if (*opt_str == 't')
			F_SET(ls_args->options, OPT_T);
		else
			handle_opt_err(*opt_str);
		opt_str++;
	}
}

static int	parse_options(t_args *ls_args, char **av)
{
	int i;

	i = 0;
	while (av[i] != NULL)
	{
		if (av[i][0] == '-' && av[i][1] == '-' && av[i][2] == '\0')
			return (i + 1);
		if (av[i][0] == '-')
			parse_opt(ls_args, av[i] + 1);
		else
			return (i);
		i++;
	}
	return (i);
}

void		ft_parse(t_args *ls_args, char **av, int size)
{
	int	i;

	(void)size;
	i = parse_options(ls_args, av);
}
