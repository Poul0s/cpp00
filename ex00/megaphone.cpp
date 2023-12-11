/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:44:56 by psalame           #+#    #+#             */
/*   Updated: 2023/12/11 17:45:43 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	ft_printupper(char *str)
{
	int	i;

	for (i = 0; str[i] != 0; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - ' ';
	}
	std::cout << str;
}

int	main(int ac, char **av)
{
	int	i;

	for (i = 1; i < ac; i++) 
		ft_printupper(av[i]);
	std::cout << "\n";
	return (0);
}
