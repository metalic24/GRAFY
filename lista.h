#pragma once
#include<iostream>


//lista kt�rej warto�ci zawieraj� pary

using namespace std;
class element
{
public:

	pair<long long, long long> value;
	element* next;
	element();
	~element();


};





class lista
{
public:
	element* begin;
	int licznik;
	void push(pair<long long,long long> para);
	void pop();
	element * top();
	void wyswietl();
	int size();
	void clear();

	//zwracaj� warto�ci par
	int wartosc_first(int x);
	int wartosc_second(int x);


	lista();
	~lista();


};

