#pragma once
#ifndef TREEAMERICAN_H
#define TREEAMERICAN_H

#include "TreeProduct.h"
#include "PayOffBridge2.h"

class TreeAmerican : public TreeProduct
{
public:
	TreeAmerican(double FinalTime_, const PayOffBridge& ThePayOff_);

	virtual TreeProduct* clone() const;
	virtual double FinalPayOff(double Spot) const;
	virtual double PreFinalValue(double Spot, double Time, double DiscountedValue) const;

	virtual ~TreeAmerican() {};

private:
	PayOffBridge ThePayOff;
};

#endif // !TREEAMERICAN_H
