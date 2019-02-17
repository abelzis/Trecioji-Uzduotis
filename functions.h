#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>	//std::sort
#include <cstdlib>	//rand()
#include <fstream>
#include <Windows.h>
#include "Cfunctions.h"
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



//function declarations:
void instructions();
void openFile(ifstream& file);
void getInput(vector<Student> &student);
void readFromKursiokai(ifstream& kursiokai, vector<Student> &student);
double avgCalc(vector<int> hw, int egz);
double medCalc(vector<int> hw, int egz);
bool compareNames(Student &a, Student &b);
void printOutput(vector<Student> student);
int longestName(vector<Student> student);
int longestSurname(vector<Student> student);




void CTypeGetInput(CStudent *Cstudent, int const Cstudent_index);