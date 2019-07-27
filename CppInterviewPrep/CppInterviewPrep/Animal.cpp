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
