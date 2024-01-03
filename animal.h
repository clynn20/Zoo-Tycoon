#ifndef ANIMAL_H
#define ANIMAL_H
#include<iostream>

class Animal{
	protected:
		int age;
		int revenue;
	
	public:
		Animal();
		Animal(int);
		Animal(const Animal&);
		Animal& operator=(const Animal&);
		~Animal();
		void set_age(int);
		void set_revenue(int);
		int get_age();
		int get_revenue();
		void add_age();
};
#endif
