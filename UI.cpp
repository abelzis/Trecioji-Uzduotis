#include "UI.h"

//function UI
//begin of 'VECTOR declaration'
void userInterface(StudentContainer& student, StudentContainer& cool_stud, StudentContainer& lame_stud,
					ifstream& file_inp,
					durationDouble& clock_file, tmPt& clock_temp)
	//end of 'DEQUE declaration'
{
	string end_var = "-2", ifstreamName = "kursiokai.txt", ofstreamName;

	//begin of 'get student input'
	while (end_var != "end")
	{
		cin >> end_var;

		//prints instruction list
		if (end_var == "help")
		{
			instructions();
			continue;
		}

		//user can open any file if the file exists and read from it
		//begin of 'open ifstream file'
		if (end_var == "open")
		{
			UI_Open(ifstreamName, file_inp);
			continue;
		}
		//end of 'open ifstream file'

		//if user wants to generate file with certain amount of students
		//begin of 'generate-file'
		if (end_var == "generate-file")
		{
			UI_GenerateFile(ofstreamName, clock_file, clock_temp);
			continue;
		}
		//end of 'generate-file'

		//if user wants to get input from file 'filename.txt', should write 'file'
		if (end_var == "file")
		{
			UI_File(file_inp, student, clock_file, clock_temp);
			continue;
		}


		//if user wants to write input into StudentContainer
		if (end_var == "input")
		{
			try
			{
				getInput(student);	//lets the user to write it's own input into vector array
			}
			catch (const char* msg) //if error
			{
				cout << "\n" << msg << "\n\n";	//print error message
			}
		}


		//calculate average
		if (end_var == "avg")
		{
			UI_Avg(student, clock_file, clock_temp);
			continue;
		}


		//calculate median
		if (end_var == "med")
		{
			UI_Med(student, clock_file, clock_temp);
			continue;
		}

		//if 'best-worst' is selected, pick students with high marks in one array, and students with bad marks in another array
		if (end_var == "best-worst")
		{
			UI_BestWorst(student, cool_stud, lame_stud, clock_file, clock_temp, 1);
			continue;
		}



		//if 'best-worst' is selected, pick students with high marks in one array, and students with bad marks in another array
		if (end_var == "best-worst2")
		{
			UI_BestWorst(student, cool_stud, lame_stud, clock_file, clock_temp);
			continue;
		}


		//if user wants to write best-worst students into seperate files
		if (end_var == "best-worst-file")
		{
			UI_BestWorstFile(student, cool_stud, lame_stud, ifstreamName, clock_file, clock_temp);
			continue;
		}

		//if user wants to clear memory
		if (end_var == "del-stud")
		{
			UI_Del(student);
			UI_Del(cool_stud);
			UI_Del(lame_stud);
			continue;
		}

		if (end_var == "results")
		{
			//print results
			cout << "-------------RESULTS OF student---------------\n\n";
			printOutput(student);	//print results of student
			cout << "TOTAL USEFUL TIME TAKEN: " << std::setprecision(10) << clock_file.count() << "s\n";
		}


		//if user wants to end the input, write 'end' to break the loop
		if (end_var == "end")
			break;

		if (end_var == "test")
		{
			openFile(file_inp, "million.txt");
			UI_File(file_inp, student, clock_file, clock_temp);
			UI_Avg(student, clock_file, clock_temp);
			UI_Med(student, clock_file, clock_temp);
			UI_BestWorst(student, cool_stud, lame_stud, clock_file, clock_temp);
			UI_BestWorstFile(student, cool_stud, lame_stud, ifstreamName, clock_file, clock_temp);

			UI_Del(student);
			UI_Del(cool_stud);
			UI_Del(lame_stud);
			break;
		}


		//if no correct input
		cout << "\nPlease follow the instructions. Type 'help' for more information.\n";

	}
	//end of 'get student input'
}




//function prints instruction set
void instructions()
{
	cout << "Programa suskaiciuoja namu darbu bei egzamino galutinius ivertinimus.\n";
	cout << "Komandu sarasas:\n";
	cout << "\t'help' ismeta instrukciju sarasa.\n";
	cout << "\t'open' leidzia atidaryti pasirinkta faila.\n";
	cout << "\t'generate-file' leidzia sugeneruot faila su atsitiktiniais studentu duomenimis.\n";
	cout << "\t'file' nuskaito is atidaryto failo duomenis ir ikelia i konteineri.\n";
	cout << "\t'input' leidzia ranka irasyti duomenis i konteineri.\n";
	cout << "\t'avg' suskaiciuoja duomenu galutini vidurki.\n";
	cout << "\t'med' suskaiciuoja duomenu galutini mediana.\n";
	cout << "\t'best-worst' surusiuoja i atskirus konteinerius geriausius studentus nuo blogiausiu.\n";
	cout << "\t'best-worst2' atrenka blogiausius studentus ir juos sudeda i nauja konteineri, o geriausius palieka.\n";
	cout << "\t'best-worst-file' israso geriausius ir blogiausius studentus i atskirus failus.\n";
	cout << "\t'del-stud' sunaikina visas duomenu strukturas.\n";
	cout << "\t'results' israso rezultatus.\n";
	cout << "\t'end' baigia darba.\n";
}





void UI_Open(string& ifstreamName, ifstream& file_inp)
{
	while (1)
	{
		cout << "Follow the template - filename.txt. - 'exit' to leave 'open'.\n";
		cout << "Enter full file name you want to access : ";
		cin >> ifstreamName;	//get input stream text

		//if user wants to leave this section
		if (ifstreamName == "exit")
		{
			ifstreamName = "kursiokai.txt";	//set to default ifstream
			break;
		}

		//test if the user has written in form filename.txt
		string test_if_txt;
		if (ifstreamName.length() > 4)
		{
			test_if_txt.append(ifstreamName, ifstreamName.length() - 4, 4);
			if (test_if_txt == ".txt")
				break;
		}
	}

	//if the ifstreamName string is not empty
	//begin of 'write random student objects'
	if (!ifstreamName.empty())
	{
		try
		{
			//file_inp.open(ifstreamName, std::fstream::in);	//get the ofstream
			//file_inp.open(ifstreamName);	//get the ofstream
			openFile(file_inp, ifstreamName);
			if (!file_inp.is_open())
				throw "Error: can't open selected file.";

			cout << "File successfully has been opened.\n";
			return;
		}
		catch (const char* msg)	//if error catch message
		{
			cout << "\n" << msg << "\n\n";	//print error message
			return;
		}
	}
	openFile(file_inp);
}



void UI_GenerateFile(string& ofstreamName, durationDouble& clock_file, tmPt& clock_temp)
{
	cout << "You are able to generate files with random student information. Please note, that only '.txt' extensions are supported.\n";
	while (1)
	{
		cout << "Follow the template - filename.txt. - 'exit' to leave 'generate-file'.\n";
		cout << "Enter full file name you want to create: ";
		cin >> ofstreamName;

		//if user wants to leave this section
		if (ofstreamName == "exit")
		{
			ofstreamName.clear();	//empty the string
			break;
		}

		//test if the user has written in form filename.txt
		string test_if_txt;
		if (ofstreamName.length() > 4)
		{
			test_if_txt.append(ofstreamName, ofstreamName.length() - 4, 4);
			if (test_if_txt == ".txt")
				break;
		}

	}

	//if the ofstreamName string is not empty
	//try to write randomized student objects to file named ofstreamName
	//begin of 'write random student objects'
	if (!ofstreamName.empty())
	{
		try
		{
			ofstream rand_out(ofstreamName);	//get the ofstream

			//get amount of randomized students
			cout << "Enter the number of randomized student objects to create: ";
			string get_rand_amount;
			cin >> get_rand_amount;

			bool is_number = checkIfStrIsNum(get_rand_amount);	//check if the given string is number

			//if string is only digits
			if (is_number)
			{
				try
				{
					cout << "Beginning to generate file...";
					//clock_temp = clock();	//begin time
					clock_temp = hrClock::now();

					generateFile(rand_out, std::stoi(get_rand_amount));	//generate file with student objects

					//end time
					//clock_file = clock() - clock_temp + clock_file;
					clock_file += durationDouble(hrClock::now() - clock_temp);
					//cout << "Finished! Took: " << (double)(clock() - clock_temp) / CLOCKS_PER_SEC << "s\n";
					cout << "Finished! Took: " << durationDouble(hrClock::now() - clock_temp).count() << "s\n";
				}
				catch (const char* msg)
				{
					cout << "\n" << msg << "\n\n";	//print error message
					return;
				}
			}


			else
				throw "Error: input is not a number.";	//throw error
			return;
		}
		catch (const char* msg)	//if error catch message
		{
			cout << "\n" << msg << "\n\n";	//print error message
			return;
		}
	}
	//end of 'write random student objects'
}


void UI_File(ifstream& file_inp, StudentContainer& student, durationDouble& clock_file, tmPt& clock_temp)
{
	cout << "Beginning to read from file...";

	clock_temp = hrClock::now();

	try
	{
		readFromFile(file_inp, student);
#ifndef LIST
		student.shrink_to_fit();
#endif
	}
	catch (const char* msg)	//if error catch message
	{
		cout << "\n" << msg << "\n\n";	//print error message
		return;
	}

	clock_file += durationDouble(hrClock::now() - clock_temp);
	cout << "Finished! Took: " << durationDouble(hrClock::now() - clock_temp).count() << "s\n";
}


void UI_Avg(StudentContainer& student, durationDouble& clock_file, tmPt& clock_temp)
{
	//begin of 'calculate average'
	cout << "Beginning to calculate averages...";
	clock_temp = hrClock::now();
	for (auto & it : student)
		it.avg_final = avgCalc(it.hw, it.egz);	//calculate average
	clock_file += durationDouble(hrClock::now() - clock_temp);
	cout << "Finished! Took: " << durationDouble(hrClock::now() - clock_temp).count() << "s\n";
	//end of 'calculate average'
}


void UI_Med(StudentContainer& student, durationDouble& clock_file, tmPt& clock_temp)
{
	//begin of 'calculate median'
	cout << "Beginning to calculate medians...";
	clock_temp = hrClock::now();
	for (auto & it : student)
		it.med_final = medCalc(it.hw, it.egz);	//calculate median
	clock_file += durationDouble(hrClock::now() - clock_temp);
	cout << "Finished! Took: " << durationDouble(hrClock::now() - clock_temp).count() << "s\n";
	//end of 'calculate median'
}


void UI_BestWorst(StudentContainer& student, StudentContainer& cool_stud, StudentContainer& lame_stud, 
					durationDouble& clock_file, tmPt& clock_temp, int version)
{
	try
	{
		cout << "Beginning to seperate best from worst...";
		clock_temp = hrClock::now();

		if (version == 1)
			sortBestWorst(student, cool_stud, lame_stud);	//sort best from worst
		if (version == 2)
			lame_stud = sortBestWorst2(student);

		//end time
		clock_file += durationDouble(hrClock::now() - clock_temp);
		cout << "Finished! Took: " << durationDouble(hrClock::now() - clock_temp).count() << "s\n";
	}
	catch (const char* msg)
	{
		cout << "\n" << msg << "\n\n";	//print error message
	}
}


void UI_BestWorstFile(StudentContainer& student, StudentContainer& cool_stud, StudentContainer& lame_stud, string& ifstreamName,
						durationDouble& clock_file, tmPt& clock_temp)
{
	//if vectors are empty, error and continue
	if (cool_stud.empty() && lame_stud.empty())
	{
		cout << "Error: cool and lame vectors are empty.\n";
		return;
	}


	string ofstreamName_temp;
	while (1)
	{
		cout << "Enter a number x, to give number cool_x.txt, lame_.txt. - 'exit' to leave this section 'best-worst-file'.\n";
		cout << "Enter a number: ";

		cin >> ofstreamName_temp;	//get output stream text name

		//if user wants to leave this section
		if (ifstreamName == "exit")
		{
			ifstreamName.clear();	//empty the string
			break;
		}

		//check if input string is number
		if (checkIfStrIsNum(ofstreamName_temp))
			break;

		cout << "\nYou did not enter a number. Try again and follow the instructions.\n";	//error msg
	}
	//if given string is not empty, means its a number
	if (!ofstreamName_temp.empty())
	{
		try
		{
			cout << "Beginning to write best and worst students to files...";
			clock_temp = hrClock::now();	//begin time

			if (cool_stud.empty())
				writeToFileBestWorst(ofstreamName_temp, student, lame_stud);
			else
				writeToFileBestWorst(ofstreamName_temp, cool_stud, lame_stud);	//output results in files

			//end time
			clock_file += durationDouble(hrClock::now() - clock_temp);
			cout << "Finished! Took: " << durationDouble(hrClock::now() - clock_temp).count() << "s\n";

		}
		catch (const char* msg)	//if error
		{
			cout << "\n" << msg << "\n\n";	//print error message
		}
	}
}

void UI_Del(StudentContainer& st)
{
	try
	{
		//delete student object
		deleteStudentContainer(st);
	}
	catch (const char* msg)	//if error
	{
		cout << "\n" << msg << "\n\n";	//print error message
	}
}