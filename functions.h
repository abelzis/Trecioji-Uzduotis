#pragma once


//#define VECTOR
//#define LIST
#define DEQUE


#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>	//std::sort
#include <random>	//random device
#include <fstream>
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

#ifdef VECTOR
typedef vector<Student> StudentContainer;
typedef vector<int> intContainer;
#endif
#ifdef LIST
typedef list<Student> StudentContainer;
typedef list<int> intContainer;
#endif
#ifdef DEQUE
typedef deque<Student> StudentContainer;
typedef deque<int> intContainer;
#endif


//function declarations:
void openFile(ifstream& file, const string name);
void openFile(ifstream& file);
void generateFile(ofstream& file, const int count);
bool checkIfStrIsNum(const string str);

void getInput(StudentContainer &student);
void readFromFile(ifstream& kursiokai, StudentContainer &student);
void sortBestWorst(const StudentContainer& student, StudentContainer& cool, StudentContainer& lame);
StudentContainer sortBestWorst2(StudentContainer& student);
void writeToFileBestWorst(const string ofstreamName_temp, const StudentContainer& cool, const StudentContainer& lame);
void deleteStudentContainer(StudentContainer& v);

#ifdef VECTOR
double avgCalc(vector<int> hw, int egz);
double medCalc(vector<int> hw, int egz);
#endif

#ifdef LIST
double avgCalc(list<int> hw, int egz);
double medCalc(list<int> hw, int egz);
#endif

#ifdef DEQUE
double avgCalc(deque<int> hw, int egz);
double medCalc(deque<int> hw, int egz);
#endif

void printOutput(StudentContainer& student);

