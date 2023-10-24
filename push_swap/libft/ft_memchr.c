/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abali <abali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:10:03 by abali             #+#    #+#             */
/*   Updated: 2023/10/24 19:10:05 by abali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	char			*str_val;
	unsigned int	i;

	str_val = (char *)str;
	i = 0;
	while (i < len)
	{
		if (str_val[i] == c)
		{
			return ((void *)(str + i));
		}
		i++;
	}
	return (NULL);
}
