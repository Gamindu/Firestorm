////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  /!\ libMirror Tests /!\
//
//  These are the test cases for libMirror, the reflection utility library.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <libCore/libCore.h>
#include <libHarnessed/libHarnessed.h>

#include <libMirror/libMirror.h>
#include <libMirror/Object.h>

class TestBasicObject : public Elf::Mirror::Object
{
	MIRROR_DECLARE(TestBasicObject, Elf::Mirror::Object);
public:
	TestBasicObject() {}
	virtual ~TestBasicObject()
	{
		std::cout << "TestBasicObject::~TestBasicObject" << std::endl;
	}
private:
};

class TestObjectWithFields : public Elf::Mirror::Object
{
	MIRROR_DECLARE(TestObjectWithFields, Elf::Mirror::Object);
public:
	TestObjectWithFields() {}
	virtual ~TestObjectWithFields() 
	{
		std::cout << "TestObjectWithFields::~TestObjectWithFields" << std::endl;
	}

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
	Elf::TestHarness h("Test libMirror");

	h.It("should allow instantiation of TestBasicObject", [](Elf::TestCase& t) {
		try
		{
			std::shared_ptr<TestBasicObject> test(new TestBasicObject);
		}
		catch(...)
		{
			t.Assert(false, "Allocation error or some other kind of error detected.");
		}
	});

	h.It("TestBasicObject::MyType() should return the same type as instance->GetType()", [](Elf::TestCase& t) {
		//try
		//{
		Elf::Mirror::Type tboStaticType = TestBasicObject::MyType();

		std::shared_ptr<TestBasicObject> tbo(new TestBasicObject);
		t.Assert(tbo->GetType() == tboStaticType, "The two types were not the same.");
		/*}
		catch(...)
		{
			t.Assert(false, "Error caught.");
		}*/
	});

	uint32_t results = h.Run();

	std::cout << "Completed with " << results << " errors." << std::endl << std::endl;
	std::cout << "Press 'Enter' to close..." << std::endl;
	std::cin.get();

    return results;
}