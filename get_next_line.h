/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 16:52:58 by khansman          #+#    #+#             */
/*   Updated: 2016/11/13 16:53:28 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
** ----------\
** Includes   |
** ----------/
*/

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

# include "./libft/includes/libft.h"

//#include <stdio.h>//debug

/*
** ----------\
** Defines    |
** ----------/
*/

# define BUFF_SIZE 2000

# define NUM_BUFF  10
# define LINE_SIZE 50

/*
** Short_hand
*/
# define ACTIVE buff->active
# define POS    buff->pos
# define AB_POS (buff->pos % BUFF_SIZE)
# define BUFF   buff->buff
# define B_FD   buff->fd
# define RET    buff->ret
# define L      buff->l
# define LINE   buff->line

/*
** ----------\
** Structures |
** ----------/
*/

typedef struct	s_buff
{
	char		buff[BUFF_SIZE];
	char		active;
	int			fd;
	int			ret;
	int			pos;
	int			l;
	char		*line;
}				t_buff;

/*
** ----------\
** Prototypes |
** ----------/
*/

 int		get_next_line(const int fd, char **line);

/*
**                                /----------\                                **
** ----- ----- ----- ----- ----- |  The End   | ----- ----- ----- ----- ----- **
**                                \----------/                                **
*/
#endif
