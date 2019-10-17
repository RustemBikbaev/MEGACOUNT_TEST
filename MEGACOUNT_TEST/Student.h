#pragma once
#include <string>
using namespace std;

class Student
{
	string Name;
	string Surname;
	string Otchestvo;
	string Birthday;
	string Address;
	string Phone;
	string Faculty;
	string Course;

public:
	Student(); // конструктор
	Student(const Student& right); //конструктор копирования 
	~Student(); //деструктор

	string GetFaculty();
	string GetCourse();
	int GetYear();
	void SetAll(string s);
	void ShowAll();

};

