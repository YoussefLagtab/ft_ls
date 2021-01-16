/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 10:54:42 by ylagtab           #+#    #+#             */
/*   Updated: 2021/01/16 17:20:03 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	g_is_multi_dir_mode;

static void	ft_ls(t_args *ls_args)
{
	sort_list(&ls_args->errors, compare_error);
	print_errors(&ls_args->errors);
	ft_free_queue(&(ls_args->errors));
	g_reverse_sort = g_options[OPT_R] == 1 ? -1 : 1;
	sort_list(&ls_args->files, get_cmp_func());
	print_inodes(&ls_args->files, 0);
	ft_free_queue(&(ls_args->files));
	if (ls_args->files.length && ls_args->dirs.length)
		ft_putstr("\n");
	g_is_multi_dir_mode = ls_args->dirs.length > 1 || ls_args->files.length
		|| ls_args->errors.length;
	sort_list(&ls_args->dirs, get_cmp_func());
	list_directories(&ls_args->dirs);
	ft_free_queue(&(ls_args->dirs));
}

int			main(int ac, char **av)
{
	t_args		ls_args;

	(void)ac;
	ft_bzero(&ls_args, sizeof(ls_args));
	ft_parse(&ls_args, av + 1);
	ft_ls(&ls_args);
	ft_flush_buff();
	return (errno > 0 ? 1 : 0);
}
