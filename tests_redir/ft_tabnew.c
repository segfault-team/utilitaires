/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:45:41 by lfabbro           #+#    #+#             */
/*   Updated: 2017/02/04 13:10:58 by kboddez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		**ft_tabnew(size_t size)
{
	char	**new;
	size_t	i;

	i = -1;
	if (size == 0 || (new = malloc(sizeof(new) * (size + 1))) == NULL)
		return (NULL);
	while (++i <= size)
		new[i] = NULL;
	return (new);
}
