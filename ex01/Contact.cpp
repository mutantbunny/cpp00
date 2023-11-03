/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 04:29:22 by gmachado          #+#    #+#             */
/*   Updated: 2023/11/03 01:00:50 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

static void print_truncated(std::string original, int width)
{
	std::cout << std::setw(width) << std::right;
	if (original.length() > width)
		std::cout << original.substr(0, width - 1) << '.';
	std::cout << original;
}

Contact::Contact() : first_name(""), last_name(""),
						nickname(""), phone_number(""),
						darkest_secret("") { }

void Contact::set(std::string first_name, std::string last_name,
				std::string nickname, std::string phone_number,
				std::string darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

void Contact::print_full(void)
{
	std::cout << "First name: " << this->first_name << '\n';
	std::cout << "Last name: " << this->last_name << '\n';
	std::cout << "Nickname: " << this->nickname << '\n';
	std::cout << "Phone number: " << this->phone_number << '\n';
	std::cout << "First name: " << this->first_name << '\n';
	std::cout << "Darkest secret: " << this->darkest_secret << std::endl;
}

void Contact::print_summary(void)
{
	const int width = 10;

	std::cout << std::setw(width) << std::right << this->index << '|';
	print_truncated(this->first_name, width);
	std::cout << '|';
	print_truncated(this->last_name, width);
	std::cout << '|';
	print_truncated(this->nickname, width);
	std::cout << std::endl;
}
