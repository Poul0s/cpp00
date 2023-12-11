/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_contact.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:22:15 by psalame           #+#    #+#             */
/*   Updated: 2023/12/11 19:39:15 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

static bool	checkPhoneNumberSize(Contact contact, bool isCountryFormated)
{
	if (isCountryFormated)
		return (contact.PhoneNumber.size() >= 11);
	else
		return (contact.PhoneNumber.size() == 10);
}

static bool	checkPhoneNumberFormat(Contact contact)
{
	size_t	i = 0;
	
	while (i < contact.PhoneNumber.size())
	{
		if (contact.PhoneNumber[i] < '0' && contact.PhoneNumber[i] > '0')
		{
			if (i != 0 || contact.PhoneNumber[i] != '+')
				return (false);
		}
	}
	return (true);
}

static bool	isPhoneNumberCorrect(Contact contact)
{
	bool	res = true;
	bool	isCountryFormated = false;

	if (contact.PhoneNumber[0] == '+')
		isCountryFormated = true;
	res = checkPhoneNumberSize(contact, isCountryFormated);
	if (res)
		res = checkPhoneNumberFormat(contact);

	if (!res)
		std::cout << "Phone number must be in format '0123456789' or '+33123456789'." << std::endl << std::endl;
	return (res);
}

void	add_contact(PhoneBook *phonebook)
{
	Contact	newContact;

	std::cout << "Enter contact first name : ";
	std::getline(std::cin, newContact.FirstName);

	std::cout << "Enter contact last name : ";
	std::getline(std::cin, newContact.LastName);

	std::cout << "Enter contact nickname : ";
	std::getline(std::cin, newContact.Nickname);

	do
	{
		std::cout << "Enter contact number : ";
		std::getline(std::cin, newContact.PhoneNumber);
	} while (!isPhoneNumberCorrect(newContact));

	std::cout << "Enter contact darkest secret : ";
	std::getline(std::cin, newContact.DarkestSecret);

	phonebook->AddContact(newContact);
}
