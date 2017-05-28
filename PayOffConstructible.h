#pragma once
#ifndef PAYOFFCONSTRUCTIBLE_H
#define PAYOFFCONSTRUCTIBE_H

#include <iostream>
#include "PayOff2.h"
#include "PayOffFactory.h"
#include <string>

template <class T>
class PayOffHelper
{
public:
	PayOffHelper(std::string id);
	static PayOff* Create(double);
};

template <class T>
PayOff* PayOffHelper<T>::Create(double Strike)
{
	return new T(Strike);
};

template <class T>
PayOffHelper<T>::PayOffHelper(std::string id)
{
	PayOffFactory& thePayOffFactory = PayOffFactory::Instance();
	thePayOffFactory.RegisterPayOff(id, PayOffHelper<T>::Create);
};



#endif // !PAYOFFCONSTRUCTIBLE_H
