#include <iostream>

#include "PayOff1.h"
#include "MinMax.h"

PayOff::PayOff(double Strike_, OptionType TheOptionsType_) :
	Strike(Strike_), TheOptionsType(TheOptionsType_)
{

}

double PayOff::operator()(double spot) const
{
	switch (TheOptionsType)
	{
	case PayOff::call:
		return max(spot - Strike, 0.0);
	case PayOff::put:
		return max(Strike - spot, 0.0);
	default:
		throw("unknown option type found.");
	}
}