/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 05:53:57 by gmachado          #+#    #+#             */
/*   Updated: 2024/01/05 05:54:13 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

int main(int argc, char **argv)
{
	int i;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (i = 1; i < argc - 1; i++)
		{
			for (int j = 0; argv[i][j]; j++)
				std::cout << (char)std::toupper(argv[i][j]);
			std::cout << " ";
		}
		for (int j = 0; argv[i][j]; j++)
			std::cout << (char)std::toupper(argv[i][j]);
	}
	std::cout << std::endl;
	return (0);
}
