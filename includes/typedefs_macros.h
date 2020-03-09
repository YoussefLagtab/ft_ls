/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs_macros.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:53:26 by ylagtab           #+#    #+#             */
/*   Updated: 2020/03/08 15:36:57 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_MACROS_H
# define TYPEDEFS_MACROS_H

# define OPTIONS "1adlprRtSu"
# define OPT_A 'a'
# define OPT_L 'l'
# define OPT_R 'r'
# define OPT_CAP_R 'R'
# define OPT_T 't'
# define OPT_CAP_S 'S'
# define OPT_1 '1'
# define OPT_D 'd'
# define OPT_P 'p'
# define OPT_U 'u'
# define F_IS_SET(x, f) (x[f] == 1)
# define F_SET(x, f) (x[f] = 1)
# define F_UNSET(x, f) (x[f] = 0)
# define PATH_MAX 1024
# define NAME_MAX 255
# define SIX_MONTHS 15724800

typedef int	(*t_cmp_func)(t_list*, t_list*);

typedef char	t_bool;

extern t_bool	g_options[256];
extern int		g_is_multi_dir_mode;

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
	t_queue		errors;
	t_queue		files;
	t_queue		dirs;
}				t_args;

#endif
