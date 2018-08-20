
#ifndef ABSTRACTVM_H
#define ABSTRACTVM_H

class VM;
class IOperand;
class OperandFactory;

enum eOperandType {
    Int8,
    Int16,
    Int32,
    Float,
    Double
};

enum eInstruction {
	Push,
	Pop,
	Dump,
	Assert,
	Add,
	Sub,
	Mul,
	Div,
	Mod,
    Print,
	Exit
};

typedef void (VM:: *oper)( void );
typedef IOperand const * (OperandFactory:: *createValue)(std::string const & value) const;

#endif
