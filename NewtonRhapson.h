#pragma once
#ifndef NEWTONRHAPSON_H
#define NEWTONRHAPSON_H

template<class T, double (T::*Value)(double) const, double (T::*Derivative)(double) const>
double NewtonRhapson(double Target,
	double Start,
	double Tolerance,
	const T& TheObject)
{
	double y = (TheObject.*Value)(Start);

	double x = Start;

	while (fabs(y - Target) > Tolerance)
	{
		double d = (TheObject.*Derivative)(x);

		x += (Target - y) / d;

		y = (TheObject.*Value)(x);
	}

	return x;
}

#endif // !NEWTONRHAPSON_H
