#pragma once

#include "functions.h"


//functions

void userInterface(StudentContainer& student, StudentContainer& cool_stud, StudentContainer& lame_stud,
	ifstream& file_inp,
	durationDouble& clock_file, tmPt& clock_temp);

void instructions();
void UI_Open(string& ifstreamName, ifstream& file_inp);
void UI_GenerateFile(string& ofstreamName, durationDouble& clock_file, tmPt& clock_temp);
void UI_File(ifstream& file_inp, StudentContainer& student, durationDouble& clock_file, tmPt& clock_temp);
void UI_Avg(StudentContainer& student, durationDouble& clock_file, tmPt& clock_temp);
void UI_Med(StudentContainer& student, durationDouble& clock_file, tmPt& clock_temp);

void UI_BestWorst(StudentContainer& student, StudentContainer& cool_stud, StudentContainer& lame_stud,
	durationDouble& clock_file, tmPt& clock_temp, int version = 2);

void UI_BestWorstFile(StudentContainer& student, StudentContainer& cool_stud, StudentContainer& lame_stud, string& ifstreamName,
	durationDouble& clock_file, tmPt& clock_temp);

void UI_Del(StudentContainer& st);
