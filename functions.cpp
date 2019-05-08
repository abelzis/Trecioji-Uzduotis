#include "functions.h"



//opens ifstream file specified with name
void openFile(ifstream& file, const string name)
{
	file.close();
	file.open(name, std::fstream::in);	//else open in input mode
	if (!file.is_open())
		throw "Error: can't open file";

	if (file.is_open())
	{
		file.clear();
		file.seekg(0, std::ios::beg);
	}
}

//opens file
void openFile(ifstream& file)
{
	file.clear();
	file.seekg(0, std::ios::beg);
}


//function generates a file for future inputs
void generateFile(ofstream& file, const int count)
{
	RandomEngine engine;
	std::uniform_int_distribution<int> dist1 = engine.uni_int_distr(1, 10);
	std::uniform_int_distribution<int> dist2 = engine.uni_int_distr(0, 50);

	if (file.is_open())
	{
		for (int i = 0; i < count; i++)
		{
			file << "Vardas" << i << " Pavarde" << i;
			int randomness = dist2(engine.mt);
			for (int j = 0; j < randomness; j++)
				file << " " << dist1(engine.mt);
			file << "\n";
		}
		cout << "Failas sekmingai sugeneruotas su " << count << " objektu.\n\n";
		file.close();
	}
	else
		throw "Error: Can't read file.";
}



//function checks if the given string is a number
bool checkIfStrIsNum(const string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}


//function returns a substring of single word
int getUntilWhitespace(const string str)
{
	int index = 0;	//index of file_str to point to characters
	while (str[index] != ' ')	//search for whitespace
	{
		index++;	//increment by one
		if (index >= str.length())	//check if array access violations are not broken
			break;
	}
	return index;
}


int getExam(string& str)
{
	while (str.length() > 0)
	{
		//begin of 'delete whitespaces at the end'
		while (str[str.length() - 1] == ' ')
			str.erase(str.length() - 1, 1);
		//end of 'delete whitespaces at the end'

		//begin of 'search for valid number'
		//the idea is to search for digits and try to identify them. Any other symbols - we don't care and we delete them
		int temp_index = 1, temp_length = str.length() - 1 - temp_index;
		if (temp_length >= 0)	//temp_length should be atleast 0, in order to avoid accessing incorrect memory
			while (str[str.length() - 1 - temp_index] != ' ' && str[str.length() - 1 - temp_index] != '1')	//add count to temp_index if wrong characters found
				temp_index++;
		//if any bad characters found, then erase them
		if (temp_index > 1)
			str.erase(str.length() - temp_index + 1, temp_index);	//erase bad characters
		//end of 'search for valid number'

		//begin of 'check if is digit'
		if (isdigit(str[str.length() - 1]))	//if last character is digit
		{
			//begin of 'if 0 found'
			if (str[str.length() - 1] == '0')	//if found 0
			{
				if (str[str.length() - 2] == '1')	//if found 1 before 0
				{
					if (str.length() > 3)
						str.erase(str.length() - 3, 3);	//erase whitespace and two last characters
					else
						str.clear();
					return 10;	//return 10 mark
				}
				str.erase(str.length() - 1, 1);
				continue;
			}
			//end of 'if 0 found'

			//begin of 'if other digit found'
			if (str[str.length() - 1] != '0')	//if found any other digit
			{
				int mark = str[str.length() - 1] - '0';	//specific digit as mark

				if (str.length() == 1)	//if last character left
					str.clear();	//erase last character

				else if (str.length() - 2 > 0)
					str.erase(str.length() - 2, 2);	//erase whitespace and last character

				return mark;	//return mark
			}
			//end of 'if other digit found'
		}
		//end of 'check if is digit'

		//if not a digit found, just erase the symbol
		else
			str.erase(str.length() - 1, 1);
	}
	return 0;
}


//function reads from 'filename.txt'
void readFromFile(ifstream& file, StudentContainer &student)
{


	/*----------------STRUCTURE OF filename.txt------------------------
	Pavarde     Vardas      ND1  ND2   ND3  ND4  ND5 ...  Egzaminas
	Vardas1     Pavarde1    8    9     10   6    10  ...  9
	Vardas2     Pavarde2    7    10    8    5    4   ...  6
	*/

	//begin of 'if file open'
	if (file.is_open())
	{
		string file_str;	//temporary string holding file's lines

		//begin of 'read from kursiokai'
		while (std::getline(file, file_str))	//getlines until eof
		{
			//removes unwanted symbols from the beginning
			while (file_str[0] < 0 || file_str[0] > 255)
				file_str.erase(0, 0 + 1);

			Student temp_stud;

			//begin of 'character scan from file_str'
			//begin of 'get name'
			int str_index = getUntilWhitespace(file_str);	//returns (name) character count of a single word substring
			string temp_name;
			temp_name.append(file_str, 0, str_index);
			temp_stud.setName(temp_name);
			file_str.erase(0, str_index + 1);	//delete name from temporary file_str string
			//end of 'get name'

			//begin of 'get surname'
			str_index = getUntilWhitespace(file_str);	//returns (surname) character count of a single word substring
			temp_name.clear();
			temp_name.append(file_str, 0, str_index);
			temp_stud.setSurname(temp_name);
			file_str.erase(0, str_index + 1);	//delete name from temporary file_str string
			//end of 'get surname'

			//get value of the exam
			temp_stud.setExam(getExam(file_str));

			//begin of 'get homework'
			str_index = 0;	//reset index
			intContainer hw;	//create temporary homework array
			while (file_str.length() > 0)	//search for homework results between whitespaces
			{
				//removes unwanted symbols from the beginning
				while (file_str[str_index] < 0 || file_str[str_index] > 255)
					file_str.erase(str_index, str_index + 1);

				if (file_str[str_index] >= 0 && file_str[str_index] <= 255)
				{
					//begin of 'if digit found'
					if (isdigit(file_str[str_index]))	//if found digit
					{
						//begin of 'any digit but 1'
						if (file_str[str_index] != '1' && file_str[str_index] != '0')	//if found any digit but '1'
						{
							if (file_str[str_index + 1] == ' ' || file_str[str_index + 1] == '.' || file_str.length() == 1)	//if the digit is followed by whitespace or found last character
								hw.push_back(file_str[str_index] - '0');	//push back into student homework the mark
							//else means there's junk we should erase
							else
								while (file_str[str_index] != ' ' && file_str.length() > 0)
									file_str.erase(str_index, 1);
						}
						//end of 'any digit but 1'

						//begin of 'found 1'
						if (file_str[str_index] == '1')	//if found '1'
						{
							if (file_str[str_index + 1] == ' ')	//if 1 is followed by whitespace
								hw.push_back(1);	//push back 1
							else if (file_str[str_index + 1] == '0')	//if 1 is followed by 0
							{
								if (file_str[str_index + 2] == ' ' || file_str.length() == 2)	//if 10 is followed by whitespace or found last 2 characters
									hw.push_back(10);	//push back 10
							}
							//else means there's junk we should erase
							else
								while (file_str[str_index] != ' ' && file_str.length() > 0)
									file_str.erase(str_index, 1);
						}
						//end of 'found 1'
					}
					//end of 'if digit found'

					//begin of 'last characters of homework found'
					if (file_str.length() == 1 && str_index == 1)	//if reached last character and already manipulated 
						break;	//then break

					//if found 10
					if (file_str.length() == 2 && str_index == 2)	//if 2 characters are last
						if (file_str[0] == '1' && file_str[1] == '0')	//if those are 1 and 0
							break;	//then break
					//end of 'last characters of homework found'

					//if the whitespace is found, delete from string beginning up to whitespace inclusive
					if (file_str[str_index] == ' ')	//if found whitespace
					{
						file_str.erase(0, str_index + 1);	//delete the pushed back homework from temporary string
						str_index = 0;	//reset index
						continue;	//go next
					}

					//if found dot
					if (file_str[str_index] == '.')
					{
						str_index = 0;
						while (file_str[str_index] != ' ' && file_str.length() > 0)
							file_str.erase(str_index, 1);
						str_index = 0;
						continue;
					}

					str_index++;	//increment by 1
				}
			}
			//end of 'get homework'
			//end of 'character scan from file_str'

#ifndef LIST
			hw.shrink_to_fit();
#endif

			temp_stud.setHomework(hw);
			hw.clear();

			student.push_back(Student(temp_stud));	//push back
		}
		//end of 'read from kursiokai'
	}
	//end of 'if file open'
	//begin of 'if file is not open'
	else
		throw "Klaida: neimanoma atidaryti failo arba failas neatidarytas.\n";
	//end of 'if file is not open'

}




//function picks students with higher or equal average final mark than 5 and puts them into 'cool' vector, otherwise in the 'loser' vector
void sortBestWorst(StudentContainer& student, StudentContainer& cool, StudentContainer& lame)
{
	if (student.size() == 0)
		throw "Error: main vector size is 0.";

	//reserve capacity trying to avoid size reallocation for vector type
#ifdef VECTOR
	cool.reserve(student.capacity());
	lame.reserve(student.capacity());
#endif
	//invariant: fill cool student container with high mark students, lame student container with low mark students
	for (auto & it : student)
	{
		//define final mark using criteria
#ifdef AVERAGE
		it.setFinalMark(it.average());	//set final mark to be average
#endif

#ifdef MEDIAN
		it.setFinalMark(it.median());	//set final mark to be average
#endif

		if (it.finalMark() >= 5 && it.finalMark() <= 10)	//if avg is not lower than 5, the student is considered cool
		{
			cool.push_back(it.copy(it));
			continue;
		}
	}
	//shrink to fit (save memory)
#ifndef LIST
	cool.shrink_to_fit();
	lame.shrink_to_fit();
#endif
}

//predicate returns true if student pass
bool passedClass(const Student& student)
{
	if (student.finalMark() >= 5)
		return true;
	return false;
}

//predicate returns true if student fails
bool failedClass(const Student& student)
{
	return !passedClass(student);
}

//predicate returns true if student is invalid
bool invalidStudent(const Student& student)
{
	if (student.finalMark() == 0)
		return true;
	return false;
}


Student assignTemporaryValues(const StudentContainer::iterator& it)
{
	Student temp;	//temporary object

#ifndef MYVECTOR
	temp.copy(*it);
#endif
#ifdef MYVECTOR
	temp.copy(it.value());
#endif

	return temp;
}

//function picks students with lower average final mark than 5 and puts them into 'lame' vector, otherwise leave them
StudentContainer sortBestWorst2(StudentContainer& student)
{
	if (student.size() == 0)
		throw "Error: main container size is 0.";


#ifndef LIST
	//use stable partition to sort students who pass at the begin of the list
	StudentContainer::iterator it = std::stable_partition(student.begin(), student.end(), passedClass);

	StudentContainer lame1( it, student.end() );
	student.erase(it, student.end()); 
	student.shrink_to_fit();

	it = std::stable_partition(lame1.begin(), lame1.end(), invalidStudent);

	StudentContainer lame( it, lame1.end() );
	lame1.clear();
#endif

#ifdef LIST
	StudentContainer lame;
	//auto it = student.begin();
	StudentContainer::iterator it = student.begin();
	//for (auto & it : student)
	for (it; it != student.end(); ++it)
	{
		if (it->finalMark() >= 0 && it->finalMark() < 5)	//if avg is lower than 5, the student is considered loser
		{
			if (it->finalMark() != 0)
				lame.push_back(assignTemporaryValues(it));	//pushback copy of iterator's values

			it = student.erase(it);
			it--;
		}
	}
#endif

	return lame;
}

void writeToFile(ofstream& file, const StudentContainer& st)
{
	for (auto const& it : st)
	{
		file << it.name() << " " << it.surname() << " " << std::fixed << std::setprecision(2) << it.finalMark() << "\n";	//output data of cool students
	}
}

//function write best students to one file, and lame students to another file
void writeToFileBestWorst(const string ofstreamName_temp, const StudentContainer& cool, const StudentContainer& lame)
{
	//create file of cool
	string file_name = "cool_" + ofstreamName_temp + ".txt";
	ofstream file_cool(file_name);	//create output file

	//write data to file
	if (file_cool.is_open())	//if file_cool is open
		writeToFile(file_cool, cool);	//write out the container to file
	//else error
	else
	{
		file_cool.clear();	//clear
		file_cool.close();	//close
		throw "Error: can't create new file cool_x.txt.";
	}
	file_cool.close();	//close file

	//create file of lame
	file_name = "lame_" + ofstreamName_temp + ".txt";
	ofstream file_lame(file_name);	//create output file

	//write data to file
	if (file_lame.is_open())	//if file_lame is open
		writeToFile(file_lame, lame);	//write out the container to file
	//else error
	else
	{
		file_lame.clear();	//clear
		file_lame.close();	//close
		throw "Error: can't create new file lame_x.txt.";
	}
	file_lame.close();
}


//delete student object vector
void deleteStudentContainer(StudentContainer& v)
{
	//delete homework vectors
	for (auto& elem : v)
		elem.clear();

	//delete student object vector
	v.clear();
#ifndef LIST
	v.shrink_to_fit();
#endif
	if (!v.empty())
		throw "Error: student array could not have been deleted.";
}


//function used in sorting function to compare string characters
bool compareNames(Student &a, Student &b)
{
	//compare by name
	if (a.name().size() < b.name().size())
		for (int i = 0; i < a.name().size(); i++)
			if (a.name()[i] != b.name()[i])
				return b.name()[i] > a.name()[i];

	//else
	return b.name()[0] > a.name()[0];
}

//returns required setw amount for names
int longestName(const StudentContainer& student)
{
	int longest = 0;
	for (auto const& it : student)
		if (it.name().length() > longest)
			longest = it.name().length();
	return longest;
}


//returns required setw amount for surnames
int longestSurname(const StudentContainer& student)
{
	int longest = 0;
	for (auto const& it : student)
		if (it.surname().length() > longest)
			longest = it.surname().length();
	return longest;
}


//function prints output of stucture student
void printOutput(StudentContainer& student)
{


#ifndef LIST
	std::sort(student.begin(), student.end(), compareNames);	//sort structures
#endif

#ifdef LIST
	student.sort(compareNames);
#endif

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
	//print the results of all students
	for (auto const& it : student)
	{
		cout << std::setw(setw_surname_lenght) << std::left << it.surname();
		cout << " " << std::setw(setw_name_lenght) << std::left << it.name();
		cout << " " << std::setw(10) << std::left << std::fixed << std::setprecision(2) << it.average();
		cout << " " << std::setw(10) << std::left << std::fixed << std::setprecision(2) << it.median() << "\n";
	}
	cout << "\nJei rezultatai lygus 0, vadinasi ivestis yra bloga.\n";
}