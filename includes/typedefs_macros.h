/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs_macros.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:53:26 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/17 16:54:14 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_MACROS_H
# define TYPEDEFS_MACROS_H

# define OPT_A 0
# define OPT_L 1
# define OPT_R 2
# define OPT_CAP_R 3
# define OPT_T 4
# define OPT_1 5
# define OPT_D 6
# define F_IS_SET(x, f) ((x & (1 << f)) && 1)
# define F_SET(x, f) (x |= (1 << f))
# define F_UNSET(x, f) (x &= ~(1 << f))
# define PATH_MAX 1024
# define NAME_MAX 255

typedef char	t_option;

typedef struct	s_inode
{
	struct stat st;
	char		path[PATH_MAX + 1];
	char		name[NAME_MAX + 1];
}				t_inode;

typedef struct	s_error
{
	char	*arg;
	int		error_no;
}				t_error;

typedef struct	s_args
{
	t_option	options;
	t_queue		errors;
	t_queue		files;
	t_queue		dirs;
}				t_args;

#endif
