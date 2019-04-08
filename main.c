/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:38:25 by yodana            #+#    #+#             */
/*   Updated: 2019/04/01 15:39:15 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int main()
{
	char	*a = "trolol";
	char	b = '~' + 2;
	printf("reel printf: %c\n",'d');
	ft_printf("mine: %c\n",'d');

	printf("reel printf:  %s\n","lol");
	ft_printf("mine:  %s\n","lol");

	printf("reel printf:  caratctere = %c || chaine = %s\n",'d',"lol");
	ft_printf("mine:  caractere = %c || chaine = %s\n",'d',"lol");

	printf("reel printf: pointer -> %p\n",&a);
	ft_printf("mine: pointer -> %p\n",&a);

	printf("reel printf: d -> %d\n",2147483647);
	ft_printf("mine : d -> %d\n",2147483647);

	printf("reel printf: d -> %d\n",0);
	ft_printf("mine : d -> %d\n",0);

	printf("reel printf: d -> %d\n",-1);
	ft_printf("mine : d -> %d\n",-1);

	printf("reel printf: d -> %hhd\n",128);
	ft_printf("mine : d -> %d\n",128);


	return (0);
}