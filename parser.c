/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 10:23:55 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/19 19:38:39 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_bool			g_options[256];

static void		exit_illegal_opt(char c)
{
	ft_printf(
		"ft_ls: illegal option -- %c\n"
		"usage: ft_ls [-1adlprtR] [file ...]\n", c);
	exit(1);
}

static void		parse_opt(char *opt_str)
{
	while (*opt_str)
	{
		if (ft_strchr(OPTIONS, *opt_str))
		{
			F_SET(g_options, (int)*opt_str);
			if (*opt_str == 'l')
				F_UNSET(g_options, '1');
			if (*opt_str == '1')
				F_UNSET(g_options, 'l');
		}
		else
			exit_illegal_opt(*opt_str);
		opt_str++;
	}
}

static int		parse_options(char **av)
{
	int i;

	i = 0;
	while (av[i] != NULL)
	{
		if (av[i][0] == '-' && av[i][1] == '-' && av[i][2] == '\0')
			return (i + 1);
		if (av[i][0] == '-')
			parse_opt(av[i] + 1);
		else
			return (i);
		i++;
	}
	return (i);
}

static void		parse_args(t_args *ls_args, char **av)
{
	struct stat	st;
	t_inode		inode;
	t_error		error;

	while (*av != NULL)
	{
		if (lstat(*av, &st) == -1)
		{
			new_error(&error, *av);
			ft_enqueue(&(ls_args->errors), &error, sizeof(t_error));
			av++;
			continue ;
		}
		new_inode(&inode, &st, "", *av);
		if (S_ISDIR(st.st_mode) && !F_IS_SET(g_options, OPT_D))
			ft_enqueue(&(ls_args->dirs), &inode, sizeof(t_inode));
		else if (S_ISLNK(st.st_mode) && !F_IS_SET(g_options, OPT_D))
			handle_link(&inode, ls_args);
		else
			ft_enqueue(&(ls_args->files), &inode, sizeof(t_inode));
		av++;
	}
}

void			ft_parse(t_args *ls_args, char **av)
{
	char	**args;
	int		i;

	i = parse_options(av);
	args = av + i;
	if (*args == NULL)
		args = (char*[2]){".", NULL};
	parse_args(ls_args, args);
}
