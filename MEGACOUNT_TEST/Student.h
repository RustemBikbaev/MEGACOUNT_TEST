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
	Student(); // �����������
	Student(const Student& right); //����������� ����������� 
	~Student(); //����������

	string GetFaculty();
	string GetCourse();
	int GetYear();
	void SetAll(string s);
	void ShowAll();

};

