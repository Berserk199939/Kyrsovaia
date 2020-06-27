#include "Autopark.h"

Autopark::Autopark()
{
	TR = nullptr;
	LT = nullptr;
	TM = nullptr;


	TR_size = NULL;
	LT_size = NULL;
	TM_size = NULL;



	TR = new Truck*[N];
	LT = new LT_Auto*[N];
	TM = new Tram*[N];

}


void Autopark::initialization()
{
	Exception ex;

	cout << endl;
	string text = "Введите количество Грузовиков >> ";
	while (ex.is_digit(TR_size, text));
	text = "Введите количетсво легкового авто >> ";
	while (ex.is_digit(LT_size, text));
	text = "Введите количество трамваев >> ";
	while (ex.is_digit(TM_size, text));

}

void Autopark::set()
{
	for (int i = 0; i < TR_size; ++i)  TR[i]->set();
	for (int i = 0; i < LT_size; ++i)  LT[i]->set();
	for (int i = 0; i < TM_size; ++i)  TM[i]->set();

}

void Autopark::info()
{
	for (int i = 0; i < TR_size; ++i)  TR[i]->info();
	for (int i = 0; i < LT_size; ++i)  LT[i]->info();
	for (int i = 0; i < TM_size; ++i)  TM[i]->info();

}

void Autopark::save_to_file(const char* filename1, const char* filename2, const char* filename3)
{
	ofstream f1;
	ofstream f2;
	ofstream f3;
	char buffer_char[20];
	int buffer_int;

	try
	{
		f1.open(filename1, ios::binary | ios::out);
		if (!f1.is_open()) {
			throw 505;
		}

		f2.open(filename2, ios::binary | ios::out);
		if (!f2.is_open()) {
			throw 505;
		}

		f3.open(filename3, ios::binary | ios::out);
		if (!f3.is_open()) {
			throw 505;
		}

		f1.write(reinterpret_cast<char*>(&TR_size), sizeof(int));
		f2.write(reinterpret_cast<char*>(&LT_size), sizeof(int));
		f3.write(reinterpret_cast<char*>(&TM_size), sizeof(int));


		for (int i = 0; i < TR_size; i++) {
			strcpy(buffer_char, TR[i]->get_name());					f1.write(reinterpret_cast<char*>(&buffer_char), sizeof(buffer_char));
			buffer_int = TR[i]->get_cost();							f1.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = TR[i]->get_engine_volume();				f1.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = TR[i]->get_route_number();					f1.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = TR[i]->get_production_year();				f1.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = TR[i]->get_year_of_commisisioning();		f1.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			strcpy(buffer_char, TR[i]->get_color());				f1.write(reinterpret_cast<char*>(&buffer_char), sizeof(buffer_char));
			strcpy(buffer_char, TR[i]->get_fuel_type());			f1.write(reinterpret_cast<char*>(&buffer_char), sizeof(buffer_char));
			buffer_int = TR[i]->get_number_of_passanger();			f1.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = TR[i]->get_cargo_volume();					f1.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
		}
		for (int i = 0; i < LT_size; i++) {
			strcpy(buffer_char, LT[i]->get_name());					f2.write(reinterpret_cast<char*>(&buffer_char), sizeof(buffer_char));
			buffer_int = LT[i]->get_cost();							f2.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = LT[i]->get_engine_volume();				f2.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = LT[i]->get_route_number();					f2.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = LT[i]->get_production_year();				f2.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = LT[i]->get_year_of_commisisioning();		f2.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			strcpy(buffer_char, LT[i]->get_color());				f2.write(reinterpret_cast<char*>(&buffer_char), sizeof(buffer_char));
			strcpy(buffer_char, LT[i]->get_fuel_type());			f2.write(reinterpret_cast<char*>(&buffer_char), sizeof(buffer_char));
			buffer_int = LT[i]->get_number_of_passanger();			f2.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = LT[i]->get_cargo_volume();					f2.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
		}
		for (int i = 0; i < TM_size; i++) {
			strcpy(buffer_char, TM[i]->get_name());					f3.write(reinterpret_cast<char*>(&buffer_char), sizeof(buffer_char));
			buffer_int = TM[i]->get_cost();							f3.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = TM[i]->get_route_number();					f3.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = TM[i]->get_production_year();				f3.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = TM[i]->get_year_of_commisisioning();		f3.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			strcpy(buffer_char, TM[i]->get_color());				f3.write(reinterpret_cast<char*>(&buffer_char), sizeof(buffer_char));
			buffer_int = TM[i]->get_number_of_passanger();			f3.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = TM[i]->get_cargo_volume();					f3.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
		}



		f1.close();
		f2.close();
		f3.close();
	}
	catch (const int ex)
	{
		//SetColor(12, 1);
		cout << "Ошибка открытия файла!" << endl << "Код ошибки: #" << ex << endl;
		//SetColor(14, 1);
	}
}

void Autopark::read_from_file(const char * filename1, const char* filename2, const char* filename3, TSFactory & factory)
{
	char buffer_char[20];
	int buffer_int;
	ifstream in1,in2,in3;
	try
	{
		in1.open(filename1, ios::binary | ios::in);
		if (!in1.is_open()) {
			throw 505;
		}

		in2.open(filename2, ios::binary | ios::in);
		if (!in2.is_open()) {
			throw 505;
		}

		in3.open(filename3, ios::binary | ios::in);
		if (!in3.is_open()) {
			throw 505;
		}




		in1.read(reinterpret_cast<char*>(&TR_size), sizeof(int));
		in2.read(reinterpret_cast<char*>(&LT_size), sizeof(int));
		in3.read(reinterpret_cast<char*>(&TM_size), sizeof(int));



		for (int i = 0; i < TR_size; ++i)  TR[i] = factory.create_Truck();
		for (int i = 0; i < LT_size; ++i)  LT[i] = factory.create_LT_Auto();
		for (int i = 0; i < TM_size; ++i)  TM[i] = factory.create_Tram();


		for (int i = 0; i < TR_size; i++) {
			in1.read(reinterpret_cast<char*>(&buffer_char), sizeof(buffer_char));	TR[i]->set_name(buffer_char);
			in1.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				TR[i]->set_cost(buffer_int);
			in1.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				TR[i]->set_engine_volume(buffer_int);
			in1.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				TR[i]->set_route_number(buffer_int);
			in1.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				TR[i]->set_production_year(buffer_int);
			in1.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				TR[i]->set_year_of_commisisioning(buffer_int);
			in1.read(reinterpret_cast<char*>(&buffer_char), sizeof(buffer_char));	TR[i]->set_color(buffer_char);
			in1.read(reinterpret_cast<char*>(&buffer_char), sizeof(buffer_char));	TR[i]->set_fuel_type(buffer_char);
			in1.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				TR[i]->set_number_of_passanger(buffer_int);
			in1.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				TR[i]->set_cargo_volume(buffer_int);
		}
		for (int i = 0; i < LT_size; i++) {
			in2.read(reinterpret_cast<char*>(&buffer_char), sizeof(buffer_char));	LT[i]->set_name(buffer_char);
			in2.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				LT[i]->set_cost(buffer_int);
			in2.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				LT[i]->set_engine_volume(buffer_int);
			in2.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				LT[i]->set_route_number(buffer_int);
			in2.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				LT[i]->set_production_year(buffer_int);
			in2.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				LT[i]->set_year_of_commisisioning(buffer_int);
			in2.read(reinterpret_cast<char*>(&buffer_char), sizeof(buffer_char));	LT[i]->set_color(buffer_char);
			in2.read(reinterpret_cast<char*>(&buffer_char), sizeof(buffer_char));	LT[i]->set_fuel_type(buffer_char);
			in2.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				LT[i]->set_number_of_passanger(buffer_int);
			in2.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				LT[i]->set_cargo_volume(buffer_int);
		}
		for (int i = 0; i < TM_size; i++) {
			in3.read(reinterpret_cast<char*>(&buffer_char), sizeof(buffer_char));	TM[i]->set_name(buffer_char);
			in3.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				TM[i]->set_cost(buffer_int);
			in3.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				TM[i]->set_route_number(buffer_int);
			in3.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				TM[i]->set_production_year(buffer_int);
			in3.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				TM[i]->set_year_of_commisisioning(buffer_int);
			in3.read(reinterpret_cast<char*>(&buffer_char), sizeof(buffer_char));	TM[i]->set_color(buffer_char);
			in3.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				TM[i]->set_number_of_passanger(buffer_int);
			in3.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				TM[i]->set_cargo_volume(buffer_int);
		}

		info();
		in1.close();
		in2.close();
		in3.close();
	}
	catch (const int &ex)
	{
		//SetColor(12, 1);
		cout << "Ошибка открытия файла!" << endl << "Код ошибки: #" << ex << endl;
		// SetColor(14, 1);
	}
}

Autopark::~Autopark()
{
	delete[] TR;
	delete[] LT;
	delete[] TM;

}
