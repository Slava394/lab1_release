/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_UniqueTest_init = false;
#include "../../test/unit_test/unique_test.hpp"

static UniqueTest suite_UniqueTest;

static CxxTest::List Tests_UniqueTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_UniqueTest( "/home/viacheslav/projects/labs_C++/lab1_release/test/unit_test/unique_test.hpp", 10, "UniqueTest", suite_UniqueTest, Tests_UniqueTest );

static class TestDescription_suite_UniqueTest_testCreation1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_UniqueTest_testCreation1() : CxxTest::RealTestDescription( Tests_UniqueTest, suiteDescription_UniqueTest, 13, "testCreation1" ) {}
 void runTest() { suite_UniqueTest.testCreation1(); }
} testDescription_suite_UniqueTest_testCreation1;

static class TestDescription_suite_UniqueTest_testCreation2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_UniqueTest_testCreation2() : CxxTest::RealTestDescription( Tests_UniqueTest, suiteDescription_UniqueTest, 30, "testCreation2" ) {}
 void runTest() { suite_UniqueTest.testCreation2(); }
} testDescription_suite_UniqueTest_testCreation2;

static class TestDescription_suite_UniqueTest_testCreation3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_UniqueTest_testCreation3() : CxxTest::RealTestDescription( Tests_UniqueTest, suiteDescription_UniqueTest, 47, "testCreation3" ) {}
 void runTest() { suite_UniqueTest.testCreation3(); }
} testDescription_suite_UniqueTest_testCreation3;

static class TestDescription_suite_UniqueTest_testCreation4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_UniqueTest_testCreation4() : CxxTest::RealTestDescription( Tests_UniqueTest, suiteDescription_UniqueTest, 64, "testCreation4" ) {}
 void runTest() { suite_UniqueTest.testCreation4(); }
} testDescription_suite_UniqueTest_testCreation4;

static class TestDescription_suite_UniqueTest_testCreation5 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_UniqueTest_testCreation5() : CxxTest::RealTestDescription( Tests_UniqueTest, suiteDescription_UniqueTest, 82, "testCreation5" ) {}
 void runTest() { suite_UniqueTest.testCreation5(); }
} testDescription_suite_UniqueTest_testCreation5;

static class TestDescription_suite_UniqueTest_testMoveConstructor1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_UniqueTest_testMoveConstructor1() : CxxTest::RealTestDescription( Tests_UniqueTest, suiteDescription_UniqueTest, 92, "testMoveConstructor1" ) {}
 void runTest() { suite_UniqueTest.testMoveConstructor1(); }
} testDescription_suite_UniqueTest_testMoveConstructor1;

static class TestDescription_suite_UniqueTest_testMoveConstructor2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_UniqueTest_testMoveConstructor2() : CxxTest::RealTestDescription( Tests_UniqueTest, suiteDescription_UniqueTest, 111, "testMoveConstructor2" ) {}
 void runTest() { suite_UniqueTest.testMoveConstructor2(); }
} testDescription_suite_UniqueTest_testMoveConstructor2;

static class TestDescription_suite_UniqueTest_testMoveConstructor3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_UniqueTest_testMoveConstructor3() : CxxTest::RealTestDescription( Tests_UniqueTest, suiteDescription_UniqueTest, 119, "testMoveConstructor3" ) {}
 void runTest() { suite_UniqueTest.testMoveConstructor3(); }
} testDescription_suite_UniqueTest_testMoveConstructor3;

static class TestDescription_suite_UniqueTest_testRelativeOperator1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_UniqueTest_testRelativeOperator1() : CxxTest::RealTestDescription( Tests_UniqueTest, suiteDescription_UniqueTest, 140, "testRelativeOperator1" ) {}
 void runTest() { suite_UniqueTest.testRelativeOperator1(); }
} testDescription_suite_UniqueTest_testRelativeOperator1;

static class TestDescription_suite_UniqueTest_testRelativeOperator2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_UniqueTest_testRelativeOperator2() : CxxTest::RealTestDescription( Tests_UniqueTest, suiteDescription_UniqueTest, 156, "testRelativeOperator2" ) {}
 void runTest() { suite_UniqueTest.testRelativeOperator2(); }
} testDescription_suite_UniqueTest_testRelativeOperator2;

static class TestDescription_suite_UniqueTest_testRelativeOperator3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_UniqueTest_testRelativeOperator3() : CxxTest::RealTestDescription( Tests_UniqueTest, suiteDescription_UniqueTest, 173, "testRelativeOperator3" ) {}
 void runTest() { suite_UniqueTest.testRelativeOperator3(); }
} testDescription_suite_UniqueTest_testRelativeOperator3;

static class TestDescription_suite_UniqueTest_testRelativeOperator4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_UniqueTest_testRelativeOperator4() : CxxTest::RealTestDescription( Tests_UniqueTest, suiteDescription_UniqueTest, 181, "testRelativeOperator4" ) {}
 void runTest() { suite_UniqueTest.testRelativeOperator4(); }
} testDescription_suite_UniqueTest_testRelativeOperator4;

static class TestDescription_suite_UniqueTest_testAccessOperator1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_UniqueTest_testAccessOperator1() : CxxTest::RealTestDescription( Tests_UniqueTest, suiteDescription_UniqueTest, 199, "testAccessOperator1" ) {}
 void runTest() { suite_UniqueTest.testAccessOperator1(); }
} testDescription_suite_UniqueTest_testAccessOperator1;

static class TestDescription_suite_UniqueTest_testAccessOperator2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_UniqueTest_testAccessOperator2() : CxxTest::RealTestDescription( Tests_UniqueTest, suiteDescription_UniqueTest, 215, "testAccessOperator2" ) {}
 void runTest() { suite_UniqueTest.testAccessOperator2(); }
} testDescription_suite_UniqueTest_testAccessOperator2;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
