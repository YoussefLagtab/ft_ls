/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmp_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:12:19 by mel-idri          #+#    #+#             */
/*   Updated: 2020/02/22 22:59:52 by mel-idri         ###   ########.fr       */
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
	if (F_IS_SET(g_options, OPT_CAP_S))
		cpm_func = compare_size;
	else
		cpm_func = compare_atime;
	return (cpm_func);
}
