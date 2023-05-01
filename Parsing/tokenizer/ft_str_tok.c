/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:31:49 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/01 16:16:00 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	ft_space(char *str, t_token **lst, int *a, int *b)
{
	char	*s;

	s = NULL;
	while (str[(*b)] && ft_is_whitespace(str[*b]))
		*b += 1;
	s = ft_substr(str, *a, *b - *a);
	ft_token_addback(lst, ft_add_token(s, SPACE));
}

void	ft_dquotes(char *str, t_token **lst, int *a, int *b)
{
	int		len;
	char	*s;

	s = NULL;
	len = ft_strlen(str);
	if (str[*b] && str[*b] == '"')
	{
		*b += 1;
		while (str[*b] && str[*b] != '"')
			*b += 1;
		if (str[*b] == '"')
		{
			s = ft_substr(str, *a, *b - *a + 1);
			ft_token_addback(lst, ft_add_token(s, D_QUOTE));
			*b += 1;
		}
		else if (*b == len)
		{
			ft_free_token(lst);
			printf("Double Quotes error !!\n");
			status = ERR;
		}
	}
}

int	ft_squotes(char *str, t_token **lst, int *a, int *b)
{
	int		len;
	char	*s;

	s = NULL;
	len = ft_strlen(str);
	if (str[*b] && str[*b] == '\'')
	{
		*b += 1;
		while (str[*b] && str[*b] != '\'')
			*b += 1;
		if (str[*b] == '\'')
		{
			s = ft_substr(str, *a, *b - *a + 1);
			ft_token_addback(lst, ft_add_token(s, S_QUOTE));
			*b += 1;
		}
		else if (*b == len)
		{
			ft_free_token(lst);
			printf("Signle Quotes error !!\n");
			status = ERR;
		}
	}
}

int	ft_rein(char *str, t_token **lst, int *a, int *b)
{
	char	*s;	

	(void)a;
	s = NULL;
	if (ft_voperator(str + *b, '<'))
	{
		if (ft_validouble(str + *b, '<'))
		{	
			s = ft_substr(str, *b, 2);
			ft_token_addback(lst, ft_add_token(s, HDOC));
			*b += 2;
		}
		else if (str[*b] == '<')
		{
			s = ft_substr(str, *b, 1);
			ft_token_addback(lst, ft_add_token(s, RE_IN));
			*b += 1;
		}
	}
	else
	{
		printf("Operators 3 Error !!");
		status = ERR;
	}
}

int	ft_reout(char *str, t_token **lst, int *a, int *b)
{
	char	*s;	

	(void)a;
	s = NULL;
	if (ft_voperator(str + *b, '<'))
	{
		if (ft_validouble(str + *b, '<'))
		{	
			s = ft_substr(str, *b, 2);
			ft_token_addback(lst, ft_add_token(s, APPEND));
			*b += 2;
		}
		else if (str[*b] == '<')
		{
			s = ft_substr(str, *b, 1);
			ft_token_addback(lst, ft_add_token(s, RE_OUT));
			*b += 1;
		}
	}
	else
	{
		printf("Operators 3 Error !!");
		status = ERR;
	}
}

int	ft_prt(char *str, t_token **lst, int *a, int *b)
{
	int		len;
	int		ret;
	char	*s;

	ret = SUCC;
	s = NULL;
	len = ft_strlen(str);
	if (str[*b] && (str[*b] == '(' && if_validp(str + *b) != -1))
	{
		*b += if_validp(str + *b);
		if (str[*b] == ')')
		{
			s = ft_substr(str, *a + 1, *b - *a -1);
			ft_token_addback(lst, ft_add_token(s, SUBSHELL));
			*b += 1;
		}
		else if (*b == len)
		{
			ft_free_token(lst);
			printf("SUBSHELL Quotes error !!\n");
			ret = ERR;
		}
	}
	else
	{
		ft_free_token(lst);
		printf("SUBSHELL errors !!\n");
		ret = ERR;
	}
	return (ret);
}

int	if_validp(char *str)
{
	int	open;
	int	i;

	i = 0;
	open = 1;
	while (str[++i])
	{
		if (str[i] == '(')
		{
			open++;
			if_validp(str + i +1);
		}
		if (str[i] == ')')
		{	
			open--;
			if (!open)
				return (i);
		}
	}
	if (!open)
		return (i);
	return (-1);
}

int ft_isoperator(char o)
{
	return(o == '|' || o == '&');
}


int	ft_operators(char *str, t_token **lst, int *a, int *b)
{
	char	*s;

	s = NULL;
	if (ft_voperator(str + *b, '|'))
	{
		ft__operators(str, lst, a, b);
	}
	else if (ft_voperator(str + *b, '&'))
	{
		if (ft_validouble(str + *b, '&'))
		{
			s = ft_substr(str, *a, 2);
			ft_token_addback(lst, ft_add_token(s, AND));
			*b += 2;
		}
		else if (str[*b] == '&')
		{
			printf("& error !!\n");
			status = SUCC;
		}
	}
	else
	{
		printf("PIPE or OR error !!\n");
		status = ERR;
	}
}

void	ft__operators(char *str, t_token **lst, int *a, int *b)
{
	char	*s;

	s = NULL;
	if (ft_validouble(str + *b, '|'))
	{
		s = ft_substr(str, *a, 2);
		ft_token_addback(lst, ft_add_token(s, OR));
		*b += 2;
	}
	else if (str[*b] == '|')
	{
		s = ft_substr(str, *a, 1);
		ft_token_addback(lst, ft_add_token(s, PIPE));
		*b += 1;
	}
}

int	ft_isword(char o)
{
	return(o != '<' && o != '>' && o != '|' && o != ';' && o != '(' && o != '\'' && o != '"');
}

t_token	*ft_strtok(char *str)
{
	int		i;
	int		j;
	char	*tmp;
	t_token	*lst;

    j = 0;
    tmp = ft_strtrim(str, " ");
	if (!tmp)
	{
		status = ERR;
		return (NULL);
	}
    while (tmp[i] && status == SUCC)
    {
        i = j;
        if (tmp[i] == ' ')
            ft_space(tmp, &lst,&i, &j);
        else if (tmp[i] && tmp[i] == '"')
            ft_dquotes(tmp, &lst,&i, &j);
        else if (tmp[i] && tmp[i] == '\'')
            ft_squotes(tmp, &lst,&i, &j);
		else if (tmp[i] && tmp[i] == '(')
			ft_prt(tmp, &lst,&i, &j);
		else
			ft__strtok(str, &lst, &i, &j);
    }		
}

int	ft__strtok(char *str, t_token **lst, int *a, int *b)
{
	if (str[*b] && str[*b] == '<')
		ft_rein(str, lst, a, b);
	else if (str[*b] && str[*b] == '>')
		ft_reout(str, lst, a, b);
	else if (ft_isoperator(str[*b]))
		ft_operators(str, lst, a, b);
	else
}