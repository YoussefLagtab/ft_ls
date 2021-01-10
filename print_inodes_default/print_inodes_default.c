/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_inodes_default.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylagtab <ylagtab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:13:46 by mel-idri          #+#    #+#             */
/*   Updated: 2021/01/10 17:22:39 by ylagtab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_inodes_default.h"

static int	get_nb_cols(void)
{
	struct winsize	w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return (w.ws_col);
}

static int	get_max_col_len(t_list *inode_node)
{
	t_inode	*inode;
	int		name_len;
	int		max_col_len;

	max_col_len = 0;
	while (inode_node)
	{
		inode = (t_inode *)inode_node->content;
		name_len = ft_strlen(inode->name);
		if (name_len > max_col_len)
			max_col_len = name_len;
		inode_node = inode_node->next;
	}
	return (max_col_len);
}

static void	fill_pointers(t_queue *inodes, t_cols_specs *cs)
{
	int		i;
	int		j;

	cs->nb_pointers = cs->nb_cols / (cs->max_col_len + 1);
	cs->nb_lines = inodes->length / cs->nb_pointers;
	if (inodes->length % cs->nb_pointers != 0)
		cs->nb_lines++;
	(cs->pointers) = (t_list **)safe_malloc(cs->nb_pointers * sizeof(t_list *));
	(cs->pointers)[0] = inodes->head;
	i = 1;
	while (i < cs->nb_pointers)
	{
		j = 0;
		cs->pointers[i] = cs->pointers[i - 1];
		while (j < cs->nb_lines && cs->pointers[i])
		{
			cs->pointers[i] = cs->pointers[i]->next;
			j++;
		}
		i++;
	}
}

static void	print_filename(t_inode *inode, int max_col_len, int is_last_col)
{
	char	*name;

	name = inode->name;
	if (g_options[OPT_P] == 1 && S_ISDIR(inode->st.st_mode))
		name = ft_strjoin(name, "/");
	if (is_last_col)
		ft_printf("%s", name);
	else
		ft_printf("%-*s ", max_col_len, name);
	if (name != inode->name)
		ft_strdel(&name);
}

void		print_inodes_default(t_queue *inodes)
{
	t_inode			*inode;
	t_cols_specs	cs;
	int				i;

	cs.nb_cols = get_nb_cols();
	if (inodes->length == 0)
		return ;
	cs.max_col_len = get_max_col_len(inodes->head);
	if (cs.nb_cols <= cs.max_col_len || g_options[OPT_1] == 1 || isatty(1) == 0)
		return (print_one_entry_per_line(inodes));
	fill_pointers(inodes, &cs);
	while (--cs.nb_lines >= 0)
	{
		i = 0;
		while (i < cs.nb_pointers && cs.pointers[i])
		{
			inode = ((t_inode*)cs.pointers[i]->content);
			print_filename(inode, cs.max_col_len, i == cs.nb_pointers - 1);
			cs.pointers[i] = cs.pointers[i]->next;
			i++;
		}
		ft_printf("\n");
	}
	ft_memdel((void**)&cs.pointers);
}
