#include "Assembly_TSFactory.h"

Truck * Russian_TSFactory::create_Truck()
{
	return new Russian_Truck;
}

LT_Auto * Russian_TSFactory::create_LT_Auto()
{
	return new Russian_LT_Auto;
}

Tram * Russian_TSFactory::create_Tram()
{
	return new Russian_Tram;
}
