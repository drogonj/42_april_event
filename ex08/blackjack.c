
#include <stdio.h>
#include <string.h>

int is_valid(char *lst, char c)
{
    if (strchr(lst, c) != 0)
        return (1);
    return (0);
}

int add(int total, char c)
{
    if (c >= '2' && c <= '9')
        return (total + (c - '0'));
    else if (c == 'J' || c == 'D' || c == 'K' || c == 'T')
        return (total + 10);
    else if (c == 'A')
    {
        if ((total + 11) > 21)
            return (total + 1);
        else
            return (total + 11);
    }
    return (0);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Invalid number of arguments\n");
        return (1);
    }

    int total = 0;
    char lst[] = "23456789TJDKA";

    for (int i = 0; argv[1][i]; i++)
    {
        if(!is_valid(lst, argv[1][i]))
        {
            printf("Invalid character: '%c'\n", argv[1][i]);
            return (1);
        }
        else
        {
            total = add(total, argv[1][i]);
        }
    }
    if (total != 21)
        printf("%d\n", total);
    else
        printf("Blackjack!\n");
    return (0);
}