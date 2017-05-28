#include "Vanilla1.h"

//before
/*
VanillaOption::VanillaOption(const PayOff& ThePayOff_, double Expiry_):
	ThePayOff(ThePayOff_), Expiry(Expiry_){}
*/
VanillaOption::VanillaOption(const PayOff& ThePayOff_, double Expiry_) :
	Expiry(Expiry_)
{
	ThePayOffPtr = ThePayOff_.clone();
}

VanillaOption::VanillaOption(const VanillaOption& original) 
{
	Expiry = original.Expiry;
	ThePayOffPtr = original.ThePayOffPtr->clone();
}

double VanillaOption::getExpiry() const
{
	return Expiry;
}

double VanillaOption::OptionPayOff(double Spot) const
{
	return (*ThePayOffPtr)(Spot);
}

VanillaOption& VanillaOption::operator=(const VanillaOption& original)
{
	if (this != &original)
	{
		Expiry = original.Expiry;
		delete ThePayOffPtr;
		ThePayOffPtr = original.ThePayOffPtr->clone();
	}
	return *this;
}

VanillaOption::~VanillaOption()
{
	delete ThePayOffPtr;
}