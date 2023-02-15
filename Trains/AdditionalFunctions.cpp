#include"Header.h"

void checkAdminRecord(vector<Users>& vect)
{
	fstream file(Way);
	if (file.peek() == EOF) { //Если первый символ конец файла 		
		cout << "Создайте учетную запись администратора" << endl;
		generateVector(vect);
		writeFileUsers(vect);
		cout << "Учетная запись администратора создана!" << endl << endl;
	}
	else
		readFileUsers(vect);
}

void checkLogin(string& login, vector<Users> vect) {

	bool flag, enumerator;
	int counter1, counter2;
	while (1) {
		getline(cin, login);
		enumerator = true;
		checkGap(login, enumerator);
		flag = true;
		checkUniqueness(login, vect, flag);
		counter1 = counter2 = 0;
		checkRequirementsLogin(login, counter1, counter2);
		if (flag == true && login.length() >= 5 && login.length() <= 15 && login.length() == counter1 && counter2 == 1 && enumerator == true)
			break;
		else
			if (flag == true)
				cout << endl << "Error!" << endl << "Логин не соответствует минимальным требованиям!" << endl
				<< "Логин может содержать только буквы или цифры (Также он не может состоять из одних цифр и не может содержать пробелы)!" << endl;

	}
}

void checkUniqueness(string login, vector<Users> vect, bool& flag) {
	for (unsigned int i = 0; i < vect.size(); i++) {
		if (login == vect.at(i).login) {
			cout << endl << "Error!" << endl << "Пользователь с таким логином уже существует. Выберите другой логин!" << endl;
			flag = false;
		}
	}
}

void checkRequirementsLogin(string login, int& counter1, int& counter2) {
	for (unsigned int i = 0; i < login.length(); i++) {
		if (login[i] >= 'A' && login[i] <= 'Z' || login[i] >= 'a' && login[i] <= 'z' || login[i] >= '0' && login[i] <= '9')
			counter1++;
		if (login[i] >= 'A' && login[i] <= 'Z' || login[i] >= 'a' && login[i] <= 'z')
			counter2 = 1;
	}
}

void checkPassword(string& password) {
	bool enumerator;
	while (1) {
		getline(cin, password);
		enumerator = true;
		checkGap(password, enumerator);
		if (enumerator == false)
			cout << endl << "Error!" << endl << "Пароль содержит пробелы. Попробуйте снова!" << endl;
		if (password.length() < 5)
			cout << endl << "Error!" << endl << "Пароль слишком короткий. Попробуйте снова!" << endl;
		if (password.length() > 15)
			cout << endl << "Error!" << endl << "Пароль слишком длинный. Попробуйте снова!" << endl;
		if (password.length() >= 5 && password.length() <= 15 && enumerator == true)
			break;
	}
}

void deleteOwnRecord(int& numUs, int key, int numberOfUsers) {
	while (1) {
		cout << endl << "Введите порядковый номер учетной записи (0 - Вернуться)" << endl;
		checkLimit(numUs, numberOfUsers);
		if (key != numUs - 1)
			break;
		else
			cout << "Error!" << endl << "Вы не можете удалить собственную учетную запись!" << endl;
	}
}

void reallyDeleteRecord(vector<Users>& vect, int& numUs) {
	int kod;
	if (numUs != 0) {
		cout << endl << "Вы действительно хотите удалить эту учетную запись?" << endl
			<< "1 - Да" << endl << "0 - Нет" << endl;
		checkInt(kod);
		switch (kod) {
		case 1:
			vect.erase(vect.begin() + numUs - 1);
			cout << endl << "Учетная запись удалена!" << endl;
			break;
		case 0:
			cout << endl << "Учетная запись не удалена!" << endl;
			break;
		default:
			cout << "Error!" << endl;
		}
	}
}


void checkWhoseCorrectRole(int& numUs, int key, bool& flag, int numberOfUsers) {
	cout << endl << "Введите порядковый номер учетной записи (0 - Вернуться)" << endl;
	checkLimit(numUs, numberOfUsers);
	if (key == numUs - 1)
		flag = false;
}

void correctOwnRole(int& kod, bool flag) {
	while (1) {
		cout << endl << "Какие данные Вы хотите изменить?" << endl;
		cout << "1 - Логин" << endl << "2 - Пароль" << endl << "3 - Роль" << endl << "0 - Вернуться" << endl;
		checkInt(kod);
		if (flag == false && kod == 3)
			cout << endl << "Error!" << endl << "Вы не можете изменить собствунную роль!" << endl;
		else
			break;
	}
}

void maskingPassword(string& pass)
{
	vector<char> password;
	char c;
	int j = 0;
	char* arr = new char[17];

	while ((c = _getch()) != '\r')
	{
		if (j == 16)
			break;
		arr[j] = c;
		password.push_back(c);
		_putch('*');
		j++;
	}
	arr[j++] = '\0';

	string str(arr);
	str = arr;
	pass = str;

	cout << endl;

	delete[]arr;
}

void checkPoint(string& point) {
	int counter;
	while (1) {
		getline(cin, point);
		counter = 0;
		for (auto str : point)
			if (str >= 'A' && str <= 'Z' || str >= 'a' && str <= 'z')
				counter++;
		if (counter == point.length() && point[0] >= 'A' && point[0] <= 'Z')
			break;
		else
			cout << "Error!" << endl;
	}
}

void checkDate(string& date) {
	int counter;
	while (1) {
		//checkSystemDate(date, getCurrentDate());
		cin >> date;
		counter = 0;
		if (date.length() == 10) {
			if (date[0] == '0') {
				counter++;
				if (date[1] >= '1' && date[1] <= '9')
					counter++;
			}
			if (date[0] == '1' || date[0] == '2') {
				counter++;
				if (date[1] >= '0' && date[1] <= '9')
					counter++;
			}
			if (date[0] == '3') {
				counter++;
				if (date[1] == '0' || date[1] == '1')
					counter++;
			}
			if (date[2] == '.')
				counter++;
			if (date[3] == '0') {
				counter++;
				if (date[4] >= '1' && date[4] <= '9')
					counter++;
			}
			if (date[3] == '1') {
				counter++;
				if (date[4] >= '0' && date[4] <= '2')
					counter++;
			}
			if (date[5] == '.')
				counter++;
			//if (date[6] == '2')
			counter++;
			//if (date[7] == '0')
			counter++;
			//if (date[8] == '1')
			counter++;
			//if (date[9] == '9')
			counter++;
		}
		if (counter == date.length())
			break;
		else
			cout << "Error!" << endl;
	}
}

void checkTime(string& time) {
	int counter;
	while (1) {
		/*getline(cin, time);*/
		cin >> time;
		counter = 0;
		if (time.length() == 5) {
			if (time[0] == '0' || time[0] == '1') {
				counter++;
				if (time[1] >= '0' && time[1] <= '9')
					counter++;
			}
			if (time[0] == '2') {
				counter++;
				if (time[1] >= '0' && time[1] <= '3')
					counter++;
			}
			if (time[2] == ':')
				counter++;
			if (time[3] >= '0' && time[3] <= '5') {
				counter++;
				if (time[4] >= '0' && time[4] <= '9')
					counter++;
			}
		}
		if (counter == time.length())
			break;
		else
			cout << "Error!" << endl;
	}
}

void checkSence(string& time) {
	int tout, tin;
	string timein, timeout;
	timeout = time;
	while (1) {
		checkTime(time);
		timein = time;
		fromStringToInt(timeout, tout);
		fromStringToInt(timein, tin);
		if (timeout >= timein)
			cout << "Error!" << endl;
		else
			break;
	}
}

void reallyDeleteTrain(vector<Train>& vectTr, int numTr) {
	int kod;
	if (numTr != 0) {
		cout << endl << "Вы действительно хотите удалить этот рейс?" << endl
			<< "1 - Да" << endl << "0 - Нет" << endl;
		checkInt(kod);
		switch (kod) {
		case 1:
			vectTr.erase(vectTr.begin() + numTr - 1);
			cout << endl << "Рейс удален!" << endl;
			break;
		case 0:
			cout << endl << "Рейс не удален!" << endl;
			break;
		default:
			cout << "Error!" << endl;
		}
	}
}

void ckeckNotNullValue(vector<Train>& vectTr, int number) {
	while (1) {
		checkDouble(vectTr.at(number - 1).val);
		if (vectTr.at(number - 1).val == 0)
			cout << "Error!" << endl;
		else
			break;
	}
}

void checkNumberOfTickets(vector<Train> vectTr, int& kol, int numTr) {
	while (1) {
		checkInt(kol);
		if (kol <= vectTr.at(numTr - 1).left && kol > 0)
			break;
		else
			cout << "Error!" << endl;
	}
}


void checkInt(int& number)
{
	while (true) {
		cin >> number;
		if (number >= 0 && cin.get() == '\n')
			break;
		else {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Error!" << endl;
		}
	}
}

void checkDouble(double& number) {
	while (true) {
		cin >> number;
		if (number >= 0 && cin.get() == '\n')
			break;
		else {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Error!" << endl;
		}
	}
}

void checkBool(bool& number) {
	while (true) {
		cout << endl << "Введите роль" << endl;
		cin >> number;
		if (cin.get() == '\n')
			break;
		else {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Error!" << endl;
		}
	}
}

void fromStringToInt(string str, int& number) {
	str.erase(2, 1);
	stringstream s(str);
	s >> number;
}

void checkLimit(int& number, int allnumber) {
	while (1) {
		checkInt(number);
		if (number >= 0 && number <= allnumber)
			break;
		else
			cout << "Error!" << endl;
	}
}

void checkGap(string& line, bool& enumerator) {
	for (auto str : line)
		if (str == ' ')
			enumerator = false;
}

int getCountOfStucturesInFile(string file_path)
{
	ifstream file(file_path, ios::in); // Открыли текстовый файл для чтения
	int numberOfStrings = 0;
	if (file.is_open())
	{
		string buffer;
		while (getline(file, buffer))
			numberOfStrings++;
	}
	file.close();
	return numberOfStrings;
}

Date getCurrentDate()
{
	SYSTEMTIME tm;
	GetLocalTime(&tm);
	Date currentDate;
	currentDate.day = to_string(tm.wDay);
	currentDate.month = to_string(tm.wMonth);
	currentDate.year = to_string(tm.wYear);
	return currentDate;
}

Time getCurrentTime()
{
	SYSTEMTIME tm;
	GetLocalTime(&tm);
	Time currentTime;
	currentTime.hour = to_string(tm.wHour);
	currentTime.minute = to_string(tm.wMinute);
	currentTime.second = to_string(tm.wSecond);
	return currentTime;
}

void checkSystemDate(string dat, Date date) {
	string day, mnth, year, c;
	while (true) {
		c = '\0';
		getline(cin, dat);
		c = dat[0];  day.append(c);
		c = dat[1];  day.append(c);
		if (dat[3] == '0')
			mnth = dat[4];
		else {
			c = dat[3];  mnth.append(c);
			c = dat[4];  mnth.append(c);
		}
		c = dat[6];  year.append(c);
		c = dat[7];  year.append(c);
		c = dat[8];  year.append(c);
		c = dat[9];  year.append(c);
		if (day >= date.day && mnth >= date.month && year == date.year)
			break;
		else
			cout << "Error!" << endl;
	}
}