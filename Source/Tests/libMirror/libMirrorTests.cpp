////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  /!\ libMirror Tests /!\
//
//  These are the test cases for libMirror, the reflection utility library.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <libCore.h>
#include <libHarnessed.h>

#include <libMirror.h>
#include <libMirror/Object.h>

class TestBasicObject : public Elf::Mirror::Object
{
	RTTR_ENABLE(Elf::Mirror::Object);
public:
	TestBasicObject() {}
	virtual ~TestBasicObject() {}
private:
};

class TestObjectWithFields : public Elf::Mirror::Object
{
	RTTR_ENABLE(Elf::Mirror::Object);
public:
	TestObjectWithFields() {}
	virtual ~TestObjectWithFields() {}

	std::string testString;
private:
};

RTTR_REGISTRATION
{
	Elf::Mirror::Registration::class_<TestBasicObject>("TestBasicObject");

	Elf::Mirror::Registration::class_<TestObjectWithFields>("TestObjectWithFields")
		.property("testString", &TestObjectWithFields::testString)
	;
}

int main()
{
	Elf::TestHarness harness("Test libMirror");

	harness.It("should allow instantiation of TestBasicObject", [](Elf::TestCase& t) {
		try
		{
			std::shared_ptr<TestBasicObject> test(new TestBasicObject);
		}
		catch(...)
		{
			t.Assert(false, "Allocation error or some other kind of error detected.");
		}
	});

	uint32_t results = harness.Run();

	std::cout << "Completed with " << results << " errors." << std::endl << std::endl;
	std::cout << "Press 'Enter' to close..." << std::endl;
	std::cin.get();

    return results;
}