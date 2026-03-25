#include "pch.h"
#include "CppUnitTest.h"
#include "../FractionLib/Fraction.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FractionUnitTest
{
	TEST_CLASS(FractionUnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
		}
		TEST_METHOD(TestConstructorWithoutArgs)
		{
			Fraction f;
			Assert::AreEqual(0, f.getNumerator());
			Assert::AreEqual(1, (int)f.getDenominator());
		}

		TEST_METHOD(TestConstructorWithOneArg)
		{
			Fraction f(-5);
			Assert::AreEqual(-5, f.getNumerator());
			Assert::AreEqual(1, (int)f.getDenominator());
		}

		TEST_METHOD(TestConstructorWithTwoArg)
		{
			Fraction f(2, -5);
			Assert::AreEqual(-2, f.getNumerator());
			Assert::AreEqual(5, (int)f.getDenominator());
		}

		TEST_METHOD(TestFractionReduction)
		{
			Fraction f(200, 400);
			Assert::AreEqual(1, f.getNumerator());
			Assert::AreEqual(2, (int)f.getDenominator());
		}

		TEST_METHOD(TestConstructorExcaption)
		{
			auto func = [] {Fraction f(20, 0); };
			Assert::ExpectException<std::invalid_argument>(func);
		}
	};
}
