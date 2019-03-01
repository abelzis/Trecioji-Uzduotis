#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>	//std::sort
#include <cstdlib>	//rand()
#include <fstream>
#include <Windows.h>	//time
#include <chrono>	//hr clock
using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;

using hrClock = std::chrono::high_resolution_clock;
using durationDouble = std::chrono::duration<double>;
using tmPt = std::chrono::time_point<hrClock>;

//structure of student
struct Student {
	vector<int> hw;	//homework marks
	int egz;	//exam mark
	string name, surname;
	double avg_final, med_final;	//average of final mark and median of final mark
};




//function declarations:

void takeInput(vector<Student>& student, vector<Student>& cool_stud, vector<Student>& lame_stud,
	ifstream& file_inp,
	durationDouble& clock_file, tmPt& clock_temp);

void instructions();
void openFile(ifstream& file, const string name);
void openFile(ifstream& file);
void generateFile(ofstream& file, const int count);
bool checkIfStrIsNum(const string str);
void getInput(vector<Student> &student);
void readFromFile(ifstream& kursiokai, vector<Student> &student);
void sortBestWorst(const vector<Student> student, vector<Student>& cool, vector<Student>& lame);
void writeToFileBestWorst(const string ofstreamName_temp, const vector<Student> cool, const vector<Student> lame);
double avgCalc(vector<int> hw, int egz);
double medCalc(vector<int> hw, int egz);
//bool compareNames(Student &a, Student &b);
void printOutput(vector<Student> student);
//int longestName(vector<Student> student);
//int longestSurname(vector<Student> student);