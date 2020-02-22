/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmp_func.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-idri <mel-idri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:04:19 by ylagtab           #+#    #+#             */
/*   Updated: 2020/02/22 22:57:58 by mel-idri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_CMP_FUNC_H
# define GET_CMP_FUNC_H

# include "../ft_ls.h"

int			compare_atime(t_list *node1, t_list *node2);
int			compare_mtime(t_list *node1, t_list *node2);
int			compare_filename(t_list *node1, t_list *node2);
int			compare_size(t_list *node1, t_list *node2);
t_cmp_func	get_cmp_func(void);

#endif
