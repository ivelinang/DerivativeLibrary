#pragma once
#ifndef VANILLA3_H
#define VANILLA3_H

#include "PayOffBridge2.h"

class VanillaOption2
{
public:
	VanillaOption2(const PayOffBridge& thePayOff_, double expiry_);

	double OptionPayOff(double Spot) const;
	double getExpiry() const;

private:
	double Expiry;
	PayOffBridge ThePayOff;
};

#endif // !VANILLA3_H

