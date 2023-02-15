#include"Header.h"

void addToVectTrain(vector<Train>& vectTr)
{
	string point, date, time;
	Train Tr;
	vectTr.push_back(Tr);
	cout << endl << "Введите номер поезда" << endl;
	checkInt(vectTr.at(vectTr.size() - 1).number);
	cout << endl << "Введите пункт назначения (Пример: Minsk)" << endl;
	checkPoint(point);
	vectTr.at(vectTr.size() - 1).point = point;
	cout << endl << "Введите дату отправления (Пример: 11.05.2019)" << endl;
	checkDate(date);
	vectTr.at(vectTr.size() - 1).date = date;
	cout << endl << "Введите время отправления (Пример: 14:53)" << endl;
	checkTime(time);
	vectTr.at(vectTr.size() - 1).timeOut = time;
	cout << endl << "Введите время прибытия (Пример: 15:53)" << endl;
	checkSence(time);
	//checkTime(time);
	vectTr.at(vectTr.size() - 1).timeIn = time;
	cout << endl << "Введите стоимость одного билета ($)" << endl;
	ckeckNotNullValue(vectTr, vectTr.size());
	cout << endl << "Введите количество оставшихся билетов" << endl;
	checkInt(vectTr.at(vectTr.size() - 1).left);
	cout << endl << "Введите количество проданных билетов" << endl;
	checkInt(vectTr.at(vectTr.size() - 1).sales);
	cout << endl << "Рейс добавлен!" << endl;
}

void showVectTrain(vector<Train> vectTr)
{
	cout << endl << "\tСписок рейсов" << endl << endl;
	cout << setw(3) << "№" << "|" << setw(9) << "Н. поезда" << "|" << setw(15) << "П. назнач." << "|"
		<< setw(12) << "Дата отпр." << "|" << setw(11) << "Время отпр." << "|" << setw(11) << "Время приб." << "|"
		<< setw(9) << "Стоимость" << "|" << setw(8) << "Осталось" << "|" << setw(7) << "Продано" << endl;
	for (unsigned int i = 0; i < vectTr.size(); i++)
		cout << "-------------------------------------------------------------------------------------------------" << endl
		<< setw(3) << i + 1 << "|"
		<< setw(9) << vectTr.at(i).number << "|"
		<< setw(15) << vectTr.at(i).point << "|"
		<< setw(12) << vectTr.at(i).date << "|"
		<< setw(11) << vectTr.at(i).timeOut << "|"
		<< setw(11) << vectTr.at(i).timeIn << "|"
		<< setw(9) << vectTr.at(i).val << "|"
		<< setw(8) << vectTr.at(i).left << "|"
		<< setw(7) << vectTr.at(i).sales << endl;
}

void correctVectTrain(vector<Train>& vectTr)
{
	int numTr, kod;
	string point, date, time;
	cout << endl << "Введите порядковый номер рейса (0 - Вернуться)" << endl;
	checkLimit(numTr, vectTr.size());
	if (numTr != 0) {
		cout << endl << "Какие данные Вы хотите изменить?" << endl;
		cout << "1 - Номер поезда" << endl << "2 - Пункт назначения" << endl << "3 - Дата отправления" << endl
			<< "4 - Время отправления" << endl << "5 - Время прибытия" << endl << "6 - Стоимость доного билета" << endl
			<< "7 - Количество оставшихся билетов" << endl << "8 - Количество проданных билетов" << endl
			<< "0 - Вернуться" << endl;
		checkInt(kod);
		switch (kod) {
		case 1:
			cout << endl << "Введите новый номер поезда" << endl;
			checkInt(vectTr.at(numTr - 1).number);
			break;
		case 2:
			cout << endl << "Введите новый пункт назначения (Пример: Minsk)" << endl;
			checkPoint(point);
			vectTr.at(numTr - 1).point = point;
			break;
		case 3:
			cout << endl << "Введите новую дату отправления (Пример: 11.05.2019)" << endl;
			checkDate(date);
			vectTr.at(numTr - 1).date = date;
			break;
		case 4:
			cout << endl << "Введите новое время отправления (Пример: 14:53)" << endl;
			checkTime(time);
			vectTr.at(numTr - 1).timeOut = time;
			break;
		case 5:
			cout << endl << "Введите новое время прибытия (Пример: 15:53)" << endl;
			time = vectTr.at(numTr - 1).timeOut;
			checkSence(time);
			vectTr.at(numTr - 1).timeIn = time;
			break;
		case 6:
			cout << endl << "Введите новую стоимость одного билета ($)" << endl;
			ckeckNotNullValue(vectTr, numTr);
			break;
		case 7:
			cout << endl << "Введите новое количество оставшихся билетов" << endl;
			checkInt(vectTr.at(numTr - 1).left);
			break;
		case 8:
			cout << endl << "Введите новое количество проданных билетов" << endl;
			checkInt(vectTr.at(numTr - 1).sales);
			break;
		case 0:
			cout << endl << "Данные не изменены!" << endl;
			break;
		default:
			cout << "Error!" << endl;
		}
		if (kod >= 1 && kod <= 8)
			cout << endl << "Данные изменены!" << endl;
	}
}

void deleteVectTrain(vector<Train>& vectTr)
{
	int numTr;
	cout << endl << "Введите порядковый номер рейса (0 - Вернуться)" << endl;
	checkLimit(numTr, vectTr.size());
	reallyDeleteTrain(vectTr, numTr);
}

void writeFileTrain(vector<Train>& vectTr)
{
	ofstream fout(WayTrain, ios::out); //Открыли файл для записи
	for (unsigned int i = 0; i < vectTr.size(); i++)
	{
		fout << vectTr.at(i).number << " "
			<< vectTr.at(i).point << " "
			<< vectTr.at(i).date << " "
			<< vectTr.at(i).timeOut << " "
			<< vectTr.at(i).timeIn << " "
			<< vectTr.at(i).val << " "
			<< vectTr.at(i).left << " "
			<< vectTr.at(i).sales;
		if (i < vectTr.size() - 1)
			fout << endl;
	}
	fout.close();
}

void addFileTrain(Train newTrain)
{
	ofstream fadd(WayTrain, ios::app); //Открыли файл для дозаписи
	fadd << endl;
	fadd << newTrain.number << " "
		<< newTrain.point << " "
		<< newTrain.date << " "
		<< newTrain.timeOut << " "
		<< newTrain.timeIn << " "
		<< newTrain.val << " "
		<< newTrain.left << " "
		<< newTrain.sales;
	fadd.close();
}

void readFileTrain(vector<Train>& vectTr)
{
	Train Tr;
	ifstream fin(WayTrain, ios::in); //Открыли файл для чтения
	if (!fin.is_open()) cout << "Указанный файл не существует!" << endl;
	else
	{
		int i = 0;
		while (!fin.eof())
		{
			vectTr.push_back(Tr);
			fin >> vectTr.at(i).number
				>> vectTr.at(i).point
				>> vectTr.at(i).date
				>> vectTr.at(i).timeOut
				>> vectTr.at(i).timeIn
				>> vectTr.at(i).val
				>> vectTr.at(i).left
				>> vectTr.at(i).sales;
			i++;
		}
	}
}

void task(vector<Train>& vectTr)
{
	int numTr, kol;
	showVectTrain(vectTr);
	cout << endl << "Выберите порядковый номер рейса для покупки билета (0 - Вернуться)" << endl;
	checkLimit(numTr, vectTr.size()); //Минимум - 1, максимум - все 
	if (numTr != 0 && vectTr.at(numTr - 1).left != 0) {
		cout << endl << "Введите количество билетов для покупки" << endl;
		checkNumberOfTickets(vectTr, kol, numTr);//Минимум - 1, максимум - все 
		vectTr.at(numTr - 1).left = vectTr.at(numTr - 1).left - kol;
		vectTr.at(numTr - 1).sales = vectTr.at(numTr - 1).sales + kol;
		cout << endl << "Билеты куплены!" << endl;
	}
	if (numTr != 0 && vectTr.at(numTr - 1).left == 0)
		cout << endl << "Билетов больше нет!" << endl;
}

void trainInInterval(vector<Train> vectTr)
{
	int a, b;
	string point, left, right, rezerv;
	cout << endl << "\tПоиск" << endl;
	cout << endl << "Введите пункт назначения (Пример: Minsk)" << endl;
	checkPoint(point);
	cout << endl << "Введите интервалы времени для поиска (Пример: 14:53)" << endl << "От - ";
	checkTime(rezerv);
	left = rezerv;
	fromStringToInt(left, a);
	cout << "До - ";
	checkSence(left);
	right = left;
	fromStringToInt(right, b);
	conclusionTrain(vectTr, point, a, b);
}

void conclusionTrain(vector<Train> vectTr, string point, int a, int b) {
	int count = 0, timeout;
	cout << endl << "\tСписок рейсов" << endl << endl;
	cout << setw(3) << "№" << "|" << setw(9) << "Н. поезда" << "|" << setw(11) << "Время отпр." << "|" << setw(8) << "Осталось" << endl;
	for (unsigned int i = 0; i < vectTr.size(); i++) {
		fromStringToInt(vectTr.at(i).timeOut, timeout);
		if (point == vectTr.at(i).point && timeout >= a && timeout <= b) {
			count++;
			cout << "------------------------------------" << endl
				<< setw(3) << count << "|"
				<< setw(9) << vectTr.at(i).number << "|"
				<< setw(11) << vectTr.at(i).timeOut << "|"
				<< setw(8) << vectTr.at(i).left << endl;
		}
	}
	if (count == 0)
		cout << endl << "\tРейсов нет" << endl << endl;
}

void search(vector<Train> vectTr) {
	cout << endl << "\tПоиск" << endl;
	int kod = 1;
	while (kod != 0) {
		cout << endl << "Поиск по" << endl << "1 - Пункту прибытия" << endl
			<< "2 - Дате отправления" << endl << "3 - Времени отправления" << endl
			<< "0 - Вернуться" << endl;
		checkInt(kod);
		switch (kod) {
		case 1: //По пункту прибытия
			searchForPoint(vectTr);
			break;
		case 2: //По дате отправления
			searchForDate(vectTr);
			break;
		case 3: //По времени отправления
			searchForTime(vectTr);
			break;
		case 0:
			return;
		default:
			cout << "Error!" << endl;
		}
	}
}

void searchForPoint(vector<Train> vectTr) {
	string point;
	int count = 0;
	cout << endl << "Введите пункт назначения (Пример: Minsk)" << endl;
	checkPoint(point);
	cout << endl << "\tСписок рейсов" << endl << endl;
	cout << setw(3) << "№" << "|" << setw(9) << "Н. поезда" << "|" << setw(15) << "П. назнач." << "|"
		<< setw(12) << "Дата отпр." << "|" << setw(11) << "Время отпр." << "|" << setw(11) << "Время приб." << "|"
		<< setw(9) << "Стоимость" << "|" << setw(8) << "Осталось" << "|" << setw(7) << "Продано" << endl;
	for (unsigned int i = 0; i < vectTr.size(); i++)
		if (point == vectTr.at(i).point) {
			count++;
			cout << "-------------------------------------------------------------------------------------------------" << endl
				<< setw(3) << i + 1 << "|"
				<< setw(9) << vectTr.at(i).number << "|"
				<< setw(15) << vectTr.at(i).point << "|"
				<< setw(12) << vectTr.at(i).date << "|"
				<< setw(11) << vectTr.at(i).timeOut << "|"
				<< setw(11) << vectTr.at(i).timeIn << "|"
				<< setw(9) << vectTr.at(i).val << "|"
				<< setw(8) << vectTr.at(i).left << "|"
				<< setw(7) << vectTr.at(i).sales << endl;
		}
	if (count == 0)
		cout << endl << "\tРейсов нет!" << endl << endl;
}

void searchForDate(vector<Train> vectTr) {
	string date;
	int count = 0;
	cout << endl << "Введите дату отправления (Пример: 11.05.2019)" << endl;
	checkDate(date);
	cout << endl << "\tСписок рейсов" << endl << endl;
	cout << setw(3) << "№" << "|" << setw(9) << "Н. поезда" << "|" << setw(15) << "П. назнач." << "|"
		<< setw(12) << "Дата отпр." << "|" << setw(11) << "Время отпр." << "|" << setw(11) << "Время приб." << "|"
		<< setw(9) << "Стоимость" << "|" << setw(8) << "Осталось" << "|" << setw(7) << "Продано" << endl;
	for (unsigned int i = 0; i < vectTr.size(); i++)
		if (date == vectTr.at(i).date) {
			count++;
			cout << "-------------------------------------------------------------------------------------------------" << endl
				<< setw(3) << i + 1 << "|"
				<< setw(9) << vectTr.at(i).number << "|"
				<< setw(15) << vectTr.at(i).point << "|"
				<< setw(12) << vectTr.at(i).date << "|"
				<< setw(11) << vectTr.at(i).timeOut << "|"
				<< setw(11) << vectTr.at(i).timeIn << "|"
				<< setw(9) << vectTr.at(i).val << "|"
				<< setw(8) << vectTr.at(i).left << "|"
				<< setw(7) << vectTr.at(i).sales << endl;
		}
	if (count == 0)
		cout << endl << "\tРейсов нет!" << endl << endl;
}

void searchForTime(vector<Train> vectTr) {
	string time;
	int count = 0;
	cout << endl << "Введите время отправления (Пример: 14:53)" << endl;
	checkTime(time);
	cout << endl << "\tСписок рейсов" << endl << endl;
	cout << setw(3) << "№" << "|" << setw(9) << "Н. поезда" << "|" << setw(15) << "П. назнач." << "|"
		<< setw(12) << "Дата отпр." << "|" << setw(11) << "Время отпр." << "|" << setw(11) << "Время приб." << "|"
		<< setw(9) << "Стоимость" << "|" << setw(8) << "Осталось" << "|" << setw(7) << "Продано" << endl;
	for (unsigned int i = 0; i < vectTr.size(); i++)
		if (time == vectTr.at(i).timeOut) {
			count++;
			cout << "-------------------------------------------------------------------------------------------------" << endl
				<< setw(3) << i + 1 << "|"
				<< setw(9) << vectTr.at(i).number << "|"
				<< setw(15) << vectTr.at(i).point << "|"
				<< setw(12) << vectTr.at(i).date << "|"
				<< setw(11) << vectTr.at(i).timeOut << "|"
				<< setw(11) << vectTr.at(i).timeIn << "|"
				<< setw(9) << vectTr.at(i).val << "|"
				<< setw(8) << vectTr.at(i).left << "|"
				<< setw(7) << vectTr.at(i).sales << endl;
		}
	if (count == 0)
		cout << endl << "\tРейсов нет!" << endl << endl;
}

void sort(vector<Train> vectTr)
{
	cout << endl << "\tСортировка" << endl;
	int kod = 1, count, flag;
	vector<Train> sort;
	sort = vectTr;
	while (kod != 0) {
		cout << endl << "Сортировать по" << endl << "1 - Времени отправления" << endl
			<< "2 - Времени прибытия" << endl << "3 - Стоимости одного билета" << endl
			<< "0 - Вернуться" << endl;
		flag = 0;
		checkInt(kod);
		switch (kod) {
		case 1: //По времени отправления
			count = 0;
			sortCase12(vectTr, sort, count);
			cout << endl << "Отсортированано по времени отправления!" << endl;
			break;
		case 2: //По времени прибытия
			count = 1;
			sortCase12(vectTr, sort, count);
			cout << endl << "Отсортированано по времени прибытия!" << endl;
			break;
		case 3: //По стоимости одного билета
			sortCase3(sort);
			cout << endl << "Отсортированано по стоимости одного билета!" << endl;
			break;
		case 0:
			return;
		default:
			flag = 1;
			cout << "Error!" << endl;
		}
		if (flag != 1)
			showVectTrain(sort);
	}
}

void sortCase12(vector<Train> vectTr, vector<Train>& sort, int count)
{
	int val, Tr;
	string time;
	vector<int> t;
	for (unsigned int i = 0; i < sort.size(); i++) {
		if (count == 0) time = sort.at(i).timeOut;
		else time = sort.at(i).timeIn;
		fromStringToInt(time, val);
		t.push_back(Tr);
		t.at(i) = val;
		sort.at(i).rez = t.at(i);
	}
	swap(sort);
}

void swap(vector<Train>& sort)
{
	for (unsigned int i = 0; i < sort.size() - 1; i++) {
		for (unsigned int j = i + 1; j < sort.size(); j++)
			if (sort.at(i).rez > sort.at(j).rez)
				swap(sort.at(i), sort.at(j));
	}
}

void sortCase3(vector<Train>& sort)
{
	for (unsigned int i = 0; i < sort.size() - 1; i++) {
		for (unsigned int j = i + 1; j < sort.size(); j++)
			if (sort.at(i).val > sort.at(j).val)
				swap(sort.at(i), sort.at(j));
	}
}