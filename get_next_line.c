/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 16:59:24 by khansman          #+#    #+#             */
/*   Updated: 2016/11/13 16:59:27 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		remalloc(char **line, int len)
{
	char			*tmp;

	tmp = *line;
	*line = ft_strnew(len + LINE_SIZE + 1);
	ft_memcpy(*line, tmp, len);
	free(tmp);
}

static void		get_buff(t_buff **buff, int fd)
{
	static t_buff	buffs[NUM_BUFF];
	int				k;

	k = -1;
	while (++k < NUM_BUFF)
		if (buffs[k].active && buffs[k].fd == fd)
		{
			*buff = &buffs[k];
			return ;
		}
	k = -1;
	while (++k < NUM_BUFF)
	{
		if (!buffs[k].active)
		{
			ft_bzero(&buffs[k], sizeof(t_buff));
			buffs[k].fd = fd;
			*buff = &buffs[k];
			return ;
		}
	}
	ft_bzero(&buffs[0], sizeof(t_buff));
	buffs[k].fd = fd;
	*buff = &buffs[0];
}

static int		read_line(t_buff *buff)
{
	if (!ACTIVE)
		ACTIVE = 1;
	else if (!RET)
	{
		ACTIVE = 0;
		return (0);
	}
	RET = read(B_FD, BUFF, BUFF_SIZE);
	if (!RET)
	{
		ACTIVE = 0;
		return (RET);
	}
	POS = 0;
	return (RET);
}

 int			get_next_line(const int fd, char **line)
 {
	 t_buff			*buff;

	 get_buff(&buff, fd);
	 if (!ACTIVE && !read_line(buff))
	 	return (RET);
	L = -1;
	while (BUFF[POS] != '\n' && BUFF[POS] != '\0')
	{
		if (POS >= RET && !read_line(buff))
			return (RET);
		if (((L + 1) % LINE_SIZE) == 0 || L == 0)
			remalloc(line, L);
		*line[++L] = BUFF[POS];
		POS++;
	}
	POS++;
	return (1);
 }