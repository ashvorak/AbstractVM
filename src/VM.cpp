/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VM.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:39:46 by oshvorak          #+#    #+#             */
/*   Updated: 2018/08/13 13:45:54 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/VM.hpp"

std::map<eInstruction, oper> VM::_om = {   {Push, &VM::push},
										   {Pop, &VM::pop},
										   {Dump, &VM::dump},
										   {Assert, &VM::assert},
										   {Add, &VM::add},
										   {Sub, &VM::sub},
										   {Mul, &VM::mul},
										   {Div, &VM::div},
										   {Mod, &VM::mod},
										   {Print, &VM::print},
										   {Exit, &VM::exit}};

VM::VM()
{
	this->_count_line = 1;
}

VM::~VM()
{
	 for(int i = this->_stack.size() - 1; i >= 0 ; i--)
		delete this->_stack[i];
}

void VM::push( void )
{
	this->_stack.push_back(Parser::value);
}

void VM::pop( void )
{
	if (this->_stack.empty())
		throw ErrorException("Pop on empty stack");
	delete this->_stack.back();
	this->_stack.pop_back();
}

void	VM::dump( void )
{
	std::vector<IOperand const *>::iterator it;
	
	for(it = this->_stack.end() - 1; it >= this->_stack.begin(); it--)
	{
    	this->_ss << (*it)->toString() << std::endl;
	}
}

void	VM::assert( void )
{
	if (this->_stack.empty())
		throw ErrorException("Assert on empty stack");
	if (this->_stack.back()->getType() != Parser::value->getType() || stod(this->_stack.back()->toString()) != stod(Parser::value->toString()))
		throw ErrorException("Assert instruction is not true");
}

void	VM::add()
{
	IOperand const	*value;

	if (this->_stack.size() < 2)
		throw ErrorException("Instruction 'add' when less that two values.");
	try
	{
		value = *(this->_stack[this->_stack.size() - 1]) + *(this->_stack[this->_stack.size() - 2]);
	}
	catch (std::exception & e)
	{
		this->_ss	<< "Error"
					 << "[Line:" << this->_count_line << "]->"
					 << e.what()
					 << std::endl;
		return ;
	}
	this->_stack.pop_back();
	delete this->_stack.back();
	this->_stack.pop_back();
	delete this->_stack.back();
	this->_stack.push_back(value);

}

void	VM::sub()
{
	IOperand const	*value;

	if (this->_stack.size() < 2)
		throw ErrorException("Instruction 'sub' when less that two values.");
	try
	{
		value = *(this->_stack[this->_stack.size() - 1]) - *(this->_stack[this->_stack.size() - 2]);
	}
	catch (std::exception & e)
	{
		this->_ss	<< "Error"
					 << "[Line:" << this->_count_line << "]->"
					 << e.what()
					 << std::endl;
		return ;
	}
	this->_stack.pop_back();
	delete this->_stack.back();
	this->_stack.pop_back();
	delete this->_stack.back();
	this->_stack.push_back(value);
}

void	VM::mul()
{
	IOperand const	*value;

	if (this->_stack.size() < 2)
		throw ErrorException("Instruction 'mul' when less that two values.");
	try
	{
		value = *(this->_stack[this->_stack.size() - 1]) * *(this->_stack[this->_stack.size() - 2]);
	}
	catch (std::exception & e)
	{
		this->_ss	<< "Error"
					 << "[Line:" << this->_count_line << "]->"
					 << e.what()
					 << std::endl;
		return ;
	}
	this->_stack.pop_back();
	delete this->_stack.back();
	this->_stack.pop_back();
	delete this->_stack.back();
	this->_stack.push_back(value);
}

void	VM::div()
{
	IOperand const	*value;

	if (this->_stack.size() < 2)
		throw ErrorException("Instruction 'div' when less that two values.");
	try
	{
		value = *(this->_stack[this->_stack.size() - 1]) / *(this->_stack[this->_stack.size() - 2]);
	}
	catch (std::exception & e)
	{
		this->_ss	<< "Error"
					 << "[Line:" << this->_count_line << "]->"
					 << e.what()
					 << std::endl;
		return ;
	}
	this->_stack.pop_back();
	delete this->_stack.back();
	this->_stack.pop_back();
	delete this->_stack.back();
	this->_stack.push_back(value);
}

void	VM::mod()
{
	IOperand const	*value;

	if (this->_stack.size() < 2)
		throw ErrorException("Instruction 'mod' when less that two values.");
	try
	{
		value = *(this->_stack[this->_stack.size() - 1]) % *(this->_stack[this->_stack.size() - 2]);
	}
	catch (std::exception & e)
	{
		this->_ss	<< "Error"
					 << "[Line:" << this->_count_line << "]->"
					 << e.what()
					 << std::endl;
		return ;
	}
	this->_stack.pop_back();
	delete this->_stack.back();
	this->_stack.pop_back();
	delete this->_stack.back();
	this->_stack.push_back(value);
}

void	VM::print( void )
{
	if (this->_stack.empty())
		throw ErrorException("Print on empty stack");
	else if (this->_stack.back()->getType() != Int8)
		throw ErrorException("Can't print (incompetiple type)");
	else
		std::cout << static_cast<char>(stoi(this->_stack.back()->toString())) << std::endl;
}

void	VM::exit( void )
{

}

void	VM::handleSI( void )
{
	std::string line;

	while (getline(std::cin, line))
		handleInstruction(line);
	std::cout << this->_ss.str();
}

void	VM::handleFile(const char *file_name)
{
	std::string line;
	std::ifstream ifs(file_name);

	try
	{
		if (!ifs.is_open())
			throw ErrorException("Can't open FILE");
		while (getline(ifs, line))
			handleInstruction(line);
	}
	catch (ErrorException & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << this->_ss.str();

}

void	VM::handleInstruction(std::string &line)
{
	Parser p;

	try
	{
		execute(p.parse(line));
	}
	catch (const char *s)
	{
		this->_ss	<< "Error"
					 << "[Line:" << this->_count_line << "]->"
					 << s
					 << std::endl;
	}
	this->_count_line++;
}

void	VM::execute(eInstruction instruction)
{
	try
	{
		(this->*_om[instruction])();
	}
	catch (ErrorException & e)
	{
		this->_ss	<< "Error"
					<< "[Line:" << this->_count_line << "]->"
				  	<< e.what()
				  	<< std::endl;
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
