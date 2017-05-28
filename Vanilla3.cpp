#include "Vanilla3.h"

VanillaOption2::VanillaOption2(const PayOffBridge& thePayOff_, double expiry_):
	ThePayOff(thePayOff_), Expiry(expiry_)
{}

double VanillaOption2::getExpiry() const
{
	return Expiry;
}

double VanillaOption2::OptionPayOff(double Spot) const
{
	return ThePayOff(Spot);
}