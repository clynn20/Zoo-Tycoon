#include<iostream>
#include"animal.h"
using namespace std;
//default constructor
Animal::Animal(){
	age = 0;
	revenue = 0;
}
//constructor w/ parameter
Animal::Animal(int new_age){
	age=new_age;
}
//copy constructor
Animal::Animal(const Animal& old){
	age=old.age;
	revenue=old.revenue;
}
//assignment operator overload
Animal& Animal::operator=(const Animal& old){
	age = old.age;
	revenue = old.revenue;
	return *this;
}
//destructor
Animal::~Animal(){
//	cout<<"Animal destructor" << endl;
}
//set age
void Animal::set_age(int new_age){
	age = new_age;
}
//set revenue
void Animal::set_revenue(int new_revenue){
	revenue = new_revenue;
}
//get age
int Animal::get_age(){
	return age;
}
//get revenue
int Animal::get_revenue(){
	return revenue;
}
//add age
void Animal::add_age(){
	age++;
	if(age == 6|| age > 6){
		revenue = revenue;
	}
	else if(age < 6){
		revenue = 2*revenue;
	}
}

