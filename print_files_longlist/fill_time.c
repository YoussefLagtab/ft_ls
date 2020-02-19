/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 09:46:23 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/18 09:53:03 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_files_longlist.h"

void	fill_time(t_file_details *f_details, t_ll_specs *ll_specs,
			time_t st_time)
{
	int time_len;

	f_details->time = ctime(&st_time);
	if (time(NULL) - st_time > SIX_MONTHS || st_time - time(NULL) > SIX_MONTHS)
		f_details->time = ft_strjoin_free(ft_strsub(f_details->time, 4, 7),
			f_details->time + 19, 1, 0);
	else
		f_details->time = ft_strsub(f_details->time, 4, 13);
	time_len = ft_strlen(f_details->time);
	f_details->time[time_len - 1] = '\0';
	if (time_len > ll_specs->time_len)
		ll_specs->time_len = time_len;
}
