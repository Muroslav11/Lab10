#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab10.2/Lab10.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest102
{
	TEST_CLASS(UnitTest102)
	{
	public:

		TEST_METHOD(TestHasWordA_True)
		{
			char fname[] = "test_true.txt";
			ofstream f(fname);
			f << "apple banana cherry" << endl;
			f.close();

			bool result = Process(fname);

			Assert::IsTrue(result);

			remove(fname);
		}

		TEST_METHOD(TestHasWordA_False)
		{
			char fname[] = "test_false.txt";
			ofstream f(fname);
			f << "bear cat dog" << endl;
			f.close();

			bool result = Process(fname);

			Assert::IsFalse(result);

			remove(fname);
		}
	};
}