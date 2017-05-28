#pragma once
#ifndef CONVERGENCETABLE_H
#define CONVERGENCETABLE_H

#include "MCStatistics.h"
#include "Wrapper.h"

class ConvergenceTable : public StatisticsMC
{
public:
	ConvergenceTable(const Wrapper<StatisticsMC>& inner_);

	virtual StatisticsMC* clone() const;
	virtual void DumpOneResult(double result);
	virtual std::vector<std::vector<double>> GetResultsSoFar() const;

private:
	Wrapper<StatisticsMC> Inner;
	std::vector<std::vector<double>> ResultsSoFar;
	unsigned long StoppingPoint;
	unsigned long PathsDone;
};

#endif // !CONVERGENCETABLE_H
