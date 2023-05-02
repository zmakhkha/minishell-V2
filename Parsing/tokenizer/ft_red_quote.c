/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red_quote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:26:11 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/02 14:06:02 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

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
			g_status = ERR;
		}
	}
}

void	ft_squotes(char *str, t_token **lst, int *a, int *b)
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
			g_status = ERR;
		}
	}
}

void	ft_rein(char *str, t_token **lst, int *a, int *b)
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
		g_status = ERR;
	}
}

void	ft_reout(char *str, t_token **lst, int *a, int *b)
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
		g_status = ERR;
	}
}
