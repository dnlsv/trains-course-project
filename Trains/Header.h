#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <conio.h> 
#include <windows.h> 
#include <time.h> 

using namespace std;

struct Users
{
	string login; //�����
	string salted_hash_password; //"����������" ������
	string salt; //����
	bool role; //����: ������������� ��� ������������
};

struct Train
{
	int number; //����� ������
	string point; //����� ���������� 
	string date; //���� �����������
	string timeOut; //����� ����������
	string timeIn; //����� ��������
	double val; //��������� ������ ������ 
	int left; //���������� ���������� �������
	int sales; //���������� ��������� �������
	int rez; //��������� ����
};

struct Date
{
	string day;
	string month;
	string year;
};

struct Time
{
	string hour;
	string minute;
	string second;
};

Date getCurrentDate();
Time getCurrentTime();

void checkSystemDate(string, Date);

//����
void mySystem(vector<Users>&, vector<Train>&); //��������� ���� ���������
void entry(vector<Users>&, vector<Train>&, int&); //���� � �������
void moduleAdmin(vector<Users>&, vector<Train>&, int); //������ ��������������
void moduleUser(vector<Train>&); //������ ������������
void workWithRecords(vector<Users>&, int); //������ � �������� ��������
void workWithData(vector<Train>&); //������ � �������
void modeEdit(vector<Train>&); //����� ��������������
void modeProcessing(vector<Train>&); //����� ���������

//������� ��� ������ � �������� �������� �������������
void writeFileUsers(vector<Users>&); //������ � ���� �������������
void addFileUsers(Users); //���������� � ���� 
void readFileUsers(vector<Users>&); //������ �� ����� 
void generateVector(vector<Users>&); //�������� ������� �������������
void addToVector(vector<Users>&); //����������
void showVector(vector<Users>); //��������
void correctVector(vector<Users>&, int&, int); //��������������
void deleteVector(vector<Users>&, int); //��������

void authorization(vector<Users>, int&); //������������� � �������������� ������������
string myHash(string); //�����������
string salt(); //����

//������� ��� ������ � ������� �������
void writeFileTrain(vector<Train>&); //������ � ���� ������
void addFileTrain(Train); //���������� � ����
void readFileTrain(vector<Train>&); //������ �� �����
void addToVectTrain(vector<Train>&); //���������� ������� ������
void showVectTrain(vector<Train>); //��������
void correctVectTrain(vector<Train>&); //��������������
void deleteVectTrain(vector<Train>&); //��������

void task(vector<Train>&); //������� ������ �� ����
void trainInInterval(vector<Train>); //�������� ������ � ��������� �� a �� b
void conclusionTrain(vector<Train>, string, int, int); //�������� ������ � ��������� �� a �� b
void search(vector<Train>); //������� ������
void searchForPoint(vector<Train>); //����� �� ������ ��������
void searchForDate(vector<Train>); //����� �� ���� �����������
void searchForTime(vector<Train>); //����� �� ������� �����������
void sort(vector<Train>); //������� ����������
void sortCase12(vector<Train>, vector<Train>&, int); //���������� �� ������� ��������/�����������
void sortCase3(vector<Train>&); //���������� �� ��������� ������ ������
void swap(vector<Train>&); //������ �������

//�������������� �������
void checkInt(int&); //�������� int ����������
void checkDouble(double&); //�������� double ����������
void checkBool(bool&); //�������� bool ����������

void checkAdminRecord(vector<Users>&); //�������� �� ������������� ���� �� ����� ������� ������
void checkLogin(string& login, vector<Users>); //�������� �� ������������ ������
void checkUniqueness(string, vector<Users>, bool&); //�������� �� ������������ ������
void checkRequirementsLogin(string, int&, int&); //�������� ���������� ������
void checkPassword(string&); //�������� �� ������������ ������
void deleteOwnRecord(int&, int, int); //�������� ����������� ������� ������
void reallyDeleteRecord(vector<Users>&, int&); //������������� ������ ������� ��� ������� ������?
void checkWhoseCorrectRole(int&, int, bool&, int); //��� ������ ����?
void correctOwnRole(int&, bool); //����� �� ����� �������� ���� ����
void maskingPassword(string&); //���������� ������

void checkPoint(string&); //�������� �� ������������ ������ ��������
void checkDate(string&); //�������� �� ������������ ���� �����������
void checkTime(string&); //�������� �� ������������ ������� �����������
void checkSence(string& time); //����� ����������� < ����� ��������
void reallyDeleteTrain(vector<Train>&, int); //������������� ������ ������� ��� �������?
void checkNumberOfTickets(vector<Train>, int&, int); //�������� ���������� ���������� �������
void ckeckNotNullValue(vector<Train>&, int); // �� ����� ����

void fromStringToInt(string, int&); //�� string � int
void checkLimit(int&, int); //�������� �� ����� �� ������ (���������� ������������/�������)
void checkGap(string&, bool&); //�������� �� �������
int getCountOfStucturesInFile(string file_path); //���������� ���������� �������� � �����

const string Way = "MyFile.txt"; //���� � ����� ������� �������
const string WayTrain = "Train.txt"; //���� � ����� ������

const int LeftSolt = 15;
const int RightSolt = 25;
const int LeftCapital = 65;
const int RightCapital = 90;
const int LeftLower = 97;
const int RightLower = 122;
const int LeftNumbers = 48;
const int RightNumbers = 57;
