// Second_Task.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "functions.h"
#include "Cfunctions.h"


int main()
{
    //variables
	vector<Student> student;	//structure of Student
	string end_var = "-2";
	ifstream kursiokai("kursiokai.txt");
	int Cstudent_index = -1, Cstudent_size = 10;
	CStudent *Cstudent = new CStudent[Cstudent_size]; //structure of CStudent

	clock_t clock_file = 0, clock_Cfile = 0, clock_temp = 0;

	srand(time(NULL));	//initialize random seed by time


	//begin of 'get student input'
	while (end_var != "end")
	{
		instructions();
		cin >> end_var;

		if (end_var == "open")
		{
			openFile(kursiokai);
			continue;
		}

		//if user wants to end the input, write 'end' to break the loop
		if (end_var == "end")	
			break;

		//if user wants to get input from file 'kursiokai.txt', should write 'file'
		if (end_var == "file")
		{
			clock_temp = clock();

			readFromKursiokai(kursiokai, student);

			clock_file = clock() - clock_temp;
			continue;
		}

		//if user wants to write input into C-type array
		if (end_var == "C-array")
		{
			//if no more space in the C-type array, then recreate the array with double the capacity
			if (Cstudent_index + 2 >= Cstudent_size)
				MultiplyCstudentSize(Cstudent, Cstudent_index, Cstudent_size);

			Cstudent_index++;	//increment size by one
			
			try
			{
				TypeGetInput(Cstudent, Cstudent_index);	//lets the user to write it's own input into C-type array
			}
			catch (const char* msg)	//if error
			{
				Cstudent_index--;
				cout << "\n" << msg << "\n\n";	//print error message
			}

			continue;
		}

		//if user wants to read from file to C-type array
		if (end_var == "Cfile")
		{
			clock_temp = clock();

			//read from kursiokai file
			readFromKursiokai(kursiokai, Cstudent, Cstudent_index, Cstudent_size);
			clock_Cfile = clock() - clock_temp;
			continue;
		}

		try 
		{
			getInput(student);	//lets the user to write it's own input into vector array
		}
		catch (const char* msg) //if error
		{
			cout << "\n" <<  msg << "\n\n";	//print error message
		}
	}
	//end of 'get student input'

	//begin of 'calculate average and median'
	clock_temp = clock();
	for (int i = 0; i < student.size(); i++)
	{
		student[i].avg_final = avgCalc(student[i].hw, student[i].egz);	//calculate average
		student[i].med_final = medCalc(student[i].hw, student[i].egz);	//calculate median
	}
	clock_file = clock() - clock_temp + clock_file;
	

	//for C-type array
	clock_temp = clock();
	for (int i = 0; i <= Cstudent_index; i++)
	{
		Cstudent[i].avg_final = avgCalc(Cstudent[i].hw, Cstudent[i].hw_count, Cstudent[i].egz);	//calculate average
		Cstudent[i].med_final = medCalc(Cstudent[i].hw, Cstudent[i].hw_count, Cstudent[i].egz);	//calculate median
	}
	clock_Cfile = clock() - clock_temp + clock_Cfile;
	//end of 'calculate average and median'
	
	//print results
	cout << "-------------RESULTS OF student---------------\n\n";
	printOutput(student);	//print results of student
	cout << "TIME TAKEN: " << std::setprecision(10) << (double)clock_file / CLOCKS_PER_SEC << "\n\n\n";
	cout << "\n\n\n-------------RESULTS OF Cstudent---------------\n\n";
	printOutput(Cstudent, Cstudent_index);	//print results of Cstudent

	cout << "TIME TAKEN: " << std::setprecision(10) << ((double)clock_Cfile) / CLOCKS_PER_SEC << "\n";

	system("pause");	//pause
}

