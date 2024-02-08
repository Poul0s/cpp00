/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_contact.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:22:15 by psalame           #+#    #+#             */
/*   Updated: 2024/02/08 13:44:28 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static bool	checkPhoneNumberSize(std::string number, bool isCountryFormated)
{
	if (isCountryFormated)
		return (number.size() >= 11);
	else
		return (number.size() == 10);
}

static bool	checkPhoneNumberFormat(std::string number)
{
	size_t	i = 0;
	
	while (i < number.size())
	{
		if (number[i] < '0' && number[i] > '0')
		{
			if (i != 0 || (i == 0 && number[i] != '+'))
				return (false);
		}
		i++;
	}
	return (true);
}

static bool	isPhoneNumberCorrect(std::string number)
{
	bool	res = true;
	bool	isCountryFormated = false;

	if (number[0] == '+')
		isCountryFormated = true;
	res = checkPhoneNumberSize(number, isCountryFormated);
	if (res)
		res = checkPhoneNumberFormat(number);

	if (!res)
		std::cout << "Phone number must be in format '0123456789' or '+33123456789'." << std::endl << std::endl;
	return (res);
}

void	add_contact(PhoneBook *phonebook)
{
	Contact		newContact;
	std::string	value;

	if (!get_input_not_empty("Enter contact first name : ", value))
		return;
	else
		newContact.SetFirstName(value);
	if (!get_input_not_empty("Enter contact last name : ", value))
		return;
	else
		newContact.SetLastName(value);
	if (!get_input_not_empty("Enter contact nickname : ", value))
		return;
	else
		newContact.SetNickname(value);
	
	do
	{
		std::cout << "Enter contact number : ";
		if (!std::getline(std::cin, value))
			return;
	} while (!isPhoneNumberCorrect(value));
	newContact.SetPhoneNumber(value);

	if (!get_input_not_empty("Enter contact darkest secret : ", value))
		return;
	else
		newContact.SetDarkestSecret(value);

	std::cout << std::endl << "new contact added !";
	phonebook->AddContact(newContact);
}
