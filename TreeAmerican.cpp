#include "TreeAmerican.h"
#include "MinMax.h"

TreeAmerican::TreeAmerican(double FinalTime_, const PayOffBridge& ThePayOff_):
	TreeProduct(FinalTime_),
	ThePayOff(ThePayOff_)
{}

TreeProduct* TreeAmerican::clone() const
{
	return new TreeAmerican(*this);
}

double TreeAmerican::FinalPayOff(double Spot) const
{
	return ThePayOff(Spot);
}

double TreeAmerican::PreFinalValue(double Spot, double Time, double DiscountedFutureValue) const
{
	return max(ThePayOff(Spot), DiscountedFutureValue);
}