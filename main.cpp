#include "Autopark.h"
#include "New_Autopark.h"
#include "Assembly_TSFactory.h"


int main()
{
	setlocale(LC_ALL, "Russian");
	New_Autopark New_Autopark;
	Russian_TSFactory factory;


	const char * filename = "AutoPark.dat";
	const char* filename1 = "gruzovik.dat";
	const char* filename2 = "LT_Auto.dat";
	const char* filename3 = "Tramvai.dat";

	Autopark * RU = nullptr;

	/////////////////////////
	/*ПОЛЬЗОВАТЕЛЬСКОЕ МЕНЮ*/
	/////////////////////////

	int swtch1 = 1;

	while (swtch1 != 0) {
		cout << endl << endl << "Выберите действие:" << endl <<
			"|1| <-> Войти в автопарк" << endl <<
			"|0| <-> Выход" << endl;
		cin >> swtch1;
		switch (swtch1)
		{
		case 1:
			cout << "Выберите действие: " << endl <<
				"|1| <-> Создать новый автопарк" << endl <<
				"|2| <-> Загрузить имеющийся автопарк" << endl <<
				"|0| <-> Выход" << endl;
			cin >> swtch1;
			switch (swtch1)
			{
			case 1:
				//SetColor(15, 1);
				cout << endl << endl << "Создание нового автопарка:" << endl;
				RU = New_Autopark.createAutopark(factory);
				RU->set();
				RU->info();
				RU->save_to_file(filename1, filename2, filename3);
				break;
			case 2:
				//SetColor(15, 1);
				RU = new Autopark;
				RU->read_from_file(filename1, filename2, filename3, factory);
				RU->info();
				break;
			default:
				break;
			}
			break;

		default:
			break;
		}
	}

	if (RU != nullptr) delete RU;

	system("pause");
	return 0;


}