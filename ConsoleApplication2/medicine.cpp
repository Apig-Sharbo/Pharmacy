//#include "stdafx.h"
#include "medicine.h"
#include <cstring>
#include <iostream>
using namespace std;
//double medicine::get_cost() {	return cost; }
//int medicine::get_quantity() { return quantity; }
//char medicine::get_name() { return *name; }
void medicine::input() {
	cout << "Input medicine name: ";	cin >> name;
	cout << "\tInput cost: ";			cin >> cost;
	cout << "\tInput quantity: ";		cin >> quantity;
	//cout << "\tInput expiry year: ";	cin >> year;
	cout << "\tInput expiry month: ";	cin >> month;
	cout << "\tInput expiry day: ";		cin >> day;
	cout << endl;
}
void medicine::output() {
	cout << "Name: " << name;
	cout << "\n\tCost: " << cost;
	cout << "\n\tQuantity: " << quantity;
	cout << "\n\tExpiry date: " << day << "/" << month;
	cout << "\n\tIncome: " << income;
	cout << endl;
}
/*void sell() 
{

}*/
double get_cost(medicine &s) { return s.cost; }
int get_month(medicine &m) { return m.month; }
int get_day(medicine &d) { return d.day; }
char* get_name(medicine &n1) { return n1.name; }
int get_quantity(medicine &q) { return q.quantity; }
double get_income(medicine &i) { return i.income; }

double medicine::totalIncome;

medicine::medicine()
{
	totalIncome = 0.0;
	cost = 0.0;
	quantity = 0;
	income = 0.0;
	//name = new char[20];
	day = 0;
	month = 0;
//	year = 0;
	//strcpy_s(name,1,"0");
}
void medicine::change_quantity(int quantity0)
{
	quantity = quantity0;
}

void medicine::change_income(double amount)
{
	income = income + (amount*0.8);
}

medicine::~medicine()
{
}
