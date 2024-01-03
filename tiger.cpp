#include<iostream>
#include"tiger.h"
using namespace std;

int Tiger::cost = 12000;
int Tiger::baby = 3;
int Tiger::mon_food_cost = 5;

//default constructor
Tiger::Tiger():Animal(){
	revenue = 2400;
}
//constructor w/ parameter
Tiger::Tiger(int new_age):Animal(new_age){
	if(age > 6 || age == 6){
		revenue = 1200;
	}
	else if(age < 6){
		revenue = 2400;
	}
}
//copy constructor
Tiger::Tiger(const Tiger &old):Animal(old){
	age = old.age;
	revenue = old.revenue;
}
//assignment operator overload
Tiger& Tiger::operator=(const Tiger& old){
	age = old.age;
	revenue = old.revenue;
	return *this;
}
//destructor
Tiger::~Tiger(){
//	cout <<"Tiger destructor"<< endl;
}
//get sick cost
int Tiger::get_sick_cost(){
	if(age > 6 || age == 6){
		return 0.5*cost;
	}
	else if(age < 6){
		return cost;
	}
}
