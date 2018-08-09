/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 17:47:16 by oshvorak          #+#    #+#             */
/*   Updated: 2018/08/09 11:13:29 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_HPP
# define OPERAND_HPP

#include <cmath>
#include "IOperand.hpp"
#include "OperandFactory.hpp"

template <typename T>
class Operand : public IOperand {

	private:
		T 				_value;
		std::string		_str;
		int				_precision;
		eOperandType 	_type;

	public:

		Operand<T>(T value, std::string str, eOperandType type, int precision) 
		{
			this->_value = value;
			this->_str = str;
			this->_type = type;
			this->_precision = precision;
		}
		
		T & getValue( void ) { return (this->_value); }
		int getPrecision( void ) const { return (this->_precision); }
		eOperandType getType( void ) const { return (this->_type); }

		void	setValue(T value) { this->_value = value; }
		void	setPrecision(int precision) { this->_precision = precision; }
		void	setType(eOperandType type) { this->_type = type; }

		IOperand const * operator+( IOperand const & rhs ) const
		{
			std::string		value;
			eOperandType	type;
			OperandFactory	Factory;

			type = (rhs.getPrecision() > this->_precision) ? rhs.getType() : this->_type;
			value = std::to_string(this->_value + stod(rhs.toString(), 0));
			return (Factory.createOperand(type, value));
		}
		
		IOperand const * operator-( IOperand const & rhs ) const
		{
			std::string		value;
			eOperandType	type;
			OperandFactory	Factory;

			type = (rhs.getPrecision() > this->_precision) ? rhs.getType() : this->_type;
			value = std::to_string(this->_value - stod(rhs.toString(), 0));
			return (Factory.createOperand(type, value));
		}
		
		IOperand const * operator*( IOperand const & rhs ) const
		{
			std::string		value;
			eOperandType	type;
			OperandFactory	Factory;

			type = (rhs.getPrecision() > this->_precision) ? rhs.getType() : this->_type;
			value = std::to_string(this->_value * stod(rhs.toString(), 0));
			return (Factory.createOperand(type, value));
		}
		
		IOperand const * operator/( IOperand const & rhs ) const
		{
			std::string		value;
			eOperandType	type;
			OperandFactory	Factory;

			if (!stod(rhs.toString(), NULL))
				throw ("Error : Division by 0");
			type = (rhs.getPrecision() > this->_precision) ? rhs.getType() : this->_type;
			value = std::to_string(this->_value / stod(rhs.toString(), 0));
			return (Factory.createOperand(type, value));
		}

		IOperand const * operator%( IOperand const & rhs ) const
		{
			std::string		value;
			eOperandType	type;
			OperandFactory	Factory;

			if (!stod(rhs.toString(), NULL))
				throw ("Error : Modulo by 0");
			type = (rhs.getPrecision() > this->_precision) ? rhs.getType() : this->_type;
			value = std::to_string(fmod(this->_value , stod(rhs.toString(), 0)));
			return (Factory.createOperand(type, value));
		}

		std::string const & toString( void ) const
		{
			return (this->_str);
		}
		
		~Operand( void ) {}
		
};

#endif