#include "MathFormula.h"

#include <stack>

MathFormula::MathFormula(std::string formula)
{
	this->formula = formula;
	this->processString();
	this->shuntingYard();
}

float MathFormula::calculate()
{
	std::queue<Token> tokens = this->tokens;
	std::stack<Token> numbers;
	float left, right, result;

	while (!tokens.empty())
	{
		if (tokens.front().getType() == Token::Number)
		{
			numbers.push(tokens.front());
		}
		else
		{
			right = numbers.top().getValue();
			numbers.pop();
			left = numbers.top().getValue();
			numbers.pop();

			switch (tokens.front().getOperation())
			{
			case '+': result = left + right; break;
			case '-': result =  left - right; break;
			case '*': result = left * right; break;
			case '/': result = left / right; break;
			case '^': result = powf(right, left);
			}
			numbers.push(Token(result));
		}
		tokens.pop();
	}

	result = numbers.top().getValue();
	numbers.pop();

	return result;
}

void MathFormula::processString()
{
	this->formula.erase(std::remove_if(formula.begin(), formula.end(), isspace), formula.end());
}

void MathFormula::shuntingYard()
{
	std::stack<Token> operators;

	std::string formula = this->formula;
	std::string buffer;

	for (int i = 0; i <= formula.length(); i++)
	{
		char currentChar = formula[i];

		Token token = Token((Token::Operation)currentChar);
		
		if (isdigit(currentChar))
		{
			buffer += currentChar;
			continue;
		}

		if (buffer.length() > 0)
		{
			tokens.push(Token(std::stof(buffer)));
			buffer = "";
		}

		if (currentChar == 0)
			break;

		if (currentChar == '(')
		{
			token = Token(Token::LeftPar);
			operators.push(token);
			continue;
		}

		if (currentChar == ')')
		{
			while (operators.top().getType() != Token::LeftPar)
			{
				tokens.push(operators.top());
				operators.pop();
			}
			operators.pop();
			continue;
		}

		if (!operators.empty())
		{
			int addedWeight = 0;

			if (token.getOperation() == Token::Pow)
				addedWeight++;

			while ((token.getWeight() + addedWeight) <= operators.top().getWeight())
			{
				if (operators.top().getType() == Token::LeftPar)
					break;
				tokens.push(operators.top());
				operators.pop();

				if (operators.empty())
					break;
			}

		}
		operators.push(token);
	}

	while (!operators.empty())
	{
		tokens.push(operators.top());
		operators.pop();
	}
}
