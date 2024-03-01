/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:23:01 by psalame           #+#    #+#             */
/*   Updated: 2024/02/08 14:04:56 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>

PhoneBook::PhoneBook(void)
{
	this->_numberContact = 0;
	this->_contactAddIndex = 0;
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::AddContact(Contact contact)
{
	this->_Contacts[this->_contactAddIndex] = contact;
	if (this->_numberContact < 8)
		this->_numberContact++;
	this->_contactAddIndex = (this->_contactAddIndex + 1) % 8;
}

Contact	PhoneBook::GetContact(short id)
{
	return (this->_Contacts[id]);
}

short	PhoneBook::GetContactsNumber(void)
{
	return (this->_numberContact);
}
