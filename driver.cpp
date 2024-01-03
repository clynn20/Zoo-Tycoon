#include<iostream>
#include<cstdlib>
#include"zoo.h"
#include"animal.h"
#include"tiger.h"
#include"sealion.h"
#include"bear.h"
using namespace std;

int main(){
	Zoo z1;
	string quit = "2";
	while(z1.get_bank_money()>0){
		z1.start_turn();
		z1.start_print();
		z1.special_event();
		z1.update_revenue();
		z1.buy_animal();
		z1.paid_food_cost();
		z1.end_print();
		cout <<"Do you want to quit(Yes press 0, No press 1): ";
		getline(cin,quit);
		if(quit=="0"){
			exit(0);
		}
		if(z1.get_bank_money()==0){
			cout << "Bankrupt, game over" << endl;
			exit(0);
		}
	}
	return 0;
}
