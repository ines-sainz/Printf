/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 09:42:15 by isainz-r          #+#    #+#             */
/*   Updated: 2024/10/18 12:38:36 by isainz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*pointer;
	size_t	i;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (0);
	pointer = malloc(count * size);
	if (!pointer)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		pointer[i] = '\0';
		i++;
	}
	return ((void *)pointer);
}
