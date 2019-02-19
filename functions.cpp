#include "functions.h"


//function prints instruction set
void instructions()
{
	cout << "Programa suskaiciuoja namu darbu bei egzamino galutinius ivertinimus.\n";
	cout << "Komandu sarasas:\n";
	cout << "\t'file' nuskaito is 'kursiokai.txt' duomenis ir ikelia i std::vector.\n";
	cout << "\t'Cfile' nuskaito is 'kursiokai.txt' duomenis ir ikelia i C-type array.\n";
	cout << "\t'open' atidaro is naujo faila 'kursiokai.txt'.\n";
	cout << "\t'C-array' leidzia ranka irasyti duomenis i C-type array.\n";
	cout << "\t'end' israso rezultatus ir baigia darba.\n";
	cout << "\tBet koks kitas tekstas leidzia ranka irasyti duomenis i std::vector.\n\n";
}


//opens file
void openFile(ifstream& file)
{
	file.clear();
	file.seekg(0, std::ios::beg);
}



//function gets input and stores to student array
void getInput(vector<Student> &student)
{
	student.push_back(Student());	//push back structure array
	int count = student.size() - 1;	//get count of student
	cout << "STUDENT SIZE: " << student.size() << "\n";

	//get name
	cout << "Iveskite studento varda: ";
	cin >> student[count].name;

	//get surname
	cout << "Iveskite studento pavarde: ";
	cin >> student[count].surname;


	//begin of 'input homework'
	cout << "Dabar veskite namu darbu rezultatus (minimali verte 1, maksimali 10).\n";
	cout << "Atsitiktiniam namu darbu ir egzaminu rezultatu sugeneravimui, rasykite \"rand\".\n";
	cout << "Kai baigsite, iveskite \"egz\": ";
	string temp_input;
	while (temp_input != "egz")
	{
		cin >> temp_input;

		//break if input is 'egz'
		if (temp_input == "egz")
			break;

		//begin of 'randomize homework results'
		if (temp_input == "rand")
		{
			int max_rand = 20;	//20 is maximum amount of homework currently
			//begin of 'rand error message'
			if (max_rand - student[count].hw.size() < 1)
			{
				cout << "Negeneruojama, kai yra virs " << max_rand << " namu darbu.";
				continue;
			}
			//end of 'rand error message'

			int rand_hw_num = rand() % (max_rand - student[count].hw.size());	//get random homework amount

			for (int i = 0; i < rand_hw_num; i++)
				student[count].hw.push_back(1 + rand() % 10);	//randomize between 1 and 10
			student[count].egz = 1 + rand() % 10;	//randomize exam

			return;
		}
		//end of 'randomize homework results'

		//get mark input
		if (temp_input == "1" || temp_input == "2" || temp_input == "3" || temp_input == "4" || temp_input == "5" || temp_input == "6"
			|| temp_input == "7" || temp_input == "8" || temp_input == "9" || temp_input == "10")//if the input is between 1 and 10 inclusive
			student[count].hw.push_back(std::stoi(temp_input));	//add to hw array
		//if invalid character is inputed throw error message
		else
		{
			student.pop_back();	//delete the invalid object
			throw "Invalid character(s). Expected numbers between 1 and 10.";
		}
	}
	//end of 'input homework'

	//begin of 'input of exam'
	cout << "Iveskite egzamino rezultata (nuo 1 iki 10): ";
	while (1)
	{
		cin >> temp_input;
		if (temp_input == "1" || temp_input == "2" || temp_input == "3" || temp_input == "4" || temp_input == "5" || temp_input == "6"
			|| temp_input == "7" || temp_input == "8" || temp_input == "9" || temp_input == "10")//if the input is between 1 and 10 inclusive
			break;
		cout << "Klaida. Neteisingas egzamino rezultato formatas. Iveskite egzamino rezultata (nuo 1 iki 10): ";
	}

	if (temp_input != "10")
		student[count].egz = std::stoi(temp_input);
	else
		student[count].egz = 10;
	//end of 'input of exam'
}


//function reads from 'kursiokai.txt'
void readFromKursiokai(ifstream& kursiokai, vector<Student> &student)
{


	/*----------------STRUCTURE OF kursiokai.txt------------------------
	Pavarde     Vardas      ND1  ND2   ND3  ND4  ND5 ...  Egzaminas
	Vardas1     Pavarde1    8    9     10   6    10  ...  9
	Vardas2     Pavarde2    7    10    8    5    4   ...  6
	*/

	//begin of 'if file open'
	if (kursiokai.is_open())
	{
		string file_str;	//temporary string holding file's lines
		//std::getline(kursiokai, file_str);
		//cout << file_str << "\n";
		//begin of 'read from kursiokai'
		while (std::getline(kursiokai, file_str))	//getlines until eof
		{
			student.push_back(Student());	//push back
			int student_count = student.size() - 1;	//counter to track indexes

			//begin of 'character scan from file_str'
			//begin of 'get name'
			int file_str_index = 0;	//index of file_str to point to characters
			while (file_str[file_str_index] != ' ')	//search for whitespace
			{
				file_str_index++;	//increment by one
				if (file_str_index >= file_str.length())	//check if array access violations are not broken
					break;
			}


			student[student_count].name.append(file_str, 0, file_str_index);	//append name to structure
			file_str.erase(0, file_str_index + 1);	//delete name from temporary file_str string
			//end of 'get name'

			//begin of 'get surname'
			file_str_index = 0;	//index of file_str to point to characters
			while (file_str[file_str_index] != ' ')	//search for whitespace
			{
				file_str_index++;	//increment by one
				if (file_str_index >= file_str.length())	//check if array access violations are not broken
					break;
			}

			student[student_count].surname.append(file_str, 0, file_str_index);	//append surname to structure
			file_str.erase(0, file_str_index + 1);	//delete name from temporary file_str string
			//end of 'get surname'


			//begin of 'get exam'
			while (file_str.length() > 0)
			{
				//begin of 'delete whitespaces at the end'
				while (file_str[file_str.length() - 1] == ' ')
					file_str.erase(file_str.length() - 1, 1);
				//end of 'delete whitespaces at the end'

				//begin of 'search for valid number'
				int temp_index = 1, temp_length = file_str.length() - 1 - temp_index;
				if (temp_length >= 0)	//temp_length should be atleast 0, in order to avoid accessing incorrect memory
					while (file_str[file_str.length() - 1 - temp_index] != ' ' && file_str[file_str.length() - 1 - temp_index] != '1')	//add count to temp_index if wrong characters found
						temp_index++;
				//if any bad characters found, then erase them
				if (temp_index > 1)
					file_str.erase(file_str.length() - temp_index + 1, temp_index);	//erase bad characters
				//end of 'search for valid number'

				//begin of 'check if is digit'
				if (isdigit(file_str[file_str.length() - 1]))	//if last character is digit
				{
					//begin of 'if 0 found'
					if (file_str[file_str.length() - 1] == '0')	//if found 0
					{
						if (file_str[file_str.length() - 2] == '1')	//if found 1 before 0
						{
							student[student_count].egz = 10;	//set .egz to 10
							file_str.erase(file_str.length() - 3, 3);	//erase whitespace and two last characters
							break;
						}
						file_str.erase(file_str.length() - 1, 1);
						continue;
					}
					//end of 'if 0 found'

					//begin of 'if other digit found'
					if (file_str[file_str.length() - 1] != '0')	//if found any other digit
					{
						student[student_count].egz = file_str[file_str.length() - 1] - '0';	//set .egz to that digit

						if (file_str.length() == 1)	//if last character left
							file_str.clear();	//erase last character
							
						else if (file_str.length() - 2 > 0)
							file_str.erase(file_str.length() - 2, 2);	//erase whitespace and last character

						break;
					}
					//end of 'if other digit found'
				}
				//end of 'check if is digit'

				//if not a digit found, just erase the symbol
				else
					file_str.erase(file_str.length() - 1, 1);
			}
			//end of 'get exam'

			//begin of 'get homework'
			file_str_index = 0;	//reset index
			while (file_str.length() > 0)	//search for homework results between whitespaces
			{
				//begin of 'if digit found'
				if (isdigit(file_str[file_str_index]))	//if found digit
				{
					//begin of 'any digit but 1'
					if (file_str[file_str_index] != '1' && file_str[file_str_index] != '0')	//if found any digit but '1'
					{
						if (file_str[file_str_index + 1] == ' ' || file_str[file_str_index + 1] == '.' || file_str.length() == 1)	//if the digit is followed by whitespace or found last character
							student[student_count].hw.push_back(file_str[file_str_index] - '0');	//push back into student homework the mark
						//else means there's junk we should erase
						else
							while (file_str[file_str_index] != ' ' && file_str.length() > 0)
								file_str.erase(file_str_index, 1);
					}
					//end of 'any digit but 1'

					//begin of 'found 1'
					if (file_str[file_str_index] == '1')	//if found '1'
					{
						if (file_str[file_str_index + 1] == ' ')	//if 1 is followed by whitespace
							student[student_count].hw.push_back(1);	//push back 1
						else if (file_str[file_str_index + 1] == '0')	//if 1 is followed by 0
						{
							if (file_str[file_str_index + 2] == ' ' || file_str.length() == 2)	//if 10 is followed by whitespace or found last 2 characters
								student[student_count].hw.push_back(10);	//push back 10
						}
						//else means there's junk we should erase
						else
							while (file_str[file_str_index] != ' ' && file_str.length() > 0)
								file_str.erase(file_str_index, 1);
					}
					//end of 'found 1'
				}
				//end of 'if digit found'

				//begin of 'last characters of homework found'
				if (file_str.length() == 1 && file_str_index == 1)	//if reached last character and already manipulated 
					break;	//then break

				//if found 10
				if (file_str.length() == 2 && file_str_index == 2)	//if 2 characters are last
					if (file_str[0] == '1' && file_str[1] == '0')	//if those are 1 and 0
						break;	//then break
				//end of 'last characters of homework found'

				//if the whitespace is found, delete from string beginning up to whitespace inclusive
				if (file_str[file_str_index] == ' ')	//if found whitespace
				{
					file_str.erase(0, file_str_index + 1);	//delete the pushed back homework from temporary string
					file_str_index = 0;	//reset index
					continue;	//go next
				}

				//if found dot
				if (file_str[file_str_index] == '.')
				{
					file_str_index = 0;
					while (file_str[file_str_index] != ' ' && file_str.length() > 0)
						file_str.erase(file_str_index, 1);
					file_str_index = 0;
					continue;
				}
					


				file_str_index++;	//increment by 1
			}
			//end of 'get homework'
			//end of 'character scan from file_str'
		}
		//end of 'read from kursiokai'
	}
	//end of 'if file open'
	//begin of 'if file is not open'
	else
		cout << "Klaida: neimanoma atidaryti failo.\n";
	//end of 'if file is not open'

}


//function returns the avarage value of the vector array
double avgCalc(const vector<int> hw, const int egz)
{
	//calculate the sum of array and return the average
	int sum = 0;
	for (int i = 0; i < hw.size(); i++)
		sum += hw[i];

	if (hw.size() != 0)	//skip division by 0
	{
		double avg = 0.4*(double)((double)sum / (double)hw.size()) + 0.6*egz;
		if (avg < 0 || avg > 10)
			return 0;
		return avg;
	}
	if (hw.size() == 0 && egz >= 1 && egz <= 10)	//if no homeworks are done, but atleast exam is passed
		return 0.6*egz;
	return 0;
}


//function returns the median value of the vector array
double medCalc(vector<int> hw, const int egz)
{
	//we need to sort the array in ascending order
	std::sort(hw.begin(), hw.end());

	//if odd
	if (hw.size() % 2 == 1)
	{
		double med = 0.4*(double)hw[hw.size() / 2] + 0.6*egz;
		if (med < 0 || med > 10)
			return 0;
		return med;
	}

	//if even
	if (hw.size() % 2 == 0)
	{
		if (hw.size() != 0)	//skip division by 0
		{
			double med = 0.4*((1.0*hw[hw.size() / 2 - 1] + 1.0*hw[hw.size() / 2]) / 2) + 0.6*egz;
			if (med < 0 || med > 10)
				return 0;
			return med;
		}
		if (hw.size() == 0 && egz >= 1 && egz <= 10)	//if no homeworks are done, but atleast exam is passed
			return 0.6*egz;
		return 0;
	}


	return 0;
}


//function used in sorting function to compare string characters
bool compareNames(Student &a, Student &b)
{
	//compare by name
	if (a.name.size() < b.name.size())
		for (int i = 0; i < a.name.size(); i++)
			if (a.name[i] != b.name[i])
				return b.name[i] > a.name[i];

	//else
	return b.name[0] > a.name[0];
}

//returns required setw amount for names
int longestName(vector<Student> student)
{
	int longest = 0;
	for (int i = 0; i < student.size(); i++)
		if (student[i].name.length() > longest)
			longest = student[i].name.length();
	return longest;
}


//returns required setw amount for surnames
int longestSurname(vector<Student> student)
{
	int longest = 0;
	for (int i = 0; i < student.size(); i++)
		if (student[i].surname.length() > longest)
			longest = student[i].surname.length();
	return longest;
}


//function prints output of stucture student
void printOutput(vector<Student> student)
{
	std::sort(student.begin(), student.end(), compareNames);	//sort structures

	//get lengths of the longest setw required
	int setw_name_lenght = longestName(student) + 2;	//for names
	int setw_surname_lenght = longestSurname(student) + 2;	//for surnames

	//outputing results
	cout << "\n\n";
	cout << std::setw(setw_surname_lenght) << std::left << "Pavarde";
	cout << " " << std::setw(setw_name_lenght) << std::left << "Vardas";
	cout << " " << std::setw(10) << std::left << "VidGalut";
	cout << " " << std::setw(10) << std::left << "MedGalut\n";
	for (int i = 0; i < setw_name_lenght + setw_surname_lenght + 10 + 10; i++)
		cout << '-';
	cout << "\n";
	for (int i = 0; i < student.size(); i++)
	{
		cout << std::setw(setw_surname_lenght) << std::left << student[i].surname;
		cout << " " << std::setw(setw_name_lenght) << std::left << student[i].name;
		cout << " " << std::setw(10) << std::left << std::fixed << std::setprecision(2) << student[i].avg_final;
		cout << " " << std::setw(10) << std::left << std::fixed << std::setprecision(2) << student[i].med_final << "\n";
	}
	cout << "\nJei rezultatai lygus 0, vadinasi ivestis yra bloga.\n";
}


