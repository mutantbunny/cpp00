/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 04:29:15 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/03 00:44:50 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	for (int i = 0; i < MAX_CONTACTS; ++i)
		this->contacts[i] = Contact();
	this->next_contact = 0;
}

void PhoneBook::add_contact(std::string first_name, std::string last_name,
	std::string nickname, std::string phone_number,
	std::string darkest_secret)
{
	this->contacts[this->next_contact % MAX_CONTACTS].set(first_name, last_name,
		nickname, phone_number, darkest_secret);
	++(this->next_contact);
}

void PhoneBook::print_contacts(void)
{
	const int max_saved(this->next_contact <= MAX_CONTACTS ?
		this->next_contact : MAX_CONTACTS);

	std::cout << "Saved contacts:\n";
	std::cout << "---------------\n";
	for (int i = 0; i < max_saved; ++i)
		this->contacts[i].print_summary();
	std::cout << "---------------" << std::endl;
}

int PhoneBook::print_contact(int index)
{
	const int max_saved(this->next_contact <= MAX_CONTACTS ?
		this->next_contact : MAX_CONTACTS);

	if (index < 0 || index >= max_saved)
		return 1;
	this->contacts[index].print_full();
	return 0;
}
