#pragma warning (disable: 4786)
#ifndef BINOMIALTREE_H
#define BINOMIALTREE_H

#include "TreeProduct.h"
#include <vector>
#include "Parameters.h"
#include "Array.h"

class SimpleBinomialTree
{
public:
	SimpleBinomialTree(double Spot_, const Parameters& r_, const Parameters& d_, double Volatility, unsigned long Steps, double Time);

	double getThePrice(const TreeProduct& TheTreeProduct);

protected:
	void BuildTree();

private:
	double Spot;
	Parameters r;
	Parameters d;
	double Volatility;
	unsigned long Steps;
	double Time;
	bool isTreeBuilt;

	std::vector<std::vector<std::pair<double, double>>> TheTree;
	MJArray Discounts;

};

#endif // !BINOMIALTREE_H

