// Second_Task.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>	//rand()
using std::cout;
using std::cin;
using std::vector;
using std::string;

//structure of student
struct Student {
	vector<int> hw;	//homework marks
	int egz;	//exam mark
	string name, surname;
	double avg_final, med_final;	//average of final mark and median of final mark
};

//function prints instruction set
void instructions()
{
	cout << "Programa suskaiciuoja namu darbu bei egzamino galutinius ivertinimus.\n";
	cout << "Norint baigti vesti studentu duomenis, pries pradedant aprasineti studenta, iveskite 'end'. Kitu atveju, iveskite bet ka: ";
}

//function gets input and stores to student array
void getInput(vector<Student> &student)
{
	student.push_back(Student());
	int count = student.size() - 1;
	cout << "STUDENT SIZE: " << student.size() << "\n";

	//get name
	cout << "Iveskite studento varda: ";
	cin >> student[count].name;

	//get surname
	cout << "Iveskite studento pavarde: ";
	cin >> student[count].surname;


	//begin of 'input homework'
	cout << "Dabar veskite namu darbu rezultatus (minimali verte 1, maksimali 10).\n";
	cout << "Atsitiktiniam namu darbu ir egzaminu rezultatu sugeneravimui, rasykite \"rand\".\n";
	cout << "Kai baigsite, iveskite \"egz\": ";
	string temp_input;
	while (temp_input != "egz")
	{
		cin >> temp_input;
		//begin of 'randomize homework results'
		if (temp_input == "rand")
		{
			int max_rand = 20;	//20 is maximum amount of homework currently
			//begin of 'rand error message'
			if (max_rand - student[count].hw.size() < 1)
			{
				cout << "Negeneruojama, kai yra virs " << max_rand << " namu darbu.";
				continue;
			}
			//end of 'rand error message'

			int rand_hw_num = rand() % (max_rand - student[count].hw.size());	

			for (int i = 0; i < rand_hw_num; i++)
				student[count].hw.push_back(1 + rand() % 10);	//randomize between 1 and 10
			student[count].egz = 1 + rand() % 10;	//randomize exam

			return;
		}
		//end of 'randomize homework results'

		//get mark input
		if (temp_input == "1" || temp_input == "2" || temp_input == "3" || temp_input == "4" || temp_input == "5" || temp_input == "6"
			|| temp_input == "7" || temp_input == "8" || temp_input == "9" || temp_input == "10")//if the input is between 1 and 10 inclusive
			student[count].hw.push_back(std::stoi(temp_input));	//add to hw array
	}
	//end of 'input homework'

	//begin of 'input of exam'
	cout << "Iveskite egzamino rezultata (nuo 1 iki 10): ";
	cin >> student[count].egz;
	while (student[count].egz < 1 || student[count].egz > 10)
		cin >> student[count].egz;
	//end of 'input of exam'
}

//function returns the avarage value of the vector array
double avgCalc(vector<int> hw, int egz)
{
	//calculate the sum of array and return the average
	int sum = 0;
	for (int i = 0; i < hw.size(); i++)
		sum += hw[i];
	return 0.4*(double)(sum / hw.size()) + 0.6*egz;
}

//function returns the median value of the vector array
double medCalc(vector<int> hw, int egz)
{
	//we need to sort the array in ascending order
	std::sort(hw.begin(), hw.end());

	//if odd
	if (hw.size() % 2 == 1)
		return 0.4*(double)hw[hw.size() / 2] + 0.6*egz;
	//if even
	if (hw.size() % 2 == 0)
		return 0.4*(double)((hw[hw.size() / 2 - 1] + hw[hw.size() / 2]) / 2) + 0.6*egz;
}


//function prints output of stucture student
void printOutput(vector<Student> student)
{
	cout << "\n\n";
	cout << std::setw(24) << std::left << "Pavarde";
	cout << " " << std::setw(24) << std::left << "Vardas";
	cout << " " << std::setw(10) << std::left << "VidGalut";
	cout << " " << std::setw(10) << std::left << "MedGalut\n";
	for (int i = 0; i < 24 + 24 + 10 + 10; i++)
		cout << '-';
	cout << "\n";
	for (int i = 0; i < student.size(); i++)
	{
		cout << std::setw(24) << std::left << student[i].surname;
		cout << " " << std::setw(24) << std::left << student[i].name;
		cout << " " << std::setw(10) << std::left << std::setprecision(2) << student[i].avg_final;
		cout << " " << std::setw(10) << std::left << std::setprecision(2) << student[i].med_final << "\n";
	}
}

int main()
{
    //variables
	vector<Student> student;	//structure of Student
	string end_var = "-2";

	srand(time(NULL));

	//begin of 'get student input'
	while (end_var != "end")
	{
		instructions();
		cin >> end_var;
		if (end_var == "end")
			break;
		getInput(student);
	}
	//end of 'get student input'

	//begin of 'calculate average and median'
	for (int i = 0; i < student.size(); i++)
	{
		student[i].avg_final = avgCalc(student[i].hw, student[i].egz);	//calculate average
		student[i].med_final = medCalc(student[i].hw, student[i].egz);	//calculate median
	}
	//end of 'calculate average and median'
	
	printOutput(student);	//print results
}

