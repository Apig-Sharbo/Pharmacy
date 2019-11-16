#pragma once
class medicine
{
	friend double get_cost(medicine &s);
	friend int get_month(medicine &m);
	friend int get_day(medicine &d);
	friend char* get_name(medicine &n1);
	friend int get_quantity(medicine &q);
	//friend double get_amount(medicine &a);
	friend double get_income(medicine &i);

private:
	
	double cost,income;
	int quantity,day,month,year;
	//char *name;  //can't use with saving database
	char name[20];
public:
	static double totalIncome;
	//double cost;
	void input();
//	void sell();

	//double get_cost();
	//int get_quantity();
	//char get_name();
	void output();
	medicine();
	void change_quantity(int quantity0);
	void change_income(double amount);
	~medicine();
};

