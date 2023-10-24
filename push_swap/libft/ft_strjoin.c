/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abali <abali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:11:30 by abali             #+#    #+#             */
/*   Updated: 2023/10/24 19:11:33 by abali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*new_str;
	int		str1_len;
	int		str2_len;
	int		new_len;

	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	new_len = str1_len + str2_len + 1;
	new_str = malloc(new_len);
	ft_memmove(new_str, str1, str1_len);
	ft_memmove((new_str + str1_len), str2, str2_len);
	new_str[new_len - 1] = '\0';
	return (new_str);
}
