#pragma once
#include "Design_Department_Tram.h"
#include "Exception.h"

class Russian_Tram : public Tram
{
	char name[20];
	int cost;
	int route_number;
	int production_year;
	int year_of_commisisioning;
	char color[20];
	int number_of_passanger;
	int cargo_volume;
	int type=2;

public:
	virtual void set_name(char * _name);
	virtual void set_cost(int _cost);
	virtual void set_route_number(int _route_number);
	virtual void set_production_year(int _production_year);
	virtual void set_year_of_commisisioning(int _year_of_commisisioning);
	virtual void set_color(char* _color) ;
	virtual void set_number_of_passanger(int _number_of_passenger);
	virtual void set_cargo_volume(int _cargo_volume);

	char* get_name();
	int get_cost();
	int get_route_number();
	int get_production_year();
	int get_year_of_commisisioning();
	char* get_color();
	int get_number_of_passanger();
	int get_cargo_volume();
	int get_type();

	void set();
	void info();
};

