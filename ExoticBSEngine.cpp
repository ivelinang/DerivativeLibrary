#include "ExoticBSEngine.h"
#include <cmath>

void ExoticBSEngine::GetOnePath(MJArray& SpotValues)
{
	TheGenerator->GetGaussians(Variates);

	double CurrentLogSpot = LogSpot;

	for (unsigned long j = 0; j < NumberOfTimes; j++)
	{
		CurrentLogSpot += Drifts[j];
		CurrentLogSpot += StandardDeviations[j] * Variates[j];
		SpotValues.setValue(j, exp(CurrentLogSpot));
	}

	return;
} 

ExoticBSEngine::ExoticBSEngine(const Wrapper<PathDependent>& TheProduct_,
	const Parameters& R_,
	const Parameters& D_,
	const Parameters& Vol_,
	const Wrapper<RandomBase>& TheGenerator_,
	double Spot_) :
	ExoticEngine(TheProduct_, R_),
	TheGenerator(TheGenerator_),
	Drifts(0),
	StandardDeviations(0),
	Variates(0)
{
	MJArray Times(TheProduct_->GetLookAtTimes());
	NumberOfTimes = Times.getSize();

	TheGenerator->ResetDimensionality(NumberOfTimes);

	Drifts.resize(NumberOfTimes);
	StandardDeviations.resize(NumberOfTimes);

	double Variance = Vol_.IntegralSquare(0, Times[0]);

	Drifts.setValue(0, R_.Integral(0.0, Times[0]) - D_.Integral(0.0, Times[0]) - 0.5*Variance);
	StandardDeviations.setValue(0, sqrt(Variance));

	for (unsigned long j = 1; j < NumberOfTimes; ++j)
	{ 
		double thisVariance = Vol_.IntegralSquare(Times[j - 1], Times[j]);
		Drifts.setValue(j, R_.Integral(Times[j - 1], Times[j]) - D_.Integral(Times[j - 1], Times[j])-0.5*thisVariance);
		StandardDeviations.setValue(j,sqrt(thisVariance));

	}

	LogSpot = log(Spot_);
	Variates.resize(NumberOfTimes);


}