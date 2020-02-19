/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_perm_acl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 09:46:16 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/18 10:00:22 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_files_longlist.h"

static int	bit_is_set(unsigned long nbr, int index)
{
	return (((nbr >> index) & 1) == 1);
}

static char	get_inode_type(mode_t st_mode)
{
	if (S_ISREG(st_mode))
		return ('-');
	else if (S_ISDIR(st_mode))
		return ('d');
	else if (S_ISCHR(st_mode))
		return ('c');
	else if (S_ISBLK(st_mode))
		return ('b');
	else if (S_ISFIFO(st_mode))
		return ('p');
	else if (S_ISLNK(st_mode))
		return ('l');
	else if (S_ISSOCK(st_mode))
		return ('s');
	return ('u');
}

void		fill_perm(t_file_details *f_details)
{
	int		i;
	mode_t	st_mode;
	char	*perms;

	st_mode = f_details->st_mode;
	f_details->perm[0] = get_inode_type(st_mode);
	i = 1;
	perms = "xwr";
	while (i < 10)
	{
		if (bit_is_set(st_mode, 10 - i - 1))
			f_details->perm[i] = perms[(10 - i - 1) % 3];
		else
			f_details->perm[i] = '-';
		i++;
	}
	i = 0;
	if (bit_is_set(st_mode, 9))
		f_details->perm[9] = f_details->perm[9] == 'x' ? 't' : 'T';
	if (bit_is_set(st_mode, 10))
		f_details->perm[6] = f_details->perm[6] == 'x' ? 's' : 'S';
	if (bit_is_set(st_mode, 11))
		f_details->perm[3] = f_details->perm[3] == 'x' ? 's' : 'S';
}
