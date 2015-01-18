/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strplit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 23:24:51 by hhismans          #+#    #+#             */
/*   Updated: 2014/12/30 19:23:34 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	char	**bigger_array(char **array, int len)
{
	char	**new_array;

	new_array = (char **)malloc(sizeof(char *) * (len + 1));
	if (array != NULL)
	{
		while (len > 0)
		{
			new_array[len - 1] = array[len - 1];
			len--;
		}
		free(array);
	}
	return (new_array);
}

unsigned int	set_begin_end(char const *s, unsigned int *begin,
		char c, int *i)
{
	int end;

	while (s[*i] && s[*i] == c)
		(*i)++;
	*begin = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	end = *i - 1;
	return (end);
}

char			**ft_strsplit(char const *s, char c)
{
	int				i;
	int				j;
	unsigned int	begin;
	unsigned int	end;
	char			**res;

	begin = 0;
	end = 0;
	res = NULL;
	j = 0;
	i = 0;
	while (s[i])
	{
		end = set_begin_end(s, &begin, c, &i);
		if (!i)
			return (NULL);
		res = bigger_array(res, j);
		res[j] = ft_strsub(s, begin, (size_t) (end - begin + 1));
		j++;
	}
	res = bigger_array(res, j);
	res[j] = NULL;
	return (res);
}
