int	ft_pile_size(t_pile *pile)
{
	int	i;

	i = 0;
	while (pile)
	{
		pile = pile->next;
		i++;
	}
	return (i);
}

int	ft_first_cell(t_pile *pile)
{
	if (pile == NULL)
		return (0);
	return (pile->data);
}

int	ft_last_cell(t_pile *pile)
{
	if (pile == NULL)
		return (0);
	while (pile->next != NULL)
	{
		pile = pile->next;
	}
	return (pile->data);
}

void	ft_push_a(t_pile *pile)
{
	int		tmp;
	t_pile	*position;

	position = NULL;
	position = pile->pile_a;
	tmp = ft_first_cell(pile->pile_a);
	pile->pile_b = ft_add_at_pile(pile->pile_b, tmp, 0);
	pile->pile_a = pile->pile_a->next;
	free(position);
}

void	ft_push_b(t_pile *pile)
{
	int		tmp;
	t_pile	*position;

	position = NULL;
	position = pile->pile_b;
	tmp = ft_first_cell(pile->pile_b);
	pile->pile_a = ft_add_at_pile(pile->pile_a, tmp, 0);
	pile->pile_b = pile->pile_b->next;
	free(position);
}

void	ft_swap_a(t_pile *pile)
{
	t_pile	*tmp;

	tmp = NULL;
	tmp = pile->pile_a;
	pile->pile_a = tmp->next;
	tmp->next = pile->pile_a->next;
	pile->pile_a->next = tmp;
}

void	ft_swap_b(t_pile *pile)
{
	t_pile	*tmp;

	tmp = NULL;
	tmp = pile->pile_b;
	pile->pile_b = tmp->next;
	tmp->next = pile->pile_b->next;
	pile->pile_b->next = tmp;
}

void	ft_ss(t_pile *pile)
{
	ft_swap_a(pile);
	ft_swap_b(pile);
}

void	ft_rotate_a(t_pile *pile)
{
	int		first_value;
	int		last_pos;
	t_pile	*free_pile;

	first_value = ft_first_cell(pile->pile_a);
	free_pile = pile->pile_a;
	pile->pile_a = pile->pile_a->next;
	last_pos = ft_pile_size(pile->pile_a);
	pile->pile_a = ft_add_at_pile(pile->pile_a, first_value, last_pos);
	free(free_pile);
}

void	ft_rotate_b(t_pile *pile)
{
	int		first_value;
	int		last_pos;
	t_pile	*free_pile;

	first_value = ft_first_cell(pile->pile_b);
	free_pile = pile->pile_b;
	pile->pile_b = pile->pile_b->next;
	last_pos = ft_pile_size(pile->pile_b);
	pile->pile_b = ft_add_at_pile(pile->pile_b, first_value, last_pos);
	free(free_pile);
}

void	ft_rr(t_pile *pile)
{
	ft_rotate_a(pile);
	ft_rotate_b(pile);
}

void	ft_reverse_rotate_a(t_pile *pile)
{
	int	last_value;

	last_value = ft_last_cell(pile->pile_a);
	pile->pile_a = ft_add_at_pile(pile->pile_a, last_value, 0);
	pile->pile_a = ft_delete_last_cell(pile->pile_a);
}

void	ft_reverse_rotate_b(t_pile *pile)
{
	int	last_value;

	last_value = ft_last_cell(pile->pile_b);
	pile->pile_b = ft_add_at_pile(pile->pile_b, last_value, 0);
	pile->pile_b = ft_delete_last_cell(pile->pile_b);
}

void	ft_rrr(t_pile *pile)
{
	ft_reverse_rotate_a(pile);
	ft_reverse_rotate_b(pile);
}

