#pragma once
#ifndef RANDOM_H
#define RANDOM_H

#include "Array.h"


class RandomBase
{
public:

	RandomBase();

	unsigned long GetDimensionality() const; 

	virtual RandomBase* clone() const = 0;
	virtual void GetUniforms(MJArray& variates) = 0;
	virtual void Skip(unsigned long numberOfPaths) = 0;
	virtual void SetSeed(unsigned long Seed) = 0;
	virtual void Reset() = 0;

	void GetGaussians(MJArray& variates);
	

	void ResetDimensionality(unsigned long NewDimensionality);
	

private:
	int Dimensionality;

};


#endif // !RANDOM_H
