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
	string login; //Логин
	string salted_hash_password; //"Засоленный" пароль
	string salt; //Соль
	bool role; //Роль: администратор или пользователь
};

struct Train
{
	int number; //Номер поезда
	string point; //Пункт назначения 
	string date; //Дата отправления
	string timeOut; //Время отпраления
	string timeIn; //Время прибытия
	double val; //Стоимость одного билета 
	int left; //Количество отсавшихся билетов
	int sales; //Количество проданных билетов
	int rez; //Резервное поле
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

//МЕНЮ
void mySystem(vector<Users>&, vector<Train>&); //Начальное окно программы
void entry(vector<Users>&, vector<Train>&, int&); //Вход в систему
void moduleAdmin(vector<Users>&, vector<Train>&, int); //Модуль администратора
void moduleUser(vector<Train>&); //Модуль пользователя
void workWithRecords(vector<Users>&, int); //Работа с учетными записями
void workWithData(vector<Train>&); //Работа с данными
void modeEdit(vector<Train>&); //Режим редактирования
void modeProcessing(vector<Train>&); //Режим обработки

//ФУНКЦИИ ДЛЯ РАБОТЫ С УЧЕТНЫМИ ЗАПИСЯМИ ПОЛЬЗОВАТЕЛЕЙ
void writeFileUsers(vector<Users>&); //Запись в файл пользователей
void addFileUsers(Users); //Добавление в файл 
void readFileUsers(vector<Users>&); //Чтение из файла 
void generateVector(vector<Users>&); //Создание вектора пользователей
void addToVector(vector<Users>&); //Добавление
void showVector(vector<Users>); //Просмотр
void correctVector(vector<Users>&, int&, int); //Редактирование
void deleteVector(vector<Users>&, int); //Удаление

void authorization(vector<Users>, int&); //Идентификация и аутентификация пользователя
string myHash(string); //Хеширование
string salt(); //Соль

//ФУНКЦИИ ДЛЯ РАБОТЫ С РЕЙСАМИ ПОЕЗДОВ
void writeFileTrain(vector<Train>&); //Запись в файл данных
void addFileTrain(Train); //Добавление в файл
void readFileTrain(vector<Train>&); //Чтение из файла
void addToVectTrain(vector<Train>&); //Добавление вектора данных
void showVectTrain(vector<Train>); //Просмотр
void correctVectTrain(vector<Train>&); //Редактирование
void deleteVectTrain(vector<Train>&); //Удаление

void task(vector<Train>&); //Покупка билета на рейс
void trainInInterval(vector<Train>); //Просмотр рейсов в интервале от a до b
void conclusionTrain(vector<Train>, string, int, int); //Просмотр рейсов в интервале от a до b
void search(vector<Train>); //Функция поиска
void searchForPoint(vector<Train>); //Поиск по пункту прибытия
void searchForDate(vector<Train>); //Поиск по дате отправления
void searchForTime(vector<Train>); //Поиск по времени отправления
void sort(vector<Train>); //Функция сортировок
void sortCase12(vector<Train>, vector<Train>&, int); //Сортировка по времени прибытия/отправления
void sortCase3(vector<Train>&); //Сортировка по стоимсоти одного билета
void swap(vector<Train>&); //Меняет местами

//ДОПОЛНИТЕЛЬНЫЕ ФУНКЦИИ
void checkInt(int&); //Проверка int переменных
void checkDouble(double&); //Проверка double переменных
void checkBool(bool&); //Проверка bool переменных

void checkAdminRecord(vector<Users>&); //Проверка на существования хотя бы одной учетной записи
void checkLogin(string& login, vector<Users>); //Проверка на корректность логина
void checkUniqueness(string, vector<Users>, bool&); //Проверка на уникальность логина
void checkRequirementsLogin(string, int&, int&); //Проверка требований логина
void checkPassword(string&); //Проверка на корректность пароля
void deleteOwnRecord(int&, int, int); //Удаление собственной учетной записи
void reallyDeleteRecord(vector<Users>&, int&); //Действительно хотите удалить эту учетную запись?
void checkWhoseCorrectRole(int&, int, bool&, int); //Кто меняте роль?
void correctOwnRole(int&, bool); //Админ не может поменять себе роль
void maskingPassword(string&); //Маскировка пароля

void checkPoint(string&); //Проверка на корректность пункта прибытия
void checkDate(string&); //Проверка на корректность даты отправления
void checkTime(string&); //Проверка на корректность времени отправления
void checkSence(string& time); //Время отправления < Время прибытия
void reallyDeleteTrain(vector<Train>&, int); //Действительно хотите удалить эту поездку?
void checkNumberOfTickets(vector<Train>, int&, int); //Проверка количество оставшихся билетов
void ckeckNotNullValue(vector<Train>&, int); // Не равно нулю

void fromStringToInt(string, int&); //Из string в int
void checkLimit(int&, int); //Проверка на выход за предел (количество пользователй/поездов)
void checkGap(string&, bool&); //Проверка на пробелы
int getCountOfStucturesInFile(string file_path); //Вычисление количества структур в файле

const string Way = "MyFile.txt"; //Путь к файлу учетных записей
const string WayTrain = "Train.txt"; //Путь к файлу данных

const int LeftSolt = 15;
const int RightSolt = 25;
const int LeftCapital = 65;
const int RightCapital = 90;
const int LeftLower = 97;
const int RightLower = 122;
const int LeftNumbers = 48;
const int RightNumbers = 57;
