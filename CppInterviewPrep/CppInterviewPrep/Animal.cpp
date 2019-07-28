#include "stdafx.h"
#include "Animal.h"
#include <iostream>


Animal::Animal() {
}


Animal::~Animal() {
}

void Animal::MakeNoiseNotVirtual() {
	std::cout << "blaaa NV" << std::endl;
}

void Animal::MakeNoiseVirtual() {
	std::cout << "blaaa V" << std::endl;
}

void Animal::MakeNoiseVirtualProtected() {
	std::cout << "blaaa VPrtc" << std::endl;
}

void Animal::MakeNoiseVirtualPrivate() {
	std::cout << "blaaa VPrvt" << std::endl;
}
