#include"Header.h"

int main()
{
	setlocale(LC_ALL, "rus");
	vector<Users> vect;
	vector<Train> vectTr;
	vect.reserve(getCountOfStucturesInFile(Way));
	vect.reserve(getCountOfStucturesInFile(WayTrain));

	checkAdminRecord(vect);

	mySystem(vect, vectTr);

	return 0;
}

