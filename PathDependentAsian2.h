#pragma once
#ifndef PATHDEPENDENTASIAN2_H
#define PATHDEPENDENTASIAN2_H

#include "PathDependent.h"
#include "PayOffBridge2.h"

class PathDependentAsian2: public PathDependent
{
public:
	PathDependentAsian2(const MJArray& LookAtTimes_,
		double DeliveryTime_,
		const PayOffBridge& ThePayOff_);

	virtual unsigned long MaxNumberOfCashFlows() const;
	virtual MJArray PossibleCashFlows() const;
	virtual unsigned long CashFlows(const MJArray& SpotValues,
		std::vector<CashFlow>& GeneratedFlows) const;

	virtual ~PathDependentAsian2() {};
	virtual PathDependent* clone() const;

private:
	double DeliveryTime;
	PayOffBridge ThePayOff;
	unsigned long NumberOfTimes;
};



#endif // !PATHDEPENDENTASIAN2_H
