#pragma once
class Animal
{
public:
	Animal();
	~Animal();

	void MakeNoiseNotVirtual();
	virtual void MakeNoiseVirtual();

protected:
	virtual void MakeNoiseVirtualProtected();

private:
	virtual void MakeNoiseVirtualPrivate();
};

