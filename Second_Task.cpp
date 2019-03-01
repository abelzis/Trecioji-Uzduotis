// Second_Task.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "functions.h"


int main()
{
    //variables
	deque<Student> student, cool_stud, lame_stud;	//structure of Student
	ifstream file_inp("kursiokai.txt");

	//clock_t clock_file = 0, clock_Cfile = 0, clock_temp = 0;

	tmPt clock_temp;
	durationDouble clock_file, clock_Cfile;


	srand(time(NULL));	//initialize random seed by time

	instructions();

	//takeInput(student, cool_stud, lame_stud, file_inp, Cstudent_index, Cstudent_size, Cstudent, clock_file, clock_Cfile, clock_temp);
	takeInput(student, cool_stud, lame_stud, file_inp, clock_file, clock_Cfile, clock_temp);


	//begin of 'calculate average and median'
	if (!student[student.size() - 1].avg_final && student.size() > 0)	//if last's student's average is not defined
	{
		clock_temp = hrClock::now();	//begin time
		for (int i = 0; i < student.size(); i++)
		{
			student[i].avg_final = avgCalc(student[i].hw, student[i].egz);	//calculate average
			student[i].med_final = medCalc(student[i].hw, student[i].egz);	//calculate median
		}
		clock_file += durationDouble(hrClock::now() - clock_temp);
	}
	//end of 'calculate average and median'
	
	//print results
	cout << "-------------RESULTS OF student---------------\n\n";
	printOutput(student);	//print results of student
	cout << "TOTAL USEFUL TIME TAKEN: " << std::setprecision(10) << clock_file.count() << "s\n";
	cout << "\n\n\n-------------RESULTS OF Cstudent---------------\n\n";

	system("pause");	//pause
}

