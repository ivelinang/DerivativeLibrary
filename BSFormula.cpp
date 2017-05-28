#include "BSFormula.h"
#include "Normals2.h"
#include <cmath>

double BlackScholesCall(double Spot,
	double Strike,
	double r,
	double d,
	double vol,
	double expiry)
{
	double standardDeviation = vol*sqrt(expiry);	double moneyness = log(Spot / Strike);	double d1 = (moneyness + (r - d)*expiry + 0.5* standardDeviation*standardDeviation) / standardDeviation;	double d2 = d1 - standardDeviation;	NormalDistribution nm;	return Spot*exp(-d*expiry) * nm.CumulativeNormal(d1) - Strike*exp(-r*expiry)*nm.CumulativeNormal(d2);
}

double BlackScholesPut(double Spot,
	double Strike,
	double r,
	double d,
	double vol,
	double expiry)
{
	double standardDeviation = vol*sqrt(expiry);	double moneyness = log(Spot / Strike);	double d1 = (moneyness + (r - d)*expiry + 0.5* standardDeviation*standardDeviation) / standardDeviation;	double d2 = d1 - standardDeviation;	NormalDistribution nm;	return -Spot*exp(-d*expiry) *(1- nm.CumulativeNormal(d1)) + Strike*exp(-r*expiry)*(1-nm.CumulativeNormal(d2));
}

double BlackScholesDigitalCall(double Spot,
	double Strike,
	double r,
	double d,
	double vol,
	double expiry)
{
	double standardDeviation = vol*sqrt(expiry);	double moneyness = log(Spot / Strike);	double d2 = (moneyness + (r - d)*expiry - 0.5* standardDeviation*standardDeviation) / standardDeviation;	NormalDistribution nm;	return exp(-r*expiry)*nm.CumulativeNormal(d2);
}

double BlackScholesCallVega(double Spot,
	double Strike,
	double r,
	double d,
	double vol,
	double expiry)
{
	double standardDeviation = vol*sqrt(expiry);	double moneyness = log(Spot / Strike);	double d1 = (moneyness + (r - d)*expiry + 0.5* standardDeviation*standardDeviation) / standardDeviation;	NormalDistribution nm;	return Spot*exp(-d*expiry) * sqrt(expiry)*nm.NormalDensity(d1);
}

double BlackScholesCallVega2(double Spot,
	double Strike,
	double r,
	double d,
	double vol,
	double expiry)
{
	double eps = 0.0001;
	double priceUp = BlackScholesCall(Spot, Strike, r, d, vol + eps, expiry);
	double priceDown = BlackScholesCall(Spot, Strike, r, d, vol - eps, expiry);

	return (priceUp - priceDown) / eps;
}


