/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:09:59 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/01 15:11:02 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	ft_vreerator(char*str, char re)
{
	int	i;

	i = 0;
	if (str[i] && str[i + 1] && str [i + 2])
	{
		if (str[i] == re && str[i + 1] == re && str[i + 2] == re)
			return (0);
	}
	if (str[i] && str[i + 1])
	{
		if (str[i] == re || str[i + 1] == re)
			return (1);
	}
	if (str[i])
	{
		if (str[i] == '&')
			return (0);
		else if (str[i] == re)
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
		if (str[i] == re && str[i + 1] == re)
			return (1);
		else
			return (0);
	}
	return (0);
}