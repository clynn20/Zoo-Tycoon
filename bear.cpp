#include<iostream>
#include"bear.h"
using namespace std;

int Bear::cost = 5000;
int Bear::baby = 2;
int Bear::mon_food_cost = 3;
//default constructor
Bear::Bear():Animal(){
	revenue = 500;
}
//constructor w/ parameter
Bear::Bear(int new_age):Animal(new_age){
	if(age > 6 || age == 6){
		revenue = 500;
	}
	else if(age < 6){
		revenue = 1000;
	}
}
//copy constructor
Bear::Bear(const Bear& old):Animal(old){
	age = old.age;
	revenue = old.revenue;
}
//assignment operator overload
Bear& Bear::operator=(const Bear& old){
	age = old.age;
	revenue = old.revenue;
	return *this;
}
//destructor
Bear::~Bear(){
	//cout <<"Bear destructor" << endl;
}
//get sick cost
int Bear::get_sick_cost(){
	if(age > 6 || age == 6){
		return 0.5*cost;
	}
	else if(age < 6){
		return cost;
	}
}
