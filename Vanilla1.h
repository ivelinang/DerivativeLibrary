#pragma once
#ifndef VANILLA1_H
#define VANILLA1_H

#include "PayOff2.h"

class VanillaOption
{
public:
	VanillaOption(const PayOff& ThePayOff_, double Expiry_);
	VanillaOption(const VanillaOption& original);
	double getExpiry() const;
	double OptionPayOff(double Spot) const;
	VanillaOption& operator=(const VanillaOption& original);
	~VanillaOption();
private:
	double Expiry;
	PayOff* ThePayOffPtr;
};

#endif // !VANILLA1_H
