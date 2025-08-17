/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:13:25 by lvargas-          #+#    #+#             */
/*   Updated: 2025/08/17 19:52:44 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strncpy(char *dest, const char *src, int n)
{
	int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static size_t	ft_count(long n)
{
	size_t	result;

	result = 0;
	if (n < 0)
	{
		n *= -1;
		result++;
	}
	if (n == 0)
	{
		result++;
		return (result);
	}
	while (n > 0)
	{
		n = n / 10;
		result++;
	}
	return (result);
}

static char	*ft_create_number(char *ptr, long num)
{
	int	i;
	int	end;

	end = ft_count(num);
	i = ft_count(num) - 1;
	if (num == 0)
	{
		ptr[0] = '0';
	}
	if (num < 0)
	{
		num *= -1;
		ptr[0] = '-';
		i = ft_count(num);
		end = ft_count(num) + 1;
	}
	while (num > 0)
	{
		ptr[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}
	ptr[end] = '\0';
	return (ptr);
}

char	*ft_itoa(int n)
{
	long	num;
	char	*ptr;

	num = (long)n;
	ptr = (char *)malloc((ft_count(num) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ptr = ft_create_number(ptr, num);
	return (ptr);
}

size_t	get_width(const char *s)
{
	int	len;

	len = 0;
	if (s == NULL)
		return (0);
	while (*s && *s != '\0' && *s != '\n')
	{
		len++;
		s++;
	}
	return (len);
}
