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
										   {And, &VM::and_b},
										   {Or, &VM::or_b},
										   {Xor, &VM::xor_b}};

VM::VM()
{
	this->_count_line = 1;
}

VM::VM(const VM & copy)
{
	*this = copy;
}

VM::~VM()
{
	for(int i = this->_stack.size() - 1; i >= 0 ; i--)
		delete this->_stack[i];
}

VM & VM::operator=(VM const &src)
{
	if (this == &src)
		return (*this);
	this->_stack = src._stack;
	this->_ss.str("");
	this->_ss << src._ss.rdbuf();
	this->_count_line = src._count_line;
	return (*this);
}

void VM::push( void )
{
	OperandFactory factory;
	this->_stack.push_back(factory.createOperand(Parser::getType(), Parser::getValue()));
}

void VM::pop( void )
{
	if (this->_stack.empty())
		throw ErrorException("Pop on empty stack");
	delete this->_stack.back();
	this->_stack.pop_back();
}

void    VM::dump( void )
{
	std::vector<IOperand const *>::iterator it;
	if (!this->_stack.empty())
	{
		for (it = this->_stack.end() - 1; it >= this->_stack.begin(); it--)
		{
			this->_ss   << "\033[1;34m"
						<< (*it)->toString()
						<< "\033[0m"
						<< std::endl;
		}
	}
}

void    VM::assert( void )
{
	if (this->_stack.empty())
		throw ErrorException("Assert on empty stack");
	if (this->_stack.back()->getType() != Parser::getType() || stod(this->_stack.back()->toString()) != stod(Parser::getValue()))
		throw ErrorException("Assert instruction is not true");
}

void    VM::add()
{
	IOperand const  *value;
	if (this->_stack.size() < 2)
		throw ErrorException("Instruction 'add' when less that two values.");
	try
	{
		value = *(this->_stack[this->_stack.size() - 1]) + *(this->_stack[this->_stack.size() - 2]);
	}
	catch (std::exception & e)
	{
		this->_ss     << "\033[1;31m"
					  << "Error"
					  << "[Line:" << this->_count_line << "]->"
					  << e.what()
					  << "\033[0m"
					  << std::endl;
		return ;
	}
	delete this->_stack.back();
	this->_stack.pop_back();
	delete this->_stack.back();
	this->_stack.pop_back();
	this->_stack.push_back(value);
}

void    VM::sub()
{
	IOperand const  *value;
	if (this->_stack.size() < 2)
		throw ErrorException("Instruction 'sub' when less that two values.");
	try
	{
		value = *(this->_stack[this->_stack.size() - 2]) - *(this->_stack[this->_stack.size() - 1]);
	}
	catch (std::exception & e)
	{
		this->_ss     << "\033[1;31m"
					  << "Error"
					  << "[Line:" << this->_count_line << "]->"
					  << e.what()
					  << "\033[0m"
					  << std::endl;
		return ;
	}
	delete this->_stack.back();
	this->_stack.pop_back();
	delete this->_stack.back();
	this->_stack.pop_back();
	this->_stack.push_back(value);
}

void    VM::mul()
{
	IOperand const  *value;
	if (this->_stack.size() < 2)
		throw ErrorException("Instruction 'mul' when less that two values.");
	try
	{
		value = *(this->_stack[this->_stack.size() - 1]) * *(this->_stack[this->_stack.size() - 2]);
	}
	catch (std::exception & e)
	{
		this->_ss     << "\033[1;31m"
					  << "Error"
					  << "[Line:" << this->_count_line << "]->"
					  << e.what()
					  << "\033[0m"
					  << std::endl;
		return ;
	}
	delete this->_stack.back();
	this->_stack.pop_back();
	delete this->_stack.back();
	this->_stack.pop_back();
	this->_stack.push_back(value);
}

void    VM::div()
{
	IOperand const  *value;
	if (this->_stack.size() < 2)
		throw ErrorException("Instruction 'div' when less that two values.");
	try
	{
		value = *(this->_stack[this->_stack.size() - 2]) / *(this->_stack[this->_stack.size() - 1]);
	}
	catch (std::exception & e)
	{
		this->_ss     << "\033[1;31m"
					  << "Error"
					  << "[Line:" << this->_count_line << "]->"
					  << e.what()
					  << "\033[0m"
					  << std::endl;
		return ;
	}
	delete this->_stack.back();
	this->_stack.pop_back();
	delete this->_stack.back();
	this->_stack.pop_back();
	this->_stack.push_back(value);
}

void    VM::mod()
{
	IOperand const  *value;
	if (this->_stack.size() < 2)
		throw ErrorException("Instruction 'mod' when less that two values.");
	try
	{
		value = *(this->_stack[this->_stack.size() - 2]) % *(this->_stack[this->_stack.size() - 1]);
	}
	catch (std::exception & e)
	{
		this->_ss     << "\033[1;31m"
					  << "Error"
					  << "[Line:" << this->_count_line << "]->"
					  << e.what()
					  << "\033[0m"
					  << std::endl;
		return ;
	}
	delete this->_stack.back();
	this->_stack.pop_back();
	delete this->_stack.back();
	this->_stack.pop_back();
	this->_stack.push_back(value);
}
void    VM::print( void )
{
	if (this->_stack.empty())
		throw ErrorException("Print on empty stack");
	else if (this->_stack.back()->getType() != Int8)
		throw ErrorException("Can't print (incompetiple type)");
	else
		this->_ss << static_cast<char>(stoi(this->_stack.back()->toString()));
}

void    VM::and_b()
{
	IOperand const  *value;
	if (this->_stack.size() < 2)
		throw ErrorException("Instruction 'and' when less that two values.");
	try
	{
		value = *(this->_stack[this->_stack.size() - 1]) & *(this->_stack[this->_stack.size() - 2]);
	}
	catch (std::exception & e)
	{
		this->_ss     << "\033[1;31m"
					  << "Error"
					  << "[Line:" << this->_count_line << "]->"
					  << e.what()
					  << "\033[0m"
					  << std::endl;
		return ;
	}
	delete this->_stack.back();
	this->_stack.pop_back();
	delete this->_stack.back();
	this->_stack.pop_back();
	this->_stack.push_back(value);
}

void    VM::or_b()
{
	IOperand const  *value;
	if (this->_stack.size() < 2)
		throw ErrorException("Instruction 'or' when less that two values.");
	try
	{
		value = *(this->_stack[this->_stack.size() - 1]) | *(this->_stack[this->_stack.size() - 2]);
	}
	catch (std::exception & e)
	{
		this->_ss     << "\033[1;31m"
					  << "Error"
					  << "[Line:" << this->_count_line << "]->"
					  << e.what()
					  << "\033[0m"
					  << std::endl;
		return ;
	}
	delete this->_stack.back();
	this->_stack.pop_back();
	delete this->_stack.back();
	this->_stack.pop_back();
	this->_stack.push_back(value);
}

void    VM::xor_b()
{
	IOperand const  *value;
	if (this->_stack.size() < 2)
		throw ErrorException("Instruction 'xor' when less that two values.");
	try
	{
		value = *(this->_stack[this->_stack.size() - 1]) ^ *(this->_stack[this->_stack.size() - 2]);
	}
	catch (std::exception & e)
	{
		this->_ss     << "\033[1;31m"
					  << "Error"
					  << "[Line:" << this->_count_line << "]->"
					  << e.what()
					  << "\033[0m"
					  << std::endl;
		return ;
	}
	delete this->_stack.back();
	this->_stack.pop_back();
	delete this->_stack.back();
	this->_stack.pop_back();
	this->_stack.push_back(value);
}

void    VM::handleSI( void )
{
	std::string line;
	while (getline(std::cin, line))
	{
		if (line == "exit" || line == ";;")
			break ;
		handleInstruction(line);
		this->_count_line++;
	}
	try
	{
		if (line != ";;")
		{
			if (line == "exit")
			{
				getline(std::cin, line);
				if (line != ";;")
					throw ErrorException("Invalid exit");
			}
			else
				throw ErrorException("Invalid exit");
		}
	}
	catch (std::exception & e)
	{
		this->_ss     << "\033[1;31m"
					  << "Error : "
					  << e.what()
					  << "\033[0m"
					  << std::endl;
	}
	std::cout << this->_ss.str();
}

void    VM::handleFile(const char *file_name)
{
	std::string line;
	std::ifstream ifs(file_name);
	try
	{
		if (!ifs.is_open())
			throw ErrorException("Can't open FILE");
		while (getline(ifs, line))
		{
			if (line == "exit")
				break ;
			handleInstruction(line);
			this->_count_line++;
		}
		if (line != "exit")
			throw ErrorException("Invalid exit");
	}
	catch (std::exception & e)
	{
		this->_ss     << "\033[1;31m"
					  << "Error : "
					  << e.what()
					  << "\033[0m"
					  << std::endl;
	}
	std::cout << this->_ss.str();
}

void    VM::handleInstruction(std::string & line)
{
	Parser p;
	if (line[0] == ';' || line == "")
		return ;
	try
	{
		execute(p.parse(line));
	}
	catch (std::exception & e)
	{
		this->_ss     << "\033[1;31m"
					  << "Error"
					  << "[Line:" << this->_count_line << "]->"
					  << e.what()
					  << "\033[0m"
					  << std::endl;
	}
}

void    VM::execute(eInstruction instruction)
{
	try
	{
		(this->*_om[instruction])();
	}
	catch (std::exception & e)
	{
		this->_ss     << "\033[1;31m"
					  << "Error"
					  << "[Line:" << this->_count_line << "]->"
					  << e.what()
					  << "\033[0m"
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
