/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:08:54 by psalame           #+#    #+#             */
/*   Updated: 2024/02/08 14:07:18 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	AddContact(Contact newContact);
		Contact	GetContact(short id);
		short	GetContactsNumber(void);

	private:
		Contact	_Contacts[8];
		short	_numberContact;
		short	_contactAddIndex;
};

#endif