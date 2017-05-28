#include "Normals2.h"
#include <cmath>


double NormalDistribution::getPi()
{
	return OneOverRootTwoPi*exp(-x*x / 2);
}

double NormalDistribution::CumulativeNormal(double x)
{
	static double a[5] = { 0.319381530,
}

double NormalDistribution::InverseCumulativeNormal(double u)
{
	static double a[4] = { 2.50662823884,

	static double b[4] = { -8.47351093090,
	double x = u - 0.5;

	if (fabs(x)<0.42) // Beasley-Springer
	

	return r;
}

double NormalDistribution::RationalApproximation(double t)
{
	// Abramowitz and Stegun formula 26.2.23.
	// The absolute value of the error should be less than 4.5 e-4.
	double c[] = { 2.515517, 0.802853, 0.010328 };
	double d[] = { 1.432788, 0.189269, 0.001308 };
	return t - ((c[2] * t + c[1])*t + c[0]) /
		(((d[2] * t + d[1])*t + d[0])*t + 1.0);
}

double NormalDistribution::NormalCDFInverse(double p)
{
	if (p <= 0.0 || p >= 1.0)
	{
		throw("invalid arguement 0,1");
	}

	// See article above for explanation of this section.
	if (p < 0.5)
	{
		// F^-1(p) = - G^-1(p)
		return -RationalApproximation(sqrt(-2.0*log(p)));
	}
	else
	{
		// F^-1(p) = G^-1(1-p)
		return RationalApproximation(sqrt(-2.0*log(1 - p)));
	}

}