#include "pch.h"
#include "CppUnitTest.h"
#include "../test2.2/String.h"
#include "../test2.2/main.cpp"
#include "../test2.2/String.cpp"
 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(ConcatenationTest)
        {
            String s1("nlo");
            String s2(" in the sky!");
            String result = s1 + s2;
            Assert::AreEqual("nlo in the sky!", result.getStr());
        }
    };
}