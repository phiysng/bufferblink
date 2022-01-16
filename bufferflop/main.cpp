#include <iostream>
#include "Flop.pb.h"

using namespace std;

int main() {

	HelloMessage message;
	message.set_name("100");
	message.set_index(10);

	auto bytes = message.SerializeAsString();

	cout << message.DebugString() << endl;

	return 0;
}
