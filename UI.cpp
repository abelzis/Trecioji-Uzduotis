#include "UI.h"

Timer timer1;

bool exit_test = false;

void dollarSign()
{
	cout << " $ ";
}

void UI_startGuide(StudentContainer& student, StudentContainer& cool_stud, StudentContainer& lame_stud,
	ifstream& file_inp)
{
	string command_str = "-2";

	beginText();

	while (command_str != "END" || command_str != "EXIT")
	{
		if (exit_test == true)
			break;
		dollarSign();

		timer1.pause();
		cin >> command_str;
		timer1.resume();

		std::transform(command_str.begin(), command_str.end(), command_str.begin(), ::toupper);	//transform command line to uppercase

		if (command_str == "FILES")
		{
			UI_filesGuide(student, cool_stud, lame_stud, file_inp);
			continue;
		}

		if (command_str == "MANUAL")
		{
			UI_manualGuide(student, cool_stud, lame_stud, file_inp);
			continue;
		}
		//UI_main(student, cool_stud, lame_stud, file_inp);

		if (command_str == "END" || command_str == "EXIT")
			break;

		else
			cout << "\nError: Unknown command.\n";
	}

	cout << "TOTAL USEFUL TIME TAKEN: " << std::setprecision(10) << timer1.elapsed() << "s\n";
}

void UI_filesGuide(StudentContainer& student, StudentContainer& cool_stud, StudentContainer& lame_stud,
	ifstream& file_inp)
{
	instructionSetForFilesGuide();

	UI_main(student, cool_stud, lame_stud, file_inp);
}

void UI_manualGuide(StudentContainer& student, StudentContainer& cool_stud, StudentContainer& lame_stud,
	ifstream& file_inp)
{
	instructionSetForManualGuide();

	UI_main(student, cool_stud, lame_stud, file_inp);
}


void beginText()
{
	cout << "Ikelti is failo ar rasyti ranka? Jei ikelti is failo - 'files'; jei rasyti ranka - 'manual'\n";
}


void instructionSetForFilesGuide()
{
	cout << "\nPradekite nuo duomenu ikelimo is failo. Tam reikia failo su duomenimis.";
	cout << "\nGalite sugeneruoti naudodami komanda 'generate-file'.";
	cout << "\nTurint faila reiktu ji atidaryti - 'open'.\n";
}

void instructionSetForManualGuide()
{
	cout << "\nPradekite irasyti duomenis i sistema: \'manual-input\'.\n";
}

void instructionSetForDataGuide()
{
	cout << "\nPradekite skanuodami duomenis is failo: \'scan\'.\n";
}

void textAfterOpeningFile()
{
	cout << "\nPuiku! Failas atidarytas. Dabar galima dirbti su juo.";
	instructionSetForDataGuide();
}

void textAfterScaningFromFile()
{
	cout << "\nNuskaicius duomenis is failo, galima juos doroti. Skaiciuoti vidurki: \'avg\', mediana: \'med\'.";
	cout << "\nVeliau, komanda \'best-worst\' atskiria geriausius studentus nuo blogiausiu.";
	cout << "\nKomanda \'best-worst-to-file\' israso geriausius ir blogiausius i atskirus failus.";
	cout << "\nDaugiau komandu: \'commands\'\n";
}


//function prints instruction set
void commands()
{
	cout << "Programa suskaiciuoja namu darbu bei egzamino galutinius ivertinimus.\n";
	cout << "Komandu sarasas:\n";
	cout << "\t'commands' ismeta instrukciju sarasa.\n";
	cout << "\t'open' leidzia atidaryti pasirinkta faila.\n";
	cout << "\t'generate-file' leidzia sugeneruot faila su atsitiktiniais studentu duomenimis.\n";
	cout << "\t'scan' nuskaito is atidaryto failo duomenis ir ikelia i konteineri.\n";
	cout << "\t'manual-input' leidzia ranka irasyti duomenis i konteineri.\n";
	cout << "\t'avg' suskaiciuoja duomenu galutini vidurki.\n";
	cout << "\t'med' suskaiciuoja duomenu galutini mediana.\n";
	cout << "\t'best-worst' surusiuoja i atskirus konteinerius geriausius studentus nuo blogiausiu.\n";
	cout << "\t'best-worst1' atrenka blogiausius studentus ir juos sudeda i nauja konteineri, o geriausius palieka.\n";
	cout << "\t'best-worst-to-file' israso geriausius ir blogiausius studentus i atskirus failus.\n";
	cout << "\t'del-stud' sunaikina visas duomenu strukturas.\n";
	cout << "\t'results' israso rezultatus.\n";
	cout << "\t'end' baigia darba.\n";
}

//main UI
void UI_main(StudentContainer& student, StudentContainer& cool_stud, StudentContainer& lame_stud,
	ifstream& file_inp)
	//end of 'DEQUE declaration'
{
	string command_str = "-2", ifstreamName = "kursiokai.txt", ofstreamName;
	
	timer1.reset();

	while (command_str != "END" || command_str == "EXIT")
	{
		dollarSign();
		cout << "Main: ";

		timer1.pause();
		cin >> command_str;
		timer1.resume();

		std::transform(command_str.begin(), command_str.end(), command_str.begin(), ::toupper);	//transform command line to uppercase


		if (command_str == "COMMANDS")
		{
			commands();
			continue;
		}

		//user can open any file if the file exists and read from it
//begin of 'open ifstream file'
		if (command_str == "OPEN")
		{
			UI_Open(ifstreamName, file_inp);
			if (file_inp.is_open())
				textAfterOpeningFile();
			continue;
		}
		//end of 'open ifstream file'

		//if user wants to generate file with certain amount of students
		//begin of 'generate-file'
		if (command_str == "GENERATE-FILE")
		{
			UI_GenerateFile(ofstreamName);
			continue;
		}
		//end of 'generate-file'

		//if user wants to get input from file 'filename.txt', should write 'file'
		if (command_str == "SCAN")
		{
			UI_File(file_inp, student);
			textAfterScaningFromFile();
			continue;
		}


		//if user wants to write input into StudentContainer
		if (command_str == "MANUAL-INPUT")
		{
			try
			{
				Student temp;	//lets the user to write it's own input into vector 
				cin >> temp;
				student.push_back(temp);
			}
			catch (const char* msg) //if error
			{
				cout << "\n" << msg << "\n\n";	//print error message
			}
			continue;
		}


		//calculate average
		if (command_str == "AVG" || command_str == "AVERAGE")
		{
			UI_Avg(student);
			continue;
		}


		//calculate median
		if (command_str == "MED" || command_str == "MEDIAN")
		{
			UI_Med(student);
			continue;
		}

		//if 'best-worst' is selected, pick students with high marks in one array, and students with bad marks in another array
		if (command_str == "BEST-WORST" || command_str == "WORST-BEST")
		{
			UI_BestWorst(student, cool_stud, lame_stud);
			continue;
		}



		//if 'best-worst' is selected, pick students with high marks in one array, and students with bad marks in another array
		if (command_str == "BEST-WORST1" || command_str == "WORST-BEST1")
		{
			UI_BestWorst(student, cool_stud, lame_stud, 1);
			continue;
		}


		//if user wants to write best-worst students into seperate files
		if (command_str == "BEST-WORST-TO-FILE" || command_str == "WORST-BEST-TO-FILE")
		{
			UI_BestWorstToFile(student, cool_stud, lame_stud);
			continue;
		}

		//if user wants to clear memory
		if (command_str == "DEL-STUD" || command_str == "STUD-DEL")
		{
			UI_Del(student);
			UI_Del(cool_stud);
			UI_Del(lame_stud);
			continue;
		}

		if (command_str == "RESULTS" || command_str == "RESULT")
		{
			//print results
			cout << "-------------RESULTS OF student---------------\n\n";
			printOutput(student);	//print results of student
			cout << "TOTAL USEFUL TIME TAKEN: " << std::setprecision(10) << timer1.elapsed() << "s\n";
			continue;
		}


		//if user wants to end the input, write 'end' to break the loop
		if (command_str == "END" || command_str == "EXIT" || command_str == "LEAVE")
			break;

		if (command_str == "TEST")
		{
			openFile(file_inp, "million.txt");
			UI_File(file_inp, student);
			UI_Avg(student);
			UI_Med(student);
			UI_BestWorst(student, cool_stud, lame_stud);
			UI_BestWorstToFile(student, cool_stud, lame_stud);

			UI_Del(student);
			UI_Del(cool_stud);
			UI_Del(lame_stud);
			break;
		}

		else
			cout << "\nError: Unknown command.\n";
	}
	exit_test = true;
}


void UI_Open(string& ifstreamName, ifstream& file_inp)
{
	while (1)
	{
		cout << "Follow the template - filename.txt. - 'exit' to leave 'open'.\n";
		cout << "Enter full file name you want to access : ";

		dollarSign();

		timer1.pause();
		cin >> ifstreamName;	//get input stream text
		timer1.resume();

		std::transform(ifstreamName.begin(), ifstreamName.end(), ifstreamName.begin(), ::tolower);	//transform command line to lowercase

		//if user wants to leave this section
		if (ifstreamName == "exit")
		{
			//ifstreamName = "kursiokai.txt";	//set to default ifstream
			return;
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



void UI_GenerateFile(string& ofstreamName)
{
	cout << "You are able to generate files with random student information. Please note, that only '.txt' extensions are supported.\n";
	while (1)
	{
		cout << "Follow the template - filename.txt. - 'exit' to leave 'generate-file'.\n";
		cout << "Enter full file name you want to create: ";

		dollarSign();

		timer1.pause();
		cin >> ofstreamName;
		timer1.resume();

		std::transform(ofstreamName.begin(), ofstreamName.end(), ofstreamName.begin(), ::tolower);	//transform command line to lowercase

		//if user wants to leave this section
		if (ofstreamName == "exit")
		{
			ofstreamName.clear();	//empty the string
			return;
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

			dollarSign();

			timer1.pause();
			cin >> get_rand_amount;
			timer1.resume();

			bool is_number = checkIfStrIsNum(get_rand_amount);	//check if the given string is number

			//if string is only digits
			if (is_number)
			{
				try
				{
					cout << "Beginning to generate file...";
					
					//begin time
					Timer timer_temp;

					generateFile(rand_out, std::stoi(get_rand_amount));	//generate file with student objects

					//end time
					cout << "Finished! Took: " << timer_temp.elapsed() << "s\n";
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


void UI_File(ifstream& file_inp, StudentContainer& student)
{
	cout << "Beginning to read from file...";

	//begin time
	Timer timer_temp;

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
	//end time
	cout << "Finished! Took: " << timer_temp.elapsed() << "s\n";
}


void UI_Avg(StudentContainer& student)
{
	//begin of 'calculate average'
	cout << "Beginning to calculate averages...";
	//begin time
	Timer timer_temp;
	for (auto & it : student)
		it.setAverage(it.averageCalc());
	//end time
	cout << "Finished! Took: " << timer_temp.elapsed() << "s\n";
	//end of 'calculate average'
}


void UI_Med(StudentContainer& student)
{
	//begin of 'calculate median'
	cout << "Beginning to calculate medians...";
	//begin time
	Timer timer_temp;
	for (auto & it : student)
		it.setMedian(it.medianCalc());	//calculate 
	cout << "Finished! Took: " << timer_temp.elapsed() << "s\n";
	//end of 'calculate median'
}


void UI_BestWorst(StudentContainer& student, StudentContainer& cool_stud, StudentContainer& lame_stud, int version)
{
	try
	{
		cout << "Beginning to seperate best from worst...";
		//begin time
		Timer timer_temp;

		if (version == 1)
			sortBestWorst(student, cool_stud, lame_stud);	//sort best from worst
		if (version == 2)
			lame_stud = sortBestWorst2(student);

		cout << "Finished! Took: " << timer_temp.elapsed() << "s\n";
	}
	catch (const char* msg)
	{
		cout << "\n" << msg << "\n\n";	//print error message
	}
}


void UI_BestWorstToFile(StudentContainer& student, StudentContainer& cool_stud, StudentContainer& lame_stud)
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
		cout << "Enter a number x, to give number to cool_x.txt, lame_.txt. - 'exit' to leave this section 'best-worst-file'.\n";
		cout << "Enter a number: ";

		dollarSign();

		timer1.pause();
		cin >> ofstreamName_temp;	//get output stream text name
		timer1.resume();

		std::transform(ofstreamName_temp.begin(), ofstreamName_temp.end(), ofstreamName_temp.begin(), ::tolower);	//transform command line to lowercase

		//if user wants to leave this section
		if (ofstreamName_temp == "exit")
		{
			ofstreamName_temp.clear();	//empty the string
			break;
		}

		//check if input string is number
		if (checkIfStrIsNum(ofstreamName_temp))
			break;

		cout << "\nYou did not enter a number. Follow the instructions and try again.\n";	//error msg
	}
	//if given string is not empty, means its a number
	if (!ofstreamName_temp.empty())
	{
		try
		{
			cout << "Beginning to write best and worst students to files...";
			//begin time
			Timer timer_temp;

			if (cool_stud.empty())
				writeToFileBestWorst(ofstreamName_temp, student, lame_stud);
			else
				writeToFileBestWorst(ofstreamName_temp, cool_stud, lame_stud);	//output results in files

			cout << "Finished! Took: " << timer_temp.elapsed() << "s\n";
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