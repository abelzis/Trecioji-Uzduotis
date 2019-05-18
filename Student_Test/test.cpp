#include "gtest/gtest.h"
#include "../Second_Task/src/studentClass.h"
#include "../Second_Task/src/studentClass.cpp"
#include "../Second_Task/src/humanClass.h"
#include "../Second_Task/src/humanClass.cpp"

namespace studenttest
{
	typedef Student st;
	TEST(TestConstructor, DefaultConstructor) 
	{
		st s;
		EXPECT_EQ(s.name(), "");
		EXPECT_EQ(s.surname(), "");
		EXPECT_EQ(s.average(), 0);
		EXPECT_EQ(s.median(), 0);
		EXPECT_EQ(s.finalMark(), 0);

		EXPECT_EQ(st::count(), 1);
	}

	TEST(TestConstructor, StringParam)
	{
		st s{ "bulis" };
		EXPECT_EQ(s.name(), "bulis");
		EXPECT_EQ(s.surname(), "");
		EXPECT_EQ(s.average(), 0);
		EXPECT_EQ(s.median(), 0);
		EXPECT_EQ(s.finalMark(), 0);
	}

	TEST(TestConstructor, StringStringParam)
	{
		st s{ "rav", "neme" };
		EXPECT_EQ(s.name(), "rav");
		EXPECT_EQ(s.surname(), "neme");
		EXPECT_EQ(s.average(), 0);
		EXPECT_EQ(s.median(), 0);
		EXPECT_EQ(s.finalMark(), 0);
	}

	TEST(TestConstructor, CopyConstructor)
	{
		st s1{ "nam", "kile" };
		s1.setAverage(3);
		s1.setFinalMark();
		st s{ s1 };
		EXPECT_EQ(s.name(), "nam");
		EXPECT_EQ(s.surname(), "kile");
		EXPECT_EQ(s.average(), 3);
		EXPECT_EQ(s.median(), 0);
		EXPECT_EQ(s.finalMark(), 3);
	}

	TEST(GetterFunctions, Name)
	{
		st s{ "nam", "kile" };
		EXPECT_EQ(s.name(), "nam");
	}

	TEST(GetterFunctions, Homework)
	{
		st s;
		intContainer hw;
		hw.push_back(3);
		hw.push_back(4);
		hw.push_back(7);
		hw.push_back(3);
		s.setHomework(hw);
		EXPECT_EQ(s.homework(), hw);
	}

	TEST(GetterSetterFunctions, Surname)
	{
		st s;
		s.setSurname("BBBBTYY");
		EXPECT_EQ(s.surname(), "BBBBTYY");
	}

	TEST(GetterSetterFunctions, Average)
	{
		st s;
		s.setAverage(7.55);
		EXPECT_EQ(s.average(), 7.55);
	}

	TEST(GetterSetterFunctions, Median)
	{
		st s;
		s.setMedian(-2.35);
		EXPECT_EQ(s.median(), -2.35);
	}

	TEST(GetterSetterFunctions, FinalMarkMedian)
	{
		st s;
		s.setMedian(3.44);
		s.setFinalMark(3.44);
		EXPECT_EQ(s.finalMark(), 3.44);
	}

	TEST(GetterSetterFunctions, FinalMarkAverage)
	{
		st s;
		s.setAverage(8.88);
		s.setFinalMark();
		EXPECT_EQ(s.finalMark(), 8.88);
	}

	TEST(GetterSetterFunctions, Homework)
	{
		st s;
		intContainer hw;
		hw.push_back(6);
		hw.push_back(3);
		hw.push_back(2);
		hw.push_back(0);
		hw.push_back(4);
		hw.push_back(1);
		hw.push_back(5);

		s.setHomework(hw);

		EXPECT_EQ(s.homework(3), 0);
	}

	TEST(GetterSetterFunctions, Exam)
	{
		st s;
		s.setExam(4);
		EXPECT_EQ(s.exam(), 4);
	}

	TEST(SetterFunctions, FinalMarkExpectException)
	{
		st s;
		EXPECT_ANY_THROW(s.setFinalMark(4.55));
	}

	TEST(AlgorithmFunctions, Copy)
	{
		st s1{ "bde", "eeeeg" };
		s1.setAverage(3);
		s1.setMedian(8);
		s1.setFinalMark(3);

		st s;
		s.copy(s1);

		EXPECT_EQ(s.name(), "bde");
		EXPECT_EQ(s.surname(), "eeeeg");
		EXPECT_EQ(s.average(), 3);
		EXPECT_EQ(s.median(), 8);
		EXPECT_EQ(s.finalMark(), 3);
	}

	TEST(AlgorithmFunctions, AverageCalculation)
	{
		st s;
		intContainer hw;
		hw.push_back(1);
		hw.push_back(5);
		hw.push_back(3);
		hw.push_back(8);
		hw.push_back(8);
		hw.push_back(8);
		hw.push_back(6);
		
		s.setHomework(hw);
		s.setExam(9);

		EXPECT_TRUE(s.averageCalc() >= 7.62 && s.averageCalc() < 7.63);
	}

	TEST(AlgorithmFunctions, MedianCalculation)
	{
		st s;
		intContainer hw;
		hw.push_back(7);
		hw.push_back(2);
		hw.push_back(3);
		hw.push_back(2);
		hw.push_back(5);
		hw.push_back(8);
		hw.push_back(6);

		s.setHomework(hw);
		s.setExam(6);

		EXPECT_TRUE(s.medianCalc() >= 5.6 && s.medianCalc() < 5.61);
	}

	TEST(AlgorithmFunctions, Clear)
	{
		st s{ "aggg", "argrsbbaa" };
		s.setAverage(7);
		s.setMedian(5);
		s.setFinalMark(5);

		EXPECT_EQ(s.name(), "aggg");
		EXPECT_EQ(s.surname(), "argrsbbaa");
		EXPECT_EQ(s.average(), 7);
		EXPECT_EQ(s.median(), 5);
		EXPECT_EQ(s.finalMark(), 5);

		s.clear();
		EXPECT_EQ(s.name(), "");
		EXPECT_EQ(s.surname(), "");
		EXPECT_EQ(s.average(), 0);
		EXPECT_EQ(s.median(), 0);
		EXPECT_EQ(s.finalMark(), 0);
	}

	TEST(AlgorithmFunctions, HomeworkSortNoParam)
	{
		st s;
		intContainer hw;
		hw.push_back(6);
		hw.push_back(3);
		hw.push_back(2);
		hw.push_back(0);
		hw.push_back(4);
		hw.push_back(1);
		hw.push_back(5);

		s.setHomework(hw);
		s.homeworkSort();

		for (int i = 0; i < hw.size(); i++)
			EXPECT_EQ(s.homework(i), i);
	}

	TEST(AlgorithmFunctions, HomeworkSortTrueParamDescendingOrder)
	{
		st s;
		intContainer hw;
		hw.push_back(6);
		hw.push_back(3);
		hw.push_back(2);
		hw.push_back(0);
		hw.push_back(4);
		hw.push_back(1);
		hw.push_back(5);

		s.setHomework(hw);
		s.homeworkSort(true);

		for (int i = 0; i < hw.size(); i++)
			EXPECT_EQ(s.homework(i), i);
	}

	TEST(AlgorithmFunctions, HomeworkSortFalseParamDescendingOrder)
	{
		st s;
		intContainer hw;
		hw.push_back(6);
		hw.push_back(3);
		hw.push_back(2);
		hw.push_back(0);
		hw.push_back(4);
		hw.push_back(1);
		hw.push_back(5);

		s.setHomework(hw);
		s.homeworkSort(false);

		for (int i = 0; i < hw.size(); i++)
			EXPECT_EQ(s.homework(i), 6 - i);
	}

	TEST(StaticFunctions, StudentCountDefaultConstructor)
	{
		st s1, s2, s3, s4, s5, s6;
		EXPECT_EQ(st::count(), 6);
	}

	TEST(StaticFunctions, StudentCountVariousConstructors)
	{
		st s1{ "5z" }, s2, s3{ s1 }, s4, s5(s3), s6, s7("naaame", "suuurname");
		EXPECT_EQ(st::count(), 7);
	}

	TEST(StaticFunctions, StudentCountDestructors)
	{
		{
			st s1{ "aaaz" }, s2, s3(s2), s4("eaa", "eaa"), s5;
			EXPECT_EQ(st::count(), 5);
		}
		EXPECT_EQ(st::count(), 0);
	}

	TEST(Operators, Assignment)
	{
		st s1{ "banana", "apple" };
		s1.setAverage(6);

		st s = s1;
		EXPECT_EQ(s.name(), "banana");
		EXPECT_EQ(s.surname(), "apple");
		EXPECT_EQ(s.average(), 6);
	}

	TEST(Operators, ConstructorBasedNameAndSurname)
	{
		st s("bull", "BOOs");
		s.setMedian(5);

		EXPECT_EQ(s.name(), "bull");
		EXPECT_EQ(s.surname(), "BOOs");
		EXPECT_EQ(s.median(), 5);
	}

	TEST(Operators, ConstructorBasedCopyParam)
	{
		st s1{ "eee", "bbb" };
		s1.setMedian(5);

		st s(s1);
		EXPECT_EQ(s.name(), "eee");
		EXPECT_EQ(s.surname(), "bbb");
		EXPECT_EQ(s.median(), 5);
	}

	TEST(Operators, BoolEqual)
	{
		st s1, s2;
		EXPECT_TRUE(s1 == s2);
	}

	TEST(Operators, BoolNotEqual)
	{
		st s1, s2{ "bannaaa" };
		EXPECT_TRUE(s1 != s2);
	}

	TEST(Operators, BoolGreaterThan)
	{
		st s1, s2{ "monkey", "Nuts" };
		s1.setAverage(3);
		s1.setFinalMark(3);
		EXPECT_TRUE(s1 > s2);
	}

	TEST(Operators, BoolGreaterEqualThan)
	{
		st s1, s2;
		s1.setAverage(7);
		s1.setFinalMark(7);

		s2.setAverage(4);
		s2.setFinalMark(4);
		EXPECT_TRUE(s1 >= s2);
	}

	TEST(Operators, BoolLowerThan)
	{
		st s1, s2;
		s1.setAverage(5);
		s1.setFinalMark(5);

		s2.setAverage(6);
		s2.setFinalMark(6);
		EXPECT_TRUE(s1 < s2);
	}

	TEST(Operators, BoolLowerEqualThan)
	{
		st s1, s2;
		s1.setAverage(2);
		s1.setFinalMark(2);

		s2.setAverage(2);
		s2.setFinalMark(2);
		EXPECT_TRUE(s1 <= s2);
	}
}


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}