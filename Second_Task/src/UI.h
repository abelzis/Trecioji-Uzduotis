#pragma once

#include "functions.h"
#include "timerClass.h"



//functions
void UI_startGuide(StudentContainer& student, StudentContainer& cool_stud, StudentContainer& lame_stud,
	ifstream& file_inp);

void UI_filesGuide(StudentContainer& student, StudentContainer& cool_stud, StudentContainer& lame_stud,
	ifstream& file_inp);

void UI_manualGuide(StudentContainer& student, StudentContainer& cool_stud, StudentContainer& lame_stud,
	ifstream& file_inp);

void UI_main(StudentContainer& student, StudentContainer& cool_stud, StudentContainer& lame_stud,
	ifstream& file_inp);

void beginText();
void instructionSetForFilesGuide();
void instructionSetForManualGuide();
void instructionSetForDataGuide();
void commands();
void UI_Open(string& ifstreamName, ifstream& file_inp);
void UI_GenerateFile(string& ofstreamName);
void UI_File(ifstream& file_inp, StudentContainer& student);
void UI_Avg(StudentContainer& student);
void UI_Med(StudentContainer& student);

void UI_BestWorst(StudentContainer& student, StudentContainer& cool_stud, StudentContainer& lame_stud,
	int version = 2);

void UI_BestWorstToFile(StudentContainer& student, StudentContainer& cool_stud, StudentContainer& lame_stud);

void UI_Del(StudentContainer& st);
