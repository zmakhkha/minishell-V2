/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:06:26 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/02 13:43:57 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"


t_token	*ft_add_token(char *str, int type)
{
	t_token	*tmp;

	if (!str)
		return (NULL);
	tmp = (t_token *) malloc(sizeof(t_token));
	if (!tmp)
		ft_exit("Token allocation failed", 1);
	tmp->str = str;
	tmp->type = type;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

t_token	*ft_getlast(t_token *lst)
{
	t_token	*tmp;

	tmp = NULL;
	if (lst)
	{
		tmp = lst;
		while (tmp->next)
			tmp = tmp->next;
	}
	return (tmp);
}

void	ft_token_addback(t_token **lst, t_token *new)
{
	t_token	*pos;

	if (*lst == NULL)
		*lst = new;
	else
	{
		pos = *lst;
		while (pos -> next != NULL)
			pos = pos -> next;
		pos -> next = new;
        new -> prev = pos;
	}
}

void	ft_token_addfront(t_token **lst, t_token *new)
{
	t_token	*pos;

	if (*lst == NULL)
		*lst = new;
	else
	{
		pos = *lst;
		while (pos -> prev != NULL)
			pos = pos -> prev;
		pos -> prev = new;
		new -> next = pos;
	}
}

void	ft_free_token(t_token **t)
{
	t_token	*tmp;

	if (t && *t)
	{
		if ((*t)-> next == NULL)
		{
			if ((*t)->str)
				free((*t)->str);
			free (*t);
		}
		else
		{
			while ((*t)->next)
			{
				tmp = *t;
				(*t) = (*t)->next;
				if (tmp->str)
					free(tmp->str);
				free (tmp);
			}
			if ((*t)->str)
				free((*t)->str);
			free ((*t));
		}
	}
}

// void	ft_delete_next_token(t_token **t)
// {
// 	t_token	*tmp;
// 	t_token	*rep;

// 	if (t && *t && (*t)->next)
// 	{
// 		tmp = *t;
// 		rep = tmp->next;
// 		tmp->next = rep->next;
// 		free (rep->str);
// 		free (rep);
// 	}
// }
