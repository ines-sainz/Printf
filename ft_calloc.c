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

/**
 * @brief Allocates memory for an array and initializes all bytes to zero.
 * 
 * This function allocates memory for an array of `count` elements of `size`
 * bytes each and sets all allocated bytes to zero. If `count` or `size` is
 * too large, it returns NULL to avoid overflow.
 * 
 * @param count Number of elements to allocate.
 * @param size Size of each element in bytes.
 * 
 * @return Pointer to the allocated memory initialized to zero, or NULL on 
 *         failure.
 */
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
