#pragma once
#ifndef NORMALS2_H
#define NORMALS2_H

class NormalDistribution
{
public:
	NormalDistribution() {};
	double getPi();
	double NormalDensity(double x);
	double CumulativeNormal(double x);
	double InverseCumulativeNormal(double x);
	double RationalApproximation(double t);
	double NormalCDFInverse(double p);

private:
	const double OneOverRootTwoPi = 0.398942280401433;
};
#endif // !NORMALS2_H
