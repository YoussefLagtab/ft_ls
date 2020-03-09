/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmp_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:12:19 by mel-idri          #+#    #+#             */
/*   Updated: 2020/03/08 16:52:34 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_cmp_func.h"

t_cmp_func	get_cmp_func(void)
{
	static t_cmp_func cmp_func;

	if (cmp_func)
		return (cmp_func);
	if (F_IS_SET(g_options, OPT_T))
	{
		if (F_IS_SET(g_options, OPT_U))
			cmp_func = compare_atime;
		else
			cmp_func = compare_mtime;
	}
	else if (F_IS_SET(g_options, OPT_CAP_S))
		cmp_func = compare_size;
	else
		cmp_func = compare_filename;
	return (cmp_func);
}
