/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-07 00:07:12 by ifeito-m          #+#    #+#             */
/*   Updated: 2024-12-07 00:07:12 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}				t_list;

int		find_newline(t_list *list);
t_list	*find_last_node(t_list *list);
char	*get_line(t_list *list);
void	copy_str(t_list *list, char *str);
int		len_to_newline(t_list *list);
void	clean_list(t_list **list);
char	*get_next_line(int fd);
void	free_nodes(t_list **list, t_list *clean_node, char *buf);
int		create_list(t_list **list, int fd);

#endif
