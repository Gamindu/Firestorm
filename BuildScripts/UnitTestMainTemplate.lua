------------------------------------------------------------------------------------------------------------------------
--
--  UnitTestMainTemplate.lua
--
--  Contains the source code for the main entry point of the unit tester.
--
------------------------------------------------------------------------------------------------------------------------
--  Copyright (c) 2018 Miki Ryan
------------------------------------------------------------------------------------------------------------------------
UNIT_TEST_MAIN = [[
#include "stdafx.h"

{INCLUDES}

#include <libCore/RefPtr.h>
#include <libCore/LibraryRegistrar.h>
#include <libCore/Logger.h>

using namespace Firestorm;

{FWD_DECLARES}

int main(int ac, char** av)
{
    size_t overallFailureCount = 0;
{LIB_INITIALIZATIONS}

    vector<RefPtr<TestHarness>> TESTS = {
{TEST_FUNCTIONS}
    };


    try
    {
        for(RefPtr<TestHarness>& harness : TESTS)
        {
            size_t testResults = harness->Run();
            overallFailureCount += testResults;

            // report the results for this particular test.
            FIRE_LOG_DEBUG("");
            FIRE_LOG_DEBUG("Completed %s with %d errors...", harness->GetName(), testResults);
            FIRE_LOG_DEBUG("-----------------------------------------------------------------------------------------------------------");
        }

        if(overallFailureCount > 0)
        {
            FIRE_LOG_DEBUG("Completed all tests with %d errors.", overallFailureCount);
        }
        else
        {
            FIRE_LOG_DEBUG("Completed all tests with no failures!");
        }
        
        libCore::ReportMemoryLeaks();

        FIRE_LOG_DEBUG("Press 'return' to close...");
        std::cin.get();
    }
    catch(AssertionException& e)
    {
        FIRE_LOG_ERROR("!!!Uncaught exception!!! %s", e.Report());
    }
    TESTS.clear();

    return overallFailureCount;
}]]
