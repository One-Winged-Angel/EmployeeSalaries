#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int main()
{
	double employeeSalary;
	double sum{0};
	int inputNum;
	vector <double> salaries;

	ifstream infile("salaries.txt");

	if (!infile)
	{
		cerr << "Failed to open salary file\n";
	}

	while (infile >> inputNum)
	{
		salaries.push_back(inputNum);
	}

	// total number of employees
	cout << "Total number of employees: " << salaries.size() << endl;
	//total payroll cost
	for (auto salary: salaries)
	{
		sum += salary;
	}
	cout << "The total cost to payroll is " << sum << endl;
	//average salary
	float averageSalary = sum / salaries.size();
	cout << "The average salary is " << averageSalary << endl;
	//number of employees earning overr 100k
	int count = 0;
	for (auto salary : salaries)
	{
		
		if (salary > 100000)
		{
			count++;
		}
	}

	cout << "The total number of employees who earn over 100k is " << count << endl;

	infile.close();
	return 0;
}