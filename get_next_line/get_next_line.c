/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifeito-m <ifeito-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:49:52 by ifeito-m          #+#    #+#             */
/*   Updated: 2024/04/13 23:41:57 by ifeito-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;
		open(const char *, int, ...) -> int
	fd = open ("file.txt", O_RDONLY |  O_CREATE);

	printf("fd of file \d\n", fd);
	return (0);
}

