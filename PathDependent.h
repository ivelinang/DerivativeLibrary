#pragma once
#ifndef PATH_DEPENDENT_H
#define PATH_DEPENDENT_H
#include "Array.h"
#include <vector>

class CashFlow 
{
public:
	double Amount;
	unsigned long TimeIndex;

	CashFlow(unsigned long TimeIndex_ = 0.0, double Amount_ = 0.0) :
		TimeIndex(TimeIndex_),
		Amount(Amount_) {};



};

class PathDependent
{
public:
	PathDependent(const MJArray& LookAtTimes);
	const MJArray& GetLookAtTimes() const;

	virtual unsigned long MaxNumberOfCashFlows() const = 0;
	virtual MJArray PossibleCashFlows() const = 0;
	virtual unsigned long CashFlows(const MJArray& SpotValues, std::vector<CashFlow>& GeneratedCashFlows) const = 0;

	virtual PathDependent* clone() const = 0;
	virtual ~PathDependent() {};

private:
	MJArray LookAtTimes;

};

#endif // !PATH_DEPENDENT_H
