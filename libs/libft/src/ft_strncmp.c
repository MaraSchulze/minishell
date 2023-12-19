/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbock <fbock@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:45:50 by fbock             #+#    #+#             */
/*   Updated: 2023/12/19 09:31:23 by fbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	while (num > 0 && *str1 == *str2 && *str1 != '\0' && *str2 != '\0')
	{
		str1++;
		str2++;
		num--;
	}
	if (num == 0)
		return (0);
	return ((unsigned char)*str1 - (unsigned char)*str2);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 == *str2 && *str1 != '\0' && *str2 != '\0')
	{
		str1++;
		str2++;
	}
	return ((unsigned char)*str1 - (unsigned char)*str2);
}
