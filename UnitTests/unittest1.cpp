#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Common/EventEngine.h"
#include "../Common/Graphics.h"
#include "../Common/NumericBox.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(NumericBoxTests)
	{
	public:
		
		TEST_METHOD(GetMinValue_ReturnsTrue)
		{

			//Arrange
			NumericBox n(1, 50, 21, { 15,3 }, 5);
			n.setMinValue(35);

			//Act
			int minVal = n.getMinValue();

			//Assert
			Assert::IsTrue(minVal == 35);
		}

		TEST_METHOD(GetMaxValue_ReturnsTrue)
		{
			//Arrange
			NumericBox n(1, 50, 21, { 15,3 }, 5);
			n.setMaxValue(72);

			//Act
			int maxVal = n.getMaxValue();

			//Assert
			Assert::IsTrue(maxVal == 72);
		}


		TEST_METHOD(SetCurrentValue_OutsideBoundries_ReturnsFalse)
		{
			//Arrange
			NumericBox n(1, 50, 21, { 15,3 }, 5);
			n.setMinValue(10);
			n.setMaxValue(20);

			//Act
			bool canBeCurrVal = n.setCurrentValue(30);

			//Assert
			Assert::IsFalse(canBeCurrVal);
		}

		TEST_METHOD(SetCurrentValue_InsideBoundries_ReturnsTrue)
		{
			//Arrange
			NumericBox n(1, 50, 21, { 15,3 }, 5);
			n.setMinValue(10);
			n.setMaxValue(30);

			//Act
			bool canBeCurrVal = n.setCurrentValue(26);

			//Assert
			Assert::IsTrue(canBeCurrVal);
		}

		TEST_METHOD(GetCurrentVal_ReturnsTrue)
		{
			//Arrange
			NumericBox n(1, 50, 21, { 15,3 }, 5);

			//Act
			int currVal = n.getCurrentValue();

			//Assert
			Assert::IsTrue(currVal == 5);
		}

		TEST_METHOD(CanGetFocus_ReturnsFalse)
		{
			//Arrange
			NumericBox n(1, 50, 21, { 15,3 }, 5);

			//Act
			bool isFocusable = n.canGetFocus();

			//Assert
			Assert::IsFalse(isFocusable);
		}

	};
}