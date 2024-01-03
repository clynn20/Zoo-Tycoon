#include<iostream>
#include"sealion.h"
using namespace std;

int Sealion::cost=700;
int Sealion::baby=1;
int Sealion::mon_food_cost=1;

//default constructor
Sealion::Sealion():Animal(){
	revenue = 140;
}
//constructor w/parameter
Sealion::Sealion(int new_age):Animal(new_age){
	if(age > 6|| age == 6){
		revenue = 140;
	}
	else if(age < 6){
		revenue = 280;
	}
}
//copy constructor
Sealion::Sealion(const Sealion& old):Animal(old){
	age = old.age;
	revenue = old.revenue;
}
//assignment operator overload
Sealion& Sealion::operator=(const Sealion& old){
	age = old.age;
	revenue = old.revenue;
	return *this;
}
//destructor
Sealion::~Sealion(){
	//cout << "Sealion destructor"<< endl;
}
//get sick cost
int Sealion::get_sick_cost(){
	if(age > 6 || age == 6){
		return 0.5*cost;
	}
	else if(age < 6){
		return cost;
	}
}
