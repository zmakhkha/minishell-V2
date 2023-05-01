/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prmpt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:24:50 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/05/01 13:24:59 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

// Add a command history
void	ft_prompt(void)
{
	char	*str;
	t_token	*t;

	t = NULL;
	while (1)
	{
		usleep(100);
		str = readline("minishell $ ");
		if (str == NULL)
			break ;
		ft_add_history(str);
		t = ft_strtok(str);
		if (t)
			ft_main_lexer(t);
			// printf("%s", t->str);
		free (str);
		ft_free_token(&t);
	}
}
