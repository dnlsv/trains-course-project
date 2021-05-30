#include"Header.h"

void generateVector(vector<Users>& vect)
{
	string login, password;
	Users Us;
	vect.push_back(Us);
	cout << endl << "Введите логин (8-16 символов)" << endl;
	checkLogin(login, vect);
	vect.at(vect.size() - 1).login = login;
	cout << endl << "Введите пароль (8-16 символов)" << endl;
	checkPassword(password);
	vect.at(vect.size() - 1).salt = salt();
	vect.at(vect.size() - 1).salted_hash_password = myHash(password + vect.at(vect.size() - 1).salt);
	vect.at(vect.size() - 1).role = 1;
	cout << endl << "Пользователь добавлен!" << endl;
}

void addToVector(vector<Users>& vect)
{
	string login, password;
	Users Us;
	vect.push_back(Us);
	cout << endl << "Введите логин (5-15 символов)" << endl;
	checkLogin(login, vect);
	vect.at(vect.size() - 1).login = login;
	cout << endl << "Введите пароль (5-15 символов)" << endl;
	checkPassword(password);
	vect.at(vect.size() - 1).salt = salt();
	vect.at(vect.size() - 1).salted_hash_password = myHash(password + vect.at(vect.size() - 1).salt);
	checkBool(vect.at(vect.size() - 1).role);
	cout << endl << "Пользователь добавлен!" << endl;
}

void showVector(vector<Users> vect)
{
	cout << endl << "\tСписок учетных записей" << endl << endl;
	cout << setw(3) << "№" << "|" << setw(15) << "Логин" << "|" << setw(5) << "Роль" << endl;
	for (unsigned int i = 0; i < vect.size(); i++)
		cout << "----------------------------" << endl
		<< setw(3) << i + 1 << "|" << setw(15) << vect.at(i).login << "|"
		<< setw(5) << vect.at(i).role << endl;
}

void correctVector(vector<Users>& vect, int& numUs, int key)
{
	string password, login;
	int kod;
	bool flag = true;
	checkWhoseCorrectRole(numUs, key, flag, vect.size());;
	if (numUs != 0) {
		correctOwnRole(kod, flag);
		switch (kod) {
		case 1: //Логин
			cout << endl << "Введите новый логин (5-15 символов)" << endl;
			checkLogin(login, vect);
			vect.at(numUs - 1).login = login;
			break;
		case 2: //Пароль
			cout << endl << "Введите новый пароль (5-15 символов)" << endl;
			checkPassword(password);
			vect.at(numUs - 1).salt = salt();
			vect.at(numUs - 1).salted_hash_password = myHash(password + vect.at(numUs - 1).salt);
			break;
		case 3: //Роль
			cout << endl << "Введите новую роль" << endl;
			checkBool(vect.at(numUs - 1).role);
			break;
		case 0:
			cout << endl << "Данные не изменены!" << endl;
			break;
		default:
			cout << "Error!" << endl;
		}
		if (kod >= 1 && kod <= 3)
			cout << endl << "Данные изменены!" << endl;
	}
}

void deleteVector(vector<Users>& vect, int key)
{
	int numUs;
	deleteOwnRecord(numUs, key, vect.size());
	reallyDeleteRecord(vect, numUs);
}

void writeFileUsers(vector<Users>& vect)
{
	ofstream fout(Way, ios::out); //Открыли файл для записи
	for (unsigned int i = 0; i < vect.size(); i++)
	{
		fout << vect.at(i).login << " "
			<< vect.at(i).salted_hash_password << " "
			<< vect.at(i).salt << " "
			<< vect.at(i).role;
		if (i < vect.size() - 1)
			fout << endl;

	}
	fout.close();
}

void addFileUsers(Users newUser)
{
	ofstream fadd(Way, ios::app); //Открыли файл для дозаписи
	fadd << endl;
	fadd << newUser.login << " "
		<< newUser.salted_hash_password << " "
		<< newUser.salt << " "
		<< newUser.role;
	fadd.close();
}

void readFileUsers(vector<Users>& vect)
{
	Users Us;
	ifstream fin(Way, ios::in); //Открыли файл для чтения
	if (!fin.is_open()) cout << "Указанный файл не существует!" << endl;
	else
	{
		int i = 0;
		while (!fin.eof())
		{
			vect.push_back(Us);
			fin >> vect.at(i).login
				>> vect.at(i).salted_hash_password
				>> vect.at(i).salt
				>> vect.at(i).role;
			i++;
		}
	}
	fin.close(); //Закрыли открытый файл
}

void authorization(vector<Users> vect, int& key) {
	string log, pass;
	bool flag;
	while (1) {
		cout << "Введите логин: ";
		cin >> log;
		flag = false;
		for (unsigned int i = 0; i < vect.size(); i++) {
			if (log == vect.at(i).login) {
				flag = true;
				key = i;
				break;
			}
		}
		cout << endl << "Введите пароль: ";
		maskingPassword(pass);
		if (flag == true && myHash(pass + vect.at(key).salt) == vect.at(key).salted_hash_password)
			break;
		else
			cout << "Введен неверный логин или пароль. Повторите попытку!" << endl << endl;
	}
}

string salt()//rand() % (b - a + 1) + a
{
	string Salt;
	int n, temp;
	char chr;
	n = rand() % (RightSolt - LeftSolt + 1) + LeftSolt;//Соль от 15 до 25 символов
	for (int i = 0; i < n; i++)
	{
		temp = rand() % (3 - 1 + 1) + 1;
		if (temp == 1) chr = rand() % (RightCapital - LeftCapital + 1) + LeftCapital;//Заглавные буквы
		if (temp == 2) chr = rand() % (RightLower - LeftLower + 1) + LeftLower;//Строчные буквы
		if (temp == 3) chr = rand() % (RightNumbers - LeftNumbers + 1) + LeftNumbers;//Цифры
		Salt += chr;
	}
	return Salt;
}

string myHash(string str)
{
	int prm;
	hash<string> hashStr;
	size_t hash = hashStr(str);
	prm = hash;
	string newStr = to_string(prm);
	return newStr;
}



