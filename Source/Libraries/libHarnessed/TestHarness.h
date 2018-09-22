///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  TestHarness.h
//
//  Abstract base class that holds a collection of TestCase instances.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) Project Elflord 2018
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef HARNESSED_TESTHARNESS_H_
#define HARNESSED_TESTHARNESS_H_
#pragma once

#include <libCore/Logger.h>

OPEN_NAMESPACE(Firestorm);

class TestCase;

class TestHarness
{
public:
	typedef Function<void(TestCase&)> TestFunction_t;

	TestHarness(const String& name, bool quietly = false);
	virtual ~TestHarness() {}

	// Run before every test case.
	virtual void Before() {}

	// Runs all of the test cases. Reports back the number of errors.
	uint32_t Run();

	// Inserts a test case. The name should be something descriptive and should be a
	// sentence that states what it should be doing.
	//
	// Example: It("should do this thing properly without errors", ...);
	void It(const String& name, TestFunction_t testFunction);

    const String& GetName() const { return m_name; }

	template <class... Args_t>
	void Print(const char* fmt, Args_t... args)
	{
		if(!m_quietly)
			FIRE_LOG_ERROR(fmt, args...);
	}

	void ReportError(TestCase* tc, const String& message);

private:
	String m_name;
	bool m_quietly;
	Vector<String>         m_caseNames;
	Vector<TestFunction_t> m_cases;
};

CLOSE_NAMESPACE(Firestorm);

#endif
