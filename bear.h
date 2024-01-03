#ifndef BEAR_H
#define BEAR_H
#include"animal.h"
using namespace std;

class Bear : public Animal{
	protected:
		int sick_cost;
	public:
		static int cost;
		static int baby;
		static int mon_food_cost;
		Bear();
		Bear(int);
		Bear(const Bear&);
		Bear& operator=(const Bear&);
		~Bear();
		int get_sick_cost();
};
#endif


