// Second_Task.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>	//rand()
#include <fstream>
using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::ifstream;

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
	cout << "Galite ivesti duomenis is failo, ivede 'file'.\n";
	cout << "Norint baigti vesti studentu duomenis, pries pradedant aprasineti studenta, iveskite 'end'. Kitu atveju, iveskite bet ka: ";
}

//function gets input and stores to student array
void getInput(vector<Student> &student)
{
	student.push_back(Student());	//push back structure array
	int count = student.size() - 1;	//get count of student
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

			int rand_hw_num = rand() % (max_rand - student[count].hw.size());	//get random homework amount

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

//function reads from 'kursiokai.txt'
void readFromKursiokai(vector<Student> &student, ifstream& kursiokai)
{


	/*----------------STRUCTURE OF kursiokai.txt------------------------
	Pavarde     Vardas      ND1  ND2   ND3  ND4  ND5 ...  Egzaminas
	Vardas1     Pavarde1    8    9     10   6    10  ...  9
	Vardas2     Pavarde2    7    10    8    5    4   ...  6
	*/

	//begin of 'if file open'
	if (kursiokai.is_open())
	{
		string file_str;	//temporary string holding file's lines
		//std::getline(kursiokai, file_str);
		//cout << file_str << "\n";
		//begin of 'read from kursiokai'
		while (std::getline(kursiokai, file_str))	//getlines until eof
		{
			student.push_back(Student());	//push back
			int student_count = student.size() - 1;	//counter to track indexes

			//begin of 'character scan from file_str'
			//begin of 'get name'
			int file_str_index = 0;	//index of file_str to point to characters
			while (file_str[file_str_index] != ' ')	//search for whitespace
				file_str_index++;	//increment by one

			student[student_count].name.append(file_str, 0, file_str_index);	//append name to structure
			file_str.erase(0, file_str_index + 1);	//delete name from temporary file_str string
			//end of 'get name'

			//begin of 'get surname'
			file_str_index = 0;	//index of file_str to point to characters
			while (file_str[file_str_index] != ' ')	//search for whitespace
				file_str_index++;

			student[student_count].surname.append(file_str, 0, file_str_index);	//append name to structure
			file_str.erase(0, file_str_index + 1);	//delete name from temporary file_str string
			//end of 'get surname'

			//begin of 'get exam'
			if (isdigit(file_str[file_str.length() - 1]))	//if last character is digit
			{
				if (file_str[file_str.length() - 1] == '0')	//if found 0
				{
					if (file_str[file_str.length() - 2 == '1'])	//if found 1 before 0
					{
						student[student_count].egz = 10;	//set .egz to 10
						file_str.erase(file_str.length() - 3, 3);	//erase whitespace and two last characters
					}

				}
				if (file_str[file_str.length() - 1] != '0')	//if found any other digit
				{
					student[student_count].egz = file_str[file_str.length() - 1] - '0';	//set .egz to that digit
					file_str.erase(file_str.length() - 2, 2);	//erase whitespace and last character
				}

			}
			//end of 'get exam'

			//begin of 'get homework'
			file_str_index = 0;	//reset index
			while (file_str.length() > 0)	//search for homework results between namespaces
			{
				//begin of 'if digit found'
				if (isdigit(file_str[file_str_index]))	//if found digit
				{
					//begin of 'any digit but 1'
					if (file_str[file_str_index] != '1' && file_str[file_str_index] != '0')	//if found any digit but '1'
					{
						if (file_str[file_str_index + 1] == ' ' || file_str.length() == 1)	//if the digit is followed by whitespace or found last character
							student[student_count].hw.push_back(file_str[file_str_index] - '0');	//push back into student homework the mark
						//if (file_str.length() == 1)
						//	student[student_count].hw.push_back(file_str[file_str_index] - '0');
					}

					//end of 'any digit but 1'

					//begin of 'found 1'
					if (file_str[file_str_index] == '1')	//if found '1'
					{
						if (file_str[file_str_index + 1] == ' ')	//if 1 is followed by whitespace
							student[student_count].hw.push_back(1);	//push back 1

						if (file_str[file_str_index + 1] == '0')	//if 1 is followed by 0
							if (file_str[file_str_index + 2] == ' ' || file_str.length() == 2)	//if 10 is followed by whitespace or found last 2 characters
								student[student_count].hw.push_back(10);	//push back 10
					}
					//end of 'found 1'
				}
				//end of 'if digit found'

				//begin of 'last characters of homework found'
				if (file_str.length() == 1 && file_str_index == 1)	//if reached last character and already manipulated 
					break;	//then break
				
				//if found 10
				if (file_str.length() == 2 && file_str_index == 2)	//if 2 characters are last
					if (file_str[0] == '1' && file_str[1] == '0')	//if those are 1 and 0
						break;	//then break
				//end of 'last characters of homework found'

				//if the whitespace is found, delete from string beginning up to whitespace inclusive
				if (file_str[file_str_index] == ' ')	//if found whitespace
				{
					file_str.erase(0, file_str_index + 1);	//delete the pushed back homework from temporary string
					file_str_index = 0;	//reset index
					continue;	//go next
				}


				file_str_index++;	//increment by 1
			}
			//end of 'get homework'
			//end of 'character scan from file_str'
		}
		//end of 'read from kursiokai'
	}
	//end of 'if file open'
	//begin of 'if file is not open'
	else
		cout << "Klaida: neimanoma atidaryti failo.\n";
	//end of 'if file is not open'
	
}

//function returns the avarage value of the vector array
double avgCalc(vector<int> hw, int egz)
{
	//calculate the sum of array and return the average
	int sum = 0;
	for (int i = 0; i < hw.size(); i++)
		sum += hw[i];

	if (hw.size() != 0)	//skip division by 0
		return 0.4*(double)((double)sum / (double)hw.size()) + 0.6*egz;
	return 0;
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
	{
		if (hw.size() != 0)	//skip division by 0
			return 0.4*(double)((hw[hw.size() / 2 - 1] + hw[hw.size() / 2]) / 2) + 0.6*egz;
		return 0;
	}
}

//function used in sorting function to compare string characters
bool compareNames(Student &a, Student &b)
{
	//compare by name
	if (a.name.size() < b.name.size())
		for (int i = 0; i < a.name.size(); i++)
			if (a.name[i] != b.name[i])
				return b.name[i] > a.name[i];
			
	//else
	return b.name[0] > a.name[0];
}


//function prints output of stucture student
void printOutput(vector<Student> student)
{
	std::sort(student.begin(), student.end(), compareNames);	//sort structures

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
		cout << " " << std::setw(10) << std::left << std::fixed << std::setprecision(2) << student[i].avg_final;
		cout << " " << std::setw(10) << std::left << std::fixed << std::setprecision(2) << student[i].med_final << "\n";
	}
}

int main()
{
    //variables
	vector<Student> student;	//structure of Student
	string end_var = "-2";
	ifstream kursiokai("kursiokai.txt");

	srand(time(NULL));

	//begin of 'get student input'
	while (end_var != "end")
	{
		instructions();
		cin >> end_var;

		if (end_var == "end")
			break;

		if (end_var == "file")
		{
			readFromKursiokai(student, kursiokai);
			continue;
		}

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

	system("pause");
}

