#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab10.1/Lab10.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest101
{
	TEST_CLASS(UnitTest101)
	{
	public:

		TEST_METHOD(TestProcessWithPairs)
		{
			char fname[] = "test1.txt";
			ofstream f(fname);
			f << "aa bb cc" << endl;
			f.close();

			bool result = Process(fname);

			Assert::IsTrue(result);

			remove(fname);
		}

		TEST_METHOD(TestProcessWithoutPairs)
		{
			char fname[] = "test2.txt";
			ofstream f(fname);
			f << "abc abc" << endl;
			f.close();

			bool result = Process(fname);

			Assert::IsFalse(result);

			remove(fname);
		}
	};
}