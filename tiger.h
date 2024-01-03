#ifndef TIGER_H
#define TIGER_H
#include"animal.h"
#include<iostream>
using namespace std;

class Tiger : public Animal{
	protected:
		int sick_cost;
	public:
		static int cost;
		static int baby;
		static int mon_food_cost;
		Tiger();
		Tiger(int);
		Tiger(const Tiger&);
		Tiger& operator=(const Tiger&);
		~Tiger();
		int get_sick_cost();
};
#endif
