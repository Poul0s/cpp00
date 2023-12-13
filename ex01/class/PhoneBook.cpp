/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:23:01 by psalame           #+#    #+#             */
/*   Updated: 2023/12/13 13:49:42 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook(void)
{
	this->Contacts = new Contact[8];
	this->number_contact = 0;
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

void	PhoneBook::AddContact(Contact contact)
{
	if (this->number_contact == 8)
		this->RemoveContact(0);
	this->Contacts[this->number_contact] = contact;
	this->number_contact++;
}

bool	PhoneBook::RemoveContact(short id)
{
	Contact	*newContactsList = new Contact[8];
	int		i = 0;
	
	if (id >= this->number_contact)
		return (false);
	else
	{
		while (i < this->number_contact)
		{
			if (i != id)
			{
				if (i > id)
					newContactsList[i - 1] = this->Contacts[i];
				else
					newContactsList[i] = this->Contacts[i];
			}
			i++;
		}
		this->Contacts = newContactsList;
		this->number_contact--;
		return (true);
	}
}
