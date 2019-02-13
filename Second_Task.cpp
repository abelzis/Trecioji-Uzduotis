// Second_Task.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "functions.h"

int main()
{
    //variables
	vector<Student> student;	//structure of Student
	string end_var = "-2";
	ifstream kursiokai("kursiokai.txt");

	srand(time(NULL));	//initialize random seed by time

	//begin of 'get student input'
	while (end_var != "end")
	{
		instructions();
		cin >> end_var;

		//if user wants to end the input, write 'end' to break the loop
		if (end_var == "end")	
			break;

		//if user wants to get input from file 'kursiokai.txt', should write 'file'
		if (end_var == "file")
		{
			readFromKursiokai(student, kursiokai);
			continue;
		}

		getInput(student);	//lets the user to write it's own input
	}
	//end of 'get student input'

	//begin of 'calculate average and median'
	for (int i = 0; i < student.size(); i++)
	{
		student[i].avg_final = avgCalc(student[i].hw, student[i].egz);	//calculate average
		student[i].med_final = medCalc(student[i].hw, student[i].egz);	//calculate median
	}
	//end of 'calculate average and median'
	
	printOutput(student);	//print results

	system("pause");	//pause
}

