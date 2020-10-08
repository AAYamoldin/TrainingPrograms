/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjennine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 10:20:13 by mjennine          #+#    #+#             */
/*   Updated: 2020/03/10 11:38:07 by mjennine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_capitalize(char *str)
{
	int i;

	i = 1;
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
	else if (str[0] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!(str[i - 1] >= 48 && str[i - 1] <= 57)
				&& !(str[i - 1] >= 'a' && str[i - 1] <= 'z')
				&& !(str[i - 1] >= 'A' && str[i - 1] <= 'Z')
				&& (str[i] >= 'a' && str[i] <= 'z'))
			str[i] = str[i] - 32;
		else if (((str[i - 1] >= 'A' && str[i - 1] <= 'Z')
				|| (str[i - 1] >= 'a' && str[i - 1] <= 'z')
				|| (str[i - 1] >= 48 && str[i - 1] <= 57))
				&& (str[i] >= 'A' && str[i] <= 'Z'))
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
