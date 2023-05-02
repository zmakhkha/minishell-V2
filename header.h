/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:53:38 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/02 14:21:46 by zmakhkha         ###   ########.fr       */
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
int g_status;
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
// Parsing stage
// Parsing/tokenizer/ft_oprt_wrd.c
int 	ft_isoperator(char o);
void		ft_operators(char *str, t_token **lst, int *a, int *b);
void	ft__operators(char *str, t_token **lst, int *a, int *b);
int		ft_isword(char o);
void	ft_space(char *str, t_token **lst, int *a, int *b);


// Parsing/tokenizer/ft_str_tok.c
int	ft_prt(char *str, t_token **lst, int *a, int *b);
int	if_validp(char *str);
t_token	*ft_strtok(char *str);
void	ft__strtok(char *str, t_token **lst, int *a, int *b);

// Parsing/tokenizer/ft_red_quote.c
void	ft_squotes(char *str, t_token **lst, int *a, int *b);
void	ft_dquotes(char *str, t_token **lst, int *a, int *b);
void	ft_reout(char *str, t_token **lst, int *a, int *b);
void	ft_rein(char *str, t_token **lst, int *a, int *b);

// utils
// utils/ft_prmpt.c
void	ft_prompt(void);
// utils/ft_history.c
int	ft_add_history(char *str);

// utils/ft_redirect.c
int	ft_voperator(char*str, char re);
int	ft_validouble(char *str, char re);
// utils/ft_token.c
t_token	*ft_add_token(char *str, int type);
t_token	*ft_getlast(t_token *lst);
void	ft_token_addback(t_token **lst, t_token *new);
void	ft_token_addfront(t_token **lst, t_token *new);
void	ft_free_token(t_token **t);

// utils/ft_history.c
void	ft_exit(char * msg, int stat);
int	ft_add_history(char *str);

#endif
