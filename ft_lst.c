#include "printf.h"

void    ft_free_lst(t_conv *list)
{
    free(list);
}

void	ft_conv_lst_add(t_conv **new, t_conv *next)
{
	t_conv *tmp;

	if (next)
	{
		tmp = *new;
		if (tmp == NULL)
			tmp = next;
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = next;
		} 
	}
}

t_conv	*ft_create_lst(void)
{
	t_conv *new;
	t_conv *next;

	next = NULL;
	if (!(new = (t_conv*)malloc(sizeof(t_conv))))
		return (NULL);
    new->type = 'c';
	new->f = ft_char;
	new->display = NULL;
	new->next = NULL;
	if (!(next = (t_conv*)malloc(sizeof(t_conv))))
		return (NULL);
	next->type = 's';
	next->f = ft_str;
	new->display = NULL;
	next->next = NULL;
	ft_conv_lst_add(&new, next);
	if (!(next = (t_conv*)malloc(sizeof(t_conv))))
		return (NULL);
	next->type = 'p';
	next->f = ft_pointer;
	new->display = NULL;
	next->next = NULL;
	ft_conv_lst_add(&new, next);
	if (!(next = (t_conv*)malloc(sizeof(t_conv))))
		return (NULL);
	next->type = 'd';
	next->f = ft_conv;
	next->display = ft_putnbr;
	next->next = NULL;
	ft_conv_lst_add(&new, next);
	if (!(next = (t_conv*)malloc(sizeof(t_conv))))
		return (NULL);
	next->type = 'i';
	next->f = ft_conv;
	next->display = ft_putnbr;
	next->next = NULL;
	ft_conv_lst_add(&new, next);
	if (!(next = (t_conv*)malloc(sizeof(t_conv))))
		return (NULL);
	next->type = 'o';
	next->f = ft_conv;
	next->display = ft_calc_octa;
	next->next = NULL;
	ft_conv_lst_add(&new, next);
	return (new);
}