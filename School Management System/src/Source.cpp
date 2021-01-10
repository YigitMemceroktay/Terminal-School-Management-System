#include <stdio.h>
#include <iostream>
#include <Windows.h>
#include "School.h"
#include <vector>
#include <string>
#include <limits>
#include <ios>
#include <istream>
using namespace std;
vector<School*> list;

void printGap(int number);
void setUp();
bool appEnd;
void appLogic();
void printOptions();
void addUser();
void listUsers();
void delUser(int number);
void setChoice(int choice);
HANDLE handle;
School* users[10];
/*4 = red
  5 = puprle
  6 = yellow
  3 = blue
*/
int main() {
	appLogic();

	return 0;
}
void printGap(int number) {
	
	SetConsoleTextAttribute(handle,6);
	for (int i = 0; i < 5; i++) {

		for (int i = 0; i < number; i++) {

			cout << "#";

		}
		cout << endl;
	}
	cout << endl << endl << endl << endl;
}
void setUp() {
	appEnd= false;
	handle = GetStdHandle(STD_OUTPUT_HANDLE);
	printGap(100);
	SetConsoleTextAttribute(handle,5);
	cout << "Welcome to School Personnel Management System"<< endl << endl;

}
void printOptions() {
	SetConsoleTextAttribute(handle, 5);
	
	cout << "Please Choose An Action" << endl;
	SetConsoleTextAttribute(handle, 3);
	cout << "1-Add User" << endl;
	cout << "2-See All Users" << endl;
	cout << "3-Delete User" << endl;
	SetConsoleTextAttribute(handle, 4);
	cout << "4-Exit App" << endl;
	cout << "########################################" << endl;


}

void appLogic() {
	setUp();

	while (!appEnd) {
		int choice;
		printOptions();

		cin >> choice;
		if (std::cin.fail()) {
			std::cout << endl << "Please Enter A Valid Number"<<endl;
			continue;
		}
		if (choice > 4 || choice < 1) {
			std::cout << endl << "Please Enter A Valid Number" << endl;
			continue;
		}
		setChoice(choice);


		cin.ignore(cin.rdbuf()->in_avail());
	}



}
void setChoice(int choice) {
	switch (choice) {
		
	case 1 :
		addUser();
		break;
	case 2 : 
		listUsers();
		break;
	case 3 :
		cin.ignore(cin.rdbuf()->in_avail());
		int student;
		cout << "What number of student would you like to delete" << endl;
		cin >> student;
		delUser(student);
		break;
	case 4 :
		exit(0);
		break;

	}
	

}
void addUser() {
	string name;
	string surname;
	string phone_number;
	string gender;
	string age;
	string year;
	SetConsoleTextAttribute(handle, 7);
	
	cout << "Name:" << endl;
	cin >> name;
	cout << "Surname:" << endl;
	cin >> surname;
	cout << "Phone Number" << endl;
	while (true) {
		cin >> phone_number;
		if (phone_number.length() == 11) { break; }
		cout << "Please Enter A Phone Number:" << endl;
	}
	cout << "Gender" << endl;
	cin >> gender;
	cout << "Age" << endl;
	cin >> age;
	cout << "Role" << endl;
	cin >> year;

	
	Students *student = new Students(name, surname, phone_number, gender, age);
	list.push_back(student);
	SetConsoleTextAttribute(handle, 6);
	cout << "Personnel Added" << endl << endl;
	
	
}
void listUsers() {
	cout << endl << endl;
	SetConsoleTextAttribute(handle, 6);
	cout << "##############################################################################################" << endl;
	SetConsoleTextAttribute(handle, 7);
	for (int i = 0; i < list.size(); i++)
	{
		cout << list.at(i)->getName() << "  " << list.at(i)->getSur_name() << "  " << list.at(i)->getAge() << "  " <<
			list.at(i)->getGender() << "  " << list.at(i)->getPhone_Number()<<"  " << list.at(i)->getRole()<<endl;
		if (list.size()- 1 != i) {
			cout << endl;
			}
	}
	SetConsoleTextAttribute(handle, 6);
	cout << "##############################################################################################" << endl<<endl;

}
	

void delUser(int number) {
	if(number<list.size()+2)	{
	
		list.erase(list.begin() + number-1);
	}
}


