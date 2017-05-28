#include "PayOffFactory.h"
#include <iostream>

void PayOffFactory::RegisterPayOff(std::string PayOffID, CreatePayOffFunction creatorFunction)
{
	TheCreatorFunctions.insert(std::pair<std::string, CreatePayOffFunction>(PayOffID, creatorFunction));
}

PayOff* PayOffFactory::CreatePayOff(std::string PayOffID, double Strike)
{
	std::map<std::string, CreatePayOffFunction>::const_iterator i = TheCreatorFunctions.find(PayOffID);

	if (i == TheCreatorFunctions.end())
	{
		std::cout << PayOffID << " is an unknown payoff" << std::endl;
		return NULL;
	}

	return (i->second)(Strike);
}

PayOffFactory& PayOffFactory::Instance()
{
	static PayOffFactory theFactory;
	return theFactory;
}