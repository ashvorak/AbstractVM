/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandFactory.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshvorak <oshvorak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 15:24:06 by oshvorak          #+#    #+#             */
/*   Updated: 2018/08/13 14:11:38 by oshvorak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/OperandFactory.hpp"
#include "../inc/Operand.hpp"

std::map< eOperandType, createValue > OperandFactory::_m =  {{Int8,   &OperandFactory::createInt8},
															 {Int16,  &OperandFactory::createInt16},
															 {Int32,  &OperandFactory::createInt32},
															 {Float,  &OperandFactory::createFloat},
															 {Double, &OperandFactory::createDouble}};

IOperand const * OperandFactory::createInt8( std::string const & value ) const
{
	return ( new Operand<int8_t>(value, Int8, 0) );
}

IOperand const * OperandFactory::createInt16( std::string const & value ) const
{
	return ( new Operand<int16_t>(value, Int16, 0) );
}

IOperand const * OperandFactory::createInt32( std::string const & value ) const
{
	return ( new Operand<int32_t>(value, Int32, 0) );
}

IOperand const * OperandFactory::createFloat( std::string const & value ) const
{
	return ( new Operand<float>(value, Float, 7) );
}

IOperand const * OperandFactory::createDouble( std::string const & value ) const
{
	return ( new Operand<double>(value, Double, 15) );
}

IOperand const * OperandFactory::createOperand( eOperandType type, std::string const & value ) const
{
	return (this->*(_m[type]))(value);
}
