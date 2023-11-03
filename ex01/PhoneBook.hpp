/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 04:29:17 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/03 01:08:10 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <limits>

# define MAX_CONTACTS 8

class PhoneBook
{
	private:
		Contact contacts[MAX_CONTACTS];
		int next_contact;

	public:
		PhoneBook(void);

		void add_contact(std::string first_name, std::string last_name,
			std::string nickname, std::string phone_number,
			std::string darkest_secret);
		int print_contact(int index);
		void print_contacts(void);
};

#endif
