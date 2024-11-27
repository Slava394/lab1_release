#pragma once
#include <cxxtest/TestSuite.h>
#include <fstream>
#include <string>
#include <complex>
#include "../pointers/unique_ptr.hpp"
#define EPSILON 0.00000001


class UniqueTest : public CxxTest::TestSuite
{
public:
    void testCreation1()
    {
        std::ifstream in("../test_data/int_data.txt");
        if (in.is_open())
        {
            for (int i = 0; i < 1000; ++i)
            {
                int num;
                in >> num;
                UniquePtr<int> uniquePtr(new int(num));
                TS_ASSERT_EQUALS(*uniquePtr, num);
                TS_ASSERT(uniquePtr != nullptr);
            }
        }
        in.close();
    }

    void testCreation2()
    {
        std::ifstream in("../test_data/double_data.txt");
        if (in.is_open())
        {
            for (int i = 0; i < 1000; ++i)
            {
                double num;
                in >> num;
                UniquePtr<double> uniquePtr(new double(num));
                TS_ASSERT(*uniquePtr - num < EPSILON);
                TS_ASSERT(uniquePtr != nullptr);
            }
        }
        in.close();
    }

    void testCreation3()
    {
        std::ifstream in("../test_data/string_data.txt");
        if (in.is_open())
        {
            for (int i = 0; i < 1000; ++i)
            {
                std::string str;
                in >> str;
                UniquePtr<std::string> uniquePtr(new std::string(str));
                TS_ASSERT_EQUALS(*uniquePtr, str);
                TS_ASSERT(uniquePtr != nullptr);
            }
        }
        in.close();
    }

    void testCreation4()
    {
        std::ifstream in("../test_data/int_data.txt");
        if (in.is_open())
        {
            for (int i = 0; i < 500; ++i)
            {
                int a, b;
                in >> a >> b;
                UniquePtr<std::complex<int>> uniquePtr(new std::complex<int>(a, b));
                TS_ASSERT_EQUALS(uniquePtr->real(), a);
                TS_ASSERT_EQUALS(uniquePtr->imag(), b);
                TS_ASSERT(uniquePtr != nullptr);
            }
        }
        in.close();
    }

    void testCreation5()
    {
        for (int i = 50; i < 200; ++i)
        {
            UniquePtr<char> uniquePtr(new char(i));
            TS_ASSERT_EQUALS(*uniquePtr, char(i));
            TS_ASSERT(uniquePtr != nullptr);
        }
    }

    void testMoveConstructor1()
    {
        std::ifstream in("../test_data/int_data.txt");
        if (in.is_open())
        {
            for (int i = 0; i < 1000; ++i)
            {
                int num;
                in >> num;
                UniquePtr<int> uniquePtr1(new int(num));
                UniquePtr<int> uniquePtr2(std::move(uniquePtr1));
                TS_ASSERT_EQUALS(*uniquePtr2, num);
                TS_ASSERT(uniquePtr1 == nullptr);
                TS_ASSERT(uniquePtr2 != nullptr);
            }
        }
        in.close();
    }

    void testMoveConstructor2()
    {
        UniquePtr<int> uniquePtr1;
        UniquePtr<int> uniquePtr2(std::move(uniquePtr1));
        TS_ASSERT(uniquePtr1 == nullptr);
        TS_ASSERT(uniquePtr2 == nullptr);
    }

    void testMoveConstructor3()
    {
        std::ifstream in("../test_data/int_data.txt");
        if (in.is_open())
        {
            for (int i = 0; i < 1000; ++i)
            {
                int num;
                in >> num;
                UniquePtr<int> uniquePtr1(new int(num));
                UniquePtr<int> uniquePtr2(std::move(uniquePtr1));
                UniquePtr<int> uniquePtr3(std::move(uniquePtr2));
                TS_ASSERT_EQUALS(*uniquePtr3, num);
                TS_ASSERT(uniquePtr1 == nullptr);
                TS_ASSERT(uniquePtr2 == nullptr);
                TS_ASSERT(uniquePtr3 != nullptr);
            }
        }
        in.close();
    }

    void testRelativeOperator1()
    {
        std::ifstream in("../test_data/int_data.txt");
        if (in.is_open())
        {
            for (int i = 0; i < 1000; ++i)
            {
                int num;
                in >> num;
                UniquePtr<int> uniquePtr1(new int(num));
                TS_ASSERT(uniquePtr1 == uniquePtr1);
            }
        }
        in.close();
    }

    void testRelativeOperator2()
    {
        std::ifstream in("../test_data/int_data.txt");
        if (in.is_open())
        {
            for (int i = 0; i < 1000; i += 2)
            {
                int num1, num2;
                in >> num1 >> num2;
                UniquePtr<int> uniquePtr1(new int(num1));
                UniquePtr<int> uniquePtr2(new int(num2));
                TS_ASSERT(uniquePtr1 != uniquePtr2);
            }
        }
        in.close();
    }

    void testRelativeOperator3()
    {
        UniquePtr<int> uniquePtr1;
        UniquePtr<int> uniquePtr2(std::move(uniquePtr1));
        TS_ASSERT(uniquePtr1 == nullptr);
        TS_ASSERT(uniquePtr2 == nullptr);
    }

    void testRelativeOperator4()
    {
        std::ifstream in("../test_data/int_data.txt");
        if (in.is_open())
        {
            for (int i = 0; i < 1000; ++i)
            {
                int num;
                in >> num;
                UniquePtr<int> uniquePtr1(new int(num));
                UniquePtr<int> uniquePtr2(std::move(uniquePtr1));
                TS_ASSERT(uniquePtr1 == nullptr);
                TS_ASSERT(uniquePtr2 != nullptr);
            }
        }
        in.close();
    }

    void testAccessOperator1()
    {
        std::ifstream in("../test_data/int_data.txt");
        if (in.is_open())
        {
            for (int i = 0; i < 1000; ++i)
            {
                int num;
                in >> num;
                UniquePtr<int> uniquePtr(new int(num));
                TS_ASSERT_THROWS_NOTHING(*uniquePtr);
                TS_ASSERT(uniquePtr != nullptr);
            }
        }
    }

    void testAccessOperator2()
    {
        UniquePtr<int> uniquePtr;
        TS_ASSERT_THROWS_ANYTHING(*uniquePtr);
        TS_ASSERT(uniquePtr == nullptr);
    }
};