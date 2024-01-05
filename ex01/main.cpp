/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:58:42 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/05 01:21:58 by gmachado         ###   ########.fr       */
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
			return 2;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return 1;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return 0;
}

static int get_line(std::string &str)
{
	int err;

	std::cin >> str;
	err = handle_input_error();
	if (err)
		return err;
	if(str == "")
		return 1;
	return 0;
}
static int get_contact(PhoneBook &book)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	int err;

	std::cout << "Enter first name: ";
	err = get_line(first_name);
	if(err)
		return err;
	std::cout << "Enter last name: ";
	err = get_line(last_name);
	if(err)
		return err;
	std::cout << "Enter nickname: ";
	err = get_line(nickname);
	if(err)
		return err;
	std::cout << "Enter phone number: ";
	err = get_line(phone_number);
	if(err)
		return err;
	std::cout << "Enter darkest secret: ";
	err = get_line(last_name);
	if(err)
		return err;
	book.add_contact(first_name, last_name, nickname,
		phone_number, darkest_secret);
	std::cout << "Contact added.\n";
	return 0;
}

static int search_contact(PhoneBook& book)
{
	int idx;
	int err;

	if (book.print_contacts())
		return 1;
	std::cout << "Enter contact index to show more information: ";
	std::cin >> idx;
	err = handle_input_error();
	if (err)
		return err;
	if (book.print_contact(idx))
	{
		std::cout << "Invalid index." << std::endl;
		return 1;
	}
	return 0;
}

int main(void)
{
	std::string response;
	PhoneBook book;
	int err;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::cin >> response;
		err = handle_input_error();
		if (err == 2)
			return(2);
		if(err)
		{
			std::cout << "Invalid command." << std::endl;
			continue;
		}
		if (response == "ADD")
		{
			err = get_contact(book);
			if (err == 2)
				return(2);
			if (err)
			{
				std::cout << "Invalid input." << std::endl;
				continue;
			}
		}
		else if (response == "SEARCH")
		{
			err = search_contact(book);
			if (err == 2)
				return(2);
		}
		else if (response == "EXIT")
			break;
		else
			std::cout << "Invalid command." << std::endl;
	}
}