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
void addUserRef();
void listUsers();
void delUser(int number);
void setChoice(string &choice);
string choseRole();
void addGeneral();
void addStudent(string& name, string& surname, string& phone_number, string& gender, string& age);
void addProfessor(string& name, string& surname, string& phone_number, string& gender, string& age);
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
		string choice;
		printOptions();

		cin >> choice;
		if (choice._Equal("1")|| choice._Equal("2")|| choice._Equal("3")|| choice._Equal("4")|| choice._Equal("5")) 
		{
			setChoice(choice);
			
		}
		else {
			cout << "Please Enter a Valid Choice" << endl;
		}
		


		
	}

	

}
void setChoice(string &choice) {
	int choiceNum = stoi(choice);
	switch (choiceNum) {
		
	case 1 :
		addUser();
		break;
	case 2 : 
		listUsers();
		break;
	case 3 :
		
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
	addGeneral();
	
	
}

void listUsers() {
	cout << endl << endl;
	SetConsoleTextAttribute(handle, 6);
	cout << "##############################################################################################" << endl;
	SetConsoleTextAttribute(handle, 7);
	cout << endl << "Num" << "   Name      " << "Surname   " << "Age  " << "Gender  " << "Phone Number  "
		<< "Role       " << "Department" << endl;
	for(int i = 0; i < list.size(); i++)
	{	
		cout << i + 1;
		if (i > 9) {
			cout << "    ";
		}
		else {
			cout<<"     ";
		}
		cout << list.at(i)->getName(); 
		for (int j = 0; j < 10 - (list.at(i)->getName()).length();j++) {
			cout << " ";

		}
		
		cout << list.at(i)->getSur_name();
		for(int j=0; j<10-list.at(i)->getSur_name().length();j++){
			cout << " ";
		}
		cout << list.at(i)->getAge();
		for (int j = 0; j <5 - list.at(i)->getAge().length();j++) {
			cout << " ";
		}
		cout <<
			list.at(i)->getGender();
		for (int j = 0; j < 8 - list.at(i)->getGender().length();j++) {
			cout << " ";
		}
		cout << list.at(i)->getPhone_Number() << "   ";
		cout << list.at(i)->getRole();
		for (int j = 0; j < 11 - list.at(i)->getRole().length();j++) {
			cout << " ";
		}
		cout << list.at(i)->getDepartment();
		cout << endl;
	}
	SetConsoleTextAttribute(handle, 6);
	cout << "##############################################################################################" << endl<<endl;

}
	

void delUser(int number) {
	if(number<list.size()+2)	{
	
		list.erase(list.begin() + number-1);
	}
}

string choseRole() {
	string choice;
	cout << endl << "What Member Would You Like To Add ?" << endl;
	cout << "1-Student" << endl;
	cout << "2-Professor" << endl;
	
	while (true) {
		
		cin >> choice;
		
		if (choice._Equal("1")|| choice._Equal("2")){
			break;
		}
		else {
			cout << "Please Enter a Valid Choice" << endl;
		}
	}
	return choice;
}
void addStudent(string &name, string &surname, string &phone_number, string &gender, string &age){
	Students* student = new Students(name, surname, phone_number, gender, age);
	list.push_back(student);
	SetConsoleTextAttribute(handle, 6);
	cout << "Personnel Added" << endl << endl;
}
void addProfessor(string& name, string& surname, string& phone_number, string& gender, string& age){
	string department;
	cout << "Department?";
	cin >> department;
	Professors* professors = new Professors(name, surname, phone_number, gender, age, department);
	list.push_back(professors);
	SetConsoleTextAttribute(handle, 6);
	cout << "Personnel Added" << endl << endl;

}
void addGeneral() {
	string name;
	string surname;
	string phone_number;
	string gender;
	string age;
	string year;
	int choice = stoi(choseRole());
	SetConsoleTextAttribute(handle, 7);

	cout << "Name:" << endl;
	cin >> name;
	cout << "Surname:" << endl;
	cin >> surname;
	cout << "Phone Number" << endl;
	while (true) {
		cin >> phone_number;
		if (phone_number.length() == 11) { break; }
		cout << "Please Enter Valid A Phone Number:" << endl;
	}
	cout << "Gender" << endl;
	cin >> gender;
	cout << "Age" << endl;
	cin >> age;
	switch(choice){
	case 1:
		addStudent(name, surname, phone_number, gender, age);
		break;
	case 2:
		addProfessor(name, surname, phone_number, gender, age );
		break;

	}
}


