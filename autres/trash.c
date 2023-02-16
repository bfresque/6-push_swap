typedef struct s_pile
{
	long			data;
	struct s_pile	*next;
	struct s_pile	*pile_a;
	struct s_pile	*pile_b;
}				t_pile;

void	ft_put_in_pile(int ac, char **av, t_pile *pile)
{
	int		i;
	int		j;
	long	cur;

	i = 1;
	j = 0;
	cur = 0;
	while (i < ac)
	{
		cur = ft_atoi(av[i]);
		pile->pile_a = ft_add_at_pile(pile->pile_a, cur, j);
		i++;
		j++;
	}
	check_int(pile);
}

long	ft_last_cell(t_pile *pile)
{
	if (pile == NULL)
		return (36);
	while (pile->next != NULL)
	{
		pile = pile->next;
	}
	return (pile->data);
}


int	main(int ac, char **av)
{
	t_pile	pile;

	pile.pile_a = NULL;

	ft_put_in_pile(ac, av, &pile);

	printf("%d", ft_last_cell(&pile));
}
