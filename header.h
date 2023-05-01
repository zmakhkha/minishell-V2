/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:53:38 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/01 15:31:55 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>

# include "libft/libft.h"

# define H_PATH "/tmp/.minishell_history"
# define H_DOCP "/tmp/"
# define SUCC 0
# define ERR 1
extern	int			status;
// -------------------------------------- //
// -----------> Token struct <---------- //
// ------------------------------------ //

typedef struct s_token
{
	char			*str;
	int				index;
	int				type;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

// -------> Tokens enumeration <------- //

enum
{
	SPACE,
	D_QUOTE,
	S_QUOTE,
	HDOC,
	RE_IN,
	APPEND,
	RE_OUT,
	SUBSHELL,
	AND,
	OR,
	PIPE,
};

// utils/ft_prmpt.c
void	ft_prompt(void);

// utils/ft_history.c
int	ft_add_history(char *str);

#endif
