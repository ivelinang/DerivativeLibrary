#pragma once
#ifndef TREEEUROPEAN_H
#define TREEEUROPEAN_H

#include "TreeProduct.h"
#include "PayOffBridge2.h"

class TreeEuropean : public TreeProduct
{
public:
	TreeEuropean(double FinalTime_, const PayOffBridge& ThePayOff_);

	virtual TreeProduct* clone() const;
	virtual double FinalPayOff(double Spot) const;
	virtual double PreFinalValue(double Spot, double Time, double DiscountedValue) const;

	virtual ~TreeEuropean() {};

private:
	PayOffBridge ThePayOff;

};

#endif // !TREEEUROPEAN_H
