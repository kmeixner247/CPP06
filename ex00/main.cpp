/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:30:36 by kmeixner          #+#    #+#             */
/*   Updated: 2022/07/05 16:14:49 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>
int	printPseudo(std::string input)
{
	int i;
	std::string strarr[8] = {"inf", "+inf", "-inf", "nan", "inff", "+inff", "-inff", "nanf"};
	for (i = 0; i < 8; i++)
		if (input == strarr[i])
			break;
	if (i < 8)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << ((i < 4) ? input + "f" : input) << std::endl;
		std::cout << "double: " << ((i < 4) ? input : (input.substr(0, input.size() - 1))) << std::endl;
		return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Exactly one argument pls." << std::endl;
		return (1);
	}
	std::string input(argv[1]);
	if (printPseudo(input))
		return (0);
	double tmp;
	if (input.size() > 1 || isdigit(input[0]))
	{
		char *endptr;
		tmp = strtod(argv[1], &endptr);
		if (*endptr)
		{
			std::cout << "Give valid input pls." << std::endl;
			return (1);
		}
	}
	else
		tmp = static_cast<double>(input[0]);
	std::cout << "char: ";
	if (tmp < 0 || tmp > 255) 
		std::cout << "impossible" << std::endl;
	else if (tmp < 32 || tmp > 126)
		std::cout << "non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(tmp) << "'" << std::endl;
	std::cout << "int: ";
	if (tmp > 2147483647 || tmp < -2147483648)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(tmp) << std::endl;
	std::cout << "float: " << static_cast<float>(tmp) << ((tmp < 1000000 && !fmod(tmp, 1)) ? ".0f" : "f") << std::endl;
	std::cout << "double: " << static_cast<double>(tmp) << ((tmp < 1000000 && !fmod(tmp, 1)) ? ".0" : "") << std::endl;
}