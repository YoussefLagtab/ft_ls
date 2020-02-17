/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 11:21:57 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/17 16:17:39 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_error	*new_error(t_error *error, char *path)
{
	ft_bzero(error, sizeof(t_error));
	error->arg = path;
	error->error_no = errno;
	return (error);
}
