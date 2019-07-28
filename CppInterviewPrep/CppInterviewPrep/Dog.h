#pragma once
#include "Animal.h"
class Dog : public Animal
{
public:
	Dog();
	~Dog();

	/// compilation error - cennot override a non virtual function
	///virtual void MakeNoiseNotVirtual() override;
	virtual void MakeNoiseNotVirtual();
	virtual void MakeNoiseVirtual() override;
	void RemoveMe();

	virtual void MakeNoiseVirtualProtected() override;

	virtual void MakeNoiseVirtualPrivate() override;

private:
	int* DogTag;
};

