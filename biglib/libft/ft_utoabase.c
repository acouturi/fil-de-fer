/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <acouturi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 16:33:19 by acouturi          #+#    #+#             */
/*   Updated: 2018/02/15 15:57:12 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/libft.h"

static int	ft_lennbr(unsigned long long nbr, int base)
{
	int		i;

	i = 0;
	if (!nbr)
		return (1);
	while (nbr > 0)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

char		*ft_utoabase(unsigned long long nbr, int base, int mod)
{
	char	*str;
	int		len;
	char	*valbase;

	len = ft_lennbr(nbr, base);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		ft_puterror("probleme malloc");
	valbase = mod == 0 ? "0123456789abcdef" : "0123456789ABCDEF";
	str[len--] = 0;
	if (!nbr)
		str[0] = '0';
	while (nbr > 0)
	{
		str[len--] = valbase[nbr % base];
		nbr /= base;
	}
	return (str);
}
