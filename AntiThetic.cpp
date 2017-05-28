/*
#include "AntiThetic.h"

AntiThetic::AntiThetic(RandomBase* innerGenerator)
	:RandomBase(2), 
InnerGenerator(innerGenerator), 
OddEven(true),
NextVariates(MJArray(0))
{
	InnerGenerator->Reset();
	OddEven = true;
	NextVariates.resize(GetDimensionality());
}

RandomBase* AntiThetic::clone() const
{
	return new AntiThetic(*this);
}

void AntiThetic::GetUniforms(MJArray& variates)
{
	if (OddEven)
	{
		InnerGenerator->GetUniforms(variates);
		for (unsigned long i = 0; i < GetDimensionality(); i++)
			NextVariates.setValue(i, 1.0 - variates[i]);
		OddEven = false;
	}
	else
	{
		variates = NextVariates;
		OddEven = true;
	}
}

void AntiThetic::SetSeed(unsigned long Seed)
{
	InnerGenerator->SetSeed(Seed);
	OddEven = true;
}

void AntiThetic::Skip(unsigned long numberOfPaths)
{
	if (numberOfPaths == 0)
		return;

	if (OddEven)
}


void AntiThetic::ResetDimensionality(unsigned long NewDimensionality)