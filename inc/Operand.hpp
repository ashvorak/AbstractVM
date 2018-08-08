/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 17:47:16 by oshvorak          #+#    #+#             */
/*   Updated: 2018/08/08 17:46:52 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_HPP
# define OPERAND_HPP

#include "IOperand.hpp"

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
			
		}
		
		IOperand const * operator-( IOperand const & rhs ) const
		{
			
		}
		
		IOperand const * operator*( IOperand const & rhs ) const
		{
			
		}
		
		IOperand const * operator/( IOperand const & rhs ) const
		{
			
		}

		IOperand const * operator%( IOperand const & rhs ) const
		{
			
		}

		std::string const & toString( void ) const
		{
			return (this->_str);
		}
		
		~Operand( void ) {}
		
};

#endif