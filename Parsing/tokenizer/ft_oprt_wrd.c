/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oprt_wrd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:24:42 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/02 14:14:08 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"


int ft_isoperator(char o)
{
	return(o == '|' || o == '&');
}


void	ft_operators(char *str, t_token **lst, int *a, int *b)
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
			g_status = SUCC;
		}
	}
	else
	{
		printf("PIPE or OR error !!\n");
		g_status = ERR;
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

void	ft_space(char *str, t_token **lst, int *a, int *b)
{
	char	*s;

	s = NULL;
	while (str[(*b)] && (str[*b] == ' '))
		*b += 1;
	s = ft_substr(str, *a, *b - *a);
	ft_token_addback(lst, ft_add_token(s, SPACE));
}

int	ft_voperator(char*str, char re)
{
	int	i;

	i = 0;
	if (str[i] && str[i + 1] && str [i + 2])
	{
		if (str[i] == re && str[i + 1] == re && str[i + 2] ==re)
			return (0);
	}
	if (str[i] && str[i + 1])
	{
		if (str[i] == re || str[i + 1] ==re)
			return (1);
	}
	if (str[i])
	{
		if (str[i] == '&')
			return (0);
		else if (str[i] ==re)
			return (1);
	}
	return (0);
}

int	ft_validouble(char *str, char re)
{
	int	i;

	i = 0;
	if (str[i] && str[i + 1])
	{
		if (str[i] == re && str[i + 1] ==re)
			return (1);
		else
			return (0);
	}
	return (0);
}
