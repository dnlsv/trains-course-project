#include"Header.h"

void mySystem(vector<Users>& vect, vector<Train>& vectTr)
{
	cout << "\tLisenkov System" << endl;
	int kod = 1, key;
	while (kod != 0) {
		cout << endl << "1 - Вход в систему" << endl
			<< "0 - Выход" << endl;
		checkInt(kod);
		switch (kod) {
		case 1: //Вход в систему
			entry(vect, vectTr, key);
			break;
		case 0: //Выход
			kod = 0;
			break;
		default:
			cout << "Error!" << endl;
		}
	}
}

void entry(vector<Users>& vect, vector<Train>& vectTr, int& key)
{
	cout << endl << "Войдите в систему" << endl << endl;
	authorization(vect, key);
	cout << endl << "Вход выполнен!" << endl;
	if (vect.at(key).role == 1)       //Модуль администратора
		moduleAdmin(vect, vectTr, key);
	else       //Модуль пользователя
		moduleUser(vectTr);
}

void moduleAdmin(vector<Users>& vect, vector<Train>& vectTr, int key)
{
	int kod = 1;
	while (kod != 0) {
		cout << endl << "\tМодуль администратора" << endl << endl;
		cout << "1 - Работа с учетными записями" << endl
			<< "2 - Работа с данными" << endl << "0 - Вернуться" << endl;
		checkInt(kod);
		switch (kod)
		{
		case 1: //Работа с учетными записями
			workWithRecords(vect, key);
			break;
		case 2: //Работа с данными
			workWithData(vectTr);
			break;
		case 0: //Вернуться
			break;
		default:
			cout << "Error!" << endl;
		}
	}
}

void moduleUser(vector<Train>& vectTr)
{
	readFileTrain(vectTr);
	int kod = 1;
	while (kod != 0) {
		cout << endl << "\tМодуль пользователя" << endl << endl;
		cout << "1 - Просмотр" << endl << "2 - Покупка билета на рейс" << endl
			<< "3 - Просмотр рейсов в интервале от a до b" << endl
			<< "4 - Поиск" << endl << "5 - Сортировка" << endl << "0 - Вернуться" << endl;
		checkInt(kod);
		switch (kod)
		{
		case 1: //Просмотр
			showVectTrain(vectTr);
			break;
		case 2: //Покупка билета на рейс
			task(vectTr);
			writeFileTrain(vectTr);
			break;
		case 3: //Просмотр рейсов в интервале от a до b
			trainInInterval(vectTr);
			break;
		case 4: //Поиск
			search(vectTr);
			break;
		case 5: //Сортировка
			sort(vectTr);
			break;
		case 0: //Вернуться
			break;
		default:
			cout << "Error!" << endl;
		}
	}
}

void workWithRecords(vector<Users>& vect, int key)
{
	int kod = 1, numUs;
	while (kod != 0) {
		cout << endl << "\tРабота с учетными записями" << endl << endl;
		cout << "1 - Просмотр" << endl << "2 - Добавление" << endl
			<< "3 - Редактирование" << endl << "4 - Удаление" << endl
			<< "0 - Вернуться" << endl;
		checkInt(kod);
		switch (kod) {
		case 1: //Просмотр
			showVector(vect);
			break;
		case 2: //Добавление
			addToVector(vect);
			addFileUsers(vect.at(vect.size() - 1));
			break;
		case 3: //Редактирование
			showVector(vect);
			correctVector(vect, numUs, key);
			writeFileUsers(vect);
			break;
		case 4: //Удаление
			showVector(vect);
			deleteVector(vect, key);
			writeFileUsers(vect);
			break;
		case 0: //Вернуться
			break;
		default:
			cout << "Error!" << endl;
		}
	}
}

void workWithData(vector<Train>& vectTr)
{
	int kod = 1;
	while (kod != 0) {
		cout << endl << "\tРабота с данными" << endl << endl;
		cout << "1 - Режим редактирования" << endl
			<< "2 - Режим обработки" << endl << "0 - Вернуться" << endl;
		checkInt(kod);
		switch (kod)
		{
		case 1: //Режим редактирования
			modeEdit(vectTr);
			break;
		case 2: //Режим обработки
			modeProcessing(vectTr);
			break;
		case 0: //Вернуться
			break;
		default:
			cout << "Error!" << endl;
		}
	}
}

void modeEdit(vector<Train>& vectTr)
{
	int kod = 1;

	while (kod != 0) {
		cout << endl << "\tРежим редактирования" << endl << endl;
		cout << "1 - Просмотр" << endl << "2 - Добавление" << endl
			<< "3 - Редактирование" << endl << "4 - Удаление" << endl
			<< "0 - Вернуться" << endl;
		checkInt(kod);
		switch (kod) {
		case 1: //Просмотр
			showVectTrain(vectTr);
			break;
		case 2: //Добавление
			addToVectTrain(vectTr);
			addFileTrain(vectTr.at(vectTr.size() - 1));
			break;
		case 3: //Редактирование
			showVectTrain(vectTr);
			correctVectTrain(vectTr);
			writeFileTrain(vectTr);
			break;
		case 4: //Удаление
			showVectTrain(vectTr);
			deleteVectTrain(vectTr);
			writeFileTrain(vectTr);
			break;
		case 0: //Вернуться
			break;
		default:
			cout << "Error!" << endl;
		}
	}
}

void modeProcessing(vector<Train>& vectTr)
{
	int kod = 1;

	while (kod != 0) {
		cout << endl << "\tРежим обработки" << endl << endl;
		cout << "1 - Покупка билета на рейс" << endl
			<< "2 - Просмотр рейсов в интервале от a до b" << endl
			<< "3 - Поиск" << endl << "4 - Сортировка" << endl << "0 - Вернуться" << endl;
		checkInt(kod);
		switch (kod) {
		case 1: //Покупка билета на рейс
			task(vectTr);
			writeFileTrain(vectTr);
			break;
		case 2: //Просмотр рейсов в интервале от a до b
			trainInInterval(vectTr);
			break;
		case 3: //Поиск
			search(vectTr);
			break;
		case 4: //Сортировка
			sort(vectTr);
			break;
		case 0: //Вернуться
			break;
		default:
			cout << "Error!" << endl;
		}
	}
}
