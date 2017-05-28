#include "SimpleMC8.h"
#include <cmath>
#include "Array.h"
#include <iostream>

void SimpleMonteCarlo6(const VanillaOption& TheOption,
	double Spot,
	const Parameters& Vol,
	const Parameters& r,
	unsigned long NumberOfPaths,
	StatisticsMC& gatherer,
	RandomBase& generator)
{
	generator.ResetDimensionality(1);

	double Expiry = TheOption.getExpiry();
	double variance = Vol.IntegralSquare(0, Expiry);
	double rootVariance = sqrt(variance);
	double iToCorrection = -0.5*variance;
	double movedSpot = Spot*exp(r.Integral(0, Expiry) + iToCorrection);

	double thisSpot;
	double discounting = exp(-r.Integral(0, Expiry));

	MJArray VariateArray(1);

	for (unsigned long i = 0; i < NumberOfPaths; i++)
	{
		generator.GetGaussians(VariateArray);
		thisSpot = movedSpot*exp(rootVariance*VariateArray[0]);
		double thisPayOff = TheOption.OptionPayOff(thisSpot);
		gatherer.DumpOneResult(thisPayOff*discounting);

		//std::cout << "payoff " << thisPayOff<< "\n";
		//std::cout << "spot " << thisSpot << "\n";
		//std::cout << "random " << VariateArray[0] << "\n";
	}
	std::cin.get();
	return;
} 