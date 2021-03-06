// Strategycpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

class BoxItems
{
public:
	virtual void effectItem() = 0;
};

class SpeedBootEffect : public BoxItems
{
public:
	void effectItem()
	{
	std::cout << "Speed UP!" << std::endl;
	}
};

class DamageBootEffect : public BoxItems
{
public:
	void effectItem()
	{
		std::cout << "Damage increase!!" << std::endl;
	}
};

class Box
{
public:
	BoxItems *boxitemsroot;

	void getEffectBox()
	{
		boxitemsroot->effectItem();
	}

	void setEffectBox(BoxItems *newBoxItems)
	{
		std::cout << "Changing effect Box" << std::endl;
		boxitemsroot = newBoxItems;
	}

	virtual void displayEffect() = 0;
};

class BoxOfBoot : public Box
{
public:
	BoxOfBoot()
	{
		boxitemsroot = new SpeedBootEffect();
	}

	void displayEffect()
	{
		std::cout << "Speedboot" << std::endl;
	}
};

class BoxOfDamage : public Box
{
public:
	BoxOfDamage()
	{
		boxitemsroot = new DamageBootEffect();
	}

	void displayEffect()
	{
		std::cout << "DAMAGEBOOT" << std::endl;
	}
};

int main()
{
	Box *speedBox = new BoxOfBoot();
	speedBox->getEffectBox();
	speedBox->displayEffect();

	Box *damageBox = new BoxOfDamage();
	damageBox->displayEffect();
	damageBox->setEffectBox(new SpeedBootEffect);
	damageBox->getEffectBox();

	return 0;
}