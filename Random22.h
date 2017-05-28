#pragma once
#ifndef RANDOM22_H
#define RANDOM22_H

#include "Array.h"
#include "Normals2.h"

class RandomBase
	virtual void GetUniforms(MJArray& variates) = 0;

private:
	unsigned long Dimensionality;
};

#endif // !RANDOM22_H