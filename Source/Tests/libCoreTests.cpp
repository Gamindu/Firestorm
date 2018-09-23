
#include <libCore/libCore.h>
#include <libCore/IRefCounted.h>
#include <libCore/RefPtr.h>
#include <libHarnessed/libHarnessed.h>
#include <functional>

using std::cout;
using std::cin;
using std::endl;

using namespace Firestorm;

struct TestObject : public IRefCounted
{
	TestObject(const Function<void()>& deletionCallback)
		: _callback(deletionCallback)
	{
	}
	virtual ~TestObject()
	{
		_callback();
	}
	Function<void()> _callback;
};

struct TestPolyObject : public TestObject
{
	TestPolyObject(const std::function<void()>& deletionCallback)
		: TestObject(deletionCallback)
	{
	}
};

RefPtr<TestHarness> libCorePrepareHarness(int argc, char** argv)
{
	RefPtr<TestHarness> h(new TestHarness("libCore Tests"));

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// RefPtr Testing
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	h->It("RefPtr should delete the object when it falls out of scope", [](TestCase& t) {
		bool objectDeleted = false;
		{
			auto callback = [&objectDeleted]() { objectDeleted = true; };
			RefPtr<TestObject> object(new TestObject(callback));
			auto count = object.GetCount();
			t.Assert(count == 1, "the ref count was not the expected value");
		}
		t.Assert(objectDeleted, "the object was not deleted");
	});

	h->It("RefPtr should use the deleter when one is provided", [](TestCase& t) {
		bool objectDeleted = false;
		bool deleterCalled = false;
		{
			auto callback = [&objectDeleted]() { objectDeleted = true; };
			RefPtr<TestObject> object(new TestObject(callback), [&deleterCalled](TestObject* ptr) {
				if(ptr)
					delete ptr;
				deleterCalled = true;
			});
			t.Assert(object.GetCount() == 1, "the ref count was not the expected value");
		}
		t.AssertIsTrue(objectDeleted, "the object was not deleted");
		t.AssertIsTrue(deleterCalled, "the deleter was not called");
	});

	h->It("RefPtr should use the deleter when one is provided, even when polymorphism is in play", [](TestCase& t) {
		bool objectDeleted = false;
		bool deleterCalled = false;
		{
			auto callback = [&objectDeleted]() { objectDeleted = true; };
			RefPtr<TestObject> object(new TestPolyObject(callback), [&deleterCalled](TestObject* ptr) {
				if (ptr)
					delete ptr;
				deleterCalled = true;
			});
			t.Assert(object.GetCount() == 1, "the ref count was not the expected value");
		}
		t.AssertIsTrue(objectDeleted, "the object was not deleted");
		t.AssertIsTrue(deleterCalled, "the deleter was not called");
	});

	h->It("RefPtr should use the deleter when one is provided, even when polymorphism is in play "
		  "and the base ptr was copy constructed", [](TestCase& t) {
			  {
				  bool objectDeleted = false;
				  bool deleterCalled = false;
				  {
					  auto callback = [&objectDeleted]() { objectDeleted = true; };
					  RefPtr<TestPolyObject> object(new TestPolyObject(callback), [&deleterCalled](TestPolyObject* ptr) {
						  if (ptr)
							  delete ptr;
						  deleterCalled = true;
					  });
					  t.Assert(object.GetCount() == 1, "the ref count was not the expected value");

					  {
						  // copy construct.
						  RefPtr<TestObject> testBaseObject(object);
						  t.Assert(object.GetCount() == 2, "the ref count was not the expected value");
						  t.Assert(testBaseObject.GetCount() == 2, "the ref count was not the expected value");
					  }
					  t.Assert(object.GetCount() == 1, "the ref count was not the expected value");
					  t.AssertIsFalse(deleterCalled, "the deleter was called prematurely");

					  RefPtr<TestObject> testBaseObject(object);
					  t.Assert(object.GetCount() == 2, "the ref count was not the expected value");
					  t.Assert(testBaseObject.GetCount() == 2, "the ref count was not the expected value");
				  }
				  t.AssertIsTrue(objectDeleted, "the object was not deleted");
				  t.AssertIsTrue(deleterCalled, "the deleter was not called");
			  }
			  {
				  bool objectDeleted = false;
				  bool deleterCalled = true;
				  {
					  auto callback = [&objectDeleted]() { objectDeleted = true; };
					  RefPtr<TestObject> ptrBase(new TestPolyObject(callback), [&deleterCalled](TestObject* ptr) {
						  if(ptr)
							  delete ptr;
						  deleterCalled = true;
					  });
				  }
				  t.AssertIsTrue(deleterCalled, "the deleter was not called on a polymorphic type");
			  }
	});

	h->It("weak pointers should not prolong the lifetime of objects managed by a shared ptr", [](TestCase& t) {
		bool objectDeleted = false;
		auto callback = [&objectDeleted]() { objectDeleted = true; };
		WeakPtr<TestObject> weak;
		{
			RefPtr<TestObject> object(new TestObject(callback));
			t.Assert(object.GetCount() == 1, "the ref count was not the expected value");
			weak = object;
			t.Assert(object.GetCount() == 1, "the ref count was not the expected value");
		}
		t.Assert(!weak, "the weak pointer still holds on to a valid object");
		t.Assert(objectDeleted, "the object was not deleted");
	});

	h->It("polymorphic types should be allowable by the RefPtr", [](TestCase& t) {
		bool objectDeleted = false;

		auto callback = [&objectDeleted]() { objectDeleted = true; };
		{
			RefPtr<TestObject> object(new TestPolyObject(callback));
			t.Assert(object.GetCount() == 1, "the ref count was not the expected value");
		}

		t.Assert(objectDeleted, "the object was not deleted");
	});

	h->It("weak pointers should also be allowed to hold polymorphic types", [](TestCase& t) {
		bool objectDeleted = false;
		auto callback = [&objectDeleted]() { objectDeleted = true; };
		WeakPtr<TestObject> weak;
		{

			RefPtr<TestPolyObject> object(new TestPolyObject(callback));
			t.Assert(object.GetCount() == 1, "the ref count was not the expected value");

			weak = object;

			t.Assert(object.GetCount() == 1, "the ref count was not the expected value");
		}
		t.Assert(!weak, "the weak pointer still holds on to a valid object");
		t.Assert(objectDeleted, "the object was not deleted");
	});

	return h;
}