// Second_Task.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "functions.h"
#include "UI.h"
#include "timerClass.h"



int main()
{
	//variables
	StudentContainer student, cool_stud, lame_stud;	//structure of Student

	ifstream file_inp;

	Timer timer;


	UI_startGuide(student, cool_stud, lame_stud, file_inp);

	cout << "TOTAL TIME TAKEN: " << std::setprecision(10) << timer.elapsed() << "s\n";

	system("pause");	//pause
}
