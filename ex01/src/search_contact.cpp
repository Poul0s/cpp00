/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_contact.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:21:49 by psalame           #+#    #+#             */
/*   Updated: 2024/03/01 09:25:19 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <iomanip>
#include <sstream>

static void	print_truncate(std::string value, unsigned long max)
{
	if (value.size() > max)
		std::cout << value.substr(0, max - 1) << ".";
	else
		std::cout << std::setw(max) << value;
}

static void	print_truncate(int value, unsigned long max)
{
	std::string str;
	std::stringstream str_stream;

	str_stream << value;
	str = str_stream.str();
	print_truncate(str, max);
}

static void print_rep(char chr, int rep)
{
	std::cout << std::setw(rep) << std::setfill(chr) << "";
	std::cout << std::setfill(' ');
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

	for (i = 0; i < phonebook->GetContactsNumber(); i++)
	{
		std::cout << '|';
		print_truncate(i, 10);
		std::cout << '|';
		print_truncate(phonebook->GetContact(i).GetFirstName(), 10);
		std::cout << '|';
		print_truncate(phonebook->GetContact(i).GetLastName(), 10);
		std::cout << '|';
		print_truncate(phonebook->GetContact(i).GetNickname(), 10);
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
	std::cout << "First name : " << contact.GetFirstName() << std::endl;
	std::cout << "Last name : " << contact.GetLastName() << std::endl;
	std::cout << "Nickname : " << contact.GetNickname() << std::endl;
	std::cout << "Phone Number : " << contact.GetPhoneNumber() << std::endl;
	std::cout << "Darkest secret : " << contact.GetDarkestSecret() << std::endl;
}

void	search_contact(PhoneBook *phonebook)
{
	std::string	contactIndexStr;
	short		contactIndex;
	
	print_contacts(phonebook);
	std::cout << std::endl;
	if (phonebook->GetContactsNumber() > 0)
	{
		contactIndex = -1;
		do
		{
			std::cout << "Enter contact index : ";
			if (!std::getline(std::cin, contactIndexStr) || contactIndexStr.size() == 0)
				break;
			if (!is_only_digit(contactIndexStr))
				std::cout << "Input must only contain positive numeric value." << std::endl << std::endl;
			else if (contactIndexStr.size() > 1 || contactIndexStr[0] - '0' >= phonebook->GetContactsNumber())
				std::cout << "Contact non-existent." << std::endl << std::endl;
			else
				contactIndex = contactIndexStr[0] - '0';
		} while (contactIndex == -1);
		if (contactIndex != -1)
			print_contact_information(phonebook->GetContact(contactIndex));
	}
}
