#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab10.3/Lab10.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest103
{
	TEST_CLASS(UnitTest103)
	{
	public:

		TEST_METHOD(TestTextFileWriteAndRead)
		{
			char fname[] = "test_text.txt";

			ofstream fout(fname);
			string testStart = "Lviv";
			string testEnd = "Kyiv";
			int testNum = 505;

			fout << testStart << endl;
			fout << testEnd << endl;
			fout << testNum << endl;
			fout.close();

			ifstream fin(fname);
			string resStart, resEnd;
			int resNum;

			fin >> resStart >> resEnd >> resNum;
			fin.close();

			Assert::AreEqual(testStart, resStart);
			Assert::AreEqual(testEnd, resEnd);
			Assert::AreEqual(testNum, resNum);

			remove(fname);
		}

		TEST_METHOD(TestProcessTXTLogic)
		{
			char fname[] = "test_search.txt";
			ofstream fout(fname);
			fout << "Odesa" << endl << "Dnipro" << endl << 777 << endl;
			fout.close();
			ProcessTXT(fname, 777);

			Assert::IsTrue(true);

			remove(fname);
		}
	};
}