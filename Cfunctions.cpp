#include "functions.h"
#include "Cfunctions.h"



//REDUNDANT FUNCTION FOR C-TYPE ARRAY



//function multiplies the homework size by 2 by creating new homework C-array
void MultiplyHwSize(CStudent *Cstudent, int const hw_count, int Cstudent_index)
{
	int *temp = new int[Cstudent[Cstudent_index].hw_size];	//create temporary array

	for (int i = 0; i < hw_count; i++)
		temp[i] = Cstudent[Cstudent_index].hw[i];	//copy each element to temporary array

	Cstudent[Cstudent_index].hw_size *= 2;	//multiply size by two
	delete[] Cstudent[Cstudent_index].hw;	//release the array
	Cstudent[Cstudent_index].hw = new int[Cstudent[Cstudent_index].hw_size];	//create new array in Cstudent

	for (int i = 0; i < hw_count; i++)
		Cstudent[Cstudent_index].hw[i] = temp[i];	//copy back each element to new array from temporary

	delete[] temp;	//delete temporary array
}


//function multiplies the Cstudent array size by 2 by creating new Cstudent C-array
void MultiplyCstudentSize(CStudent *&Cstudent, int Cstudent_index, int &Cstudent_size)
{
	Cstudent_index++;	//increment by to get current size of array instead of index

	CStudent *temp = new CStudent[Cstudent_index];	//create temporary array

	for (int i = 0; i < Cstudent_index; i++)
		temp[i] = Cstudent[i];	//copy each element to temporary array

	Cstudent_size *= 2;	//multiply size by two
	delete[] Cstudent;	//release the array	
	CStudent *newCstudent = new CStudent[Cstudent_size];	//create new Cstudent array

	for (int i = 0; i < Cstudent_index; i++)
		newCstudent[i] = temp[i];	//copy back each element to new array from temporary

	Cstudent = newCstudent;	//point Cstudent to new Cstudent array

	delete[] temp;	//delete temporary array
}


//function gets input and stores to student array
void TypeGetInput(CStudent *Cstudent, int const Cstudent_index)
{
	cout << "CSTUDENT SIZE: " << Cstudent_index + 1 << "\n";
	//get name
	cout << "Iveskite studento varda: ";
	cin >> Cstudent[Cstudent_index].name;

	//get surname
	cout << "Iveskite studento pavarde: ";
	cin >> Cstudent[Cstudent_index].surname;


	//begin of 'input homework'
	cout << "Dabar veskite namu darbu rezultatus (minimali verte 1, maksimali 10).\n";
	cout << "Atsitiktiniam namu darbu ir egzaminu rezultatu sugeneravimui, rasykite \"rand\".\n";
	cout << "Kai baigsite, iveskite \"egz\": ";
	string temp_input;
	int hw_count = 0;
	while (temp_input != "egz")
	{
		cin >> temp_input;
		//begin of 'randomize homework results'
		if (temp_input == "rand")
		{
			int max_rand = 20;	//20 is maximum amount of homework currently
			//begin of 'rand error message'
			if (max_rand - hw_count < 1)
			{
				cout << "Negeneruojama, kai yra virs " << max_rand << " namu darbu.";
				continue;
			}
			//end of 'rand error message'

			int rand_hw_num = rand() % (max_rand - hw_count);	//get random homework amount

			for (int i = 0; i < rand_hw_num; i++)
			{
				//if homework count exceed the homework size, multiply array size by two
				if (hw_count + 1 >= Cstudent->hw_size)
					MultiplyHwSize(Cstudent, hw_count, Cstudent_index);

				//if homework count does not exceed the size of the homework array, add mark
				if (hw_count + 1 < Cstudent->hw_size)
				{
					Cstudent[Cstudent_index].hw[i] = 1 + rand() % 10;	//randomize between 1 and 10
					hw_count++;	//increment homework count
				}
			}

			Cstudent[Cstudent_index].egz = 1 + rand() % 10;	//randomize exam
			Cstudent[Cstudent_index].hw_count += hw_count;	//add the homework count
			return;
		}
		//end of 'randomize homework results'

		//get mark input
		if (temp_input == "1" || temp_input == "2" || temp_input == "3" || temp_input == "4" || temp_input == "5" || temp_input == "6"
			|| temp_input == "7" || temp_input == "8" || temp_input == "9" || temp_input == "10")//if the input is between 1 and 10 inclusive
		{
			//if homework count exceed the size of the array, increase the array by 2
			if (hw_count + 1 >= Cstudent->hw_size)
				MultiplyHwSize(Cstudent, hw_count, Cstudent_index);

			Cstudent[Cstudent_index].hw[hw_count] = std::stoi(temp_input);	//add mark to hw array
			hw_count++;	//increment homework count
		}
	}
	//end of 'input homework'

	//begin of 'input of exam'
	cout << "Iveskite egzamino rezultata (nuo 1 iki 10): ";
	cin >> Cstudent[Cstudent_index].egz;
	while (Cstudent[Cstudent_index].egz < 1 || Cstudent[Cstudent_index].egz > 10)
		cin >> Cstudent[Cstudent_index].egz;
	//end of 'input of exam'

	Cstudent[Cstudent_index].hw_count += hw_count;	//add the homework count
}



//function reads from 'kursiokai.txt'
void readFromKursiokai(ifstream& kursiokai, CStudent *&Cstudent, int &Cstudent_index, int &Cstudent_size)
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
			Cstudent_index++;	//increment Cstudent index

			//if no more space in the C-type array, then recreate the array with double the capacity
			if (Cstudent_index + 2 >= Cstudent_size)
				MultiplyCstudentSize(Cstudent, Cstudent_index, Cstudent_size);


			//begin of 'character scan from file_str'
			//begin of 'get name'
			int file_str_index = 0;	//index of file_str to point to characters
			while (file_str[file_str_index] != ' ')	//search for whitespace
				file_str_index++;	//increment by one

			Cstudent[Cstudent_index].name.append(file_str, 0, file_str_index);	//append name to structure
			file_str.erase(0, file_str_index + 1);	//delete name from temporary file_str string
			//end of 'get name'

			//begin of 'get surname'
			file_str_index = 0;	//index of file_str to point to characters
			while (file_str[file_str_index] != ' ')	//search for whitespace
				file_str_index++;

			Cstudent[Cstudent_index].surname.append(file_str, 0, file_str_index);	//append surname to structure
			file_str.erase(0, file_str_index + 1);	//delete name from temporary file_str string
			//end of 'get surname'

			//begin of 'get exam'
			if (isdigit(file_str[file_str.length() - 1]))	//if last character is digit
			{
				if (file_str[file_str.length() - 1] == '0')	//if found 0
				{
					if (file_str[file_str.length() - 2 == '1'])	//if found 1 before 0
					{
						Cstudent[Cstudent_index].egz = 10;	//set .egz to 10
						file_str.erase(file_str.length() - 3, 3);	//erase whitespace and two last characters
					}

				}
				if (file_str[file_str.length() - 1] != '0')	//if found any other digit
				{
					Cstudent[Cstudent_index].egz = file_str[file_str.length() - 1] - '0';	//set .egz to that digit
					file_str.erase(file_str.length() - 2, 2);	//erase whitespace and last character
				}

			}
			//end of 'get exam'

			//begin of 'get homework'
			file_str_index = 0;	//reset index
			int hw_count = 0;
			while (file_str.length() > 0)	//search for homework results between namespaces
			{
				//begin of 'if digit found'
				if (isdigit(file_str[file_str_index]))	//if found digit
				{
					//begin of 'any digit but 1'
					if (file_str[file_str_index] != '1' && file_str[file_str_index] != '0')	//if found any digit but '1'
					{
						if (file_str[file_str_index + 1] == ' ' || file_str.length() == 1)	//if the digit is followed by whitespace or found last character
						{
							//if homework count exceed the homework size, multiply array size by two
							if (hw_count + 1 >= Cstudent->hw_size)
								MultiplyHwSize(Cstudent, hw_count, Cstudent_index);

							Cstudent[Cstudent_index].hw[hw_count] = file_str[file_str_index] - '0';	//insert mark into student homework
							hw_count++;	//increment howework count
						}

						//if (file_str.length() == 1)
						//	student[student_count].hw.push_back(file_str[file_str_index] - '0');
					}

					//end of 'any digit but 1'

					//begin of 'found 1'
					if (file_str[file_str_index] == '1')	//if found '1'
					{
						if (file_str[file_str_index + 1] == ' ')	//if 1 is followed by whitespace
						{
							//if homework count exceed the homework size, multiply array size by two
							if (hw_count + 1 >= Cstudent->hw_size)
								MultiplyHwSize(Cstudent, hw_count, Cstudent_index);

							Cstudent[Cstudent_index].hw[hw_count] = 1;	//insert mark into student homework
							hw_count++;	//increment howework count
						}

						if (file_str[file_str_index + 1] == '0')	//if 1 is followed by 0
							if (file_str[file_str_index + 2] == ' ' || file_str.length() == 2)	//if 10 is followed by whitespace or found last 2 characters
							{
								//if homework count exceed the homework size, multiply array size by two
								if (hw_count + 1 >= Cstudent->hw_size)
									MultiplyHwSize(Cstudent, hw_count, Cstudent_index);

								Cstudent[Cstudent_index].hw[hw_count] = 10;	//insert mark into student homework
								hw_count++;	//increment howework count
							}
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


				file_str_index++;	//increment by 1
			}
			//end of 'get homework'
			//end of 'character scan from file_str'
			Cstudent[Cstudent_index].hw_count = hw_count;	//add the homework count
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
double avgCalc(const int const *hw, const int hw_count, const int egz)
{
	//calculate the sum of array and return the average
	int sum = 0;
	for (int i = 0; i < hw_count; i++)
		sum += hw[i];

	if (hw_count != 0)	//skip division by 0
		return 0.4*(double)((double)sum / (double)hw_count) + 0.6*egz;
	return 0;
}


//function returns the median value of the vector array
double medCalc(int *hw, const int hw_count, const int egz)
{
	//we need to sort the array in ascending order
	std::sort(hw, hw + hw_count);

	//if odd
	if (hw_count % 2 == 1)
		return 0.4*(double)hw[hw_count / 2] + 0.6*egz;
	//if even
	if (hw_count % 2 == 0)
	{
		if (hw_count != 0)	//skip division by 0
			return 0.4*(double)((hw[hw_count / 2 - 1] + hw[hw_count / 2]) / 2) + 0.6*egz;
		return 0;
	}
}


//function used in sorting function to compare string characters
bool CcompareNames(CStudent &a, CStudent &b)
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
int longestName(const CStudent *Cstudent, int Cstudent_index)
{
	Cstudent_index++;
	int longest = 0;
	for (int i = 0; i < Cstudent_index; i++)
		if (Cstudent[i].name.length() > longest)
			longest = Cstudent[i].name.length();
	return longest;
}


//returns required setw amount for surnames
int longestSurname(const CStudent *Cstudent, int Cstudent_index)
{
	Cstudent_index++;
	int longest = 0;
	for (int i = 0; i < Cstudent_index; i++)
		if (Cstudent[i].surname.length() > longest)
			longest = Cstudent[i].surname.length();
	return longest;
}


//function prints output of stucture student
void printOutput(CStudent *Cstudent, int Cstudent_index)
{
	Cstudent_index++;
	std::sort(Cstudent, Cstudent + Cstudent_index, CcompareNames);		//sort structures

	//get lengths of the longest setw required
	int setw_name_lenght = longestName(Cstudent, Cstudent_index) + 2;	//for names
	int setw_surname_lenght = longestSurname(Cstudent, Cstudent_index) + 2;	//for surnames

	//outputing results
	cout << "\n\n";
	cout << std::setw(setw_surname_lenght) << std::left << "Pavarde";
	cout << " " << std::setw(setw_name_lenght) << std::left << "Vardas";
	cout << " " << std::setw(10) << std::left << "VidGalut";
	cout << " " << std::setw(10) << std::left << "MedGalut\n";
	for (int i = 0; i < setw_name_lenght + setw_surname_lenght + 10 + 10; i++)
		cout << '-';
	cout << "\n";
	for (int i = 0; i < Cstudent_index; i++)
	{
		cout << std::setw(setw_surname_lenght) << std::left << Cstudent[i].surname;
		cout << " " << std::setw(setw_name_lenght) << std::left << Cstudent[i].name;
		cout << " " << std::setw(10) << std::left << std::fixed << std::setprecision(2) << Cstudent[i].avg_final;
		cout << " " << std::setw(10) << std::left << std::fixed << std::setprecision(2) << Cstudent[i].med_final << "\n";
	}
}


