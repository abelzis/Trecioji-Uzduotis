#pragma once

#include <iostream>
#include <iomanip>
#include <deque>
#include <string>
#include <algorithm>	//std::sort
#include <cstdlib>	//rand()
#include <fstream>
#include <Windows.h>	//time
#include <chrono>	//hr clock
#include "Cfunctions.h"
using std::cout;
using std::cin;
using std::deque;
using std::string;
using std::ifstream;
using std::ofstream;

using hrClock = std::chrono::high_resolution_clock;
using durationDouble = std::chrono::duration<double>;
using tmPt = std::chrono::time_point<hrClock>;

//structure of student
struct Student {
	deque<int> hw;	//homework marks
	int egz;	//exam mark
	string name, surname;
	double avg_final, med_final;	//average of final mark and median of final mark
};



//function declarations:
//void takeInput(vector<Student>& student, vector<Student>& cool_stud, vector<Student>& lame_stud,
//	ifstream& file_inp,
//	int& Cstudent_index, int& Cstudent_size,
//	CStudent *Cstudent,
//	clock_t& clock_file, clock_t& clock_Cfile, clock_t& clock_temp);

void takeInput(deque<Student>& student, deque<Student>& cool_stud, deque<Student>& lame_stud,
	ifstream& file_inp,
	durationDouble& clock_file, durationDouble& clock_Cfile, tmPt& clock_temp);

void instructions();
void openFile(ifstream& file, const string name);
void openFile(ifstream& file);
void generateFile(ofstream& file, const int count);
bool checkIfStrIsNum(const string str);
void getInput(deque<Student> &student);
void readFromFile(ifstream& file, deque<Student> &student);
void sortBestWorst(const deque<Student> student, deque<Student>& cool, deque<Student>& lame);
void writeToFileBestWorst(const string ofstreamName_temp, const deque<Student> cool, const deque<Student> lame);
double avgCalc(deque<int> hw, int egz);
double medCalc(deque<int> hw, int egz);
//bool compareNames(Student &a, Student &b);
void printOutput(deque<Student> student);
//int longestName(vector<Student> student);
//int longestSurname(vector<Student> student);