/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:58:42 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/03 00:57:58 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstdlib>

static int handle_input_error()
{
	if (!std::cin)
	{
		if (std::cin.eof())
		{
			std::cout << "Error: Stream closed, unable to continue!" << std::endl;
			exit(1);
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return 1;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return 0;
}

static int get_contact(PhoneBook book)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	std::cout << "Enter first name:\n";
	std::cin >> first_name;
	if(handle_input_error())
		return 1;
	std::cout << "Enter last name:\n";
	std::cin >> last_name;
	if(handle_input_error())
		return 1;
	std::cout << "Enter nickname:\n";
	std::cin >> nickname;
	if(handle_input_error())
		return 1;
	std::cout << "Enter phone number:\n";
	std::cin >> phone_number;
	if(handle_input_error())
		return 1;
	std::cout << "Enter darkest secret:\n";
	std::cin >> darkest_secret;
	if(handle_input_error())
		return 1;
	book.add_contact(first_name, last_name, nickname,
		phone_number, darkest_secret);
	return 0;
}

static void search_contact(PhoneBook& book)
{
	int idx;

	std::cout << "Saved contacts:\n";
	book.print_contacts();
	std::cout << "Enter contact index to show more information:\n";
	std::cin >> idx;
	if (handle_input_error() || book.print_contact(idx))
		std::cout << "Error: Invalid index." << std::endl;
}

int main(void)
{
	std::string response;
	PhoneBook	book;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT):\n";
		std::cin >> response;
		if(handle_input_error())
		{
			std::cout << "Invalid command." << std::endl;
			continue;
		}
		if (response == "ADD")
			get_contact(book);
		else if (response == "SEARCH")
			search_contact(book);
		else if (response == "EXIT")
			break;
		else
			std::cout << "Invalid command." << std::endl;
	}
}