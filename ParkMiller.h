#pragma once
#ifndef PARKMILLER_H
#define PARKMILLER_H

#include "Random22.h"

class ParkMiller{public:	ParkMiller(int a);	static unsigned long Max();	static unsigned long Min();	long GetOneRandomInteger();	void SetSeed(long Seed);};class RandomParkMiller : public RandomBase{public:	RandomParkMiller(unsigned long Dimensionality, unsigned long Seed = 1);	virtual RandomBase* clone() const;	virtual void GetUniforms(MJArray& variates);	virtual void Skip(unsigned long numberOfPaths);	virtual void SetSeed(unsigned long Seed);	virtual void Reset();	virtual void ResetDimensionality(unsigned long NewDimensionality);private:	ParkMiller InnerGenerator;	unsigned long InitialSeed;	double Reciprocal;};

#endif // !PARKMILLER_H
