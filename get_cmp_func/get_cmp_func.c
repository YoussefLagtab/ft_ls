/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmp_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:12:19 by mel-idri          #+#    #+#             */
/*   Updated: 2020/10/22 11:26:15 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_cmp_func.h"

t_cmp_func	get_cmp_func(void)
{
	static t_cmp_func cmp_func;

	if (cmp_func)
		return (cmp_func);
	if (g_options[OPT_T] == 1)
	{
		if (g_options[OPT_U] == 1)
			cmp_func = compare_atime;
		else
			cmp_func = compare_mtime;
	}
	else if (g_options[OPT_CAP_S] == 1)
		cmp_func = compare_size;
	else
		cmp_func = compare_filename;
	return (cmp_func);
}
