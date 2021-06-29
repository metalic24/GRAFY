#include "lista.h"

element::element()
{
	this->next = NULL;
	this->value = { NULL,NULL };
}

element::~element()
{
	
}

void lista::push(pair<long long, long long> para)
{
	element* temp = new element();
	temp->value = para;
	if (this->begin== NULL)
	{
		this->begin = temp;
		temp->next = NULL;
	}
	else
	{
		element* k = new element();
		k = this->begin;
		while (k->next != NULL)
		{
			k = k->next;
		}

		k->next = temp;
		temp->next = NULL;

	}

	this->licznik++;



	
}

void lista::pop()
{
	element* temp = new element();

	temp = this->begin;
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

element * lista::top()
{
	element *temp= new element();
	temp = this->begin;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}

	return  temp;
}

void lista::wyswietl()
{
	element* k = new element();
	k = this->begin;
	while (k != NULL)
	{
		cout << " "<<k->value.first;
		k = k->next;
	}
}

int lista::size()
{
	
	return this->licznik;
}

void lista::clear()
{
	

	if (this->licznik==0)
	{
		return;
	}
	else
	{
		while (this->licznik!=0)
		{
			this->pop();
			
		}
		
	}
	this->begin = NULL;

}

int lista::wartosc_first(int x)
{
	element* temp = new element();
	temp = this->begin;
	
	
		for (int i = 0; i < x; i++)
		{
			if (temp->next != NULL)
			{
				temp = temp->next;
			}
			
		}
		return temp->value.first;
	
	

}

int lista::wartosc_second(int x)
{
	element* temp = new element();
	temp = this->begin;
	
		for (int i = 0; i < x; i++)
		{
			if (temp->next != NULL)
			{
				temp = temp->next;
			}

		}
		return temp->value.second;
	

}

lista::lista()
{
	this->begin = NULL;
	this->licznik = 0;
}

lista::~lista()
{
	
}
