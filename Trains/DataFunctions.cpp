#include"Header.h"

void addToVectTrain(vector<Train>& vectTr)
{
	string point, date, time;
	Train Tr;
	vectTr.push_back(Tr);
	cout << endl << "������� ����� ������" << endl;
	checkInt(vectTr.at(vectTr.size() - 1).number);
	cout << endl << "������� ����� ���������� (������: Minsk)" << endl;
	checkPoint(point);
	vectTr.at(vectTr.size() - 1).point = point;
	cout << endl << "������� ���� ����������� (������: 11.05.2019)" << endl;
	checkDate(date);
	vectTr.at(vectTr.size() - 1).date = date;
	cout << endl << "������� ����� ����������� (������: 14:53)" << endl;
	checkTime(time);
	vectTr.at(vectTr.size() - 1).timeOut = time;
	cout << endl << "������� ����� �������� (������: 15:53)" << endl;
	checkSence(time);
	//checkTime(time);
	vectTr.at(vectTr.size() - 1).timeIn = time;
	cout << endl << "������� ��������� ������ ������ ($)" << endl;
	ckeckNotNullValue(vectTr, vectTr.size());
	cout << endl << "������� ���������� ���������� �������" << endl;
	checkInt(vectTr.at(vectTr.size() - 1).left);
	cout << endl << "������� ���������� ��������� �������" << endl;
	checkInt(vectTr.at(vectTr.size() - 1).sales);
	cout << endl << "���� ��������!" << endl;
}

void showVectTrain(vector<Train> vectTr)
{
	cout << endl << "\t������ ������" << endl << endl;
	cout << setw(3) << "�" << "|" << setw(9) << "�. ������" << "|" << setw(15) << "�. ������." << "|"
		<< setw(12) << "���� ����." << "|" << setw(11) << "����� ����." << "|" << setw(11) << "����� ����." << "|"
		<< setw(9) << "���������" << "|" << setw(8) << "��������" << "|" << setw(7) << "�������" << endl;
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
	cout << endl << "������� ���������� ����� ����� (0 - ���������)" << endl;
	checkLimit(numTr, vectTr.size());
	if (numTr != 0) {
		cout << endl << "����� ������ �� ������ ��������?" << endl;
		cout << "1 - ����� ������" << endl << "2 - ����� ����������" << endl << "3 - ���� �����������" << endl
			<< "4 - ����� �����������" << endl << "5 - ����� ��������" << endl << "6 - ��������� ������ ������" << endl
			<< "7 - ���������� ���������� �������" << endl << "8 - ���������� ��������� �������" << endl
			<< "0 - ���������" << endl;
		checkInt(kod);
		switch (kod) {
		case 1:
			cout << endl << "������� ����� ����� ������" << endl;
			checkInt(vectTr.at(numTr - 1).number);
			break;
		case 2:
			cout << endl << "������� ����� ����� ���������� (������: Minsk)" << endl;
			checkPoint(point);
			vectTr.at(numTr - 1).point = point;
			break;
		case 3:
			cout << endl << "������� ����� ���� ����������� (������: 11.05.2019)" << endl;
			checkDate(date);
			vectTr.at(numTr - 1).date = date;
			break;
		case 4:
			cout << endl << "������� ����� ����� ����������� (������: 14:53)" << endl;
			checkTime(time);
			vectTr.at(numTr - 1).timeOut = time;
			break;
		case 5:
			cout << endl << "������� ����� ����� �������� (������: 15:53)" << endl;
			time = vectTr.at(numTr - 1).timeOut;
			checkSence(time);
			vectTr.at(numTr - 1).timeIn = time;
			break;
		case 6:
			cout << endl << "������� ����� ��������� ������ ������ ($)" << endl;
			ckeckNotNullValue(vectTr, numTr);
			break;
		case 7:
			cout << endl << "������� ����� ���������� ���������� �������" << endl;
			checkInt(vectTr.at(numTr - 1).left);
			break;
		case 8:
			cout << endl << "������� ����� ���������� ��������� �������" << endl;
			checkInt(vectTr.at(numTr - 1).sales);
			break;
		case 0:
			cout << endl << "������ �� ��������!" << endl;
			break;
		default:
			cout << "Error!" << endl;
		}
		if (kod >= 1 && kod <= 8)
			cout << endl << "������ ��������!" << endl;
	}
}

void deleteVectTrain(vector<Train>& vectTr)
{
	int numTr;
	cout << endl << "������� ���������� ����� ����� (0 - ���������)" << endl;
	checkLimit(numTr, vectTr.size());
	reallyDeleteTrain(vectTr, numTr);
}

void writeFileTrain(vector<Train>& vectTr)
{
	ofstream fout(WayTrain, ios::out); //������� ���� ��� ������
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
	ofstream fadd(WayTrain, ios::app); //������� ���� ��� ��������
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
	ifstream fin(WayTrain, ios::in); //������� ���� ��� ������
	if (!fin.is_open()) cout << "��������� ���� �� ����������!" << endl;
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
	cout << endl << "�������� ���������� ����� ����� ��� ������� ������ (0 - ���������)" << endl;
	checkLimit(numTr, vectTr.size()); //������� - 1, �������� - ��� 
	if (numTr != 0 && vectTr.at(numTr - 1).left != 0) {
		cout << endl << "������� ���������� ������� ��� �������" << endl;
		checkNumberOfTickets(vectTr, kol, numTr);//������� - 1, �������� - ��� 
		vectTr.at(numTr - 1).left = vectTr.at(numTr - 1).left - kol;
		vectTr.at(numTr - 1).sales = vectTr.at(numTr - 1).sales + kol;
		cout << endl << "������ �������!" << endl;
	}
	if (numTr != 0 && vectTr.at(numTr - 1).left == 0)
		cout << endl << "������� ������ ���!" << endl;
}

void trainInInterval(vector<Train> vectTr)
{
	int a, b;
	string point, left, right, rezerv;
	cout << endl << "\t�����" << endl;
	cout << endl << "������� ����� ���������� (������: Minsk)" << endl;
	checkPoint(point);
	cout << endl << "������� ��������� ������� ��� ������ (������: 14:53)" << endl << "�� - ";
	checkTime(rezerv);
	left = rezerv;
	fromStringToInt(left, a);
	cout << "�� - ";
	checkSence(left);
	right = left;
	fromStringToInt(right, b);
	conclusionTrain(vectTr, point, a, b);
}

void conclusionTrain(vector<Train> vectTr, string point, int a, int b) {
	int count = 0, timeout;
	cout << endl << "\t������ ������" << endl << endl;
	cout << setw(3) << "�" << "|" << setw(9) << "�. ������" << "|" << setw(11) << "����� ����." << "|" << setw(8) << "��������" << endl;
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
		cout << endl << "\t������ ���" << endl << endl;
}

void search(vector<Train> vectTr) {
	cout << endl << "\t�����" << endl;
	int kod = 1;
	while (kod != 0) {
		cout << endl << "����� ��" << endl << "1 - ������ ��������" << endl
			<< "2 - ���� �����������" << endl << "3 - ������� �����������" << endl
			<< "0 - ���������" << endl;
		checkInt(kod);
		switch (kod) {
		case 1: //�� ������ ��������
			searchForPoint(vectTr);
			break;
		case 2: //�� ���� �����������
			searchForDate(vectTr);
			break;
		case 3: //�� ������� �����������
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
	cout << endl << "������� ����� ���������� (������: Minsk)" << endl;
	checkPoint(point);
	cout << endl << "\t������ ������" << endl << endl;
	cout << setw(3) << "�" << "|" << setw(9) << "�. ������" << "|" << setw(15) << "�. ������." << "|"
		<< setw(12) << "���� ����." << "|" << setw(11) << "����� ����." << "|" << setw(11) << "����� ����." << "|"
		<< setw(9) << "���������" << "|" << setw(8) << "��������" << "|" << setw(7) << "�������" << endl;
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
		cout << endl << "\t������ ���!" << endl << endl;
}

void searchForDate(vector<Train> vectTr) {
	string date;
	int count = 0;
	cout << endl << "������� ���� ����������� (������: 11.05.2019)" << endl;
	checkDate(date);
	cout << endl << "\t������ ������" << endl << endl;
	cout << setw(3) << "�" << "|" << setw(9) << "�. ������" << "|" << setw(15) << "�. ������." << "|"
		<< setw(12) << "���� ����." << "|" << setw(11) << "����� ����." << "|" << setw(11) << "����� ����." << "|"
		<< setw(9) << "���������" << "|" << setw(8) << "��������" << "|" << setw(7) << "�������" << endl;
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
		cout << endl << "\t������ ���!" << endl << endl;
}

void searchForTime(vector<Train> vectTr) {
	string time;
	int count = 0;
	cout << endl << "������� ����� ����������� (������: 14:53)" << endl;
	checkTime(time);
	cout << endl << "\t������ ������" << endl << endl;
	cout << setw(3) << "�" << "|" << setw(9) << "�. ������" << "|" << setw(15) << "�. ������." << "|"
		<< setw(12) << "���� ����." << "|" << setw(11) << "����� ����." << "|" << setw(11) << "����� ����." << "|"
		<< setw(9) << "���������" << "|" << setw(8) << "��������" << "|" << setw(7) << "�������" << endl;
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
		cout << endl << "\t������ ���!" << endl << endl;
}

void sort(vector<Train> vectTr)
{
	cout << endl << "\t����������" << endl;
	int kod = 1, count, flag;
	vector<Train> sort;
	sort = vectTr;
	while (kod != 0) {
		cout << endl << "����������� ��" << endl << "1 - ������� �����������" << endl
			<< "2 - ������� ��������" << endl << "3 - ��������� ������ ������" << endl
			<< "0 - ���������" << endl;
		flag = 0;
		checkInt(kod);
		switch (kod) {
		case 1: //�� ������� �����������
			count = 0;
			sortCase12(vectTr, sort, count);
			cout << endl << "��������������� �� ������� �����������!" << endl;
			break;
		case 2: //�� ������� ��������
			count = 1;
			sortCase12(vectTr, sort, count);
			cout << endl << "��������������� �� ������� ��������!" << endl;
			break;
		case 3: //�� ��������� ������ ������
			sortCase3(sort);
			cout << endl << "��������������� �� ��������� ������ ������!" << endl;
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