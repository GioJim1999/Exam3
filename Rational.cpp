#include "Rational.h"

//Constructors:
Rational::Rational()
{
	numerator = 0;
	denominator = 1;
}

Rational::Rational(int numerator, int denominator)
{
	if (denominator == 0)
		throw InvalidDenominator();
	else
	{
		this->numerator = numerator;
		this->denominator = denominator;
		normalize();
	}
}

string Rational::toString()
{
	return to_string(numerator) + "/" + to_string(denominator);
}

//simplify rational number ex: 2/4  = 1/2 do this later xDDD also if negative number in denominator put in numerator
void Rational::normalize()
{
	if (this->denominator < 0)
	{
		this->denominator = abs(denominator);
		this->numerator *= -1;
	}

}

//Setters:
void Rational::setNumerator(int numerator)
{
	this->numerator = numerator;
	normalize();
}

void Rational::setDenominator(int denominator)
{
	if (denominator == 0)
		throw InvalidDenominator();
	else
		this->denominator = denominator;

	normalize();
}

//Getters:
int Rational::getNumerator() const
{
	return numerator;
}

int Rational::getDenominator() const
{
	return denominator;
}

//Operators:
bool Rational::operator==(const Rational& obj)
{
	if ((this->numerator == obj.getNumerator()) && (this->denominator == obj.getDenominator()))
		return true;
	else
		return false;
}

bool Rational::operator<(const Rational& obj)
{
	float num1, num2;

	num1 = static_cast<float>(this->numerator) / static_cast<float>(this->denominator);
	num2 = static_cast<float>(obj.numerator) / static_cast<float>(obj.denominator);

	if (num1 < num2)
		return true;
	else
		return false;
}  