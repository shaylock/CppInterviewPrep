#include "stdafx.h"
#include "CppFamiliarityQuestion.h"
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include <iostream>



void FuncByValue(int Val) {
	Val = 20;
}

void FuncByReference(int& Val) {
	Val = 30;
}

CppFamiliarityQuestion::CppFamiliarityQuestion() {
}


CppFamiliarityQuestion::~CppFamiliarityQuestion() {
}

void CppFamiliarityQuestion::RunQuestion() {
	this->RunInheritenceQuestion();
	this->RunPointerReferenceQuestion();
}

void CppFamiliarityQuestion::RunArrayQuestion() {
	/// compilation error - array size must be defined
	///int IntArr[];
	int IntArr1[5];
	int IntArr2[] = { 4, 8, 16 };
	/// compilation error - array receivs initialization that oveflows
	///int IntArr3[2] = { 4, 8, 16 };
	int IntArr4[3] = { 4, 8, 16 };
	int IntArr5[4] = { 4, 8, 16 };
	/// compilation error - multi dimentional array must have a defined size
	///int Int2DArr[][] = { { 1, 2 },{ 3, 4 } };
	/// compilation error - multi dimentional array must have a defined size
	///int Int2DArr[2][] = { { 1, 2 },{ 3, 4 } };
	int Int2DArr1[][2] = { { 1, 2 }, { 3, 4 } };
	int Int2DArr2[2][2] = { { 1, 2 }, { 3, 4 } };
	int Int2DArr3[2][2] = { 1, 2, 3, 4 };
	int Int3DArr1[][2][2] = { { 1, 2 },{ 3, 4 } };
	int* IntPtr;
	int* IntPtrArr = new int[5];
	/// memory leak - not all array elements will be deleted
	///delete IntPtrArr;
	delete[] IntPtrArr;
}

void CppFamiliarityQuestion::RunInheritenceQuestion() {
	//TODO: add initial calls to each make noise
	Animal* Animal1 = new Animal();
	Animal1->MakeNoiseNotVirtual();
	Animal1->MakeNoiseVirtual();
	/// compilation error - function is inaccessible
	///Animal1->MakeNoiseVirtualProtected();
	Animal* Dog1 = new Dog();
	Dog1->MakeNoiseNotVirtual();
	Dog1->MakeNoiseVirtual();
	Dog* Dog2 = new Dog();
	Dog2->MakeNoiseVirtualProtected();
	Dog2->MakeNoiseVirtualPrivate();
	Animal* Cat1 = new Cat();
	Cat1->MakeNoiseNotVirtual();
	Cat1->MakeNoiseVirtual();
}

void CppFamiliarityQuestion::RunPointerReferenceQuestion() {
	int Int1 = 5;
	int Int2 = 10;
	const int IntConst = 5;
	int* IntPtr = new int(5);
	int* IntPtrBlank1 = nullptr;
	int* IntPtrBlank2 = new int;
	int* IntPtrMulti = new int;
	IntPtrMulti = new int(4);
	IntPtrMulti = new int(1000);
	int IntArr[] = { 4, 8, 16 };
	/// compilation error - reference must be nitialized
	///int& IntRef;
	/// compilation error - new returns pointer, reference must receive value on initialization;
	///int& IntRef = new int(5);
	/// compilation error - cannot reference to a const value
	///int& IntRef = 5;
	/// comiplation error - cannot bind reference to const variable
	///int& IntRef = IntConst;
	/// runtime error (segmentation fault) - address is nullptr so memory at that address is not valid memory
	///*IntPtrBlank = 5;
	int& IntRef = Int1;
	std::cout << "Int1 value " << Int1 << std::endl;
	std::cout << "Int1 address (on stack) " << &Int1 << std::endl;
	std::cout << "Int2 value " << Int2 << std::endl;
	std::cout << "Int2 address (on stack) " << &Int2 << std::endl;
	std::cout << "IntPtr value " << *IntPtr << std::endl;
	std::cout << "IntPtr address (on heap) " << IntPtr << std::endl;
	std::cout << "address of IntPtr address (on stack) " << &IntPtr << std::endl;
	std::cout << "IntRef value " << IntRef << std::endl;
	std::cout << "IntRef address " << &IntRef << std::endl;
	std::cout << "IntPtrBlank2 value " << *IntPtrBlank2 << std::endl;

	FuncByValue(Int1);
	FuncByReference(Int1);
	FuncByValue(IntRef);
	std::cout << "++ IntRef value " << IntRef << std::endl;
	FuncByReference(IntRef);
	std::cout << "++ IntRef value " << IntRef << std::endl;

	/// compilation error - delete only works on dynamically allocated memory, not static - only pointer
	///delete Int1;
	delete IntPtr;
	/// runtime error (seg fault) - address is now junk address and does not point to valid memory
	///std::cout << "IntPtr value " << *IntPtr << std::endl;
	std::cout << "-- IntPtr address (on heap) " << IntPtr << std::endl;
	IntPtr = new int(6);
	std::cout << "-- IntPtr reuse address (on heap) " << IntPtr << std::endl;
	//std::cout << "IntRef value " << IntRef << std::endl;
	//std::cout << "IntRef value " << IntRef << std::endl;

	Dog* Dog1 = new Dog();
	Dog Dog2;
	std::cout << "Dog1 address " << Dog1 << std::endl;
	Dog1->RemoveMe();
	std::cout << "Dog1 address after removal stays the same " << Dog1 << std::endl;
	/// runtime error (seg fault) - accessing an object that was deleted from dynamic memory
	///Dog1->MakeNoiseVirtual();
	/// runtime error (program crash) - deleting a statically allocated variable
	///Dog2.RemoveMe();
	std::cout << "end of pointer reference section" << std::endl;
}
