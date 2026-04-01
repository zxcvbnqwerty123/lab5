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
		TEST_METHOD(TestConstructorFromString)
		{
			Fraction f("3/4");
			Assert::AreEqual(3, f.getNumerator());
			Assert::AreEqual(4, (int)f.getDenominator());
		}

		TEST_METHOD(TestConstructorFromStringWithNegative)
		{
			Fraction f("-5/2");
			Assert::AreEqual(-5, f.getNumerator());
			Assert::AreEqual(2, (int)f.getDenominator());
		}

		TEST_METHOD(TestConstructorFromStringWithReduction)
		{
			Fraction f("4/8");
			Assert::AreEqual(1, f.getNumerator());
			Assert::AreEqual(2, (int)f.getDenominator());
		}

		TEST_METHOD(TestConstructorFromStringWithZeroDenominator)
		{
			auto func = [] { Fraction f("3/0"); };
			Assert::ExpectException<std::invalid_argument>(func);
		}
		TEST_METHOD(TestEqualityOperator)
		{
			Fraction f1(1, 2);
			Fraction f2(2, 4);
			Fraction f3(1, 3);

			Assert::IsTrue(f1 == f2);
			Assert::IsFalse(f1 == f3);
		}

		TEST_METHOD(TestInequalityOperator)
		{
			Fraction f1(1, 2);
			Fraction f2(2, 4);
			Fraction f3(1, 3);

			Assert::IsFalse(f1 != f2);
			Assert::IsTrue(f1 != f3);
		}

		TEST_METHOD(TestLessThanOperator)
		{
			Fraction f1(1, 3);
			Fraction f2(1, 2);
			Fraction f3(2, 4);

			Assert::IsTrue(f1 < f2);
			Assert::IsFalse(f2 < f1);
			Assert::IsFalse(f2 < f3);  
		}

		TEST_METHOD(TestGreaterThanOperator)
		{
			Fraction f1(1, 2);
			Fraction f2(1, 3);
			Fraction f3(2, 4);

			Assert::IsTrue(f1 > f2);
			Assert::IsFalse(f2 > f1);
			Assert::IsFalse(f1 > f3); 
		}

		TEST_METHOD(TestLessOrEqualOperator)
		{
			Fraction f1(1, 3);
			Fraction f2(1, 2);
			Fraction f3(2, 4);

			Assert::IsTrue(f1 <= f2);
			Assert::IsTrue(f2 <= f3); 
			Assert::IsFalse(f2 <= f1);
		}

		TEST_METHOD(TestGreaterOrEqualOperator)
		{
			Fraction f1(1, 2);
			Fraction f2(1, 3);
			Fraction f3(2, 4);

			Assert::IsTrue(f1 >= f2);
			Assert::IsTrue(f1 >= f3);  
			Assert::IsFalse(f2 >= f1);
		}
		TEST_METHOD(TestPlusEqualOperator)
		{
			Fraction f1(1, 2);
			Fraction f2(1, 3);
			f1 += f2;

			Assert::AreEqual(5, f1.getNumerator());
			Assert::AreEqual(6, (int)f1.getDenominator());
		}

		TEST_METHOD(TestMinusEqualOperator)
		{
			Fraction f1(1, 2);
			Fraction f2(1, 3);
			f1 -= f2;

			Assert::AreEqual(1, f1.getNumerator());
			Assert::AreEqual(6, (int)f1.getDenominator());
		}

		TEST_METHOD(TestMultiplyEqualOperator)
		{
			Fraction f1(2, 3);
			Fraction f2(3, 4);
			f1 *= f2;

			Assert::AreEqual(1, f1.getNumerator());
			Assert::AreEqual(2, (int)f1.getDenominator());
		}

		TEST_METHOD(TestDivideEqualOperator)
		{
			Fraction f1(2, 3);
			Fraction f2(4, 5);
			f1 /= f2;

			Assert::AreEqual(5, f1.getNumerator());
			Assert::AreEqual(6, (int)f1.getDenominator());
		}

		TEST_METHOD(TestDivideEqualByZero)
		{
			Fraction f1(1, 2);
			Fraction f2(0, 5);

			auto func = [&] { f1 /= f2; };
			Assert::ExpectException<std::invalid_argument>(func);
		}
		TEST_METHOD(TestUnaryMinus)
		{
			Fraction f1(1, 2);
			Fraction f2 = -f1;

			Assert::AreEqual(-1, f2.getNumerator());
			Assert::AreEqual(2, (int)f2.getDenominator());

			Assert::AreEqual(1, f1.getNumerator());
			Assert::AreEqual(2, (int)f1.getDenominator());
		}

		TEST_METHOD(TestUnaryMinusOnNegative)
		{
			Fraction f1(-1, 2);
			Fraction f2 = -f1;

			Assert::AreEqual(1, f2.getNumerator());
			Assert::AreEqual(2, (int)f2.getDenominator());
		}
		TEST_METHOD(TestAdditionOperator)
		{
			Fraction f1(1, 2);
			Fraction f2(1, 3);
			Fraction result = f1 + f2;

			Assert::AreEqual(5, result.getNumerator());
			Assert::AreEqual(6, (int)result.getDenominator());

			// ѕроверка, что исходные дроби не изменились
			Assert::AreEqual(1, f1.getNumerator());
			Assert::AreEqual(2, (int)f1.getDenominator());
			Assert::AreEqual(1, f2.getNumerator());
			Assert::AreEqual(3, (int)f2.getDenominator());
		}

		TEST_METHOD(TestSubtractionOperator)
		{
			Fraction f1(1, 2);
			Fraction f2(1, 3);
			Fraction result = f1 - f2;

			Assert::AreEqual(1, result.getNumerator());
			Assert::AreEqual(6, (int)result.getDenominator());
		}

		TEST_METHOD(TestMultiplicationOperator)
		{
			Fraction f1(2, 3);
			Fraction f2(3, 4);
			Fraction result = f1 * f2;

			Assert::AreEqual(1, result.getNumerator());
			Assert::AreEqual(2, (int)result.getDenominator());
		}

		TEST_METHOD(TestDivisionOperator)
		{
			Fraction f1(2, 3);
			Fraction f2(4, 5);
			Fraction result = f1 / f2;

			Assert::AreEqual(5, result.getNumerator());
			Assert::AreEqual(6, (int)result.getDenominator());
		}

		TEST_METHOD(TestDivisionByZero)
		{
			Fraction f1(1, 2);
			Fraction f2(0, 5);

			auto func = [&] { Fraction result = f1 / f2; };
			Assert::ExpectException<std::invalid_argument>(func);
		}
		TEST_METHOD(TestChainedOperations)
		{
			Fraction f(1, 2);
			f += Fraction(1, 3);
			f *= Fraction(3, 5);

			Assert::AreEqual(1, f.getNumerator());
			Assert::AreEqual(2, (int)f.getDenominator());
		}

		TEST_METHOD(TestComparisonChaining)
		{
			Fraction f1(1, 2);
			Fraction f2(2, 4);
			Fraction f3(3, 6);

			Assert::IsTrue(f1 == f2 && f2 == f3);
			Assert::IsTrue(f1 <= f2 && f2 <= f3);
		}
	};
}
