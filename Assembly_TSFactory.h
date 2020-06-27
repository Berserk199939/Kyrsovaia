#pragma once
#include "TSFactory.h"
#include "Assembly_Truck.h"
#include "Assembly_LT_Auto.h"
#include "Assembly_Tram.h"


class Russian_TSFactory :	public TSFactory
{
public:
	Truck * create_Truck();
	LT_Auto* create_LT_Auto(); 
	Tram* create_Tram();

};

