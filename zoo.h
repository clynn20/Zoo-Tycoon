#ifndef ZOO_H
#define ZOO_H
#include<iostream>
#include"animal.h"
#include"tiger.h"
#include"bear.h"
#include"sealion.h"
using namespace std;

class Zoo{
	protected:
		int month;
		int bank_money;
		int revenue;
		int food_cost;
		int paid;
	    int num_animals;
		int num_tigers;
		int num_bears;
		int num_sealions;
		Tiger *tigers;
		Bear *bears;
		Sealion *sealions;
	public:
		Zoo();
		Zoo(const Zoo&);
		Zoo& operator=(const Zoo&);
		~Zoo();
		int get_bank_money();
		int get_revenue();
		int get_food_cost();
		int get_paid();
		int get_num_animals();
		int get_num_tigers();
		int get_adult_tigers();
		int get_baby_tigers();
		Tiger* get_tigers();
		Tiger random_tiger();
		int get_num_bears();
		int get_adult_bears();
		int get_baby_bears();
		Bear* get_bears();
		Bear random_bear();
		int get_num_sealions();
		int get_adult_sealions();
		int get_baby_sealions();
		Sealion* get_sealions();
		Sealion random_sealion();
		void set_food_cost();
		void paid_food_cost();
		void update_revenue();
		void add_tiger(int);
		void remove_tiger(int);
		void add_bear(int);
		void remove_bear(int);
		void add_sealion(int);	
		void remove_sealion(int);
		void special_event();
		void sick_event();
		bool have_tiger();
		bool have_bear();
		bool have_sealion();
		void birth_event();
		bool birth_chance();	
		int birth_species();
		void boom_event();
		void buy_animal();
		bool can_buyA(string);
		bool can_buyB(string,string);
		void start_turn();
		void start_print();
		void end_print();

};
#endif
