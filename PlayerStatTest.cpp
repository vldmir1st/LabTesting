#include "pch.h"
#include "CppUnitTest.h"
#include "..\LabTesting\PlayerStat.h"
#include "..\LabTesting\PlayerStat.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PlayerStatTest
{
	TEST_CLASS(PlayerStatTest)
	{
	public:
		
		TEST_METHOD(ConstructorTest)
		{
			PlayerStat Pl("John", 56);
			Assert::IsTrue(Pl.nickname == "John", L"Wrong name");
			Assert::IsTrue(Pl.score == 56, L"Wrong score");
		}

		TEST_METHOD(SumOperatorScoreIsZero)
		{
			PlayerStat Pl("John", 0);
			Pl += 49;
			Assert::IsTrue(Pl.score == 49);
		}

		TEST_METHOD(SumOperatorScoreIsPositive)
		{
			PlayerStat Pl("John", 50);
			Pl += 50;
			Assert::IsTrue(Pl.score == 100);
		}

		TEST_METHOD(SumOperatorScoreIsNegative)
		{
			PlayerStat Pl("John", -50);
			Pl += 50;
			Assert::IsTrue(Pl.score == 0);
		}

		TEST_METHOD(SumOperatorZeroPoints)
		{
			PlayerStat Pl("John", 72);
			Pl += 0;
			Assert::IsTrue(Pl.score == 72);
		}

		TEST_METHOD(DifOperatorScoreIsZero)
		{
			PlayerStat Pl("John", 0);
			Pl -= 49;
			Assert::IsTrue(Pl.score == -49);
		}

		TEST_METHOD(DifOperatorScoreIsPositive)
		{
			PlayerStat Pl("John", 50);
			Pl -= 50;
			Assert::IsTrue(Pl.score == 0);
		}

		TEST_METHOD(DifOperatorScoreIsNegative)
		{
			PlayerStat Pl("John", -50);
			Pl -= 50;
			Assert::IsTrue(Pl.score == -100);
		}

		TEST_METHOD(DifOperatorZeroPoints)
		{
			PlayerStat Pl("John", -72);
			Pl -= 0;
			Assert::IsTrue(Pl.score == -72);
		}

		TEST_METHOD(EqualityOperator)
		{
			PlayerStat Pl1("John", 64);
			PlayerStat Pl2("Sam", 64);
			PlayerStat Pl3("Leha", 38);
			Assert::IsTrue((Pl1 == Pl2) == true);
			Assert::IsTrue((Pl1 == Pl3) == false);
		}

		TEST_METHOD(LessOperator)
		{
			PlayerStat Pl1("John", 64);
			PlayerStat Pl2("Sam", 64);
			PlayerStat Pl3("Leha", 38);
			Assert::IsTrue((Pl1 < Pl2) == false);
			Assert::IsTrue((Pl3 < Pl2) == true);
		}

		TEST_METHOD(MoreOperator)
		{
			PlayerStat Pl1("John", 64);
			PlayerStat Pl2("Sam", 64);
			PlayerStat Pl3("Leha", 38);
			Assert::IsTrue((Pl1 > Pl2) == false);
			Assert::IsTrue((Pl2 > Pl3) == true);
		}
	};
}
