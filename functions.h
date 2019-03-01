#pragma once

#include <iostream>
#include <iomanip>
#include <list>
#include <string>
#include <algorithm>	//std::sort
#include <cstdlib>	//rand()
#include <fstream>
#include <Windows.h>	//time
#include <chrono>	//hr clock
using std::cout;
using std::cin;
using std::list;
using std::string;
using std::ifstream;
using std::ofstream;

using hrClock = std::chrono::high_resolution_clock;
using durationDouble = std::chrono::duration<double>;
using tmPt = std::chrono::time_point<hrClock>;

//structure of student
struct Student {
	list<int> hw;	//homework marks
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

void takeInput(list<Student>& student, list<Student>& cool_stud, list<Student>& lame_stud,
	ifstream& file_inp,
	durationDouble& clock_file, durationDouble& clock_Cfile, tmPt& clock_temp);

void instructions();
void openFile(ifstream& file, const string name);
void openFile(ifstream& file);
void generateFile(ofstream& file, const int count);
bool checkIfStrIsNum(const string str);
void getInput(list<Student> &student);
void readFromFile(ifstream& file, list<Student> &student);
void sortBestWorst(const list<Student> student, list<Student>& cool, list<Student>& lame);
void writeToFileBestWorst(const string ofstreamName_temp, const list<Student> cool, const list<Student> lame);
double avgCalc(list<int> hw, int egz);
double medCalc(list<int> hw, int egz);
//bool compareNames(Student &a, Student &b);
void printOutput(list<Student> student);
//int longestName(vector<Student> student);
//int longestSurname(vector<Student> student);