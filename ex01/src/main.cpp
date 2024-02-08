/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:28:47 by psalame           #+#    #+#             */
/*   Updated: 2024/02/08 13:12:51 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	askCommand(PhoneBook *phonebook)
{
	std::string	command;

	std::cout << "Enter command : ";
	if (!std::getline(std::cin, command))
	{
		std::cout << "EXIT" << std::endl;
		return (true);
	}

	if (command == "ADD")
	{
		add_contact(phonebook);
		std::cout << std::endl << std::endl;
	}
	else if (command == "SEARCH")
	{
		search_contact(phonebook);
		std::cout << std::endl;
	}
	else if (command == "EXIT")
		return (true);
	else
	{
		if (command.size() == 0)
			std::cout << NO_COMMAND_ERROR;
		else
			std::cout << COMMAND_NOT_FOUND_ERROR;
	}
	return (false);
}

int	main(void)
{
	PhoneBook	phonebook;
	bool		running;

	std::cout << TITLE << std::endl << std::endl;

	running = true;
	while (running)
	{
		if (askCommand(&phonebook))
			running = false;
	}
	return (0);
}