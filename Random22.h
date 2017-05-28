#pragma once
#ifndef RANDOM22_H
#define RANDOM22_H

#include "Array.h"
#include "Normals2.h"

class RandomBase{public:	RandomBase(unsigned long Dimensionality);	unsigned long GetDimensionality() const;	virtual RandomBase* clone() const = 0;
	virtual void GetUniforms(MJArray& variates) = 0;	virtual void Skip(unsigned long numberOfPaths) = 0;	virtual void SetSeed(unsigned long Seed) = 0;	virtual void Reset() = 0;	void GetGaussians(MJArray& variates);	void ResetDimensionality(unsigned long NewDimensionality);

private:
	unsigned long Dimensionality;
};

#endif // !RANDOM22_H
