/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgritsen <pgritsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 18:20:50 by pgritsen          #+#    #+#             */
/*   Updated: 2017/11/24 12:54:43 by pgritsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, unsigned char symb)
{
	char	*new;
	size_t	s1_l;
	size_t	s2_l;

	if (!s2 && s1)
		return ((char *)s1);
	else if (!s1 && s2)
		return ((char *)s2);
	else if (!s1 && !s2)
		return (NULL);
	s1_l = ft_strlen(s1);
	s2_l = ft_strnlen(s2, symb);
	if (!(new = (char *)malloc((s1_l + s2_l + 1) * sizeof(char))))
		return (NULL);
	*new = 0;
	ft_strlcat(new, s1, s1_l + s2_l + 1);
	ft_strncat(new, s2, s2_l);
	return (new);
}
