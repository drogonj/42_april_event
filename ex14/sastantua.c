
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int all_digit(char *arg)
{
    int i = 0;

    if (!arg)
        return (-1);
    while (arg[i])
    {
        if (!isdigit(arg[i]))
            return (-1);
        i++;
    }
    return (0);
}

int *get_bases_width(int size)
{
    int *result = malloc(size * sizeof(int));
    int act = 1;
    int n = 12;
    int bool = 2;

    result[0] = 7;
    while (act < size)
    {
        result[act] = result[act - 1] + n;
        n += bool;
        if (bool == 2)
            bool = 4;
        else
            bool = 2;
        act++;
    }
    return (result);
}

void draw_spaces(int *bases_width, int width, int size, int act)
{
    for (int i = 0; i < (bases_width[size - 1] - width) / 2; i++)
        printf(" ");
}

int get_door_dimensions(int arg)
{
    if (arg % 2)
        return (arg);
    else
        return (arg - 1);
}

void draw_line(int width, int stage, int size, int line, int door_width, int door_height)
{
    printf("/");
    for (int i = 0; i < width - 2; i++)
    {
        if (stage == size && i >= (width - door_width - 1) / 2 && i < (width + door_width - 1) / 2 && line >= stage + 2 - door_height)
        {
            if (line == stage - 1 && i == (width + door_width) / 2 - 3 && door_width >= 5)
                printf("$");
            else
                printf("|");
        }
        else
        {
            printf("*");
        }
    }
    printf("\\\n");
}


void sastantua(int *bases_width, int size, int stage)
{
    int width = 1;
    int i;
    int door_width = get_door_dimensions(size);
    int door_height = get_door_dimensions(door_width);

    while (++stage <= size)
    {
        i = 0;
        while (i < stage + 2)
        {
            width += 2;
            draw_spaces(bases_width, width, size, stage);
            draw_line(width, stage, size, i, door_width, door_height);
            i++;
        }
        width += (2 * ((stage - 1) / 2)) + 4;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2 || all_digit(argv[1]) == -1)
    {
        printf("Bad arguments\n");
        return (1);
    }
    int size = atoi(argv[1]);
    int stage = 0;
    int *bases_width = get_bases_width(size);

    sastantua(bases_width, size, stage);

    free(bases_width);
    return (0);
}
