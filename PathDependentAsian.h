#pragma once
#ifndef PATHDEPENDENTASIAN_H
#define PATHDEPENDENTASIAN_H

#include "PathDependent.h"
#include "PayOff2.h"

class PathDependentAsian : public PathDependent
{
public:
	PathDependentAsian(const MJArray& LookAtTimes_,
		double DeliveryTime_,
		const PayOff& ThePayOff_);

	virtual unsigned long MaxNumberOfCashFlows() const;
	virtual MJArray PossibleCashFlows() const;
	virtual unsigned long CashFlows(const MJArray& SpotValues,
		std::vector<CashFlow>& GeneratedFlows) const;

	virtual ~PathDependentAsian() {};
	virtual PathDependent* clone() const;

private:
	double DeliveryTime;
	PayOff* ThePayOff;
	unsigned long NumberOfTimes;
};

#endif // !PATHDEPENDENTASIAN_H
