#pragma once
#ifndef SIMPLEMC6_H
#define SIMPLEMC6_H

#include "Vanilla1.h"
#include "Parameters.h"

double SimpleMonteCarlo4(const VanillaOption& TheOption,	double Spot,	const Parameters& Vol,	const Parameters& r,	unsigned long NumberOfPaths);

#endif // !SIMPLEMC6_H
