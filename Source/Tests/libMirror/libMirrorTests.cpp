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
#include <libCore/RefPtr.h>

#include <libMirror/libMirror.h>
#include <libMirror/Object.h>
#include <libMirror/SerialTraits.h>
#include <libMirror/EventDispatcher.h>

#include <rttr/registration.h>
#include <rttr/registration_friend.h>

using namespace Elf;

class TestBasicObject : public Mirror::Object
{
	ELF_MIRROR_DECLARE(TestBasicObject, Mirror::Object);
private:
public:
	TestBasicObject() {}
	virtual ~TestBasicObject()
	{
		std::cout << "TestBasicObject::~TestBasicObject" << std::endl;
	}
private:
};

class TestObjectWithFields : public Mirror::Object
{
	ELF_MIRROR_DECLARE(TestObjectWithFields, Mirror::Object);
public:
	TestObjectWithFields() {}
	explicit TestObjectWithFields(const String& str) : testString(str) {}
	virtual ~TestObjectWithFields() 
	{
		std::cout << "TestObjectWithFields::~TestObjectWithFields" << std::endl;
	}

	String testString;
private:
};



struct TestEvent
{
	ELF_MIRROR_DECLARE(TestEvent);
public:
	TestEvent(Elf::String s) : Message(s) {}
	String Message;
};
ELF_MIRROR_DEFINE(TestEvent)
{
	Property("Message", &TestEvent::Message);
}

class TestEventObject
{
public:
	void DoRegistration(EventDispatcher& dispatcher)
	{
		using namespace std::placeholders;
		Function<void(const TestEvent&)> func(std::bind(&TestEventObject::Invoke, this, _1));
		_receipt = dispatcher.Register<TestEvent>(&TestEventObject::Invoke, this);
	}

	void Invoke(const TestEvent& arg) const
	{
		std::cout << "TestEventObject says '" << arg.Message << "'." << std::endl;
	}
private:
	Elf::RefPtr<Elf::EDReceipt> _receipt;
};

RTTR_REGISTRATION
{
	Mirror::Registration::class_<TestBasicObject>("TestBasicObject");

	Mirror::Registration::class_<TestObjectWithFields>("TestObjectWithFields")
		.property("testString", &TestObjectWithFields::testString)
	;
}

/*template<class T1, class T2>
void TestTypeUtils(T1 obj1, T2 obj2, TestCase& t)
{
	Mirror::Type t1 = Mirror::TypeUtils::get(obj1);
	Mirror::Type t2 = Mirror::TypeUtils::get(obj2);

	t.Assert(t1 == t2, "The types do not match.");
}*/

int main(int argc, char** argv)
{
	Elf::TestHarness h("Test libMirror");

	Elf::libMirror::Initialize(argc, argv);

	h.It("TestBasicObject::MyType() should return the same type as instance->GetType()", [](Elf::TestCase& t) {
		Elf::Mirror::Type tboStaticType = TestBasicObject::MyType();

		Elf::RefPtr<TestBasicObject> tbo(new TestBasicObject());
		t.Assert(tbo->GetType() == tboStaticType, "The two types were not the same.");
	});

	h.It("the properties in an object instance should be retrievable when passing in a shared_ptr", [](Elf::TestCase& t) {
		using namespace rttr;

		std::string testStringValue("testing value!");
		Elf::RefPtr<Elf::Mirror::Object> test(new TestObjectWithFields(testStringValue));
		// test->testString = testStringValue;

		Elf::Result<void, Elf::Error> result;
		t.Assert(result.has_value(), "Elf::Result<void> does not contain a value...");

		instance objInstance(test);
		Elf::Mirror::Type testType = test->GetType();

		Mirror::Property testStringProperty = testType.get_property("testString");
		Mirror::Variant extractedValueVariant = testStringProperty.get_value(objInstance);

		t.Assert(extractedValueVariant.get_value<std::string>() == testStringValue, "testStringValue != extractedValueVariant");
	});


	h.It("the event dispatcher should allow the registration of events", [](Elf::TestCase& t) {
		std::unique_ptr<TestEventObject> object(std::make_unique<TestEventObject>());
		Elf::EventDispatcher dispatcher;
		//object->DoRegistration(dispatcher);
		Elf::EventDispatcher::Receipt receipt = dispatcher.Register<TestEvent>([](const TestEvent& str){
			std::cout << "TEST EVENT: " << str.Message << std::endl <<std::flush;
		});

		TestEventObject o;
		Elf::EventDispatcher::Receipt objReceipt = dispatcher.Register<TestEvent>(&TestEventObject::Invoke, &o);

		t.Assert(dispatcher.GetNumRegisteredEvents() == 2, "There was an incorrect number of registered events.");

		dispatcher.Dispatch(TestEvent("Hello test suite!"));
	});

	h.It("the event dispatcher should unregister when receipts fall out of scope", [](Elf::TestCase& t) {
		std::unique_ptr<TestEventObject> object(std::make_unique<TestEventObject>());
		Elf::EventDispatcher dispatcher;

		{
			Elf::EventDispatcher::Receipt receipt = dispatcher.Register<TestEvent>([](const TestEvent& str) {
				std::cout << "TEST EVENT: " << str.Message << std::endl << std::flush;
			});
			t.Assert(dispatcher.GetNumRegisteredEvents() == 1, "There was an incorrect number of registered events.");
			t.Assert(dispatcher.GetNumRegisteredReceipts() == 1, "There was an incorrect number of registered receipts.");
			dispatcher.Dispatch(TestEvent("Hello test suite!"));
		}
		t.Assert(dispatcher.GetNumRegisteredEvents() == 0, "There was an incorrect number of registered events.");
		t.Assert(dispatcher.GetNumRegisteredReceipts() == 0, "There was an incorrect number of registered receipts.");
	});

	uint32_t results = h.Run();

	std::cout << "Completed with " << results << " errors." << std::endl << std::endl;
	std::cout << "Press 'Enter' to close..." << std::endl;
	std::cin.get();

    return results;
}