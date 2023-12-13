/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_contact.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:22:15 by psalame           #+#    #+#             */
/*   Updated: 2023/12/13 18:34:15 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
			if (i != 0 || (i == 0 && contact.PhoneNumber[i] != '+'))
				return (false);
		}
		i++;
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

// todo check for empty fields
void	add_contact(PhoneBook *phonebook)
{
	Contact	newContact;

	if (!get_input_not_empty("Enter contact first name : ", &newContact.FirstName))
		return;
	if (!get_input_not_empty("Enter contact last name : ", &newContact.LastName))
		return;
	if (!get_input_not_empty("Enter contact nickname : ", &newContact.Nickname))
		return;
	
	do
	{
		std::cout << "Enter contact number : ";
		if (!std::getline(std::cin, newContact.PhoneNumber))
			return;
	} while (!isPhoneNumberCorrect(newContact));

	if (!get_input_not_empty("Enter contact darkest secret : ", &newContact.DarkestSecret))
		return;

	std::cout << std::endl << "new contact added !";

	phonebook->AddContact(newContact);
}
