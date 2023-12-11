#pragma once
#include<string>
using namespace std;

class Rational
{
private:
	int numerator;
	int denominator;

public:
	//Constructors
	Rational();
	Rational(int numerator, int denominator);
	class InvalidDenominator {};

	//Methods:
	string toString();
	void normalize();

	//Setters:
	void setNumerator(int numerator);
	void setDenominator(int denominator);

	//Getters:
	int getNumerator() const;
	int getDenominator() const;

	//Operators:
	bool operator==(const Rational&);
	bool operator<(const Rational&);
};

