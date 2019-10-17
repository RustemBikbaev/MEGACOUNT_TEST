#include "pch.h"
#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

Student::Student()
{
	Name = "";
	Surname = "";
	Otchestvo = "";
	Birthday = "";
	Address = "";
	Phone =  "";
	Faculty = "";
	Course = "";
}

Student::Student(const Student& right)
{
	Name = right.Name;
	Surname = right.Surname;
	Otchestvo = right.Otchestvo;
	Birthday = right.Birthday;
	Address = right.Address;
	Phone = right.Phone;
	Faculty = right.Faculty;
	Course = right.Course;
}

Student::~Student()
{
}

string Student::GetFaculty()
{
	return Faculty;
}

string Student::GetCourse()
{
	return Course;
}

int Student::GetYear()
{
	int a = 0, b = 0;
	sscanf_s(Birthday.c_str(), "%d.%d.%d", &a, &a, &b);
	return b;
}


void Student::SetAll(string s)
{
	int pos = 0;

	pos = s.find_first_of(',');
	if (pos == std::string::npos) return;
	Name = s.substr(0, pos);
	if (s.size() - 1 == pos) return;
	s = s.substr(pos + 2, s.size() - 1);

	pos = s.find_first_of(',');
	if (pos == std::string::npos) return;
	Surname = s.substr(0, pos);
	if (s.size() - 1 == pos) return;
	s = s.substr(pos + 2, s.size() - 1);

	pos = s.find_first_of(',');
	if (pos == std::string::npos) return;
	Otchestvo = s.substr(0, pos);
	if (s.size() - 1 == pos) return;
	s = s.substr(pos + 2, s.size() - 1);

	pos = s.find_first_of(',');
	if (pos == std::string::npos) return;
	Birthday = s.substr(0, pos);
	if (s.size() - 1 == pos) return;
	s = s.substr(pos + 2, s.size() - 1);

	pos = s.find_first_of(',');
	if (pos == std::string::npos) return;
	Address = s.substr(0, pos);
	if (s.size() - 1 == pos) return;
	s = s.substr(pos + 2, s.size() - 1);

	pos = s.find_first_of(',');
	if (pos == std::string::npos) return;
	Phone = s.substr(0, pos);
	if (s.size() - 1 == pos) return;
	s = s.substr(pos + 2, s.size() - 1);

	pos = s.find_first_of(',');
	if (pos == std::string::npos) return;
	Faculty = s.substr(0, pos);
	if (s.size() - 1 == pos) return;
	s = s.substr(pos + 2, s.size() - 1);

	Course = s;

}

void Student::ShowAll()
{
	cout << Name << ", " << Surname << ", " << Otchestvo << ", " << Birthday << ", " << Address << ", " << Phone << ", " << Faculty << ", " << Course;
}