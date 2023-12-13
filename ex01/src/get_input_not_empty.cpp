/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input_not_empty.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:28:03 by psalame           #+#    #+#             */
/*   Updated: 2023/12/13 18:38:13 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

bool	get_input_not_empty(std::string input_msg, std::string *input_res)
{
	do
	{
		std::cout << input_msg;
		if (!std::getline(std::cin, *input_res))
			return (false);
		if ((*input_res).size() == 0)
			std::cout << "Input must not be empty." << std::endl << std::endl;
	} while ((*input_res).size() == 0);
	return (true);
}
