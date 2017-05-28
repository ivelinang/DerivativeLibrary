#include "Random22.h"
#include "Normals2.h"
#include <iostream>

RandomBase::RandomBase(unsigned long Dimensionality_)
	: Dimensionality(Dimensionality_){}unsigned long RandomBase::GetDimensionality() const{	return Dimensionality;}void RandomBase::GetGaussians(MJArray& variates){	GetUniforms(variates);		NormalDistribution nm;	for (unsigned long i = 0; i < Dimensionality; i++)	{		double x = variates[i];		variates.setValue(i, nm.NormalCDFInverse(x));			}	}void RandomBase::ResetDimensionality(unsigned long NewDimensionality){	Dimensionality = NewDimensionality;}