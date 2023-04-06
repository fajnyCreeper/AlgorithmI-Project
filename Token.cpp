#include "Token.h"

Token::Token(float value)
{
	this->type = Number;
	this->value = value;
}

Token::Token(Type type)
{
	this->type = type;
}

Token::Token(Operation operation)
{
	this->type = Operator;
	this->operation = operation;

	switch (this->operation)
	{
	case Add:
	case Sub:
		this->weight = 0;
		break;
	case Mul:
	case Div:
		this->weight = 1;
		break;
	case Pow:
		this->weight = 2;
		break;
	}
}

Token::Operation Token::getOperation()
{
	return this->operation;
}

Token::Type Token::getType()
{
	return this->type;
}

float Token::getValue()
{
	return this->value;
}

int Token::getWeight()
{
	return this->weight;
}




