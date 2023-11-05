/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:58:42 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/04 04:42:06 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

static int handle_input_error()
{
	if (!std::cin)
	{
		if (std::cin.eof())
		{
			std::cout << "Error: Stream closed, unable to continue!" << std::endl;
			std::abort();
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return 1;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return 0;
}

static int get_contact(PhoneBook &book)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	std::cout << "Enter first name: ";
	std::cin >> first_name;
	if(handle_input_error() || first_name == "")
		return 1;
	std::cout << "Enter last name: ";
	std::cin >> last_name;
	if(handle_input_error() || last_name == "")
		return 1;
	std::cout << "Enter nickname: ";
	std::cin >> nickname;
	if(handle_input_error() || nickname == "")
		return 1;
	std::cout << "Enter phone number: ";
	std::cin >> phone_number;
	if(handle_input_error() || phone_number == "")
		return 1;
	std::cout << "Enter darkest secret: ";
	std::cin >> darkest_secret;
	if(handle_input_error() || darkest_secret == "")
		return 1;
	book.add_contact(first_name, last_name, nickname,
		phone_number, darkest_secret);
	std::cout << "Contact added.\n";
	return 0;
}

static void search_contact(PhoneBook& book)
{
	int idx;

	if (book.print_contacts())
		return;
	std::cout << "Enter contact index to show more information: ";
	std::cin >> idx;
	if (handle_input_error() || book.print_contact(idx))
		std::cout << "Invalid index." << std::endl;
}

int main(void)
{
	std::string response;
	PhoneBook	book;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::cin >> response;
		if(handle_input_error())
		{
			std::cout << "Invalid command." << std::endl;
			continue;
		}
		if (response == "ADD")
		{
			if (get_contact(book))
			{
			std::cout << "Invalid input." << std::endl;
			continue;
			}
		}
		else if (response == "SEARCH")
			search_contact(book);
		else if (response == "EXIT")
			break;
		else
			std::cout << "Invalid command." << std::endl;
	}
}