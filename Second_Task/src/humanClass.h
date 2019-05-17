#pragma once

#include <string>
using std::string;

class Human 
{
private:
	static int human_count_;
protected:
	string name_, surname_;

	//default constructor
	Human() : name_(""), surname_("") { human_count_++; }
	Human(const string& name) : name_(name), surname_("") { human_count_++; }
	Human(const string& name, const string& surname) : name_(name), surname_(surname) { human_count_++; }

public:
	~Human() { human_count_--; }
};
