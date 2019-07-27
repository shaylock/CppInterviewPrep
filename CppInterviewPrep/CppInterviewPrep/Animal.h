#pragma once
class Animal
{
public:
	Animal();
	~Animal();

	void MakeNoiseNotVirtual();
	virtual void MakeNoiseVirtual();
};

