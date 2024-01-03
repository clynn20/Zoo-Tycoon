#include<iostream>
#include<cstdlib>
#include"zoo.h"
#include"animal.h"
#include"tiger.h"
#include"bear.h"
#include"sealion.h"
using namespace std;

//default constructor
Zoo::Zoo(){
	sealions = NULL;
	tigers = NULL;
	bears = NULL;
	bank_money = 100000;
	revenue = 0;
	food_cost = 80;
	paid = 0;
	num_animals = 0;
	num_tigers = 0;
	num_bears = 0;
	num_sealions = 0;
	month = 0;
}
//copy constructor
Zoo::Zoo(const Zoo& old){
	sealions = old.sealions;
	tigers = old.tigers;
	bears = old.bears;
	bank_money = old.bank_money;
	revenue = old.revenue;
	food_cost = old.food_cost;
	paid = old.paid;
	num_animals = old.num_animals;
	num_tigers = old.num_tigers;
	num_bears = old.num_bears;
	num_sealions = old.num_sealions;
	month = old.month;

}
//assignment operator overload
Zoo& Zoo::operator=(const Zoo& old){
	if (this != &old){
		delete [] sealions;
		delete [] tigers;
		delete [] bears;
	}
	sealions = old.sealions;
	tigers = old.tigers;
	bears = old.bears;
	bank_money = old.bank_money;
	revenue = old.revenue;
	food_cost = old.food_cost;
	paid = old.paid;
	num_animals = old.num_animals;
	num_tigers = old.num_tigers;
	num_bears = old.num_bears;
	num_sealions = old.num_sealions;
	month = old.month;
	return *this;
}
//destructor
Zoo::~Zoo(){
	//cout <<"Zoo destructor"<< endl;
	if(num_tigers > 0){
		delete [] tigers;
	}
	else if(num_bears > 0){
		delete [] bears;
	}
	else if(num_sealions > 0){
		delete [] sealions;
	}
}
//get tiger
Tiger* Zoo::get_tigers(){
	return tigers;
}
//get bear
Bear* Zoo::get_bears(){
	return bears;
}
//get sealions
Sealion* Zoo::get_sealions(){
	return sealions;
}
//get revenue
int Zoo::get_revenue(){
	return revenue;
}
//get bank money
int Zoo::get_bank_money(){
	return bank_money;
}
//get food cost
int Zoo::get_food_cost(){
	return food_cost;
}
//get paid
int Zoo::get_paid(){
	return paid;
}
//get number of animal
int Zoo::get_num_animals(){
	return num_animals;
}
//get number of tiger
int Zoo::get_num_tigers(){
	return num_tigers;
}
//get number of sealions
int Zoo::get_num_sealions(){
	return num_sealions;
}
//get number of bear
int Zoo::get_num_bears(){
	return num_bears;
}
//get number of adult tiger
int Zoo::get_adult_tigers(){
	int adult_tigers = 0;
	for(int i=0;i<num_tigers;i++){
		if(tigers[i].get_age()>48 || tigers[i].get_age()==48){
			adult_tigers++;
		}
	}
		return adult_tigers;
}
//get number of baby tiger
int Zoo::get_baby_tigers(){
	int baby_tigers = 0;
	for(int i=0;i<num_tigers;i++){
		if(tigers[i].get_age()<6){
			baby_tigers++;
		}
	}
	return baby_tigers;
}
//get number of adult bear
int Zoo::get_adult_bears(){
	int adult_bears = 0;
	for(int i=0;i<num_bears;i++){
		if(bears[i].get_age()>48 || bears[i].get_age()==48){
			adult_bears++;
		}
	}
	return adult_bears;
}
//get number of baby bear
int Zoo::get_baby_bears(){
	int baby_bears = 0;
	for(int i=0;i<num_bears;i++){
		if(bears[i].get_age()<6){
			baby_bears++;
		}
	}
	return baby_bears;
}
//get number of adult sealions
int Zoo::get_adult_sealions(){
	int adult_sealions = 0;
	for(int i=0;i<num_sealions;i++){
		if(sealions[i].get_age()>48 || sealions[i].get_age()==48){
			adult_sealions++;
		}
	}
	return adult_sealions;
}
//get number of baby sealions
int Zoo::get_baby_sealions(){
	int baby_sealions = 0;
	for(int i=0;i<num_sealions;i++){
		if(sealions[i].get_age()<6){
			baby_sealions++;
		}
	}
	return baby_sealions;
}
// get random tiger
Tiger Zoo::random_tiger(){
	int index = rand() % num_tigers;
	return tigers[index];
}
//get random bear
Bear Zoo::random_bear(){
	int index = rand() % num_bears;
	return bears[index];
}
//get random sealions
Sealion Zoo::random_sealion(){
	int index = rand() % num_sealions;
	return sealions[index];
}	
//set food cost 
void Zoo::set_food_cost(){
	srand(time(NULL));
	int percent = rand()%41 + 80;
	int new_food_cost = food_cost*(float)percent / (float)100;
	food_cost += new_food_cost;
}
//paid food cost
void Zoo::paid_food_cost(){
	if(num_animals > 0){
		bank_money = bank_money - (5*num_tigers*food_cost) - (3*num_bears*food_cost) - (num_sealions*food_cost);
		paid = paid + (5*num_tigers*food_cost)+(3*num_bears*food_cost)+(num_sealions*food_cost);
	}
}
//add tiger 
void Zoo::add_tiger(int age){
	Tiger *new_tigers = new Tiger[num_tigers+1];
	for(int i=0;i<num_tigers;i++){
		new_tigers[i].set_age(tigers[i].get_age());
		new_tigers[i].set_revenue(tigers[i].get_revenue());
	}
	if(num_tigers > 0){
		delete [] tigers;
	}
	new_tigers[num_tigers].set_age(age);
	if(age<6){
		new_tigers[num_tigers].set_revenue(2400);
	}
	else if(age>6||age==6){
		new_tigers[num_tigers].set_revenue(1200);
	}
	tigers = new_tigers;
	num_animals++;
	num_tigers++;
}
//add bear
void Zoo::add_bear(int age){
	Bear *new_bears = new Bear[num_bears+1];
	for(int i=0;i<num_bears;i++){
		new_bears[i].set_age(bears[i].get_age());
		new_bears[i].set_revenue(bears[i].get_revenue());
	}
	if(num_bears>0){
		delete[] bears;
	}
	new_bears[num_bears].set_age(age);
	if(age<6){
		new_bears[num_bears].set_revenue(1000);
	}
	else if(age>6||age==6){
		new_bears[num_bears].set_revenue(500);
	}
	bears = new_bears;
	num_animals++;
	num_bears++;
}
//add sealion
void Zoo::add_sealion(int age){
	Sealion *new_sealions = new Sealion[num_sealions+1];
	for(int i=0;i<num_sealions;i++){
		new_sealions[i].set_age(sealions[i].get_age());
		new_sealions[i].set_revenue(sealions[i].get_revenue());
	}
	if(num_sealions>0){
		delete[] sealions;
	}
	new_sealions[num_sealions].set_age(age);
	if(age<6){
		new_sealions[num_sealions].set_revenue(280);
	}
	else if(age>6||age==6){
		new_sealions[num_sealions].set_revenue(140);
	}
	sealions = new_sealions;
	num_animals++;
	num_sealions++;
}
//remove tiger
void Zoo::remove_tiger(int index){
	Tiger *new_tigers;
	if(num_tigers!=1){
		new_tigers = new Tiger[num_tigers-1];
	}
	else{
		new_tigers = NULL;
	}
	for(int i=0;i<num_tigers;i++){
		if(i!=index){
			int new_age = tigers[i].get_age();
			new_tigers[i].set_age(new_age);
			if(new_age<6){
				new_tigers[i].set_revenue(280);
			}
			else if(new_age > 6 || new_age == 6){
				new_tigers[i].set_revenue(140);
			}
		}
	}
	delete[] tigers;
	tigers = new_tigers;
	num_animals--;
	num_tigers--;
}
//remove bear
void Zoo::remove_bear(int index){
	Bear* new_bears;
	if(num_bears!=1){
		new_bears = new Bear[num_bears-1];
	}
	else{
		new_bears = NULL;
	}
	for(int i=0;i<num_bears;i++){
		if(i!=index){
			int new_age = bears[i].get_age();
			new_bears[i].set_age(new_age);
			if(new_age<6){
				new_bears[i].set_revenue(1000);
			}
			else if(new_age > 6 || new_age == 6){
				new_bears[i].set_revenue(500);
			}
		}
	}
	delete[] bears;
	bears = new_bears;
	num_animals--;
	num_bears--;
}
//remove sealion
void Zoo::remove_sealion(int index){
	Sealion* new_sealions;
	if(num_sealions!=1){
		new_sealions = new Sealion[num_sealions-1];
	}
	else{
		new_sealions = NULL;
	}
	for(int i=0;i<num_sealions;i++){
		if(i!=index){
			int new_age = sealions[i].get_age();
			new_sealions[i].set_age(new_age);
			if(new_age<6){
				new_sealions[i].set_revenue(280);
			}
			else if(new_age > 6|| new_age == 6){
				new_sealions[i].set_revenue(140);
			}
		}
	}
	delete[] sealions;
	num_animals--;
	num_sealions--;
}
//random choose one event 
void Zoo::special_event(){
	if(num_animals == 0){
		cout << "No animals right now, so no special event this turn" << endl;
	}
	else if(num_animals!=0){
		int num = rand() % 4;
		switch(num){
			case 0:
				cout <<"You are given a sick event" << endl;
				sick_event();
				break;
			case 1:
				cout <<"You are given a birth event" << endl;
				birth_event();
				break;
			case 2:
				cout <<"You are given a boom event" << endl;
				boom_event();
				break;
			case 3:
				cout <<"No event are given this turn" << endl;
				break;
		}
	}
}
// have tiger or not
bool Zoo::have_tiger(){
	return (num_tigers!=0? true : false);
}
//have bear or not
bool Zoo::have_bear(){
	return (num_bears!=0? true : false);
}
//have sealion or not
bool Zoo::have_sealion(){
	return (num_sealions!=0? true : false);
}
//sick event
void Zoo::sick_event(){
	int species = birth_species();
	switch(species){
		case 0:{//tiger
			if(have_tiger()){
				int index = rand() % num_tigers;
				int sick_cost = tigers[index].get_sick_cost();
				if(bank_money > sick_cost){
					bank_money -= sick_cost;
					paid += sick_cost;
					cout <<"Tiger get sick, you paid " << sick_cost << endl;
				}
				else{
					remove_tiger(index);
					cout <<"Tiger get sick, and you don't have enough money,so tiger dies." <<endl;
				}
			}
			else if(have_tiger()==false){
				break;
			}
			break;
		}
		case 1:{//bear
			if(have_bear()){
				int index = rand() % num_bears;
				int sick_cost = bears[index].get_sick_cost();
				if(bank_money > sick_cost){
			      	bank_money -= sick_cost;
					paid += sick_cost;
			      	cout <<"Bear get sick, you paid " << sick_cost << endl;
				}
				else{
					remove_bear(index);
					cout<<"Bear get sick, and you don't have enough money, so bear dies." << endl;
				}
			}
			else if(have_bear()==false){
				break;
			}
			break;
		}
		case 2:{//sealion
			if(have_sealion()){
				int index = rand() % num_sealions;
				int sick_cost = sealions[index].get_sick_cost();
				if(bank_money > sick_cost){
					bank_money -= sick_cost;
					cout <<" Sealion get sick, you paid " << sick_cost <<endl;
				}
				else{
					remove_sealion(index);
					cout <<"Sealion get sick, and you don't have enough money, so sealion dies" << endl;
				}
			}
			else if(have_sealion()==false){
				break;
			}
			break;
		}
	}
}
// birth species
int Zoo::birth_species(){
	int species = rand() % 3;
	switch(species){
		case 0://tiger
			if(get_adult_tigers()>=2)
				return 0;
			break;
		case 1://bear
			if(get_adult_bears()>=2)
				return 1;
			break;
		case 2://sealion
			if(get_adult_sealions()>=2)
				return 2;
			break;
		}
}

//can birth or not
bool Zoo::birth_chance(){
	if(get_adult_tigers()>=2 && birth_species()==0){
		return true;
	}
	else if(get_adult_bears()>=2 && birth_species()==1){
		return true;
	}
	else if(get_adult_sealions()>=2 && birth_species()==2){
		return true;
	}
	cout << "Chosen birth species: " << birth_species() << " (0 for tiger, 1 for bear, 2 for sealion)" << endl;
	cout << "Impossible to give birth, since no enough adult animals(2) of the same specie" << endl;
	return false;
}

// birth event
void Zoo::birth_event(){
	if(!birth_chance()){
		return;
	}
	else if(birth_chance()){
		int species = birth_species();
		switch(species){
			case 0:{//tiger
				for(int i=0;i<Tiger::baby;i++){
					add_tiger(0);
				}
				cout <<"Add " << Tiger::baby << " baby tiger(s) to zoo" << endl;
				break;
			}
			case 1:{//bear
				for(int i=0;i<Bear::baby;i++){
					add_bear(0);
				}
				cout << "Add " << Bear::baby << " baby bear(s) to zoo" << endl;
				break;
			}
			case 2:{//sealion
				for(int i=0;i<Sealion::baby;i++){
					add_sealion(0);
				}
				cout << "Add " << Sealion::baby << " baby sealion(s) to zoo" << endl;
				break;
			}
		}
	}
}
//boom event
void Zoo::boom_event(){
	srand(time(NULL));
	if(num_sealions == 0){
		cout<<"No sealion so no extra bonus" << endl;
	}
	else{
		for(int i=0;i<num_sealions;i++){
			int bonus = rand() % 251 + 150;
			bank_money += (bonus*num_sealions);
			revenue += (bonus*num_sealions);
		}
	}
}
//update revenue 
void Zoo::update_revenue(){
	for(int i=0;i<num_tigers;i++){
		bank_money += tigers[i].get_revenue();
		revenue += tigers[i].get_revenue();
	}
	for(int i=0;i<num_bears;i++){
		bank_money += bears[i].get_revenue();
		revenue += bears[i].get_revenue();
	}
	for(int i=0;i<num_sealions;i++){
		bank_money += sealions[i].get_revenue();
		revenue += sealions[i].get_revenue();
	}
}
//buy animal
void Zoo::buy_animal(){
	string str = "3";
	while(str!="0" && str!="1"){
		cout <<"Do you want to buy animal? (Yes : 0 , No : 1): ";
		getline(cin,str);
	}
	if(str=="1"){
		return;
	}
//	cout << endl;
	string option = "5";
	while(option!="0" && option!="1" && option!="2"){
		cout <<"Which species do you want to buy? (tiger press 0, bear press 1, sealion press 2): " ;
		getline(cin,option);
		if(!can_buyA(option)){
			cout <<"No enough money try again." << endl;
			option = "5";
		}
	}
	int species = atoi(option.c_str());
	string num = "3";
	while(num!="1"&&num!="2"){
		cout <<"How many amount do you want to buy? (choose 1 or 2): ";
		getline(cin,num);
		if(!can_buyB(num,option)){
			cout <<"No enough money try again." << endl;
			num = "3";
		}
	}
	int amount = atoi(num.c_str());
	for(int i=0;i<amount;i++){
		if(species == 0){//tiger
			add_tiger(48);
			bank_money -= 12000;
			paid += 12000;
		}
		else if(species == 1){//bear
			add_bear(48);
			bank_money -= 5000;
			paid += 5000;
		}
		else if(species == 2){//sealion
			add_sealion(48);
			bank_money -= 700;
			paid += 700;
		}
	}
}

//can buy ver1
bool Zoo::can_buyA(string option){
	int species = atoi(option.c_str());
	if(species == 0){//tiger
		return (bank_money > 12000)? true : false;
	}
	else if(species == 1){//bear
		return (bank_money > 5000)? true : false;
	}
	else if(species == 2){//sealion
		return (bank_money > 700)? true : false;
	}
}
//can buy ver2
bool Zoo::can_buyB(string num,string option){
	int amount = atoi(num.c_str());
	int species = atoi(option.c_str());
		if(species == 0){//tiger
			return (bank_money > amount*12000)? true : false;
		}
		else if(species == 1){//bear
			return (bank_money > amount*5000)? true : false;
		}
		else if(species == 2){//sealion
			return (bank_money > amount*700)? true : false;
		}
}
//start turn
void Zoo::start_turn(){
	paid = 0;
	revenue = 0;
	for(int i=0;i<num_tigers;i++){
		tigers[i].add_age();
	}
	for(int i=0;i<num_bears;i++){
		bears[i].add_age();
	}
	for(int i=0;i<num_sealions;i++){
		sealions[i].add_age();
	}
}

//print status
void Zoo::start_print(){
	cout << "--------------------------------" << endl;
	cout << "Start of month: " << month  << endl;
	cout << "Money in the bank: " << get_bank_money() << endl;
	cout << "Number of animals in zoo: " << get_num_animals() << endl;
	cout << "Number of tiger in zoo: " << get_num_tigers() << endl;
	cout << "Number of bear in zoo: " << get_num_bears() << endl;
	cout << "Number of sealion in zoo: " << get_num_sealions() << endl;
	cout << "----------------------------------" << endl;
	month++;
}
//print status
void Zoo::end_print(){
	cout << "--------------------------------" << endl;
	cout <<"End of month" <<endl;
	cout <<"Revenue get this month: "<< get_revenue()<< endl;
	cout <<"Money paid out: " << get_paid()<< endl;
	cout <<"Money in the bank remain: " << get_bank_money() <<endl;
	cout << "---------------------------------" << endl;
	Tiger *tigers = get_tigers();
	Bear *bears = get_bears();
	Sealion *sealions = get_sealions();
	num_tigers = get_num_tigers();
	num_bears = get_num_bears();
	num_sealions = get_num_sealions();

}
		



	
	


	
