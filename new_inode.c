/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_inode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 11:21:57 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/17 16:14:44 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_inode	*new_inode(t_inode *inode, struct stat *st, char *path, char *name)
{
	ft_bzero(inode, sizeof(t_inode));
	inode->st = *st;
	ft_strncpy(inode->path, path, PATH_MAX);
	ft_strncpy(inode->name, name, NAME_MAX);
	return (inode);
}
