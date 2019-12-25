/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs_macros.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:53:26 by ylagtab           #+#    #+#             */
/*   Updated: 2019/12/14 15:38:57 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_MACROS_H
# define TYPEDEFS_MACROS_H

# include <sys/stat.h>

# define OPT_A 0
# define OPT_L 1
# define OPT_R 2
# define OPT_CAP_R 3
# define OPT_T 4
# define OPT_D 5
# define F_IS_SET(x, f) ((x & (1 << f)) && 1)
# define F_SET(x, f) (x |= (1 << f))
# define F_UNSET(x, f) (x &= ~(1 << f))

typedef char	t_opt;

typedef enum	e_errno
{
	OPT_ERROR,
	NO_FILE__ERROR,
	PERM_ERRO
}				t_errno;

typedef struct	s_file
{
	char		*name;
	struct stat file_stat;
}				t_file;

typedef struct	s_dir
{
	char		*name;
	struct stat dir_stat;
}				t_dir;

typedef struct	s_args
{
	t_opt		options;
	t_queue		errors;
	t_queue		files;
	t_queue		dirs;
}				t_args;

#endif
