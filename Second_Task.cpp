// Second_Task.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "functions.h"
#include "UI.h"
#include "timerClass.h"



int main()
{
	////test class
	//cout << "student count = " << Student::count() << "\n";

	//Student test;

	//cout << "student count = " << test.count() << "\n";

	//cin >> test;

	//Student b = { "namas", "vasarnamis" };

	//cout << test << "\n";
	//cout << "student count = " << test.count() << "\n";

	//system("Pause");


	//{
	//	Student test;
	//	cin >> test;

	//	cout << "sizeof test = " << sizeof(test) << "\n";
	//	{
	//		Student b = test;
	//		cout << b << "\n";
	//	}
	//	cout << test << "\n";
	//}

	//variables


	StudentContainer student, cool_stud, lame_stud;	//structure of Student

	ifstream file_inp;

	Timer timer;


	UI_startGuide(student, cool_stud, lame_stud, file_inp);

	cout << "TOTAL TIME TAKEN: " << std::setprecision(10) << timer.elapsed() << "s\n";

	system("pause");	//pause
}
