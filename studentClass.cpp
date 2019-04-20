#include "studentClass.h"


int Student::student_count_ = 0;	//initialize stundet_count_ static

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
Student Student::copy(const Student& it)
{
	Student temp;

	temp.setName(it.name());
	temp.setSurname(it.surname());
	temp.setAverage(it.average());
	temp.setMedian(it.median());
	temp.setExam(it.exam());
	temp.setHomework(it.homework());
	temp.setFinalMark(it.finalMark());

	return temp;
}


double Student::averageCalc()
{
	double avg = avgCalc();
#ifdef AVERAGE
	final_mark_ = avg;
#endif
	return avg;
}

//function returns the avarage value of the vector array
double Student::avgCalc()
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
		return avg;
	}
	if (hw_.size() == 0 && exam_ >= 1 && exam_ <= 10)	//if no homeworks are done, but atleast exam is passed
		return exam_;
	return 0;
}


double Student::medianCalc()
{
	double med = medCalc();
#ifdef MEDIAN
	final_mark_ = med;
#endif;
	return med;
}

//function returns the median value of the vector array
double Student::medCalc()
{
	//we need to sort the array in ascending order
#ifndef LIST
	std::sort(hw_.begin(), hw_.end());

	int sz = hw_.size() / 2;
	int *it = &sz;
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
void Student::sortHw()
{
#ifndef LIST
	std::sort(hw_.begin(), hw_.end());
#endif

#ifdef LIST
	hw_.sort();
#endif
}


//if true sort ascending, if false - descending order
void Student::sortHw(bool ascendingOrder)
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

	exam_ = 0;
	average_ = 0;
	median_ = 0;
	final_mark_ = 0;
}

//print all the info about student
void Student::print()
{
	cout << "Informacija apie studenta:\n";
	cout << "Vardas:\t\t" << name_;
	cout << "\nPavarde:\t\t" << surname_;
	cout << "\nNamu darbu kiekis:\t\t" << hw_.size();
	cout << "\nNamu darbu ivertinimai:\t\t";
	for (auto const& it : hw_)
		cout << it << " ";
	cout << "\nEgzamino rezultatas:\t\t" << exam_;
	cout << "\nVidurkis:\t\t" << average_;
	cout << "\nMediana:\t\t" << median_;
	cout << "\nGalutinis balas:\t\t" << final_mark_;
	cout << "\n";
}


//delete student object vector
Student::~Student()
{
	student_count_--;

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
	//delete student object vector
}