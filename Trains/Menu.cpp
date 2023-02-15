#include"Header.h"

void mySystem(vector<Users>& vect, vector<Train>& vectTr)
{
	cout << "\tLisenkov System" << endl;
	int kod = 1, key;
	while (kod != 0) {
		cout << endl << "1 - ���� � �������" << endl
			<< "0 - �����" << endl;
		checkInt(kod);
		switch (kod) {
		case 1: //���� � �������
			entry(vect, vectTr, key);
			break;
		case 0: //�����
			kod = 0;
			break;
		default:
			cout << "Error!" << endl;
		}
	}
}

void entry(vector<Users>& vect, vector<Train>& vectTr, int& key)
{
	cout << endl << "������� � �������" << endl << endl;
	authorization(vect, key);
	cout << endl << "���� ��������!" << endl;
	if (vect.at(key).role == 1)       //������ ��������������
		moduleAdmin(vect, vectTr, key);
	else       //������ ������������
		moduleUser(vectTr);
}

void moduleAdmin(vector<Users>& vect, vector<Train>& vectTr, int key)
{
	int kod = 1;
	while (kod != 0) {
		cout << endl << "\t������ ��������������" << endl << endl;
		cout << "1 - ������ � �������� ��������" << endl
			<< "2 - ������ � �������" << endl << "0 - ���������" << endl;
		checkInt(kod);
		switch (kod)
		{
		case 1: //������ � �������� ��������
			workWithRecords(vect, key);
			break;
		case 2: //������ � �������
			workWithData(vectTr);
			break;
		case 0: //���������
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
		cout << endl << "\t������ ������������" << endl << endl;
		cout << "1 - ��������" << endl << "2 - ������� ������ �� ����" << endl
			<< "3 - �������� ������ � ��������� �� a �� b" << endl
			<< "4 - �����" << endl << "5 - ����������" << endl << "0 - ���������" << endl;
		checkInt(kod);
		switch (kod)
		{
		case 1: //��������
			showVectTrain(vectTr);
			break;
		case 2: //������� ������ �� ����
			task(vectTr);
			writeFileTrain(vectTr);
			break;
		case 3: //�������� ������ � ��������� �� a �� b
			trainInInterval(vectTr);
			break;
		case 4: //�����
			search(vectTr);
			break;
		case 5: //����������
			sort(vectTr);
			break;
		case 0: //���������
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
		cout << endl << "\t������ � �������� ��������" << endl << endl;
		cout << "1 - ��������" << endl << "2 - ����������" << endl
			<< "3 - ��������������" << endl << "4 - ��������" << endl
			<< "0 - ���������" << endl;
		checkInt(kod);
		switch (kod) {
		case 1: //��������
			showVector(vect);
			break;
		case 2: //����������
			addToVector(vect);
			addFileUsers(vect.at(vect.size() - 1));
			break;
		case 3: //��������������
			showVector(vect);
			correctVector(vect, numUs, key);
			writeFileUsers(vect);
			break;
		case 4: //��������
			showVector(vect);
			deleteVector(vect, key);
			writeFileUsers(vect);
			break;
		case 0: //���������
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
		cout << endl << "\t������ � �������" << endl << endl;
		cout << "1 - ����� ��������������" << endl
			<< "2 - ����� ���������" << endl << "0 - ���������" << endl;
		checkInt(kod);
		switch (kod)
		{
		case 1: //����� ��������������
			modeEdit(vectTr);
			break;
		case 2: //����� ���������
			modeProcessing(vectTr);
			break;
		case 0: //���������
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
		cout << endl << "\t����� ��������������" << endl << endl;
		cout << "1 - ��������" << endl << "2 - ����������" << endl
			<< "3 - ��������������" << endl << "4 - ��������" << endl
			<< "0 - ���������" << endl;
		checkInt(kod);
		switch (kod) {
		case 1: //��������
			showVectTrain(vectTr);
			break;
		case 2: //����������
			addToVectTrain(vectTr);
			addFileTrain(vectTr.at(vectTr.size() - 1));
			break;
		case 3: //��������������
			showVectTrain(vectTr);
			correctVectTrain(vectTr);
			writeFileTrain(vectTr);
			break;
		case 4: //��������
			showVectTrain(vectTr);
			deleteVectTrain(vectTr);
			writeFileTrain(vectTr);
			break;
		case 0: //���������
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
		cout << endl << "\t����� ���������" << endl << endl;
		cout << "1 - ������� ������ �� ����" << endl
			<< "2 - �������� ������ � ��������� �� a �� b" << endl
			<< "3 - �����" << endl << "4 - ����������" << endl << "0 - ���������" << endl;
		checkInt(kod);
		switch (kod) {
		case 1: //������� ������ �� ����
			task(vectTr);
			writeFileTrain(vectTr);
			break;
		case 2: //�������� ������ � ��������� �� a �� b
			trainInInterval(vectTr);
			break;
		case 3: //�����
			search(vectTr);
			break;
		case 4: //����������
			sort(vectTr);
			break;
		case 0: //���������
			break;
		default:
			cout << "Error!" << endl;
		}
	}
}
