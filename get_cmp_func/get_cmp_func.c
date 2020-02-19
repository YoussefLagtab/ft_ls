/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmp_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:12:19 by mel-idri          #+#    #+#             */
/*   Updated: 2020/02/19 19:35:51 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_cmp_func.h"

t_cmp_func	get_cmp_func(void)
{
	static t_cmp_func cpm_func;

	if (cpm_func)
		return (cpm_func);
	if (F_IS_SET(g_options, OPT_T))
		cpm_func = compare_mtime;
	else
		cpm_func = compare_atime;
	return (cpm_func);
}
