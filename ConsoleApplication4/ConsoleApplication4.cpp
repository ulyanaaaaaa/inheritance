#include<iostream>
#include <fstream>
using namespace std;

class Human
{
	string fio;
	int day;
	int month;
	int year;
public:
	Human() {
		cout << "Enter fio" << endl;
		cin >> fio;
		cout << "Enter day of birth" << endl;
		while (!(cin >> this->day) || this->day < 1 || this->day > 31) {
				cout << "Error" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
		}
		cout << "Enter month of birth:" << endl;
		while (!(cin >> this->month) || this->month < 1 || this->month > 12) {
			cout << "Error" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		cout << "Enter year of birth" << endl;
		while (!(cin >> this->year) || this->year < 1900 || this->year > 2022) {
			cout << "Error" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
	}
	virtual void putData(){
		cout << "FIO:" << fio << endl;
		cout << "Birth:" << day << "." << month << "." << year << endl;
	}
	~Human() {
		cout << "Destructor" << endl;
	}
	
	void writeFile(Human* k) {
		ofstream out;
		out.open("my.txt");
		if (!out.is_open())
		{
			cout << "File don't open" << endl;
		}
		out << k;
		out.close();
		cout << "File has been written" << endl;
	}
};

class Teacher :public virtual Human
{ 
	string position;
	int academicDegree;
	string speciality;
	string scientificList;
public:
	Teacher() {
		cout << "Enter position" << endl;
		cin >> position;
		do {
			cout << "Enter academic degree(if isnt enter 0)" << endl;
			cin >> academicDegree;
		} while (academicDegree <= 0 && academicDegree > 10);
		cout << "Enter speciality" << endl;
		cin >> speciality;
		cout << "Enter list of scientific work" << endl;
		cin >> scientificList;
	}

	virtual void putData() {
		cout << "Position:" << position << endl;
		cout << "Academic degree:" << academicDegree << endl;
		cout << "Speciality:" << speciality << endl;
		cout << "List of scientific work:" << scientificList << endl;
	}

	virtual int getDegree() {
		return this->academicDegree;
	}

	~Teacher() {
		cout << "Destructor" << endl;
	}
};

class Representative :public virtual Human
{
	string nameCommission;
	int year1;
public:
	Representative() {
		cout << "Enter name of commission" << endl;
		cin >> nameCommission;
		do {
			cout << "Enter year of commission" << endl;
			cin >> year1;
		} while (year1 < 1900 && year1 > 2024);

	}
	virtual void putData() {
		cout << "Name of commission:" << nameCommission << endl;
		cout << "Year of commission:" << year1 << endl;
	}
	~Representative() {
		cout << "Destructor" << endl;
	}
};

class TeacherRepresentative :public Teacher, public Representative
{
	string workList;
public:
	TeacherRepresentative() {
		cout << "Enter work list" << endl;
		cin >> workList;
	}

	virtual void putData() {

		cout << "Work list:" << workList << endl;
	}
	~TeacherRepresentative() {
		cout << "Destructor" << endl;
	}
};

void menu() {
	cout << "1. Add teacher" << endl;
	cout << "2. Add representative" << endl;
	cout << "3. Add teacher-representative" << endl;
	cout << "4. View all human" << endl;
	cout << "5. View teachers only with academicc degree" << endl;
	cout << "0. Exit" << endl;
}
 
int main()
{
	Teacher* emp = NULL;
	Human* g = NULL;
	Human* h = NULL;
	int size = 0, size1 = 0, size2 = 0;
	while (1) {
		menu();
		int a;
		cin >> a;
		switch (a) {
		case 1:
			cout << "How many?" << endl;
			cin >> size;
			emp = new Teacher[size];
			break;
			system("pause");
		case 2:
			cout << "How many?" << endl;
			cin >> size1;
			g = new Representative[size1];
			break;
			system("pause");
		case 3:
			cout << "How many?" << endl;
			cin >> size2;
			h = new TeacherRepresentative[size2];
			break;
			system("pause");
		case 4:
			for (int i = 0;i < size;i++) {
				cout << "Teacher:" << endl;
				emp[i].putData();
			}
			for (int j = 0;j < size1;j++) {
				cout << "Representative" << endl;
				g[j].putData();
			}
			for (int k = 0;k < size2;k++) {
				cout << "Teacher-representative:" << endl;
				h[k].putData();
			}
			break;
			system("pause");
		case 5:
			for (int i = 0;i < size;i++) {
				if (emp[i].getDegree() >= 1) {
					emp[i].putData();
					emp[i].writeFile(&emp[i]);
				}
			}
		case 0:
			delete[] emp;
			delete[] g;
			delete[] h;
			return 0;
		}
	}
}
