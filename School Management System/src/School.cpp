#include "School.h"

	School::School(string name, string sur_name, string phone_number, string gender, string age) {
		this->name = name;
		this->sur_name = sur_name;
		this->phone_number = phone_number;
		this->gender = gender;
		this->age = age;
		
		
	}
	School::~School(void){}
	

	string School::getName() {
		return name;
	}

	string School::getSur_name() {
		return sur_name;
	}
	string School::getPhone_Number() {

		return phone_number;

	}
	string School::getGender() {

		return gender;
	}
	string School::getAge() {

		return age;
	}
	Students::Students(string name, string sur_name, string phone_number, string gender, string age) :
		School(name, sur_name, phone_number, gender, age) {
		role = "Student";
	}
    string Students::getRole() {
		return role;
	}
	Professors::Professors(string name, string sur_name, string phone_number, string gender, string age, string department) :
		School(name, sur_name, phone_number, gender, age) {
		this->department = department;
		role = "Professor";
	 }
	string Professors::getRole() {
		return this->role;
 }
	string Professors::getDepartment() {
		return this->department;
	}
	string Students::getDepartment() {
		return "NaN";
	}
	
