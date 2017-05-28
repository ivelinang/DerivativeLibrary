#pragma once
#ifndef DOUBLEDIGITAL_h
#define DOUBLEDIGITAL_H

#include "PayOff2.h"

class PayOffDoubleDigital : public PayOff 
{
public:
	PayOffDoubleDigital(double LowerLevel_, double UpperLevel_);
	virtual double operator()(double Spot) const;
	virtual ~PayOffDoubleDigital() {};
	virtual PayOff* clone() const;
private:
	double LowerLevel;
	double UpperLevel;
};
#endif // !DOUBLEDIGITAL_h
