/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VM.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:39:46 by oshvorak          #+#    #+#             */
/*   Updated: 2018/08/01 18:06:07 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/VM.hpp"

void VM::push(int value) 
{
	this->_stack.push(value);
}

void VM::pop( void )
{
	try
	{
		if (this->_stack.empty())
			throw ErrorException("Error : Pop on empty stack");
		this->_stack.pop();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}

int  VM::print( void )
{
	try
	{
		if (this->_stack.empty())
			throw ErrorException("Error : Print on empty stack");
		return (this->_stack.top());
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
		return (0);
	}
}

VM::ErrorException::ErrorException() {}
VM::ErrorException::~ErrorException() throw() {}

VM::ErrorException::ErrorException(std::string message)
{
	this->_message = message;
}

const char* VM::ErrorException::what() const throw() 
{
	return (this->_message.c_str());
}