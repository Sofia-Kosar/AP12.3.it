#include "pch.h"
#include "CppUnitTest.h"
#include "../AP12.3it/AP12.3it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest123it
{
	TEST_CLASS(UnitTest123it)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

			Elem* L1 = nullptr;
			Elem* L2 = nullptr;

			// Додайте елементи до списків
			LAdd(L1, L1, 1);
			LAdd(L1, L1, 2);
			LAdd(L1, L1, 3);

			LAdd(L2, L2, 2);
			LAdd(L2, L2, 3);

			// Act
			bool result = LisSubset(L1, L2);

			// Assert
			Assert::IsTrue(result);
		}
	};
}
