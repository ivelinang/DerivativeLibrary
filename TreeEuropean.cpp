#include "TreeEuropean.h"

TreeEuropean::TreeEuropean(double FinalTime_, const PayOffBridge& ThePayOff_):
	TreeProduct(FinalTime_),
	ThePayOff(ThePayOff_)
{}

TreeProduct* TreeEuropean::clone() const
{
	return new TreeEuropean(*this);
}

double TreeEuropean::FinalPayOff(double Spot) const
{
	return ThePayOff(Spot);
}

double TreeEuropean::PreFinalValue(double Spot, double Time, double DiscountedFutureValue) const
{
	return DiscountedFutureValue;
}
