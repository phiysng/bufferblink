#include <iostream>
#include <string>
#include "Lemon.pb.h"
#include "Rocket.pb.h"
#include "google/protobuf/util/json_util.h"

using std::string;
using std::cout;
using std::endl;

using io::github::phiysng::Person;
using io::github::phiysng::Rocket;
using google::protobuf::Descriptor;
using google::protobuf::Message;
using google::protobuf::util::MessageToJsonString;
using google::protobuf::util::JsonPrintOptions;

const Message* getProtoDefaultInstance(string fullName)
{
	// https://developers.google.com/protocol-buffers/docs/reference/cpp/google.protobuf.message#MessageFactory.generated_factory.details
	// generated_pool() is thread safe.
	const Descriptor* descriptor = ::google::protobuf::DescriptorPool::generated_pool()->
		FindMessageTypeByName(fullName);
	const Message* val = google::protobuf::MessageFactory::generated_factory()->GetPrototype(descriptor);
	assert(val != nullptr);
	return val;
}

int main()
{
	Person p;
	p.set_id(100);
	p.set_email("exmaple@gmail.com");
	p.set_name("exmaple");
	p.PrintDebugString();

	Rocket rocket;
	rocket.mutable_p()->set_id(111);
	rocket.PrintDebugString();

	// to bytes
	string container;
	p.SerializeToString(&container);

	// decode from message full_name
	const Descriptor* descriper = p.GetDescriptor();
	const Message* person = getProtoDefaultInstance(descriper->full_name());
	auto ptr = &Person::default_instance();
	assert(ptr == person);
	// from bytes
	Message* dynamicPerson = person->New();
	dynamicPerson->ParseFromString(container);
	dynamicPerson->PrintDebugString();

	// to JSON
	string json;
	JsonPrintOptions options;
	options.add_whitespace = true;

	MessageToJsonString(*dynamicPerson, &json, options);
	cout << json << endl;
}
