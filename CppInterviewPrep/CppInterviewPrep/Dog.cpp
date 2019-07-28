#include "stdafx.h"
#include "Dog.h"
#include <iostream>


Dog::Dog() {
	/// can cause memory leak if not deleted at destructor
	this->DogTag = new int(5);
}


Dog::~Dog() {
	delete this->DogTag;
}

void Dog::MakeNoiseNotVirtual() {
	std::cout << "bark NV" << std::endl;
}

void Dog::MakeNoiseVirtual() {
	std::cout << "bark V" << std::endl;
}

void Dog::RemoveMe() {
	delete this;
}

void Dog::MakeNoiseVirtualProtected() {
	std::cout << "bark VPrtc" << std::endl;
}

void Dog::MakeNoiseVirtualPrivate() {
	std::cout << "bark VPrvt" << std::endl;
}
