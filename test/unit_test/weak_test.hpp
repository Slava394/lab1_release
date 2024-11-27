#pragma once
#include <cxxtest/TestSuite.h>
#include <fstream>
#include <string>
#include <complex>
#include "../pointers/shared_weak_ptr.hpp"
#define EPSILON 0.00000001


class WeakTest : public CxxTest::TestSuite
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
                SharedPtr<int> sharedPtr(new int(num));
                WeakPtr<int> weakPtr(sharedPtr);
                TS_ASSERT_EQUALS(*(weakPtr.lock()), num);
                TS_ASSERT_EQUALS(weakPtr.getSharedCount(), 1UL);
                TS_ASSERT_EQUALS(weakPtr.getWeakCount(), 1UL);
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
                SharedPtr<double> sharedPtr(new double(num));
                WeakPtr<double> weakPtr(sharedPtr);
                TS_ASSERT(*(weakPtr.lock()) - num < EPSILON);
                TS_ASSERT_EQUALS(weakPtr.getSharedCount(), 1UL);
                TS_ASSERT_EQUALS(weakPtr.getWeakCount(), 1UL);
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
                SharedPtr<std::string> sharedPtr(new std::string(str));
                WeakPtr<std::string> weakPtr(sharedPtr);
                TS_ASSERT_EQUALS(*(weakPtr.lock()), str);
                TS_ASSERT_EQUALS(weakPtr.getSharedCount(), 1UL);
                TS_ASSERT_EQUALS(weakPtr.getWeakCount(), 1UL);
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
                SharedPtr<std::complex<int>> sharedPtr(new std::complex<int>(a, b));
                WeakPtr<std::complex<int>> weakPtr(sharedPtr);
                TS_ASSERT_EQUALS(weakPtr.lock()->real(), a);
                TS_ASSERT_EQUALS(weakPtr.lock()->imag(), b);
                TS_ASSERT_EQUALS(weakPtr.getSharedCount(), 1UL);
                TS_ASSERT_EQUALS(weakPtr.getWeakCount(), 1UL);
            }
        }
        in.close();
    }

    void testCreation5()
    {
        for (int i = 50; i < 200; ++i)
        {
            SharedPtr<char> sharedPtr(new char(i));
            WeakPtr<char> weakPtr(sharedPtr);
            TS_ASSERT_EQUALS(*(weakPtr.lock()), char(i));
            TS_ASSERT_EQUALS(weakPtr.getSharedCount(), 1UL);
            TS_ASSERT_EQUALS(weakPtr.getWeakCount(), 1UL);
        }
    }

    void testCopyConstructor1()
    {
        std::ifstream in("../test_data/int_data.txt");
        if (in.is_open())
        {
            for (int i = 0; i < 1000; ++i)
            {
                int num;
                in >> num;
                SharedPtr<int> sharedPtr1(new int(num));
                WeakPtr<int> weakPtr1(sharedPtr1);
                WeakPtr<int> weakPtr2(weakPtr1);
                TS_ASSERT_EQUALS(weakPtr1, weakPtr2);
                TS_ASSERT_EQUALS(sharedPtr1.getSharedCount(), 1UL);
                TS_ASSERT_EQUALS(sharedPtr1.getWeakCount(), 2UL);
            }
        }
        in.close();
    }

    void testCopyConstructor2()
    {
        SharedPtr<int> sharedPtr;
        WeakPtr<int> weakPtr1(sharedPtr);
        WeakPtr<int> weakPtr2(weakPtr1);
        TS_ASSERT_EQUALS(weakPtr1, weakPtr2);
        TS_ASSERT_EQUALS(weakPtr1.getSharedCount(), 0UL);
        TS_ASSERT_EQUALS(weakPtr1.getWeakCount(), 0UL);
        TS_ASSERT_EQUALS(weakPtr2.getSharedCount(), 0UL);
        TS_ASSERT_EQUALS(weakPtr2.getWeakCount(), 0UL);
    }

    void testCopyConstructor3()
    {
        std::ifstream in("../test_data/double_data.txt");
        if (in.is_open())
        {
            for (int i = 0; i < 1000; ++i)
            {
                double num;
                in >> num;
                SharedPtr<double> sharedPtr1(new double(num));
                WeakPtr<double> weakPtr1(sharedPtr1);
                WeakPtr<double> weakPtr2(weakPtr1);
                WeakPtr<double> weakPtr3(weakPtr2);
                TS_ASSERT_EQUALS(weakPtr1, weakPtr2);
                TS_ASSERT_EQUALS(weakPtr1, weakPtr3);
                TS_ASSERT_EQUALS(sharedPtr1.getSharedCount(), 1UL);
                TS_ASSERT_EQUALS(sharedPtr1.getWeakCount(), 3UL);
            }
        }
        in.close();
    }

    void testMemoryRelease1()
    {
        std::ifstream in("../test_data/int_data.txt");
        if (in.is_open())
        {
            for (int i = 0; i < 1000; ++i)
            {
                int num;
                in >> num;
                SharedPtr<int> sharedPtr(new int(num));
                {
                    WeakPtr<int> weakPtr(sharedPtr);
                    TS_ASSERT_EQUALS(sharedPtr, weakPtr);
                    TS_ASSERT_EQUALS(weakPtr.getSharedCount(), 1UL);
                    TS_ASSERT_EQUALS(weakPtr.getWeakCount(), 1UL);
                }
                TS_ASSERT_EQUALS(*sharedPtr, num);
                TS_ASSERT_EQUALS(sharedPtr.getSharedCount(), 1UL);
                TS_ASSERT_EQUALS(sharedPtr.getWeakCount(), 0UL);
            }
        }
        in.close();
    }

    void testMemoryRelease2()
    {
        std::ifstream in("../test_data/double_data.txt");
        if (in.is_open())
        {
            for (int i = 0; i < 1000; ++i)
            {
                double num;
                in >> num;
                SharedPtr<double> sharedPtr(new double(num));
                {
                    WeakPtr<double> weakPtr(sharedPtr);
                    TS_ASSERT_EQUALS(sharedPtr, weakPtr);
                    TS_ASSERT_EQUALS(weakPtr.getSharedCount(), 1UL);
                    TS_ASSERT_EQUALS(weakPtr.getWeakCount(), 1UL);
                }
                TS_ASSERT(*sharedPtr - num < EPSILON);
                TS_ASSERT_EQUALS(sharedPtr.getSharedCount(), 1UL);
                TS_ASSERT_EQUALS(sharedPtr.getWeakCount(), 0UL);
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
                SharedPtr<int> sharedPtr(new int(num));
                WeakPtr<int> weakPtr(sharedPtr);
                TS_ASSERT(weakPtr == sharedPtr);
                TS_ASSERT_EQUALS(sharedPtr.getSharedCount(), 1UL);
                TS_ASSERT_EQUALS(sharedPtr.getWeakCount(), 1UL);
            }
        }
        in.close();
    }

    void testRelativeOperator2()
    {
        std::ifstream in("../test_data/int_data.txt");
        if (in.is_open())
        {
            for (int i = 0; i < 1000; ++i)
            {
                int num;
                in >> num;
                SharedPtr<int> sharedPtr1(new int(num));
                SharedPtr<int> sharedPtr2(new int(num + 1));
                WeakPtr<int> weakPtr(sharedPtr1);
                TS_ASSERT(weakPtr != sharedPtr2);
                TS_ASSERT_EQUALS(weakPtr.getSharedCount(), 1UL);
                TS_ASSERT_EQUALS(weakPtr.getWeakCount(), 1UL);
            }
        }
        in.close();
    }

    void testRelativeOperator3()
    {
        std::ifstream in("../test_data/string_data.txt");
        if (in.is_open())
        {
            for (int i = 0; i < 500; ++i)
            {
                std::string str1, str2;
                in >> str1 >> str2;
                SharedPtr<std::string> sharedPtr1(new std::string(str1));
                SharedPtr<std::string> sharedPtr2(new std::string(str2));
                WeakPtr<std::string> weakPtr(sharedPtr1);
                TS_ASSERT(weakPtr != sharedPtr2);
                TS_ASSERT_EQUALS(weakPtr.getSharedCount(), 1UL);
                TS_ASSERT_EQUALS(weakPtr.getWeakCount(), 1UL);
            }
        }
        in.close();
    }

    void testRelativeOperator4()
    {
        std::ifstream in("../test_data/int_data.txt");
        if (in.is_open())
        {
            for (int i = 0; i < 250; ++i)
            {
                int a1, b1, a2, b2;
                in >> a1 >> b1 >> a2 >> b2;
                SharedPtr<std::complex<int>> sharedPtr1(new std::complex<int>(a1, b1));
                SharedPtr<std::complex<int>> sharedPtr2(new std::complex<int>(a2, b2));
                WeakPtr<std::complex<int>> weakPtr(sharedPtr1);
                TS_ASSERT(weakPtr != sharedPtr2);
                TS_ASSERT_EQUALS(weakPtr.getSharedCount(), 1UL);
                TS_ASSERT_EQUALS(weakPtr.getWeakCount(), 1UL);
            }
        }
        in.close();
    }

    void testRelativeOperator5()
    {
        std::ifstream in("../test_data/double_data.txt");
        if (in.is_open())
        {
            for (int i = 0; i < 500; ++i)
            {
                double num1, num2;
                in >> num1 >> num2;
                SharedPtr<double> sharedPtr1(new double(num1));
                SharedPtr<double> sharedPtr2(new double(num2));
                WeakPtr<double> weakPtr(sharedPtr1);
                TS_ASSERT(weakPtr != sharedPtr2);
                TS_ASSERT_EQUALS(weakPtr.getSharedCount(), 1UL);
                TS_ASSERT_EQUALS(weakPtr.getWeakCount(), 1UL);
            }
        }
        in.close();
    }

    void testRelativeOperator6()
    {
        std::ifstream in("../test_data/int_data.txt");
        if (in.is_open())
        {
            for (int i = 0; i < 500; ++i)
            {
                int num1, num2;
                in >> num1 >> num2;
                SharedPtr<int> sharedPtr1(new int(num1));
                SharedPtr<int> sharedPtr2(new int(num2));
                WeakPtr<int> weakPtr(sharedPtr1);
                TS_ASSERT(weakPtr != sharedPtr2);
                TS_ASSERT_EQUALS(weakPtr.getSharedCount(), 1UL);
                TS_ASSERT_EQUALS(weakPtr.getWeakCount(), 1UL);
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
                SharedPtr<int> sharedPtr(new int(num));
                WeakPtr<int> weakPtr(sharedPtr);
                TS_ASSERT_THROWS_NOTHING(*(weakPtr.lock()));
                TS_ASSERT_EQUALS(weakPtr.getSharedCount(), 1UL);
                TS_ASSERT_EQUALS(weakPtr.getWeakCount(), 1UL);
            }
        }
        in.close();
    }

    void testAccessOperator2()
    {
        WeakPtr<int> weakPtr(nullptr);
        TS_ASSERT_THROWS_ANYTHING(*(weakPtr.lock()));
        TS_ASSERT_EQUALS(weakPtr.getSharedCount(), 0UL);
        TS_ASSERT_EQUALS(weakPtr.getWeakCount(), 0UL);
    }
};