/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:18:38 by kmeixner          #+#    #+#             */
/*   Updated: 2022/07/05 16:58:26 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main()
{
	Data *org = new Data;
	Data *cpy;
	uintptr_t n;
	org->secret_stuff = "Birds aren't real.";
	std::cout << org << " " << org->secret_stuff << std::endl;
	n = serialize(org);
	std::cout << std::hex << "0x" << n << std::endl;
	cpy = deserialize(n);
	std::cout << cpy << " " << cpy->secret_stuff << std::endl;
	delete org;
}