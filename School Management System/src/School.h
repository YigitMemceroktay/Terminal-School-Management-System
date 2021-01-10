#pragma once
#include <iostream>
#include <stdio.h>


#include "School.h"


using namespace std;

	class School
	{
	protected:
		
		string name;
		string sur_name;
		string phone_number;
		string age;
		string gender;
	public:
		~School(void);
		School(string name, string sur_name, string phone_number, string gender, string age);
		string getName();
		string getSur_name();
		string getPhone_Number();
		string getAge();
		string getGender();
		virtual string getRole() =0;
	};
	
	class Students : public School {
	private:
		string role;
	public:
		Students(string name, string sur_name, string phone_number, string gender, string age);
		 string getRole() override;

	};


