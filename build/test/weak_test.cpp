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
bool suite_WeakTest_init = false;
#include "../../test/unit_test/weak_test.hpp"

static WeakTest suite_WeakTest;

static CxxTest::List Tests_WeakTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_WeakTest( "/home/viacheslav/projects/labs_C++/lab1_release/test/unit_test/weak_test.hpp", 10, "WeakTest", suite_WeakTest, Tests_WeakTest );

static class TestDescription_suite_WeakTest_testCreation1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_WeakTest_testCreation1() : CxxTest::RealTestDescription( Tests_WeakTest, suiteDescription_WeakTest, 13, "testCreation1" ) {}
 void runTest() { suite_WeakTest.testCreation1(); }
} testDescription_suite_WeakTest_testCreation1;

static class TestDescription_suite_WeakTest_testCreation2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_WeakTest_testCreation2() : CxxTest::RealTestDescription( Tests_WeakTest, suiteDescription_WeakTest, 32, "testCreation2" ) {}
 void runTest() { suite_WeakTest.testCreation2(); }
} testDescription_suite_WeakTest_testCreation2;

static class TestDescription_suite_WeakTest_testCreation3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_WeakTest_testCreation3() : CxxTest::RealTestDescription( Tests_WeakTest, suiteDescription_WeakTest, 51, "testCreation3" ) {}
 void runTest() { suite_WeakTest.testCreation3(); }
} testDescription_suite_WeakTest_testCreation3;

static class TestDescription_suite_WeakTest_testCreation4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_WeakTest_testCreation4() : CxxTest::RealTestDescription( Tests_WeakTest, suiteDescription_WeakTest, 70, "testCreation4" ) {}
 void runTest() { suite_WeakTest.testCreation4(); }
} testDescription_suite_WeakTest_testCreation4;

static class TestDescription_suite_WeakTest_testCreation5 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_WeakTest_testCreation5() : CxxTest::RealTestDescription( Tests_WeakTest, suiteDescription_WeakTest, 90, "testCreation5" ) {}
 void runTest() { suite_WeakTest.testCreation5(); }
} testDescription_suite_WeakTest_testCreation5;

static class TestDescription_suite_WeakTest_testCopyConstructor1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_WeakTest_testCopyConstructor1() : CxxTest::RealTestDescription( Tests_WeakTest, suiteDescription_WeakTest, 102, "testCopyConstructor1" ) {}
 void runTest() { suite_WeakTest.testCopyConstructor1(); }
} testDescription_suite_WeakTest_testCopyConstructor1;

static class TestDescription_suite_WeakTest_testCopyConstructor2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_WeakTest_testCopyConstructor2() : CxxTest::RealTestDescription( Tests_WeakTest, suiteDescription_WeakTest, 122, "testCopyConstructor2" ) {}
 void runTest() { suite_WeakTest.testCopyConstructor2(); }
} testDescription_suite_WeakTest_testCopyConstructor2;

static class TestDescription_suite_WeakTest_testCopyConstructor3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_WeakTest_testCopyConstructor3() : CxxTest::RealTestDescription( Tests_WeakTest, suiteDescription_WeakTest, 134, "testCopyConstructor3" ) {}
 void runTest() { suite_WeakTest.testCopyConstructor3(); }
} testDescription_suite_WeakTest_testCopyConstructor3;

static class TestDescription_suite_WeakTest_testMemoryRelease1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_WeakTest_testMemoryRelease1() : CxxTest::RealTestDescription( Tests_WeakTest, suiteDescription_WeakTest, 156, "testMemoryRelease1" ) {}
 void runTest() { suite_WeakTest.testMemoryRelease1(); }
} testDescription_suite_WeakTest_testMemoryRelease1;

static class TestDescription_suite_WeakTest_testMemoryRelease2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_WeakTest_testMemoryRelease2() : CxxTest::RealTestDescription( Tests_WeakTest, suiteDescription_WeakTest, 180, "testMemoryRelease2" ) {}
 void runTest() { suite_WeakTest.testMemoryRelease2(); }
} testDescription_suite_WeakTest_testMemoryRelease2;

static class TestDescription_suite_WeakTest_testRelativeOperator1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_WeakTest_testRelativeOperator1() : CxxTest::RealTestDescription( Tests_WeakTest, suiteDescription_WeakTest, 204, "testRelativeOperator1" ) {}
 void runTest() { suite_WeakTest.testRelativeOperator1(); }
} testDescription_suite_WeakTest_testRelativeOperator1;

static class TestDescription_suite_WeakTest_testRelativeOperator2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_WeakTest_testRelativeOperator2() : CxxTest::RealTestDescription( Tests_WeakTest, suiteDescription_WeakTest, 223, "testRelativeOperator2" ) {}
 void runTest() { suite_WeakTest.testRelativeOperator2(); }
} testDescription_suite_WeakTest_testRelativeOperator2;

static class TestDescription_suite_WeakTest_testRelativeOperator3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_WeakTest_testRelativeOperator3() : CxxTest::RealTestDescription( Tests_WeakTest, suiteDescription_WeakTest, 243, "testRelativeOperator3" ) {}
 void runTest() { suite_WeakTest.testRelativeOperator3(); }
} testDescription_suite_WeakTest_testRelativeOperator3;

static class TestDescription_suite_WeakTest_testRelativeOperator4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_WeakTest_testRelativeOperator4() : CxxTest::RealTestDescription( Tests_WeakTest, suiteDescription_WeakTest, 263, "testRelativeOperator4" ) {}
 void runTest() { suite_WeakTest.testRelativeOperator4(); }
} testDescription_suite_WeakTest_testRelativeOperator4;

static class TestDescription_suite_WeakTest_testRelativeOperator5 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_WeakTest_testRelativeOperator5() : CxxTest::RealTestDescription( Tests_WeakTest, suiteDescription_WeakTest, 283, "testRelativeOperator5" ) {}
 void runTest() { suite_WeakTest.testRelativeOperator5(); }
} testDescription_suite_WeakTest_testRelativeOperator5;

static class TestDescription_suite_WeakTest_testRelativeOperator6 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_WeakTest_testRelativeOperator6() : CxxTest::RealTestDescription( Tests_WeakTest, suiteDescription_WeakTest, 303, "testRelativeOperator6" ) {}
 void runTest() { suite_WeakTest.testRelativeOperator6(); }
} testDescription_suite_WeakTest_testRelativeOperator6;

static class TestDescription_suite_WeakTest_testAccessOperator1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_WeakTest_testAccessOperator1() : CxxTest::RealTestDescription( Tests_WeakTest, suiteDescription_WeakTest, 323, "testAccessOperator1" ) {}
 void runTest() { suite_WeakTest.testAccessOperator1(); }
} testDescription_suite_WeakTest_testAccessOperator1;

static class TestDescription_suite_WeakTest_testAccessOperator2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_WeakTest_testAccessOperator2() : CxxTest::RealTestDescription( Tests_WeakTest, suiteDescription_WeakTest, 342, "testAccessOperator2" ) {}
 void runTest() { suite_WeakTest.testAccessOperator2(); }
} testDescription_suite_WeakTest_testAccessOperator2;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
