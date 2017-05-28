#pragma once
#ifndef PAYOFFBRIDGE_H
#define PAYOFFBRIDGE_H

#include "PayOff2.h"

class PayOffBridge
{
public:
	PayOffBridge(const PayOffBridge& original);
	PayOffBridge(const PayOff& innerPayOff);
	inline double operator()(double Spot) const;
	~PayOffBridge();
	PayOffBridge& operator=(const PayOffBridge& original);
private:
	PayOff* ThePayOffPtr;

};

inline double PayOffBridge::operator()(double Spot) const
#endif // !PAYOFFBRIDGE_H