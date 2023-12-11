/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:28:47 by psalame           #+#    #+#             */
/*   Updated: 2023/12/11 19:39:27 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#define NO_COMMAND_ERROR "This command doesn't exist, please enter one of these commands : 'ADD', 'SEARCH', 'EXIT'.\n\n"

bool	askCommand(PhoneBook *phonebook)
{
	std::string	command;

	std::cout << "Enter command : ";
	std::getline(std::cin, command);
	if (command == "ADD")
		std::cout << "todo add function" << std::endl;  // function ready todo test
	else if (command == "SEARCH")
		std::cout << "todo search function" << std::endl;
	else if (command == "EXIT")
		return (true);
	else
		std::cout << NO_COMMAND_ERROR;
	return (false);
}

int	main(void)
{
	PhoneBook	phonebook;
	bool		running;

	running = true;
	while (running)
	{
		if (askCommand(&phonebook))
			running = false;
	}
	return (0);
}