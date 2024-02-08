/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:44:56 by psalame           #+#    #+#             */
/*   Updated: 2024/02/08 13:08:59 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void	ft_printupper(std::string str)
{
	int	i;

	for (i = 0; str[i] != 0; i++)
		str[i] = toupper(str[i]);
	std::cout << str;
}

int	main(int ac, char **av)
{
	int	i;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (i = 1; i < ac; i++) 
		ft_printupper(av[i]);
	std::cout << "\n";
	return (0);
}
