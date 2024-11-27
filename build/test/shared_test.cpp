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
bool suite_SharedTest_init = false;
#include "../../test/unit_test/shared_test.hpp"

static SharedTest suite_SharedTest;

static CxxTest::List Tests_SharedTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_SharedTest( "/home/viacheslav/projects/labs_C++/lab1_release/test/unit_test/shared_test.hpp", 10, "SharedTest", suite_SharedTest, Tests_SharedTest );

static class TestDescription_suite_SharedTest_testCreation1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SharedTest_testCreation1() : CxxTest::RealTestDescription( Tests_SharedTest, suiteDescription_SharedTest, 13, "testCreation1" ) {}
 void runTest() { suite_SharedTest.testCreation1(); }
} testDescription_suite_SharedTest_testCreation1;

static class TestDescription_suite_SharedTest_testCreation2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SharedTest_testCreation2() : CxxTest::RealTestDescription( Tests_SharedTest, suiteDescription_SharedTest, 30, "testCreation2" ) {}
 void runTest() { suite_SharedTest.testCreation2(); }
} testDescription_suite_SharedTest_testCreation2;

static class TestDescription_suite_SharedTest_testCreation3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SharedTest_testCreation3() : CxxTest::RealTestDescription( Tests_SharedTest, suiteDescription_SharedTest, 47, "testCreation3" ) {}
 void runTest() { suite_SharedTest.testCreation3(); }
} testDescription_suite_SharedTest_testCreation3;

static class TestDescription_suite_SharedTest_testCreation4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SharedTest_testCreation4() : CxxTest::RealTestDescription( Tests_SharedTest, suiteDescription_SharedTest, 64, "testCreation4" ) {}
 void runTest() { suite_SharedTest.testCreation4(); }
} testDescription_suite_SharedTest_testCreation4;

static class TestDescription_suite_SharedTest_testCreation5 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SharedTest_testCreation5() : CxxTest::RealTestDescription( Tests_SharedTest, suiteDescription_SharedTest, 82, "testCreation5" ) {}
 void runTest() { suite_SharedTest.testCreation5(); }
} testDescription_suite_SharedTest_testCreation5;

static class TestDescription_suite_SharedTest_testCopyConstructor1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SharedTest_testCopyConstructor1() : CxxTest::RealTestDescription( Tests_SharedTest, suiteDescription_SharedTest, 92, "testCopyConstructor1" ) {}
 void runTest() { suite_SharedTest.testCopyConstructor1(); }
} testDescription_suite_SharedTest_testCopyConstructor1;

static class TestDescription_suite_SharedTest_testCopyConstructor2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SharedTest_testCopyConstructor2() : CxxTest::RealTestDescription( Tests_SharedTest, suiteDescription_SharedTest, 111, "testCopyConstructor2" ) {}
 void runTest() { suite_SharedTest.testCopyConstructor2(); }
} testDescription_suite_SharedTest_testCopyConstructor2;

static class TestDescription_suite_SharedTest_testCopyConstructor3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SharedTest_testCopyConstructor3() : CxxTest::RealTestDescription( Tests_SharedTest, suiteDescription_SharedTest, 120, "testCopyConstructor3" ) {}
 void runTest() { suite_SharedTest.testCopyConstructor3(); }
} testDescription_suite_SharedTest_testCopyConstructor3;

static class TestDescription_suite_SharedTest_testMemoryRelease1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SharedTest_testMemoryRelease1() : CxxTest::RealTestDescription( Tests_SharedTest, suiteDescription_SharedTest, 142, "testMemoryRelease1" ) {}
 void runTest() { suite_SharedTest.testMemoryRelease1(); }
} testDescription_suite_SharedTest_testMemoryRelease1;

static class TestDescription_suite_SharedTest_testMemoryRelease2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SharedTest_testMemoryRelease2() : CxxTest::RealTestDescription( Tests_SharedTest, suiteDescription_SharedTest, 165, "testMemoryRelease2" ) {}
 void runTest() { suite_SharedTest.testMemoryRelease2(); }
} testDescription_suite_SharedTest_testMemoryRelease2;

static class TestDescription_suite_SharedTest_testRelativeOperator1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SharedTest_testRelativeOperator1() : CxxTest::RealTestDescription( Tests_SharedTest, suiteDescription_SharedTest, 188, "testRelativeOperator1" ) {}
 void runTest() { suite_SharedTest.testRelativeOperator1(); }
} testDescription_suite_SharedTest_testRelativeOperator1;

static class TestDescription_suite_SharedTest_testRelativeOperator2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SharedTest_testRelativeOperator2() : CxxTest::RealTestDescription( Tests_SharedTest, suiteDescription_SharedTest, 207, "testRelativeOperator2" ) {}
 void runTest() { suite_SharedTest.testRelativeOperator2(); }
} testDescription_suite_SharedTest_testRelativeOperator2;

static class TestDescription_suite_SharedTest_testRelativeOperator3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SharedTest_testRelativeOperator3() : CxxTest::RealTestDescription( Tests_SharedTest, suiteDescription_SharedTest, 225, "testRelativeOperator3" ) {}
 void runTest() { suite_SharedTest.testRelativeOperator3(); }
} testDescription_suite_SharedTest_testRelativeOperator3;

static class TestDescription_suite_SharedTest_testRelativeOperator4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SharedTest_testRelativeOperator4() : CxxTest::RealTestDescription( Tests_SharedTest, suiteDescription_SharedTest, 243, "testRelativeOperator4" ) {}
 void runTest() { suite_SharedTest.testRelativeOperator4(); }
} testDescription_suite_SharedTest_testRelativeOperator4;

static class TestDescription_suite_SharedTest_testRelativeOperator5 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SharedTest_testRelativeOperator5() : CxxTest::RealTestDescription( Tests_SharedTest, suiteDescription_SharedTest, 263, "testRelativeOperator5" ) {}
 void runTest() { suite_SharedTest.testRelativeOperator5(); }
} testDescription_suite_SharedTest_testRelativeOperator5;

static class TestDescription_suite_SharedTest_testRelativeOperator6 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SharedTest_testRelativeOperator6() : CxxTest::RealTestDescription( Tests_SharedTest, suiteDescription_SharedTest, 270, "testRelativeOperator6" ) {}
 void runTest() { suite_SharedTest.testRelativeOperator6(); }
} testDescription_suite_SharedTest_testRelativeOperator6;

static class TestDescription_suite_SharedTest_testAccessOperator1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SharedTest_testAccessOperator1() : CxxTest::RealTestDescription( Tests_SharedTest, suiteDescription_SharedTest, 286, "testAccessOperator1" ) {}
 void runTest() { suite_SharedTest.testAccessOperator1(); }
} testDescription_suite_SharedTest_testAccessOperator1;

static class TestDescription_suite_SharedTest_testAccessOperator2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_SharedTest_testAccessOperator2() : CxxTest::RealTestDescription( Tests_SharedTest, suiteDescription_SharedTest, 302, "testAccessOperator2" ) {}
 void runTest() { suite_SharedTest.testAccessOperator2(); }
} testDescription_suite_SharedTest_testAccessOperator2;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
