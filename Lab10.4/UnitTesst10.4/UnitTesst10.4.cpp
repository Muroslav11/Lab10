#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab10.4/Lab10.4.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest104
{
	TEST_CLASS(UnitTest104)
	{
	public:

		TEST_METHOD(TestCountStartChar)
		{
			char fname[] = "test_start.txt";
			ofstream f(fname);
			f << "apple" << endl;
			f << "banana" << endl;
			f << "apricot" << endl;
			f.close();

			int result = CountStartChar(fname, 'a');
			Assert::AreEqual(2, result);

			remove(fname);
		}

		TEST_METHOD(TestCountSameStartEnd)
		{
			char fname[] = "test_same.txt";
			ofstream f(fname);
			f << "level" << endl;
			f << "radar" << endl;
			f << "apple" << endl;
			f.close();

			int result = CountSameStartEnd(fname);
			Assert::AreEqual(2, result);

			remove(fname);
		}

		TEST_METHOD(TestCountAllSame)
		{
			char fname[] = "test_all_same.txt";
			ofstream f(fname);
			f << "aaaaa" << endl; 
			f << "abc" << endl;   
			f << "bb" << endl;    
			f.close();

			int result = CountAllSame(fname);
			Assert::AreEqual(2, result);

			remove(fname);
		}

		TEST_METHOD(TestCountEmpty)
		{
			char fname[] = "test_empty.txt";
			ofstream f(fname);
			f << "not empty" << endl;
			f << "" << endl; 
			f << " " << endl; 
			f.close();

			int result = CountEmpty(fname);
			Assert::AreEqual(1, result);

			remove(fname);
		}
	};
}