#include "AntiThetic2.h"
#include <iostream>


AntiThetic::AntiThetic(const Wrapper<RandomBase>& innerGenerator)
	:RandomBase(*innerGenerator),
	InnerGenerator(innerGenerator),
	NextVariates(MJArray(3))	
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

		//std::cout << "gausians " << variates[0] <<"\n";

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
	OddEven = true;
}

void AntiThetic::Skip(unsigned long numberOfPaths)
{
	if (numberOfPaths == 0)
		return;

	if (OddEven)	{		OddEven = false;		numberOfPaths--;	}		if (numberOfPaths % 2)	{		MJArray tmp(GetDimensionality());		GetUniforms(tmp);	}
}


void AntiThetic::ResetDimensionality(unsigned long NewDimensionality){	RandomBase::ResetDimensionality(NewDimensionality);	NextVariates.resize(NewDimensionality);	InnerGenerator->ResetDimensionality(NewDimensionality);		}void AntiThetic::Reset(){		OddEven = true;}unsigned long AntiThetic::GetDimensionality() const{	return RandomBase::GetDimensionality();}