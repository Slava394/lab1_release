#pragma once
#include <cxxtest/TestSuite.h>
#include <fstream>
#include <string>
#include <complex>
#include "../pointers/shared_weak_ptr.hpp"
#define EPSILON 0.00000001


class SharedTest : public CxxTest::TestSuite
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
                TS_ASSERT_EQUALS(*sharedPtr, num);
                TS_ASSERT_EQUALS(sharedPtr.getSharedCount(), 1UL);
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
                TS_ASSERT(*sharedPtr - num < EPSILON);
                TS_ASSERT_EQUALS(sharedPtr.getSharedCount(), 1UL);
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
                TS_ASSERT_EQUALS(*sharedPtr, str);
                TS_ASSERT_EQUALS(sharedPtr.getSharedCount(), 1UL);
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
                TS_ASSERT_EQUALS(sharedPtr->real(), a);
                TS_ASSERT_EQUALS(sharedPtr->imag(), b);
                TS_ASSERT_EQUALS(sharedPtr.getSharedCount(), 1UL);
            }
        }
        in.close();
    }

    void testCreation5()
    {
        for (int i = 50; i < 200; ++i)
        {
            SharedPtr<char> sharedPtr(new char(i));
            TS_ASSERT_EQUALS(*sharedPtr, char(i));
            TS_ASSERT_EQUALS(sharedPtr.getSharedCount(), 1UL);
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
                SharedPtr<int> sharedPtr2(sharedPtr1);
                TS_ASSERT_EQUALS(sharedPtr1, sharedPtr2);
                TS_ASSERT_EQUALS(sharedPtr1.getSharedCount(), 2UL);
                TS_ASSERT_EQUALS(sharedPtr2.getSharedCount(), 2UL);
            }
        }
        in.close();
    }

    void testCopyConstructor2()
    {
        SharedPtr<int> sharedPtr1;
        SharedPtr<int> sharedPtr2(sharedPtr1);
        TS_ASSERT_EQUALS(sharedPtr1, sharedPtr2);
        TS_ASSERT_EQUALS(sharedPtr1.getSharedCount(), 0UL);   
        TS_ASSERT_EQUALS(sharedPtr2.getSharedCount(), 0UL);
    }

    void testCopyConstructor3()
    {
        std::ifstream in("../test_data/int_data.txt");
        if (in.is_open())
        {
            for (int i = 0; i < 1000; ++i)
            {
                int num;
                in >> num;
                SharedPtr<int> sharedPtr1(new int(num));
                SharedPtr<int> sharedPtr2(sharedPtr1);
                SharedPtr<int> sharedPtr3(sharedPtr2);
                TS_ASSERT_EQUALS(sharedPtr1, sharedPtr3);
                TS_ASSERT_EQUALS(sharedPtr2, sharedPtr3);
                TS_ASSERT_EQUALS(sharedPtr1.getSharedCount(), 3UL);
                TS_ASSERT_EQUALS(sharedPtr2.getSharedCount(), 3UL);
                TS_ASSERT_EQUALS(sharedPtr3.getSharedCount(), 3UL);
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
                SharedPtr<int> sharedPtr1(new int(num));
                {
                    SharedPtr<int> sharedPtr2(sharedPtr1);
                    TS_ASSERT_EQUALS(sharedPtr1, sharedPtr2);
                    TS_ASSERT_EQUALS(sharedPtr1.getSharedCount(), 2UL);
                    TS_ASSERT_EQUALS(sharedPtr2.getSharedCount(), 2UL);
                }
                TS_ASSERT_EQUALS(*sharedPtr1, num);
                TS_ASSERT_EQUALS(sharedPtr1.getSharedCount(), 1UL);
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
                SharedPtr<double> sharedPtr1(new double(num));
                {
                    SharedPtr<double> sharedPtr2(sharedPtr1);
                    TS_ASSERT_EQUALS(sharedPtr1, sharedPtr2);
                    TS_ASSERT_EQUALS(sharedPtr1.getSharedCount(), 2UL);
                    TS_ASSERT_EQUALS(sharedPtr2.getSharedCount(), 2UL);
                }
                TS_ASSERT(*sharedPtr1 - num < EPSILON);
                TS_ASSERT_EQUALS(sharedPtr1.getSharedCount(), 1UL);
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
                SharedPtr<int> sharedPtr1(new int(num));
                SharedPtr<int> sharedPtr2(sharedPtr1);
                TS_ASSERT(sharedPtr1 == sharedPtr2);
                TS_ASSERT_EQUALS(sharedPtr1.getSharedCount(), 2UL);
                TS_ASSERT_EQUALS(sharedPtr2.getSharedCount(), 2UL);
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
                TS_ASSERT(sharedPtr1 != sharedPtr2);
                TS_ASSERT_EQUALS(sharedPtr1.getSharedCount(), 1UL);
                TS_ASSERT_EQUALS(sharedPtr2.getSharedCount(), 1UL);
            }
        }
    }

    void testRelativeOperator3()
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
                TS_ASSERT(sharedPtr1 == weakPtr1);
                TS_ASSERT_EQUALS(sharedPtr1.getSharedCount(), 1UL);
                TS_ASSERT_EQUALS(sharedPtr1.getWeakCount(), 1UL);
            }
        }
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
                SharedPtr<int> sharedPtr1(new int(num));
                SharedPtr<int> sharedPtr2(new int(num + 1));
                WeakPtr<int> weakPtr1(sharedPtr1);
                TS_ASSERT(sharedPtr2 != weakPtr1);
                TS_ASSERT_EQUALS(sharedPtr1.getSharedCount(), 1UL);
                TS_ASSERT_EQUALS(sharedPtr1.getWeakCount(), 1UL);
                TS_ASSERT_EQUALS(sharedPtr2.getSharedCount(), 1UL);
            }
        }
    }

    void testRelativeOperator5()
    {
        SharedPtr<int> sharedPtr(nullptr);
        TS_ASSERT(sharedPtr == nullptr);
        TS_ASSERT_EQUALS(sharedPtr.getSharedCount(), 0UL);
    }

    void testRelativeOperator6()
    {
        std::ifstream in("../test_data/int_data.txt");
        if (in.is_open())
        {
            for (int i = 0; i < 1000; ++i)
            {
                int num;
                in >> num;
                SharedPtr<int> sharedPtr(new int(num));
                TS_ASSERT(sharedPtr != nullptr);
                TS_ASSERT_EQUALS(sharedPtr.getSharedCount(), 1UL);
            }
        }
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
                TS_ASSERT_THROWS_NOTHING(*sharedPtr);
                TS_ASSERT_EQUALS(sharedPtr.getSharedCount(), 1UL);
            }
        }
    }

    void testAccessOperator2()
    {
        SharedPtr<int> sharedPtr;
        TS_ASSERT_THROWS_ANYTHING(*sharedPtr);
        TS_ASSERT_EQUALS(sharedPtr.getSharedCount(), 0UL);
    }
};