/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daltrad <daltrad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 22:28:49 by daltrad           #+#    #+#             */
/*   Updated: 2026/11/05 20:33:30 by daltrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_to_stash(int fd, char *stash)
{
	char	*buf;
	ssize_t	bytes;

	bytes = 1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (free_all(stash, NULL));
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (free_all(stash, buf));
		buf[bytes] = '\0';
		stash = ft_strjoin(stash, buf);
		if (!stash)
			return (free_all(NULL, buf));
	}
	free(buf);
	return (stash);
}
