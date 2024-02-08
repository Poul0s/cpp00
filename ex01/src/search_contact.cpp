/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_contact.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:21:49 by psalame           #+#    #+#             */
/*   Updated: 2024/02/08 13:14:35 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	print_truncate(std::string value, unsigned long max)
{
	unsigned long	i;

	for (i = 0; i < max; i++)
	{
		if (i >= value.size())
			std::cout << " ";
		else if (i == max - 1 && value.size() > max)
			std::cout << ".";
		else
			std::cout << value[i];
	}
}

static void print_rep(char chr, int rep)
{
	int	i;

	for (i = 0; i < rep; i++)
		std::cout << chr;
}

static void	print_contacts(PhoneBook *phonebook)
{
	short	i;

	print_rep('-', 10 * 4 + 5);
	std::cout << std::endl;
	
	std::cout << '|';
	print_truncate("INDEX", 10);
	std::cout << '|';
	print_truncate("FIRST NAME", 10);
	std::cout << '|';
	print_truncate("LAST NAME", 10);
	std::cout << '|';
	print_truncate("NICKNAME", 10);
	std::cout << '|' << std::endl;

	std::cout << '|';
	print_rep(' ', 10);
	std::cout << '|';
	print_rep(' ', 10);
	std::cout << '|';
	print_rep(' ', 10);
	std::cout << '|';
	print_rep(' ', 10);
	std::cout << '|' << std::endl;

	for (i = 0; i < phonebook->number_contact; i++)
	{
		std::cout << '|';
		std::cout << i << "         ";
		std::cout << '|';
		print_truncate(phonebook->Contacts[i].FirstName, 10);
		std::cout << '|';
		print_truncate(phonebook->Contacts[i].LastName, 10);
		std::cout << '|';
		print_truncate(phonebook->Contacts[i].Nickname, 10);
		std::cout << '|' << std::endl;
	}
	print_rep('-', 10 * 4 + 5);
	std::cout << std::endl;
}

static bool	is_only_digit(std::string str)
{
	unsigned long	i;

	i = 0;
	while (i < str.size())
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

static void	print_contact_information(Contact contact)
{
	std::cout << "First name : " << contact.FirstName << std::endl;
	std::cout << "Last name : " << contact.LastName << std::endl;
	std::cout << "Nickname : " << contact.Nickname << std::endl;
	std::cout << "Phone Number : " << contact.PhoneNumber << std::endl;
	std::cout << "Darkest secret : " << contact.DarkestSecret << std::endl;
}

void	search_contact(PhoneBook *phonebook)
{
	std::string	contactIndexStr;
	short		contactIndex;
	
	print_contacts(phonebook);
	std::cout << std::endl;
	if (phonebook->number_contact > 0)
	{
		contactIndex = -1;
		do
		{
			std::cout << "Enter contact index : ";
			if (!std::getline(std::cin, contactIndexStr) || contactIndexStr.size() == 0)
				break;
			if (!is_only_digit(contactIndexStr))
				std::cout << "Input must only contain positive numeric value." << std::endl << std::endl;
			else if (contactIndexStr.size() > 1 || contactIndexStr[0] - '0' >= phonebook->number_contact)
				std::cout << "Contact non-existent." << std::endl << std::endl;
			else
				contactIndex = contactIndexStr[0] - '0';
		} while (contactIndex == -1);
		if (contactIndex != -1)
			print_contact_information(phonebook->Contacts[contactIndex]);
	}
}
