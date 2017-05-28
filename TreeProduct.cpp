#include "TreeProduct.h"

TreeProduct::TreeProduct(double FinalTime_):
	FinalTime(FinalTime_)
{}

double TreeProduct::getFinalTime() const
{
	return FinalTime;
}