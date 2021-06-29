#pragma once
#include<iostream>

//kolejka piorytetowa


using namespace std;
class element_kolejki
{
public:

	pair<long long, long long> value;
	int waga; // waga bêdzie równa pierwszemu elementowi w parze 
	element_kolejki* next;


	element_kolejki();



};



class kolejka //kolejka piorytetowa
{
public:

	element_kolejki* begin;
	int licznik;
	void push(pair<long long, long long> para);
	void pop();
	element_kolejki* top();
	void wyswietl();
	int size();
	bool empty();
	void clear();


	kolejka();
	


};

