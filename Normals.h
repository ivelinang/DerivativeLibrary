#pragma once
#ifndef NORMALS_H
#define NORMALS_H

class NormalProbability
{
public:
	NormalProbability() {};

	double NormalDensity(double x);

	double tryDD(double x);

};



#endif // !NORMALS_H