#include "PathDependentAsian2.h"

PathDependentAsian2::PathDependentAsian2(const MJArray& LookAtTimes_,
double DeliveryTime_,
const PayOffBridge& ThePayOff_) :

PathDependent(LookAtTimes_), 
DeliveryTime(DeliveryTime_),
ThePayOff(ThePayOff_),
NumberOfTimes(LookAtTimes_.getSize())
{}

unsigned long PathDependentAsian2::MaxNumberOfCashFlows() const
{
	return 1UL;
}

MJArray PathDependentAsian2::PossibleCashFlows() const
{
	MJArray tmp(1UL);
	tmp.setValue(0, DeliveryTime);
	return tmp;
}

unsigned long PathDependentAsian2::CashFlows(const MJArray& SpotValues,
	std::vector<CashFlow>& GeneratedFlows) const
{
	double sum = SpotValues.sum();
	double mean = sum / NumberOfTimes;

	GeneratedFlows[0].TimeIndex = 0UL;
	GeneratedFlows[0].Amount = ThePayOff(mean);

	return 1UL;
}

PathDependent* PathDependentAsian2::clone() const
{
	return new PathDependentAsian2(*this);
}