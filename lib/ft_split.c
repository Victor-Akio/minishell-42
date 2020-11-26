/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqrodri <jaqrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 03:38:36 by jaqrodri          #+#    #+#             */
/*   Updated: 2020/02/15 18:11:32 by jaqrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strbuild(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	cont;

	cont = 0;
	if (!s)
		return (NULL);
	substring = (char *)malloc((len + 1) * sizeof(char));
	if (substring == NULL)
		return (NULL);
	while (cont < len)
	{
		substring[cont] = s[start + cont];
		cont++;
	}
	substring[cont] = '\0';
	return (substring);
}

static int	ft_count_words(const char *s, char c)
{
	char	*f;
	int		i;

	f = (char	*)s;
	i = 0;
	while (*f != '\0')
	{
		if (*f != c)
		{
			while (*f != c && *f != '\0')
			{
				f++;
			}
			i++;
		}
		else
		{
			f++;
		}
	}
	return (i);
}

static void	ft_allocword(char const *s, char c, int count_words,
char **new_word)
{
	char	*a;
	char	*f;
	int		i;
	int		j;

	a = (char *)s;
	i = 0;
	while (i < count_words)
		while (*a != '\0')
		{
			if (*a != c)
			{
				j = 0;
				f = a;
				while (*a != c && *a != '\0')
				{
					j++;
					a++;
				}
				new_word[i++] = ft_strbuild(f, 0, j);
			}
			else
				a++;
		}
	new_word[i] = NULL;
}

char		**ft_split(char const *s, char c)
{
	char	**new_word;
	int		count_words;

	if (!s)
		return (NULL);
	count_words = ft_count_words(s, c);
	new_word = (char **)malloc((count_words + 1) * sizeof(char *));
	if (new_word == NULL)
		return (NULL);
	ft_allocword(s, c, count_words, new_word);
	return (new_word);
}
