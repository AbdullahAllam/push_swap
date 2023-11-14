/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abali <abali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:11:13 by abali             #+#    #+#             */
/*   Updated: 2023/10/24 19:11:16 by abali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*letter;
	int		i;

	letter = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			letter = (char *)(str + i);
			return (letter);
		}
		i++;
	}
	if (str[i] == c)
		return ((char *)(str + i));
	return (NULL);
}
