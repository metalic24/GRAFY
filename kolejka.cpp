#include "kolejka.h"


element_kolejki::element_kolejki()
{
	this->next = NULL;
	this->value = { NULL,NULL };
	this->waga = 0;
}



//dodawanie elementu do kolejki w zale¿noœci od piorytetu wstawianej wartoœci

void kolejka::push(pair<long long, long long> para)
{
	element_kolejki* temp = new element_kolejki();
	temp->value = para;
	temp->waga = temp->value.first;

	if (this->begin == NULL)
	{
		this->begin = temp;
		temp->next = NULL;
	}
	else if (this->begin->waga < temp->waga)
	{
		temp->next = begin;
		this->begin = temp;
	}
	else 
	{
		element_kolejki* k = new element_kolejki();
		k = this->begin;
		while ((k->next != NULL) && (k->next->waga > temp->waga) )
		{
			k = k->next;
		}

		temp->next=k->next ;
		k->next = temp;

	}

	
	this->licznik++;




}

void kolejka::pop()
{
	element_kolejki* temp = new element_kolejki();

	temp = this->begin;
	if(temp)
	{


		if (temp->next == NULL)
		{
			this->begin = NULL;
		}
		else
		{
			while (temp->next->next != NULL)
			{
				temp = temp->next;
			}

			free(temp->next);

			temp->next = NULL;

		}




		this->licznik--;
	}

}

element_kolejki* kolejka::top()
{
	element_kolejki* temp = new element_kolejki();
	temp = this->begin;
	if (temp)
	{


		while (temp->next != NULL)
		{
			temp = temp->next;
		}
	}
	return  temp;
}

void kolejka::wyswietl()
{
	element_kolejki* k = new element_kolejki();
	k = this->begin;
	while (k != NULL)
	{
		cout << endl << k->value.first;
		k = k->next;
	}
}

int kolejka::size()
{
	return this->licznik;
}

bool kolejka::empty()
{
	if (this->begin)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void kolejka::clear()
{
	if (this->licznik == 0)
	{
		return;
	}
	else
	{
		while (this->licznik != 0)
		{
			this->pop();

		}

	}
}

kolejka::kolejka()
{
	this->begin = NULL;
	this->licznik = 0;
}
