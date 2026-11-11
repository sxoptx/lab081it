#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab081/lab081.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81
{
    TEST_CLASS(UnitTest81)
    {
    public:

        TEST_METHOD(Count_TwoGroups)
        {
            char s[30] = "while a while";
            Assert::AreEqual(2, Count(s));
        }

        TEST_METHOD(Count_NoGroups)
        {
            char s[30] = "whil wile";
            Assert::AreEqual(0, Count(s));
        }

        TEST_METHOD(Count_GroupsInRow)
        {
            char s[30] = "whilewhile";
            Assert::AreEqual(2, Count(s));
        }

        TEST_METHOD(Change_Result)
        {
            char s[30] = "while a while";
            char* dest = Change(s);
            Assert::AreEqual("*** a ***", dest);
            delete[] dest;
        }

        TEST_METHOD(Change_Param)
        {
            char s[30] = "x while y";
            char* dest = Change(s);
            Assert::AreEqual("x *** y", s);
            delete[] dest;
        }

        TEST_METHOD(Change_NoGroups)
        {
            char s[30] = "whil";
            char* dest = Change(s);
            Assert::AreEqual("whil", dest);
            delete[] dest;
        }
    };
}