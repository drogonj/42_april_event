
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void free_tab(char **tab)
{
    for (int i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
    tab = 0;
}

int	ft_strlen(char *str)
{
    int	n;

    n = 0;
    while (*(str + n))
    {
        n++;
    }
    return (n);
}

int	is_charset(char ch, char *charset)
{
    int	i;

    i = 0;
    while (charset[i])
    {
        if (ch == charset[i])
            return (1);
        i++;
    }
    return (0);
}

int	calc_malloc(char *str, char *charset)
{
    int	i;
    int	res;

    i = 1;
    res = 1;
    while (str[i])
    {
        if (is_charset(str[i], charset) == 1
            && is_charset(str[i - 1], charset) == 0
            && str[i + 1] != '\0')
            res++;
        i++;
    }
    return (res + 1);
}

char	*get_tab(char *str, char *charset, int indice)
{
    char	*tab;
    int		len;
    int		i;
    int		j;

    j = 0;
    len = 0;
    i = indice;
    while (str[i] && is_charset(str[i], charset) != 1)
    {
        len++;
        i++;
    }
    tab = (char *)malloc(len + 1);
    i = indice;
    while (str[i] && is_charset(str[i], charset) != 1)
    {
        tab[j] = str[i];
        j++;
        i++;
    }
    tab[j] = '\0';
    return (tab);
}

char	**ft_split(char *str, char *charset)
{
    int		i;
    int		j;
    char	**result;

    result = malloc(sizeof(char *) * calc_malloc(str, charset) + 1);
    i = 0;
    j = 0;
    while (str[i])
    {
        while (str[i] && is_charset(str[i], charset) == 1)
            i++;
        if (i < ft_strlen(str))
        {
            result[j] = get_tab(str, charset, i);
        }
        while (str[i] && is_charset(str[i], charset) == 0)
            i++;
        j++;
    }
    result[j] = 0;
    return (result);
}

int longest_word_in_tab(char *str)
{
    int len = 0;
    int max_len = 0;
    int n = strlen(str);

    for (int i = 0; i < n; i++)
    {
        if (!is_charset(str[i], " \t\n\r\f\v"))
            len++;
        else
        {
            if (len > max_len)
                max_len = len;
            len = 0;
        }
    }
    if (len > max_len)
        max_len = len;
    return max_len;
}

int longest_word_in_argv(char **argv)
{
    int longest_length = 0;
    int length;

    for (int i = 1; argv[i]; i++)
    {
        length = longest_word_in_tab(argv[i]);
        if (length > longest_length)
            longest_length = length;
    }
    return (longest_length);
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return(0);

    int max_len = longest_word_in_argv(argv);
    int count;
    char **act = 0;

    for (int i = 0; i < max_len + 2; i++)
        printf("*");
    printf("\n");

    for (int i = 1; argv[i]; i++)
    {
        act = ft_split(argv[i], " \t\n\r\f\v");
        for (int j = 0; act[j]; j++)
        {
            count = 0;
            count += printf("*");
            count += printf("%s", act[j]);
            while (count <= max_len)
                count += printf(" ");
            printf("*\n");
        }
        free_tab(act);
    }

    for (int i = 0; i < max_len + 2; i++)
        printf("*");
    printf("\n");

    return (0);
}