#include "Assembly_Tram.h"

void Russian_Tram::set_name(char * _name)
{
	strcpy(name, _name);
}

void Russian_Tram::set_cost(int _cost)
{
	cost = _cost;
}

void Russian_Tram::set_route_number(int _route_number)
{
	route_number = _route_number;
}

void Russian_Tram::set_production_year(int _production_year)
{
	production_year = _production_year;
}

void Russian_Tram::set_color(char* _color)
{
	strcpy(color, _color);
}

void Russian_Tram::set_number_of_passanger(int _number_of_passanger)
{
	number_of_passanger = _number_of_passanger;
}

void Russian_Tram::set_cargo_volume(int _cargo_volume)
{
	cargo_volume = _cargo_volume;
}

void Russian_Tram::set_year_of_commisisioning(int _year_of_commisisioning)
{
	year_of_commisisioning = _year_of_commisisioning;
}

char * Russian_Tram::get_name()
{
	return name;
}

int Russian_Tram::get_cost()
{
	return cost;
}

int Russian_Tram::get_route_number()
{
	return route_number;
}

int Russian_Tram::get_production_year()
{
	return production_year;
}


char * Russian_Tram::get_color()
{
	return color;
}


int Russian_Tram::get_number_of_passanger()
{
	return number_of_passanger;
}

int Russian_Tram::get_cargo_volume()
{
	return cargo_volume;
}

int Russian_Tram::get_year_of_commisisioning()
{
	return year_of_commisisioning;
}

int Russian_Tram::get_type()
{
	return type;
}

void Russian_Tram::set()
{
	Exception ex;
	string text;
	cout << endl << "Трамвай" << endl;
	cout << "Введите название: ";
	cin >> name;
	text = "Введите стоимость: ";						while (ex.is_digit(cost, text)); // исключение
	text = "Введите номер маршрута: ";					while (ex.is_digit(route_number, text)); // исключение
	text = "Введите год выпуска: ";						while (ex.is_digit(production_year, text)); // исключение
	text = "Введите время экспуатации: ";				while (ex.is_digit(year_of_commisisioning, text)); // исключение
	cout << "Введите цвет : ";							cin >> color;
	text = "Введите число пассажиров: ";				while (ex.is_digit(number_of_passanger, text)); // исключение
	text = "Введите объём груза: ";						while (ex.is_digit(cargo_volume, text)); // исключение

}

void Russian_Tram::info()
{
	cout << endl << "Трамвай" << endl;
	cout << "Назавние \t\t\t" << name << endl;
	cout << "Стоимость\t\t\t" << cost << endl;
	cout << "Номер маршрута \t\t\t" << route_number << endl;
	cout << "Год производства \t\t" << production_year << endl;
	cout << "Год в эксплуатации \t\t" << year_of_commisisioning << endl;
	cout << "Цвет \t\t\t\t" << color << endl;
	cout << "Кол-во пассажиров \t\t" << number_of_passanger << endl;
	cout << "Объём груза \t\t\t" << cargo_volume << endl;
}
