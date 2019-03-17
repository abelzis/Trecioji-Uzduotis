#pragma once


#define VECTOR
//#define LIST
//#define DEQUE


#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>	//std::sort
#include <random>	//random device
#include <fstream>
#include <Windows.h>	//time
#include <chrono>	//hr clock

//begin of 'VECTOR include'
#ifdef VECTOR
	#include <vector>
	using std::vector;
#endif	
//end of 'VECTOR include'

//begin of 'LIST include'
#ifdef LIST	
	#include <list>
	using std::list;
#endif
//end of 'LIST include'

//begin of 'DEQUE include'
#ifdef DEQUE
	#include <deque>
	using std::deque;
#endif
//end of 'DEQUE include'

using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;

using hrClock = std::chrono::high_resolution_clock;
using durationDouble = std::chrono::duration<double>;
using tmPt = std::chrono::time_point<hrClock>;

//structure of student
struct Student {
#ifdef VECTOR
	vector<int> hw;	//homework marks
#endif

#ifdef LIST
	list<int> hw;	//homework marks
#endif

#ifdef DEQUE
	deque<int> hw;	//homework marks
#endif
	int egz;	//exam mark
	string name, surname;
	double avg_final, med_final;	//average of final mark and median of final mark
};




//function declarations:
void instructions();
void openFile(ifstream& file, const string name);
void openFile(ifstream& file);
void generateFile(ofstream& file, const int count);
bool checkIfStrIsNum(const string str);


//begin of 'VECTOR functions'
#ifdef VECTOR
void takeInput(vector<Student>& student, vector<Student>& cool_stud, vector<Student>& lame_stud,
	ifstream& file_inp,
	durationDouble& clock_file, tmPt& clock_temp);

void getInput(vector<Student> &student);
void readFromFile(ifstream& kursiokai, vector<Student> &student);
void sortBestWorst(const vector<Student>& student, vector<Student>& cool, vector<Student>& lame);
void sortBestWorst2(vector<Student>& student, vector<Student>& lame);
void writeToFileBestWorst(const string ofstreamName_temp, const vector<Student>& cool, const vector<Student>& lame);
void deleteStudentVector(vector<Student>& v);
double avgCalc(vector<int> hw, int egz);
double medCalc(vector<int> hw, int egz);
void printOutput(vector<Student>& student);
#endif
//end of 'VECTOR functions'


//begin of 'LIST functions'
#ifdef LIST
void takeInput(list<Student>& student, list<Student>& cool_stud, list<Student>& lame_stud,
	ifstream& file_inp,
	durationDouble& clock_file, tmPt& clock_temp);

void getInput(list<Student> &student);
void readFromFile(ifstream& kursiokai, list<Student> &student);
void sortBestWorst(const list<Student>& student, list<Student>& cool, list<Student>& lame);
void sortBestWorst2(list<Student>& student, list<Student>& lame);
void writeToFileBestWorst(const string ofstreamName_temp, const list<Student>& cool, const list<Student>& lame);
void deleteStudentVector(list<Student>& v);
double avgCalc(list<int> hw, int egz);
double medCalc(list<int> hw, int egz);
void printOutput(list<Student>& student);
#endif
//end of 'LIST functions'


//begin of 'DEQUE functions'
#ifdef DEQUE
void takeInput(deque<Student>& student, deque<Student>& cool_stud, deque<Student>& lame_stud,
	ifstream& file_inp,
	durationDouble& clock_file, tmPt& clock_temp);

void getInput(deque<Student> &student);
void readFromFile(ifstream& kursiokai, deque<Student> &student);
void sortBestWorst(const deque<Student>& student, deque<Student>& cool, deque<Student>& lame);
void sortBestWorst2(deque<Student>& student, deque<Student>& lame);
void writeToFileBestWorst(const string ofstreamName_temp, const deque<Student>& cool, const deque<Student>& lame);
void deleteStudentVector(deque<Student>& v);
double avgCalc(deque<int> hw, int egz);
double medCalc(deque<int> hw, int egz);
void printOutput(deque<Student>& student);
#endif
//end of 'DEQUE functions'

