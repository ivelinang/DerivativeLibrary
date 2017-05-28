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
	double standardDeviation = vol*sqrt(expiry);
}

double BlackScholesPut(double Spot,
	double Strike,
	double r,
	double d,
	double vol,
	double expiry)
{
	double standardDeviation = vol*sqrt(expiry);
}

double BlackScholesDigitalCall(double Spot,
	double Strike,
	double r,
	double d,
	double vol,
	double expiry)
{
	double standardDeviation = vol*sqrt(expiry);
}

double BlackScholesCallVega(double Spot,
	double Strike,
	double r,
	double d,
	double vol,
	double expiry)
{
	double standardDeviation = vol*sqrt(expiry);
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

