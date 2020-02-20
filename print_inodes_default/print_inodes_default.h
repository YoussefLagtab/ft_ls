/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_inodes_default.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 01:15:31 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/20 01:34:50 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_INODES_DEFAULT_H
# define PRINT_INODES_DEFAULT_H

# include <sys/ioctl.h>
# include "../ft_ls.h"

typedef struct	s_cols_specs
{
	t_list	**pointers;
	int		nb_pointers;
	int		max_col_len;
	int		nb_lines;
	int		nb_cols;
}				t_cols_specs;

void			print_one_entry_per_line(t_queue *inodes);

#endif
