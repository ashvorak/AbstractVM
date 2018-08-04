/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VM.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:39:46 by oshvorak          #+#    #+#             */
/*   Updated: 2018/08/04 16:30:48 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/VM.hpp"

void VM::push(IOperand * value)
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

void	VM::print( void )
{
	try
	{
		if (this->_stack.empty())
			throw ErrorException("Error : Print on empty stack");
		IOperand *tmp = this->_stack.top();
		switch (tmp->getType())
		{
			case _int :
			{
				Operand<int> *x = dynamic_cast<Operand<int>*>(tmp);
				std::cout << x->getValue() << std::endl;
				break ;
			}
			case _float :
			{
				Operand<float> *x = dynamic_cast<Operand<float>*>(tmp);
				std::cout << x->getValue() << std::endl;
				break ;
			}
			case _double :
			{
				Operand<double> *x = dynamic_cast<Operand<double>*>(tmp);
				std::cout << x->getValue() << std::endl;
				break ;
			}
			default :
				break ;
		}
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
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
