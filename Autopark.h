#pragma once
#include "Header.h"
#include "Design_Department_Truck.h"
#include "Design_Department_LT_Auto.h"
#include "Design_Department_Tram.h"
#include "Exception.h"
#include "TSFactory.h"


class Autopark
{
	friend class New_Autopark;
private:

	Truck ** TR;
	LT_Auto** LT;
	Tram** TM;

	int TR_size;
	int LT_size;
	int TM_size;


public:

	Autopark();
	void initialization();
	void set();
	void info();
	void save_to_file(const char * filename1, const char* filename2, const char* filename3);
	void read_from_file(const char * filename1, const char* filename2, const char* filename3, TSFactory& factory);
	~Autopark();

};

