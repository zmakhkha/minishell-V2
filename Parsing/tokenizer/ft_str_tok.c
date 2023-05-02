/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tok.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:31:49 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/02 14:06:02 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

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

t_token	*ft_strtok(char *str)
{
	int		i;
	int		j;
	char	*tmp;
	t_token	*lst;

	lst = NULL;
    j = 0;
	i = 0;
	tmp = NULL;
    tmp = ft_strtrim(str, " ");
	if (!tmp)
	{
		g_status = ERR;
		return (NULL);
	}
    while (tmp[i] && g_status == SUCC)
    {
        i = j;
        if (tmp[j] == ' ')
            ft_space(tmp, &lst,&i, &j);
        else if (tmp[j] && tmp[j] == '"')
            ft_dquotes(tmp, &lst,&i, &j);
        else if (tmp[j] && tmp[j] == '\'')
            ft_squotes(tmp, &lst,&i, &j);
		else if (tmp[j] && tmp[j] == '(')
			ft_prt(tmp, &lst,&i, &j);
		else
			ft__strtok(str, &lst, &i, &j);
    }
	return (lst);
}

void	ft__strtok(char *str, t_token **lst, int *a, int *b)
{
	if (str[*b] && str[*b] == '<')
		ft_rein(str, lst, a, b);
	else if (str[*b] && str[*b] == '>')
		ft_reout(str, lst, a, b);
	else if (ft_isoperator(str[*b]))
		ft_operators(str, lst, a, b);
}