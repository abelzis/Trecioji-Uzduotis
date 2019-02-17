#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>	//std::sort
#include <cstdlib>	//rand()
#include <fstream>
using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::ifstream;

//structure of Cstudent
struct CStudent {
	int hw_size = 20, hw_count = 0;
	int *hw = new int[hw_size];	//homework marks
	int egz;	//exam mark
	string name, surname;
	double avg_final, med_final;	//average of final mark and median of final mark
};


void MultiplyHwSize(CStudent *Cstudent, int const hw_count, int Cstudent_index);
void MultiplyCstudentSize(CStudent *&Cstudent, int Cstudent_index, int &Cstudent_size);
void TypeGetInput(CStudent *Cstudent, int const Cstudent_index);
void readFromKursiokai(ifstream& kursiokai, CStudent *&Cstudent, int &Cstudent_index, int& Cstudent_size);
double avgCalc(const int const *hw, const int hw_size, const int egz);
double medCalc(int *hw, const int hw_size, const int egz);
bool CcompareNames(CStudent &a, CStudent &b);
int longestName(const CStudent *Cstudent, const int Cstudent_index);
int longestSurname(const CStudent *Cstudent, const int Cstudent_index);
void printOutput(CStudent *Cstudent, const int Cstudent_index);
