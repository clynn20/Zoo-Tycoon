#ifndef SEALION_H
#define SEALION_H
#include"animal.h"
#include<iostream>
using namespace std;

class Sealion : public Animal{
	protected:
		int sick_cost;
	public:
		static int cost;
		static int baby;
		static int mon_food_cost;
		Sealion();
		Sealion(int);
		Sealion(const Sealion&);
		Sealion& operator=(const Sealion&);
		~Sealion();
		int get_sick_cost();
};
#endif
