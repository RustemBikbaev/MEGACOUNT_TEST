// MEGACOUNT_TEST.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
using namespace std;

void one_point_one()
{
	int count = 0;
	string str1;
	string str2;
	char symbol;
	bool first = true;
	cout << "Enter the string \n";
	cin >> str1;

	for (char& c : str1)
	{
		if (first)
		{
			symbol = c;
			first = false;
		}
		if (symbol == c)
		{
			count++;
		}
		else
		{
			str2 = str2 + symbol + to_string(count);

			symbol = c;
			count = 1;
		}

	}
	str2 = str2 + symbol + to_string(count);
	cout << str2 << endl;
}



void one_point_two()
{
	int x = 0;
	int y = 0;
	int dx = 0;
	int dy = 1;
	bool back = false;

	int n;
	cout << "Enter integer value: ";
	cin >> n;
	int **array = new int*[n];
	for (int i = 0; i < n; i++)
		array[i] = new int[n];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
		array[i][j]=0;
		}
	}
	for (int i = 1; i < (n*n + 1); i++)
	{
		array[x][y] = i;
		int new_x = x + dx;
		int new_y =  y + dy;

		if (((0 <= new_x) && (new_x < n) ) && ((0 <= new_y) && (new_y < n)) && (array[new_x][new_y] == 0))
		{
						
			x= new_x;
			y = new_y;

		}
		else
		{
			if (back == true)
			{
				dx += dy;
				dy = dx - dy;
				dx -= dy;

				dx = -dx;
				dy = -dy;
				back = false;
			}
			else
			{
				dx += dy;
				dy = dx - dy;
				dx -= dy;

				back = true;
			}

			x = x + dx;;
			y = y + dy;
		}
		
	}

	for (int i=0; i<n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << array[i][j]<<"|" ;

		}	
		cout << endl;
	}
	

}

void three()
{
	string s = "Ivanov, Ivan, Ivanovich, 01.01.1998, Moscow, 128500, RK-6, 4. Petrov, Petr, Petrovich, 02.02.1995, Moscow, 128500, RK-4, 3. RK-6, 3, 1994";
	int position = 0;
	string Next_Seq = "";

	position = s.find_last_of('.');
	Next_Seq = s.substr(position + 2);

	s = s.substr(0, position + 1);

	vector<string> vec;

	position = s.find_first_of('.');
	position = s.find_first_of('.', position + 1);
	position = s.find_first_of('.', position + 1);
	while (position != string::npos)
	{
		vec.push_back(s.substr(0, position));
		if (s.size() - 1 != position) {
			s = s.substr(position + 2, s.size() - 1);
			position = s.find_first_of('.');
			position = s.find_first_of('.', position + 1);
			position = s.find_first_of('.', position + 1);
		}
		else
			break;
	}

	vector<Student> Svec;

	for (int i = 0; i < vec.size(); i++)
	{
		Student S;
		S.SetAll(vec[i]);
		Svec.push_back(S);
	}

	//а) список студентов заданного факультета;
	//б) список студентов для заданного курса;
	//в) список студентов, родившихся после заданного года.
	string Faculty = "", Course = "", Year = "";
	unsigned int year = 0;

	s = Next_Seq;
	position = s.find_first_of(',');

	Faculty = s.substr(0, position);

	s = s.substr(position + 2, s.size() - 1);

	position = s.find_first_of(',');
	Course = s.substr(0, position);

	s = s.substr(position + 2, s.size() - 1);

	Year = s;
	sscanf_s(Year.c_str(), "%d", &year);
	cout << endl << "  " << Faculty << "  " << Course << "  " << Year << endl;


	int j = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (Svec[i].GetFaculty() == Faculty)
		{
			if (j > 0) cout << "; ";
			j++;
			Svec[i].ShowAll();
		}
	}
	cout << ". ";
	j = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (Svec[i].GetCourse() == Course)
		{
			if (j > 0) cout << "; ";
			j++;
			Svec[i].ShowAll();
		}
	}
	cout << ". ";
	j = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (Svec[i].GetYear() > year)
		{
			if (j > 0) cout << "; ";
			j++;
			Svec[i].ShowAll();
		}
	}
	cout << "." <<  endl;
}

int main()
{
	int ch;
	cout << "Job 1.1 - 1" << endl;
	cout << "Job 1.2 - 2" << endl;
	cout << "Job 3 - 3" << endl;
	cout << "Enter job number" << endl;
	cin >> ch;
	switch (ch) 
	{
	case 1: one_point_one();    break;
	case 2: one_point_two();    break;
	case 3: three();  break;
	default: cout << "error\n";
	}

	return 0;
}

