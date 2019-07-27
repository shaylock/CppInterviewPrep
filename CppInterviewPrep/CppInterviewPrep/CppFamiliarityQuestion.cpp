#include "stdafx.h"
#include "CppFamiliarityQuestion.h"
#include "Animal.h"
#include <iostream>


CppFamiliarityQuestion::CppFamiliarityQuestion() {
}


CppFamiliarityQuestion::~CppFamiliarityQuestion() {
}

void CppFamiliarityQuestion::RunQuestion() {
	Animal* Animal1 = new Animal();
	Animal1->MakeNoiseNotVirtual();
}
