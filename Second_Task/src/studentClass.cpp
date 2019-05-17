#include "studentClass.h"


int Student::student_count_ = 0;	//initialize stundet_count_ static


int Student::homework(const size_t index) const 
{
	if (index < hw_.size())
		return hw_[index];
	else 
		throw std::out_of_range{ "Student::homework(const size_t index) index value out of range." };
}

//average or median as a parameter
void Student::setFinalMark(double const criteria)
{
	if (criteria == average_ || criteria == median_)
		final_mark_ = criteria;
	else
		throw "Error: final mark has to be either average or median.\n";
}


void Student::setFinalMark()
{
#ifdef AVERAGE
	final_mark_ = average_;
#endif
#ifdef MEDIAN
	final_mark_ = median_;
#endif;
}


//copies information from student
Student& Student::copy(const Student& it)
{
	name_ = it.name_;
	surname_ = it.surname_;
	hw_ = it.hw_;
	average_ = it.average_;
	median_ = it.median_;
	exam_ = it.exam_;
	final_mark_ = it.final_mark_;

	return *this;
}


double Student::averageCalc()
{
	double avg = avgCalc_();
#ifdef AVERAGE
	final_mark_ = avg;
#endif
	return avg;
}

//function returns the avarage value of the vector array
double Student::avgCalc_()
{
	//calculate the sum of array and return the average
	int sum = 0;
	for (auto const& i : hw_)
		sum += i;

	if (hw_.size() != 0)	//skip division by 0
	{
		double avg = 0.4*(double)((double)sum / (double)hw_.size()) + 0.6*exam_;
		if (avg < 0 || avg > 10)
			return 0;

		if (avg < 5 && avg >= 4.990000)	//fix the issue where 4.995 <= avg < 5.00 would have been assigned a value of 5.00 when writting to file (lame_x.txt)
			avg = 4.99;
		return avg;
	}
	if (hw_.size() == 0 && exam_ >= 1 && exam_ <= 10)	//if no homeworks are done, but atleast exam is passed
		return exam_;
	return 0;
}


double Student::medianCalc()
{
	double med = medCalc_();
#ifdef MEDIAN
	final_mark_ = med;
#endif;
	return med;
}

//function returns the median value of the vector array
double Student::medCalc_()
{
	//we need to sort the array in ascending order
#ifndef LIST
	std::sort(hw_.begin(), hw_.end());

	int sz = hw_.size() / 2;
	int *it = &hw_[sz];
#endif

#ifdef LIST
	hw_.sort();

	std::list<int>::iterator it = hw_.begin();
	std::advance(it, std::distance(hw_.begin(), hw_.end()) / 2);
#endif

	//if odd
	if (hw_.size() % 2 == 1)
	{
		//double med = 0.4*(double)hw[hw.size() / 2] + 0.6*egz;
		double med = 0.4*(double)(*it) + 0.6*exam_;
		if (med < 0 || med > 10)
			return 0;

		if (med < 5 && med >= 4.990000)	//fix the issue where 4.995 <= med < 5.00 would have been assigned a value of 5.00 when writting to file (lame_x.txt)
			med = 4.99;
		return med;
	}

	//if even
	if (hw_.size() % 2 == 0)
	{
		if (hw_.size() != 0)	//skip division by 0
		{
			//double med = 0.4*((1.0*hw[hw.size() / 2 - 1] + 1.0*hw[hw.size() / 2]) / 2) + 0.6*egz;
			double med = 0.4*((1.0*(*(--it)) + 1.0*(*(++it))) / 2) + 0.6*exam_;
			if (med < 0 || med > 10)
				return 0;

			if (med < 5 && med >= 4.990000)	//fix the issue where 4.995 <= med < 5.00 would have been assigned a value of 5.00 when writting to file (lame_x.txt)
				med = 4.99;
			return med;
		}
		if (hw_.size() == 0 && exam_ >= 1 && exam_ <= 10)	//if no homeworks are done, but atleast exam is passed
			return exam_;
		return 0;
	}


	return 0;
}

class descending
{
public:
	template<class T>
	bool operator()(T const& a, T const& b) const { return a > b; }
};

//sorts in ascending order
void Student::sortHw_()
{
#ifndef LIST
	std::sort(hw_.begin(), hw_.end());
#endif

#ifdef LIST
	hw_.sort();
#endif
}


//if true sort ascending, if false - descending order
void Student::sortHw_(bool ascendingOrder)
{
#ifndef LIST
	if (!ascendingOrder)
		std::sort(hw_.begin(), hw_.end(), descending());
	else
		std::sort(hw_.begin(), hw_.end());
#endif

#ifdef LIST
	if (!ascendingOrder)
		hw_.sort(descending());
	else
		hw_.sort();
#endif
}


//set values to NULL or 0 otherwise
void Student::clear()
{
	average_ = 0;
	median_ = 0;
	final_mark_ = 0;
	exam_ = 0;

	//delete homework vectors
	hw_.clear();
	if (!hw_.empty())
		cout << "Error: homework array could not have been deleted.";

	name_.clear();
	if (!name_.empty())
		cout << "Error: name string could not have been deleted.";

	surname_.clear();
	if (!surname_.empty())
		cout << "Error: surname string could not have been deleted.";
}

//print all the info about student
void Student::print(std::ostream& out)
{
	out << "Informacija apie studenta:\n";
	out << "Vardas:\t\t" << name_;
	out << "\nPavarde:\t\t" << surname_;
	out << "\nNamu darbu kiekis:\t\t" << hw_.size();
	out << "\nNamu darbu ivertinimai:\t\t";
	for (auto const& it : hw_)
		out << it << " ";
	out << "\nEgzamino rezultatas:\t\t" << exam_;
	out << "\nVidurkis:\t\t" << average_;
	out << "\nMediana:\t\t" << median_;
	out << "\nGalutinis balas:\t\t" << final_mark_;
	out << "\n";
}

//operators

//copy constructor using parenthesis operator
void Student::operator()(const string& name, const string& surname)
{
	name_ = name;
	surname_ = surname;
	exam_ = 0;
	average_ = 0;
	median_ = 0;
	final_mark_ = 0;
}

//copy constructor using parenthesis operator
void Student::operator()(const Student& obj)
{
	name_ = obj.name_;
	surname_ = obj.surname_;
	exam_ = obj.exam_;
	hw_ = obj.hw_;
	average_ = obj.average_;
	median_ = obj.median_;
	final_mark_ = obj.final_mark_;
}

Student& Student::operator=(const Student& obj)
{
	this->copy(obj);
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Student& obj)
{
	out << "\nInformacija apie studenta:\n";
	out << "Vardas: \t\t\t" << obj.name_;
	out << "\nPavarde: \t\t\t" << obj.surname_;
	out << "\nNamu darbu kiekis: \t\t" << obj.hw_.size();
	out << "\nNamu darbu ivertinimai: \t";
	for (auto const& it : obj.hw_)
		out << it << " ";
	out << "\nEgzamino rezultatas: \t\t" << obj.exam_;
	out << "\nVidurkis: \t\t\t" << obj.average_;
	out << "\nMediana: \t\t\t" << obj.median_;
	out << "\nGalutinis balas: \t\t" << obj.final_mark_;
	out << "\n";

	return out;
}


std::istream& operator>>(std::istream& in, Student& obj)
{
	Student temp_stud;

	//get name
	cout << "Iveskite studento varda: ";
	string name;
	temp_stud.dollarSign_();
	in >> name;
	temp_stud.setName(name);

	//get surname
	cout << "Iveskite studento pavarde: ";
	string surname;
	temp_stud.dollarSign_();
	in >> surname;
	temp_stud.setSurname(surname);


	//begin of 'input homework'
	cout << "Dabar veskite namu darbu rezultatus (minimali verte 1, maksimali 10).\n";
	cout << "Atsitiktiniam namu darbu ir egzaminu rezultatu sugeneravimui, rasykite \"rand\".\n";
	cout << "Kai baigsite, iveskite \"egz\": ";
	string temp_input;

	intContainer hw;
	while (temp_input != "egz")
	{
		temp_stud.dollarSign_();
		in >> temp_input;

		//break if input is 'egz'
		if (temp_input == "egz")
			break;

		//begin of 'randomize homework results'
		if (temp_input == "rand")
		{
			int max_rand = 20;	//20 is maximum amount of homework currently
			//begin of 'rand error message'
			//if homework amount is 20 or more, don't randomize
			if (max_rand - hw.size() < 1)
			{
				cout << "Negeneruojama, kai yra virs " << max_rand << " namu darbu.";
				continue;
			}
			//end of 'rand error message'

			//initialize random device and set a uniform distribution of integers between 1 and 10
			RandomEngine engine;
			std::uniform_int_distribution<int> dist = engine.uni_int_distr(1, 10);
			std::uniform_int_distribution<int> dist2 = engine.uni_int_distr(0, int(max_rand - hw.size() - 1));

			int rand_hw_num = dist2(engine.mt);	//get random homework amount

			//set randomized marks to homeworks and then exam
			for (int i = 0; i < rand_hw_num; i++)
				hw.push_back(dist(engine.mt));	//randomize between 1 and 10

			temp_stud.setHomework(hw);
			temp_stud.setExam(dist(engine.mt));	//randomize exam

			obj = temp_stud;
			return in;
		}
		//end of 'randomize homework results'

		//get mark input
		if (temp_input == "1" || temp_input == "2" || temp_input == "3" || temp_input == "4" || temp_input == "5" || temp_input == "6"
			|| temp_input == "7" || temp_input == "8" || temp_input == "9" || temp_input == "10")//if the input is between 1 and 10 inclusive
			hw.push_back(std::stoi(temp_input));	//add to hw array
		//if invalid character is inputed throw error message
		else
		{
			cout << "Invalid character(s). Expected numbers between 1 and 10.\n";
			continue;
		}
		temp_stud.setHomework(hw);
	}

#ifndef LIST
	hw.shrink_to_fit();
#endif
	//end of 'input homework'

	//begin of 'input of exam'
	cout << "Iveskite egzamino rezultata (nuo 1 iki 10): ";
	while (1)
	{
		temp_stud.dollarSign_();
		in >> temp_input;
		if (temp_input == "1" || temp_input == "2" || temp_input == "3" || temp_input == "4" || temp_input == "5" || temp_input == "6"
			|| temp_input == "7" || temp_input == "8" || temp_input == "9" || temp_input == "10")//if the input is between 1 and 10 inclusive
			break;
		cout << "Klaida. Neteisingas egzamino rezultato formatas. Iveskite egzamino rezultata (nuo 1 iki 10): ";
	}

	if (temp_input != "10")
		temp_stud.setExam(std::stoi(temp_input));
	else
		temp_stud.setExam(10);
	//end of 'input of exam'

	cout << "\nStudentas sekmingai ivestas!\n";

	obj = temp_stud;
	return in;
}


//delete student object vector
Student::~Student()
{
	//cout << "DESTRUCTOR CALLED\n";
	student_count_--;
}