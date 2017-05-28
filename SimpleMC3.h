#pragma once
#ifndef SIMPLEMC3_H
#define SIMPLEMC3_H

#include "Vanilla1.h"

double SimpleMonteCarlo3(const VanillaOption& TheOptions,
	double Spot,
	double Vol,
	double r,
	unsigned long NumberOfPaths);
#endif // !SIMPLEMC3_H
