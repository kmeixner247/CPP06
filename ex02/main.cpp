/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <konstantin.meixner@freenet.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:03:12 by kmeixner          #+#    #+#             */
/*   Updated: 2022/07/05 17:44:15 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	srand(time(NULL));
	int i = rand();
	if (i % 3 == 0)
		return (new A);
	if (i % 3 == 1)
		return (new B);
	if (i % 3 == 2)
		return (new C);
	return (NULL);
}

void identify(Base *p)
{
	A *pa = dynamic_cast<A*>(p);
	B *pb = dynamic_cast<B*>(p);
	C *pc = dynamic_cast<C*>(p);

	if (pa)
		std::cout << "A" << std::endl;
	if (pb)
		std::cout << "B" << std::endl;
	if (pc)
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	Base ref;
	try
	{	
		ref = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
	}
	try
	{
		ref = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;	
	}
	catch (std::bad_cast &bc)
	{
	}
	try
	{
		ref = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;	
	}
	catch (std::bad_cast &bc)
	{
	}
}

int main()
{
	Base *ptr = generate();
	Base &ref = *ptr;
	identify(ptr);
	identify(ref);
	delete ptr;
}
