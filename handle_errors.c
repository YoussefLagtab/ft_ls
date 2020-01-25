/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 10:24:28 by ylagtab           #+#    #+#             */
/*   Updated: 2020/01/25 10:26:12 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	handle_opt_err(char option)
{
	ft_printf("ls: illegal option -- %c\nusage: [-Radert] [file ...]", option);
	exit(1);
}
