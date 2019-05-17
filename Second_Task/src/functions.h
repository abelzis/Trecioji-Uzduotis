#pragma once


#include <algorithm>	//std::sort
#include <chrono>	//hr clock
#include <fstream>
#include <iomanip>
#include <iostream>
#include "randomEngine.h"
#include <string>
#include "studentClass.h"



using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;



//function declarations:
void dollarSign();	//ui when cin


void openFile(ifstream& file, const string name);
void openFile(ifstream& file);
void generateFile(ofstream& file, const int count);
bool checkIfStrIsNum(const string str);

void readFromFile(ifstream& kursiokai, StudentContainer &student);
void sortBestWorst(StudentContainer& student, StudentContainer& cool, StudentContainer& lame);
StudentContainer sortBestWorst2(StudentContainer& student);
void writeToFileBestWorst(const string ofstreamName_temp, const StudentContainer& cool, const StudentContainer& lame);
void deleteStudentContainer(StudentContainer& v);


void printOutput(StudentContainer& student);

