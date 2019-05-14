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
	new->attribut = NULL;
	new->champ = 0;
	new->display = NULL;
	new->next = NULL;
	if (!(next = (t_conv*)malloc(sizeof(t_conv))))
		return (NULL);
	next->type = 's';
	next->f = ft_str;
	next->attribut = NULL;
	next->display = NULL;
	next->champ = 0;
	next->next = NULL;
	ft_conv_lst_add(&new, next);
	if (!(next = (t_conv*)malloc(sizeof(t_conv))))
		return (NULL);
	next->type = 'p';
	next->f = ft_pointer;
	next->display = NULL;
	next->attribut = NULL;
	next->champ = 0;
	next->next = NULL;
	ft_conv_lst_add(&new, next);
	if (!(next = (t_conv*)malloc(sizeof(t_conv))))
		return (NULL);
	next->type = 'd';
	next->f = ft_conv;
	next->display = ft_putnbr;
	next->attribut = NULL;
	next->champ = 0;
	next->next = NULL;
	ft_conv_lst_add(&new, next);
	if (!(next = (t_conv*)malloc(sizeof(t_conv))))
		return (NULL);
	next->type = 'i';
	next->f = ft_conv;
	next->display = ft_putnbr;
	next->attribut = NULL;
	next->champ = 0;
	next->next = NULL;
	ft_conv_lst_add(&new, next);
	if (!(next = (t_conv*)malloc(sizeof(t_conv))))
		return (NULL);
	next->type = 'o';
	next->f = ft_conv_2;
	next->display = ft_calc_octa;
	next->attribut = NULL;
	next->champ = 0;
	next->next = NULL;
	ft_conv_lst_add(&new, next);
	if (!(next = (t_conv*)malloc(sizeof(t_conv))))
		return (NULL);
	next->type = 'u';
	next->f = ft_conv_2;
	next->display = ft_putnbr;
	next->attribut = NULL;
	next->champ = 0;
	next->next = NULL;
	ft_conv_lst_add(&new, next);
	if (!(next = (t_conv*)malloc(sizeof(t_conv))))
		return (NULL);
	next->type = 'x';
	next->f = ft_conv_2;
	next->display = ft_calc_long_hexa;
	next->attribut = NULL;
	next->champ = 0;
	next->next = NULL;
	ft_conv_lst_add(&new, next);
	if (!(next = (t_conv*)malloc(sizeof(t_conv))))
		return (NULL);
	next->type = 'X';
	next->f = ft_conv_2;
	next->display = ft_calc_long_hexam;
	next->attribut = NULL;
	next->champ = 0;
	next->next = NULL;
	ft_conv_lst_add(&new, next);
	if (!(next = (t_conv*)malloc(sizeof(t_conv))))
		return (NULL);
	next->type = 'f';
	next->f = ft_conv_f;
	next->display = NULL;
	next->attribut = NULL;
	next->champ = 0;
	next->next = NULL;
	ft_conv_lst_add(&new, next);
	if (!(next = (t_conv*)malloc(sizeof(t_conv))))
		return (NULL);
	next->type = '%';
	next->f = ft_conv_spe;
	next->display = NULL;
	next->attribut = NULL;
	next->champ = 0;
	next->next = NULL;
	ft_conv_lst_add(&new, next);
	return (new);
}