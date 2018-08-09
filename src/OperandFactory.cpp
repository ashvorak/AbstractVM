/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 15:24:06 by oshvorak          #+#    #+#             */
/*   Updated: 2018/08/09 10:21:35 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/OperandFactory.hpp"
#include "../inc/Operand.hpp"

IOperand const * OperandFactory::createInt8( std::string const & value ) const
{
	return ( new Operand<int8_t>(atoi(value.c_str()), value, Int8, 0) );
}

IOperand const * OperandFactory::createInt16( std::string const & value ) const
{
	return ( new Operand<int16_t>(atoi(value.c_str()), value, Int16, 0) );
}

IOperand const * OperandFactory::createInt32( std::string const & value ) const
{
	return ( new Operand<int32_t>(atoi(value.c_str()), value, Int32, 0) );
}

IOperand const * OperandFactory::createFloat( std::string const & value ) const
{
	return ( new Operand<float>(stod(value), value, Float, 0) );
}

IOperand const * OperandFactory::createDouble( std::string const & value ) const
{
	return ( new Operand<double>(stod(value), value, Double, 0) );
}

IOperand const * OperandFactory::createOperand( eOperandType type, std::string const & value ) const
{
	IOperand const * (OperandFactory:: *createValue[5])(std::string const & value) const = {&OperandFactory::createInt8, 
																							&OperandFactory::createInt16,
																							&OperandFactory::createInt32,
																							&OperandFactory::createFloat,
																							&OperandFactory::createDouble};
	eOperandType createType[5] = {Int8, Int16, Int32, Float, Double};
	for (int i = 0; i < 5; i++)
		if (createType[i] == type)						 
			return ((this->*(createValue[type]))(value));
}

