/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 10:23:55 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/17 16:58:08 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	exit_illegal_opt(char c)
{
	ft_printf(
		"ft_ls: illegal option -- %c\n"
		"usage: ft_ls [-1adlprtRd] [file ...]\n", c);
	exit(1);
}

static void	parse_opt(t_args *ls_args, char *opt_str)
{
	while (*opt_str)
	{
		if (*opt_str == 'a')
			F_SET(ls_args->options, OPT_A);
		else if (*opt_str == 'l')
		{
			F_SET(ls_args->options, OPT_L);
			F_UNSET(ls_args->options, OPT_1);
		}
		else if (*opt_str == 'r')
			F_SET(ls_args->options, OPT_R);
		else if (*opt_str == 'R')
			F_SET(ls_args->options, OPT_CAP_R);
		else if (*opt_str == 't')
			F_SET(ls_args->options, OPT_T);
		else if (*opt_str == '1')
		{
			F_SET(ls_args->options, OPT_1);
			F_UNSET(ls_args->options, OPT_L);
		}
		else
			exit_illegal_opt(*opt_str);
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

static void	parse_args(t_args *ls_args, char **av)
{
	struct stat	st;
	t_inode		inode;
	t_error		error;
	int			i;

	i = 0;
	while (av[i] != NULL)
	{
		if (lstat(av[i], &st) == -1)
		{
			new_error(&error, av[i]);
			ft_enqueue(&(ls_args->errors), &error, sizeof(t_error));
		}
		else
		{
			new_inode(&inode, &st, "", av[i]);
			if (S_ISDIR(st.st_mode) && !F_IS_SET(ls_args->options, OPT_D))
				ft_enqueue(&(ls_args->dirs), &inode, sizeof(t_inode));
			else if (S_ISLNK(st.st_mode) && !F_IS_SET(ls_args->options, OPT_D))
				handle_link(&inode, ls_args);
			else
				ft_enqueue(&(ls_args->files), &inode, sizeof(t_inode));
		}
	}
}

void		ft_parse(t_args *ls_args, char **av)
{
	char	**args;
	int		i;

	i = parse_options(ls_args, av);
	args = av + i;
	if (*args == NULL)
		args = (char*[2]){".", NULL};
	parse_args(ls_args, args);
}
