/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-07 00:07:16 by ifeito-m          #+#    #+#             */
/*   Updated: 2024-12-07 00:07:16 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <stdio.h>

void	clean_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		j;
	char	*buf;

	buf = malloc(BUFFER_SIZE +1);
	clean_node = malloc(sizeof(t_list));
	if (buf == NULL || clean_node == NULL)
	{
		free(buf);
		free(clean_node);
		return ;
	}
	last_node = find_last_node(*list);
	i = 0;
	j = 0;
	while (last_node->str_buf[i] && last_node->str_buf[i] != '\n')
		++i;
	while (last_node->str_buf[i] && last_node->str_buf[++i])
		buf[j++] = last_node->str_buf[i];
	buf[j] = '\0';
	clean_node->str_buf = buf;
	clean_node->next = NULL;
	free_nodes(list, clean_node, buf);
}

char	*get_line(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (list == NULL)
		return (NULL);
	str_len = len_to_newline(list);
	next_str = malloc(str_len +1);
	if (next_str == NULL)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

void	link_new_node(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buf = buf;
	new_node->next = NULL;
}

int	create_list(t_list **list, int fd)
{
	int		char_read;
	char	*buf;

	while (!find_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (NULL == buf)
			return (1);
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read < 0)
		{
			free(buf);
			return (1);
		}
		if (char_read == 0)
		{
			free(buf);
			return (0);
		}
		buf[char_read] = '\0';
		link_new_node(list, buf);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_list	*list[1024];
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (create_list(&list[fd], fd) == 1)
		return (NULL);
	if (list[fd] == NULL)
		return (NULL);
	next_line = get_line(list[fd]);
	clean_list(&list[fd]);
	return (next_line);
}

int	main()
{
	char	*line;
	int		fd;
	int		fd1;

	fd = open ("prueba3.txt", O_RDONLY);
	fd1 = open ("prueba4.txt", O_RDONLY);
	if (fd == -1)
		close (fd);
	line = "";
	if (fd1 == -1)
		close (fd1);
	while (line != NULL)
	{
		line = get_next_line (fd);
		if (!line)
		{
			free (line);
			break ;	
		}
		printf ("LINEA FD: %d, %s", fd, line);
		free (line);
		line = get_next_line (fd1);
		if (!line)
		{
			free (line);
			break ;	
		}
		printf ("LINEA FD: %d, %s", fd1, line);
		free (line);
	}
	close (fd);
	close (fd1);
	return (0);
}