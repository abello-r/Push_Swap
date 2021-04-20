#include "swap.h"

int adn_size(char **adn)
{
    int i;

    i = 0;
    while (adn[i])
        i++;
    return(i);
}

void free_adn(char **adn)
{
    int i;

    i = -1;
    while (adn[++i])
        free(adn[i]);
    free(adn);
}

int adn_control(t_global *g, char **argv, int i, int j)
{
    int *numbers;
    char **adn;

    while (argv[++i])
    {
        adn = ft_split(argv[i], ' ');
        j += adn_size(adn);
        free_adn(adn);
    }
    numbers = (int *)malloc(sizeof(int) * j);
    if (!numbers)
        return(1);
    i = 0;
    g->len = -1;
    while(argv[++i])
    {
        j = -1;
        adn = ft_split(argv[i], ' ');
        while (adn[++j])
            numbers[++g->len] = ft_atoi(adn[j]);
        free_adn(adn);
    }
    fill_list(g, numbers);
    return(0);
}