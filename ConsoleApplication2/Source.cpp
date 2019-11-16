//#include "stdafx.h"
#include <fstream>
#include "medicine.h"
#include <iostream>
#include <cstring>
using namespace std;
void expiration(medicine *pharmacy, int n);
void my_read(medicine *pharmacy, int n);
void my_save(medicine *pharmacy, int n);
void input_switch(medicine *pharmacy, int n);
void sort_switch(medicine *pharmacy, int n);
void output_switch(medicine *pharmacy, int n);
//void sell_switch(medicine *pharmacy, int n, int zz);
int search(medicine *pharmacy,int n);
void sell(medicine *pharmacy,int zz,double &amount);
//double TotalIncome(medicine *pharmacy, int n, double amount);

void main()
{
	cout << "Enter number of type of medicines: ";  // could be worded better, I know.
	int n;
	cin >> n;
	medicine *pharmacy = new medicine[n];
	int t=0;
	double amount = 0.0;
	while (t==0)
	{
		int z;
		cout << "Enter \t (1) to input, (2) to read from database,";
		cout << "\n\t (3) to sort by ascending price, (4) to output,";
		cout<<"\n\t(5) to check expiration date, (6) to save, \n\t(7) to search medicine, (8) to sell, (9) to exit : "; cin >> z;
		//cout << endl;
		switch (z)
		{
		case 1:
			input_switch(pharmacy, n);
			//my_save(pharmacy, n);
			break;
		case 2:
			my_read(pharmacy, n);
			break;
		case 3:
			sort_switch(pharmacy, n);
			//my_save(pharmacy, n);
			break;
		case 4:
			output_switch(pharmacy, n);
			break;
		case 5:
			expiration(pharmacy, n);
			break;
		case 6:
			my_save(pharmacy, n);
			break;
		case 7:
		{	int zz = search(pharmacy, n);
			if (zz == -1)
				cout << "Medicine not found";
			else {
				cout << "\tThe income of this medicine:" << get_income(*(pharmacy + zz));
			//	cout << "\n\ttotal income = " << TotalIncome(pharmacy, n, amount);
				cout << "\n\tTotal income = " << medicine::totalIncome;
				cout << endl;
			}

			break;
		}
		case 8:
		{
			int zz=search(pharmacy, n);
			sell(pharmacy, zz,amount);
			break;
		}
		case 9:
			t = 1;
			break;
		}
		               //delete []pharmacy  \\\\\\\\\\\\\\\\\ !!!!
		cout << endl;               //    \\\\!!!
	}                             //    !!!!!!!!!!                                  
	delete []pharmacy; //delete should be always at the end, and not here \\\\\!
	cout << endl;
}

/*double TotalIncome(medicine *pharmacy, int n, double amount)
{
	static double totalIncome = 0.0;
	for (int i = 0; i < n; i++)
	{//totalincome = (pharmacy + i)->Income(amount) + totalincome;
		totalIncome = get_income(*(pharmacy +i))+totalIncome;
	}
	return totalIncome;
}*/

/*void sell_switch(medicine *pharmacy, int n, int zz)
{
	(pharmacy + zz)->sell(pharmacy,zz, &amount);
}*/

void sell(medicine *pharmacy, int zz, double &amount) //get quantity using friend , compare with requested quantity, and decrease from stock
{                                    //income  which is 20% of medicine price, //total income is static, 
	int quantity1;
	cout << "How many do you want: "; cin >> quantity1;
	amount = quantity1*get_cost(*(pharmacy + zz));
	int quantitynew;
	int quantityPharm = get_quantity(*(pharmacy + zz));
	while (quantity1 > quantityPharm)
		{
			cout << "We only have this much: " << get_quantity(*(pharmacy + zz)) << endl;;
			cout << "So, how many do you want: "; cin >> quantity1;
		}
		cout << "The amount is: " << amount;
		quantitynew = quantityPharm-quantity1;
		(pharmacy + zz)->change_quantity(quantitynew);
		medicine::totalIncome += get_income(*(pharmacy + zz)) + amount*0.8;
		(pharmacy + zz)->change_income(amount);
		cout << endl;
	
	
}

int search(medicine *pharmacy,int n)
{
	char name1[20];
	cout<<"Input name of medicine to search: ";cin>>name1;
	for(int i=0;i<n;i++)
	{
		if(strcmp(get_name(*(pharmacy +i)),name1)==0)
			return i;
	}
	return -1;

}

void expiration(medicine *pharmacy, int n)
{
	int day1, month1;
	cout << "Input month to check: "; cin >> month1;
	cout << "Input day to check: "; cin >> day1;
	for (int k = 0; k < n; k++)
	{
		if (get_month(*(pharmacy + k)) - month1 < 0)
		{
			(pharmacy + k)->output();
			cout << "Expired\n";
		}
		if (get_month(*(pharmacy + k)) -month1 > 0 && get_day(*(pharmacy+k))-day1 >0)
		{
			(pharmacy + k)->output();
			cout << "Remaning " << get_month(*(pharmacy + k)) - month1 << " months and " << get_day(*(pharmacy + k)) - day1<< " days\n";
		}
		if (get_month(*(pharmacy + k)) - month1 > 0 && get_day(*(pharmacy + k)) - day1 < 0)
		{
			(pharmacy + k)->output();
			cout << "Remaning " << get_month(*(pharmacy + k)) - month1-1<< " months and " << get_day(*(pharmacy + k)) - day1+31 << " days\n";
		}
	}
}

void input_switch(medicine *pharmacy, int n)
{
	for (int i = 0; i < n; i++)
		(pharmacy + i)->input();
}

void output_switch(medicine *pharmacy, int n)
{
	for (int i = 0; i < n; i++)
		(pharmacy + i)->output();
}

void sort_switch(medicine *pharmacy, int n)
{
	medicine test;
	for (int k = 0; k < n - 1; k++) 
	{
		double min = get_cost(*(pharmacy + k));
		for (int j = k + 1; j < n; j++)
		{
			if (min >get_cost(*(pharmacy + j)))
			{
				test = *(pharmacy + k);
				*(pharmacy + k) = *(pharmacy + j);
				*(pharmacy + j) = test;
				min = get_cost(*(pharmacy + k));
			}
		}
	}
}

void my_read(medicine *pharmacy, int n)
{
	ifstream file("base.dat");
	file.read((char*)pharmacy, n * sizeof(medicine));
	file.close();
}

void my_save(medicine *pharmacy, int n)
{
	ofstream file("base.dat");
	file.write((char*)pharmacy, n * sizeof(medicine));
	file.close();
}
