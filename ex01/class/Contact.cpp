/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:28:47 by psalame           #+#    #+#             */
/*   Updated: 2024/02/08 13:46:02 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


Contact::Contact(void)
{
	this->FirstName = "";
	this->LastName = "";
	this->Nickname = "";
	this->PhoneNumber = "";
	this->DarkestSecret = "";
}
Contact::~Contact(void)
{
}

std::string	Contact::GetFirstName(void)
{
	return (this->FirstName);
}

std::string	Contact::GetLastName(void)
{
	return (this->LastName);
}

std::string	Contact::GetNickname(void)
{
	return (this->Nickname);
}

std::string	Contact::GetPhoneNumber(void)
{
	return (this->PhoneNumber);
}

std::string	Contact::GetDarkestSecret(void)
{
	return (this->DarkestSecret);
}

void	Contact::SetFirstName(std::string value)
{
	this->FirstName = value;
}

void	Contact::SetLastName(std::string value)
{
	this->LastName = value;
}

void	Contact::SetNickname(std::string value)
{
	this->Nickname = value;
}

void	Contact::SetPhoneNumber(std::string value)
{
	this->PhoneNumber = value;
}

void	Contact::SetDarkestSecret(std::string value)
{
	this->DarkestSecret = value;
}
