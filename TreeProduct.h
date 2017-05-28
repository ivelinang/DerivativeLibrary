#pragma once
#ifndef TREEPRODUCT_H
#define TREEPRODUCT_H

class TreeProduct
{
public:
	TreeProduct(double FinalTime_);
	virtual double FinalPayOff(double Spot) const = 0;
	virtual double PreFinalValue(double Spot, double Time, double DiscountedValue) const = 0;

	virtual ~TreeProduct() {};
	virtual TreeProduct* clone() const = 0;
	double getFinalTime() const;

private:
	double FinalTime;
};

#endif // !TREEPRODUCT_H
