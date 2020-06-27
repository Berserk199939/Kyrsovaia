#pragma once

class LT_Auto
{
public:
	virtual void set_name(char*) = 0;
	virtual void set_cost(int) = 0;
	virtual void set_engine_volume(int) = 0;
	virtual void set_route_number(int) = 0;
	virtual void set_production_year(int) = 0;
	virtual void set_color(char*) = 0;
	virtual void set_fuel_type(char*) = 0;
	virtual void set_number_of_passanger(int) = 0;
	virtual void set_cargo_volume(int) = 0;

	virtual char* get_name() = 0;
	virtual int get_cost() = 0;
	virtual int get_engine_volume() = 0;
	virtual int get_route_number() = 0;
	virtual int get_production_year() = 0;
	virtual int get_year_of_commisisioning() = 0;
	virtual char* get_fuel_type() = 0;
	virtual char* get_color() = 0;
	virtual int get_number_of_passanger() = 0;
	virtual int get_cargo_volume() = 0;
	virtual int get_type() = 0;


	virtual void set_year_of_commisisioning(int) = 0;
	virtual void set() = 0;
	virtual void info() = 0;
	virtual ~LT_Auto() {}
};