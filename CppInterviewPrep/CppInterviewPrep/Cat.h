#pragma once
#include "Animal.h"
class Cat : public Animal
{
public:
	Cat();
	~Cat();

	// compilation error - cennot override a non virtual function
	//virtual void MakeNoiseNotVirtual() override;
	virtual void MakeNoiseNotVirtual();
	virtual void MakeNoiseVirtual() override;
};

