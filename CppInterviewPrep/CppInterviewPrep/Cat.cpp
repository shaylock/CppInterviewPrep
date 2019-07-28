#include "stdafx.h"
#include "Cat.h"
#include <iostream>


Cat::Cat() {
}


Cat::~Cat() {
}

void Cat::MakeNoiseNotVirtual() {
	std::cout << "Meaw NV" << std::endl;
}

void Cat::MakeNoiseVirtual() {
	std::cout << "Meaw V" << std::endl;
}
