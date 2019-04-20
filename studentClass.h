#pragma once

//DEFINE CONTAINER:
#define VECTOR
//#define LIST
//#define DEQUE


//DEFINE FINAL MARK CRITERIA:
#define AVERAGE
//#define MEDIAN


//begin of 'VECTOR include'
#ifdef VECTOR
#include <vector>
using std::vector;
#endif	
//end of 'VECTOR include'

//begin of 'LIST include'
#ifdef LIST	
#include <list>
using std::list;
#endif
//end of 'LIST include'

//begin of 'DEQUE include'
#ifdef DEQUE
#include <deque>
using std::deque;
#endif
//end of 'DEQUE include'


#include <iostream>
#include <algorithm>
#include <string>
using std::string;
using std::cout;


#ifdef VECTOR
typedef vector<int> intContainer;
#endif
#ifdef LIST
typedef list<int> intContainer;
#endif
#ifdef DEQUE
typedef deque<int> intContainer;
#endif


//structure of student
class Student {
private:	
	//variables
	intContainer hw_;	//homework marks
	int exam_;	//exam mark
	string name_, surname_;
	double average_, median_;	//average of final mark and median of final mark
	double final_mark_;

	//static members
	static int student_count_;

	//private funcions
	double avgCalc();
	double medCalc();
	void sortHw();
	void sortHw(bool ascendingOrder);

public:	//interface
	//constructors
	Student() : exam_(0), average_(0), median_(0), final_mark_(0) { student_count_++; }
	Student(string name, string surname) : name_(name), surname_(surname), exam_(0), average_(0), median_(0), final_mark_(0) { student_count_++; }

	//get'er functions
	inline string name() const { return name_; }	//get name
	inline string surname() const { return surname_; }	//get surname
	inline double average() const { return average_; }	//get average
	inline double median() const { return median_; }	//get median
	inline double finalMark() const { return final_mark_; }	//get final mark
	inline intContainer homework() const { return hw_; }	//get homework container
	inline int exam() const { return exam_; }	//get exam mark

	//set'er functions
	inline void setName(const string& name) { name_ = name; }	//set name
	inline void setSurname(const string& surname) { surname_ = surname; }	//set surname
	inline void setExam(const int& exam) { exam_ = exam; }	//set exam
	inline void setHomework(const intContainer& homework) { hw_ = homework; }	//set homework
	inline void setAverage(const double& average) { average_ = average; }	//set average mark
	inline void setMedian(const double& median) { median_ = median; }	//set median mark
	void setFinalMark(double criteria);	//set final mark
	void setFinalMark();

	//other functions
	Student copy(const Student& it);
	double averageCalc();	//function calculates the average
	double medianCalc(); //function calculates the median
	void clear();	//reset values to NULL
	void print();	//print information about the student
	inline void homeworkSort() { return sortHw(); }	//sort homework in ascending order
	inline void homeworkSort(const bool& ascendingOrder) { return sortHw(ascendingOrder); }	//sort homework

	//static functions
	inline static int count() { return student_count_; }	//returns the count of objects made of this class

	//destructor
	~Student();
};


#ifdef VECTOR
typedef vector<Student> StudentContainer;
#endif
#ifdef LIST
typedef list<Student> StudentContainer;
#endif
#ifdef DEQUE
typedef deque<Student> StudentContainer;
#endif