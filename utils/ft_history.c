/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:30:04 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/02 14:06:02 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_exit(char * msg, int stat)
{
	printf("%s\n", msg);
	g_status = stat;
	exit(stat);
}

// Add a file history
int	ft_add_history(char *str)
{
	int		fd;
	ssize_t	b;

	add_history(str);
	fd = open(H_PATH, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd == -1)
		ft_exit("Failed to create the history file !!\n", 1);
	b = write(fd, str, ft_strlen(str));
	if (b == -1)
		ft_exit("Failed to update the history file !!\n", 1);
	b = write(fd, "\n", 1);
	if (b == -1)
		ft_exit("Failed to update the history file !!\n", 1);
	if (close(fd) == -1)
		ft_exit("Failed to close history file !!\n", 1);
	return (0);
}
