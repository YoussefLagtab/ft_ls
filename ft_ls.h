/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 10:55:09 by ylagtab           #+#    #+#             */
/*   Updated: 2020/01/25 10:34:51 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "dirent.h"
# include "libft/libft.h"
# include "includes/typedefs_macros.h"

void	handle_opt_err(char option);
void	parse_args(t_args *ls_args, char **av, int size);

#endif
