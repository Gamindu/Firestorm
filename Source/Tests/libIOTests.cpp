////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  /!\ libIO Tests /!\
//
//  These are the test cases for libIO, the disk library.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <libCore/libCore.h>
#include <libCore/RefPtr.h>

#include <libHarnessed/libHarnessed.h>

#include <libMirror/libMirror.h>
#include <libMirror/Object.h>

#include <libIO/libIO.h>
#include <libIO/IDocument.h>
#include <libIO/Document.h>
#include <libIO/TypeTraits.h>
#include <libIO/Logger.h>
#include <libIO/ResourceMgr.h>

#include <libJson/libJson.h>

using namespace Firestorm;

#define FAIL_END(T, FUNC_CALL) \
{\
	Firestorm::Result<void, Firestorm::Error> err = document -> FUNC_CALL ; \
	T.Assert(err.has_value(), "error calling function "#FUNC_CALL": "+err.error().Message); \
}


class IO_TestBasicObject : public Firestorm::Mirror::Object
{
	FIRE_MIRROR_DECLARE(IO_TestBasicObject, Firestorm::Mirror::Object);
public:
	IO_TestBasicObject() {}
	virtual ~IO_TestBasicObject()
	{
		std::cout << "TestBasicObject::~TestBasicObject" << std::endl;
	}
private:
};

FIRE_MIRROR_DEFINE(IO_TestBasicObject)
{
}

RefPtr<TestHarness> libIOPrepareHarness(int argc, char** argv)
{
	IO_TestBasicObject::RegisterReflection();

	RefPtr<TestHarness> h(new TestHarness("Test libIOTests"));

	h->It("documents should be properly constructed when the Document::Make* functions are called", [](Firestorm::TestCase& t) {
		Firestorm::RefPtr<Firestorm::IDocument> document = Firestorm::Document::MakeBlank("JSON");
		t.Assert(document != nullptr, "No JSON blank document was created.");

		Firestorm::Vector<char> data = { '{', '}' };
		Firestorm::RefPtr<Firestorm::IDocument> dataDocument = Firestorm::Document::MakeFromData("JSON", data);
		t.Assert(dataDocument != nullptr, "No JSON document was created from data.");
	});

	h->It("documents should write out to a string as expected", [](Firestorm::TestCase& t) {
		Firestorm::RefPtr<Firestorm::IDocument> document(Firestorm::Document::MakeBlank("JSON"));
		t.Assert(document != nullptr, "something went wrong with creating the document");
		if (document)
		{
			document->WriteSubsection("subsection");
			Firestorm::Vector<char> data;
			document->WriteToData(data);
			Firestorm::String str(data.begin(), data.end());
			Firestorm::String valid("{\"subsection\":{}}\n");
			t.Assert(str == valid, "document output was not what was expected: '" + valid + "' got : '" + str + "'");
		}
	});

	h->It("complex documents should write out to a string as expected", [](Firestorm::TestCase& t) {
		/*Json::Value value;
		value[Firestorm::TraitsDocs::DATA_KEY] = Json::Value(Json::objectValue);

		Firestorm::IDocument* document = new Firestorm::JSONDocument(value);
		document->FindSubsection(Firestorm::TraitsDocs::DATA_KEY);
		document->EnterSubsection();

		rttr::type ty = rttr::type::get_by_name("Firestorm::Mirror::Object");
		std::cout << std::endl << "++++++" << ty.get_name().to_string() << std::endl;
		std::cout.flush();
		t.Assert(ty == Firestorm::Mirror::Object::MyType(), "the types do not match");

		FAIL_END(t, WriteSubsection("object_1"));
		FAIL_END(t, EnterSubsection());

			FAIL_END(t, WriteString(Firestorm::TraitsDocs::OBJECT_TYPE_KEY, Firestorm::Mirror::Object::MyType().get_name().to_string()));
			FAIL_END(t, WriteSubsection(Firestorm::TraitsDocs::OBJECT_DATA_KEY));
			FAIL_END(t, EnterSubsection());

			FAIL_END(t, WriteString("firstPart", "Hello there!"));
			FAIL_END(t, WriteString("secondPart", "Lovely weather, right?"));

			FAIL_END(t, LeaveSubsection());
		FAIL_END(t, LeaveSubsection());

		std::cout << std::endl << document->ToString() << std::endl;
		delete document;*/
	});

	h->It("the FileIOMgr should spin up and shut down without issue", [](TestCase& t) {
		ResourceMgr fileMgr;
		fileMgr.Shutdown();
	});

	h->It("the FileIOMgr should be able to load a basic resource", [](TestCase& t) {
		ResourceMgr fileMgr;

		fileMgr.Shutdown();
	});

	return h;
}