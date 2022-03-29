#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab_12_1.8\Cursor.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Cursor c;
			c.Init();
			c.move(10, 20);
			Assert::IsTrue(c.getPosition().getHigh() == 10 && c.getPosition().getLow() == 20);
		}
	};
}
