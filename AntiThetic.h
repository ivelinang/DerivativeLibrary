#pragma once
#ifndef ANTITHETIC_H
#define ANTITHETIC_H

#include "Random2.h"
#include "Wrapper.h"
//#include "Normals.h"

class AntiThetic : RandomBase{public:	AntiThetic(RandomBase* innerGenerator);	virtual RandomBase* clone() const;	virtual void GetUniforms(MJArray& variates);	virtual void Skip(unsigned long numberOfPaths);	virtual void SetSeed(unsigned long Seed);	virtual void ResetDimensionality(unsigned long NewDimensionality);	virtual void Reset();	unsigned long GetDimensionality() const;private:	RandomBase* InnerGenerator;	bool OddEven;	MJArray NextVariates;};


#endif // !ANTITHETIC_H
