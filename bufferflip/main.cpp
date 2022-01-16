#include<iostream>
#include"Lemon.pb.h"
#include "Rocket.pb.h"

using io::github::phiysng::Person;
using io::github::phiysng::Rocket;
int main() {
	Person p;
	p.set_id(100);
	p.set_email("exmaple@gmail.com");
	p.set_name("exmaple");

	p.PrintDebugString();

	Rocket rocket;

	rocket.mutable_p()->set_id(111);
	rocket.PrintDebugString();
}