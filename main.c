/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 10:54:42 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/19 16:52:55 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_free_errors(t_queue *errors)
{
	t_list *err_node;

	while (errors->length)
	{
		err_node = ft_dequeue(errors);
		ft_memdel((void **)&(err_node->content));
		ft_memdel((void **)&err_node);
	}
}

static void	ft_ls(t_args *ls_args)
{
	print_errors(&(ls_args->errors));
	print_files(ls_args->files.head);
}

int			main(int ac, char **av)
{
	t_args		ls_args;

	(void)ac;
	ft_bzero(&ls_args, sizeof(ls_args));
	ft_parse(&ls_args, av + 1);
	ft_ls(&ls_args);
	ft_free_errors(&(ls_args.errors));
	ft_flush_buff();
	return (errno > 0 ? 1 : 0);
}
