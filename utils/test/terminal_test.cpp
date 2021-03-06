#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>

#include <stdlib.h>

#include "utils/terminal.h"

// Namespaces.
using namespace CppUnit;
using namespace std;

//-----------------------------------------------------------------------------

class TestTerminal: public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(TestTerminal);
    CPPUNIT_TEST(testHello);
    CPPUNIT_TEST(testOutput);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void testHello(void);
    void testOutput(void);
private:
    // Our objects
};

//-----------------------------------------------------------------------------

void TestTerminal::testHello(void) {
    CPPUNIT_ASSERT(1 == 1);
}

void TestTerminal::setUp(void) {
    // setup code here
    return;
}

void TestTerminal::tearDown(void) {
    // cleanup code here
    return;
}

void TestTerminal::testOutput(void) {

    cout << utils::Terminal::LightBlue() << endl << "LightBlue" << utils::Terminal::Normal() << endl;
    cout << utils::Terminal::Brown() << "Brown" << utils::Terminal::Normal() << endl;
    cout << utils::Terminal::Cyan() << "Cyan" << utils::Terminal::Normal() << endl;
    cout << utils::Terminal::Pink() << "Pink" << utils::Terminal::Normal() << endl;
    cout << utils::Terminal::Green() << "Green" << utils::Terminal::Normal() << endl;
    return;
}

//-----------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION(TestTerminal);

//int main(int argc, char* argv[]) {
int main() {
    // informs test-listener about testresults
    CPPUNIT_NS::TestResult testresult;

    // register listener for collecting the test-results
    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener(&collectedresults);

    // register listener for per-test progress output
    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener(&progress);

    // insert test-suite at test-runner by registry
    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
    testrunner.run(testresult);

    // output results in compiler-format
    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write();

    // Output XML for Jenkins CPPunit plugin
    ofstream xmlFileOut("terminal_test.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    // NB: In the return code never return just 0!
    if (collectedresults.wasSuccessful()) {
        // return EXIT_SUCCESS if the tests were successful
        return EXIT_SUCCESS;
    } else {
        // return EXIT_FAILURE if the tests failed
        return EXIT_FAILURE;
    }
}
