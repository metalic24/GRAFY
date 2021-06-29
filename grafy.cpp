// grafy.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//




// 1-reprezentacja listowa
// 2- reprezentacja macierzowa

#include <iostream>
#include<fstream>
#include"lista.h"
#include"kolejka.h"
#include"funkcje.h"
#include<time.h>
#include<stdio.h>
#include<Windows.h>

using namespace std;

clock_t start, stop;
double czas;

float listowa[4], macierzowa[4]; //przechowują czasy dla wierzcholkow od gestosci

const int  MAXN = 300000;

long long INF = LONG_MAX;

lista *graf[MAXN];//do przechowywania reprezentacji listy sasiadow
long long graf2[10000][10000]; //do przechowywania macierzy

long long droga[MAXN]; //droga
long long droga2[MAXN];

kolejka* kol;  //kolejka piorytetowa
kolejka* kol2;

bool odw[MAXN]; //tablica odwiedzonych
bool odw2[MAXN];

void wygeneruj(int ile_wierzcholkow, float gestosc, string nazwa);
bool czy_wylosowana(long long tab_pocz[], long long tab_kon[], int pocz, int kon, long long ile);

void Dijkstry(int start);
void Dijkstry2(int start, int ile_wierzcholkow);
void eksperyment();

int main()
{
	

	string nazwa="plik.txt";
	int wybor = 0;
	int wierzcholki;
	float gestosc;
	int x;  // ile krawedzi
	int y; //ile wierzcholkow
		//zmienne do wczytania z pliku a-poczatek b- koniec c-waga krawedzi
	int a, b, c;
	fstream plik;
	

	//eksperyment();
	cout << "Witaj gicie";



	do
	{
		cout << endl;
		cout << endl << "[1] wczytaj z pliku";
		cout << endl << "[2] wygeneruj";
		cout << endl << "[3] wyswietl";
		cout << endl << "[4] Dijkstry";
		cout << endl << "[5]koniec";
		cout << endl;
		cin >> wybor;
		switch (wybor)
		{
		case 1:
			cout << endl << "[1] podanie nazwy pliku";
			cout << endl << "[2] domyslny plik" << endl;
			int wybor2;
			cin >> wybor2;
			if (wybor2 == 1)
			{
				cout << endl;
				cout << "Podaj sciezke do pliku: ";
				cin >> nazwa;
			}
			else
			{
				nazwa = "plik.txt";
			}
			plik.open(nazwa, ios::in | ios::out);

			
			if (!plik.good())
			{
				cout << "Blad pliku";
			}
			else
			{



				//wczytanie 1 wiersza
				plik >> x;
				plik >> y;




				for (int h = 0; h < x; h++)
				{
					graf[h] = new lista();
					graf[h]->clear();
				}

				while (!plik.eof())
				{
					plik >> a >> b >> c;


					graf[a]->push({ b,c }); //wczytywanie do listy
					graf2[a][b] = c; //wszytywanie do macierzy
				}
			}
			plik.close();
		
				
			
			break;

		case 2:

			cout << endl;
			cout << endl << "ile wierzholkow? ";
			cin >> y;
			cout << endl << "Jaka gestosc: (w %)  ";
			do
			{
				cin >> gestosc;

			} while (gestosc <= 0 && gestosc >= 100);
			//nazwa = "plik.txt";
			wygeneruj(y, gestosc / 100, nazwa);
			




		


			break;

		


			

		case 3:

			
			cout << endl;
	
			cout << endl;
		for (int i = 0; i < y; i++)
		{
			cout<<"|";
			
			for (int j = 0; j <y; j++)
			{

				cout << graf2[i][j];
			}
			cout << "|";
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i < y; i++)
		{
			cout << "sasiedzi wieszcholka " << i << " to:";
			graf[i]->wyswietl();
			cout << endl;

		}
			

			

			break;
		case 4:

		
			int pocz;
			int kon;
			cout << endl << "Podaj poczatek: ";
			cin >> pocz;
			cout << "Podaj koniec: ";
			cin >> kon;
			kol = new kolejka();
			Dijkstry(pocz);
			kol2 = new kolejka();
			Dijkstry2(pocz, y);

		

			for (int i = 0; i < y; i++)
			{
				if (droga[i] == INF)
				{
					droga[i] = -1;
				}
				
				

			}
			cout << endl;
			if (droga[kon] == -1)
			{
				cout << "Nie ma drogi z wierzcholka " << pocz << " do wierzcholka " << kon;
			}
			else
			{
				cout << "Najkrotsza droga z wierzcholka " << pocz << " do wierzcholka " << kon << " wynosi: " << droga[kon];
			}

			for (int i = 0; i < y; i++)
			{
				if (droga2[i] == INF)
				{
					droga2[i] = -1;
				}


			}
			cout << endl;
			if (droga2[kon] == -1)
			{
				cout << "Nie ma drogi z wierzcholka " << pocz << " do wierzcholka " << kon;
			}
			else
			{
				cout << "Najkrotsza droga z wierzcholka " << pocz << " do wierzcholka " << kon << " wynosi: " << droga2[kon];
			}
		
			break;

			



		}
	} while (wybor < 5);




	









	


}




void Dijkstry(int start)
{
	for (int i = 0; i < MAXN; i++)
	{
		droga[i] = INF;
		odw[i] = false;

	}
	
	droga[start] = 0;
	kol->push({ 0,start });
	while (kol->licznik!=0)
	{
		
		long long x = kol->top()->value.second;
		kol->pop();
		
		if (!odw[x])
		{
			
			odw[x] = true;

			
			for (int i = 0; i < graf[x]->size(); i++)
			{

				long long v = graf[x]->wartosc_first(i);


				long long w = graf[x]->wartosc_second(i);


				if (droga[v] > droga[x] + w)
				{
					droga[v] = droga[x] + w;


				}

				kol->push({ -droga[v],v });
			
			}
			
		}

	}
}



void Dijkstry2(int start, int ile_wierzcholkow)
{
	for (int i = 0; i < MAXN; i++)
	{
		droga2[i] = INF;
		odw2[i] = false;

	}

	droga2[start] = 0;
	kol2->push({ 0,start });

	while (kol2->licznik !=0)
	{

		long long x = kol2->top()->value.second;
		kol2->pop();

		if (!odw2[x])
		{

			odw2[x] = true;


			for (int i = 0; i <ile_wierzcholkow; i++)
			{
				if (graf2[x][i]!=0)
				{
					long long v = i;


					long long w = graf2[x][i];
					

					if (droga2[v] > droga2[x] + w)
					{
						droga2[v] = droga2[x] + w;


					}

					kol2->push({ -droga2[v],v });
				}
				
			}
		
		}

	}
}

void eksperyment()
{
	int ile_wierzch = 200;
	float gestosc[4] = { 0.25,0.5,0.75,0.9 };
	int ile_prob = 50;


	//zmiana wierzcholka


		//zmiana gestosci
	for (int g = 0; g < 4; g++)
	{





		//ile prob
		for (int p = 0; p < ile_prob; p++)
		{
			cout << endl << "Proba " << p;
			wygeneruj(ile_wierzch, gestosc[g], "plik.txt");



			kol = new kolejka();

			start = clock();
			Dijkstry(ile_wierzch/2);
			stop = clock();
			czas = (double)(stop - start) / CLOCKS_PER_SEC;
			listowa[g] += czas;
			kol->clear();


			kol2 = new kolejka();

			start = clock();
			Dijkstry2(ile_wierzch/2, ile_wierzch);

			stop = clock();
			czas = (double)(stop - start) / CLOCKS_PER_SEC;
			macierzowa[g] += czas;

			kol2->clear();

			/*for (int i = 0; i < ile_wierzch; i++)
			{
				if (droga[i] == INF)
				{
					droga[i] = -1;
				}
				else
				{
					cout << "droga do wierzchilka " << i << ": " << droga[i] << endl;
				}

			}
			cout << endl << endl;


			for (int i = 0; i < ile_wierzch; i++)
			{
				if (droga2[i] == INF)
				{
					droga2[i] = -1;
				}
				else
				{
					cout << "droga do wierzchilka " << i << ": " << droga2[i] << endl;
				}

			}*/
			//for (int i = 0; i < ile_wierzch; i++)
			//{
			//	if (droga[i] == INF)
			//	{
			//		droga[i] = -1;
			//	}
			//	if (droga2[i] == INF)
			//	{
			//		droga2[i] = -1;
			//	}

			//	//if (droga[i] != droga2[i])
			//	//{

			//	//	//cout << "roznica dla wierzcholka: " << i << " " << droga[i] << " " << droga2[i] << endl;
			//	//	cout << endl;
			//	//	cout << "jest dla "<<i;
			//	//	//graf[i]->wyswietl();
			//
			//	//}
			//
			//	}

		}


		for (int h = 0; h < ile_wierzch; h++)
		{
			delete graf[h];
		}
		delete kol;
		delete kol2;
		for (int i = 0; i <= ile_wierzch; i++)
		{

			for (int j = 0; j <= ile_wierzch; j++)
			{
				graf2[i][j] = 0;
			}
			droga[i] = -1;
			droga2[i] = -1;
			odw[i] = false;
			odw2[i] = false;
		}

		//wygeneruj(ile_wierzch, gestosc[g], "plik.txt");


		cout << endl << endl;
		cout << endl << "Czas wykonywania algorytmu Dijkstry dla grafu skladajacego sie z " << ile_wierzch <<
			" wierzcholkow oraz o gestosci " << gestosc[g] * 100 << "% z wierzcholka " << ile_wierzch / 2 << " wynosi: ";
		cout << endl << "Listowo: " << srednia(listowa[g], ile_prob) << "s.";
		cout << endl << "Macierzowo: " << srednia(macierzowa[g], ile_prob) << "s.";
	}

}


void wygeneruj(int ile_wierzcholkow, float gestosc, string nazwa)
{
	srand(time(NULL));
	long long ile_krawedzi = 0;
	ile_krawedzi = (long long)(gestosc * ile_wierzcholkow * (ile_wierzcholkow - 1)) ; // liczy ile będzie krawedzi ze wszystkich możliwych 

	long long poczatek;
	long long koniec;
	int waga;
	long long* tab_pocz = new long long[ile_krawedzi];
	long long* tab_kon = new long long[ile_krawedzi];
	
	//fstream plik;

	//plik.open(nazwa, ios::in | ios::out);
	

	
	for (int h = 0; h < ile_wierzcholkow; h++)
	{
		graf[h] = new lista();

	}

	//plik<< ile_krawedzi << " " << ile_wierzcholkow << endl;
	

	for (long long i = 0; i < ile_krawedzi; i++)
	{
		do
		{
			poczatek = rand() % ile_wierzcholkow;
			koniec = rand() % ile_wierzcholkow;
		} while (czy_wylosowana(tab_pocz, tab_kon, poczatek, koniec, i) || koniec == poczatek);


		tab_pocz[i] = poczatek;
		tab_kon[i] = koniec;

		waga = rand() % 10 + 1;

		//plik << poczatek << " " << koniec << " " << waga << endl;
		
		graf[poczatek]->push({ koniec,waga });
		graf2[poczatek][koniec] = waga;
	}

	//plik.close();
	
	delete[] tab_kon;
	delete[] tab_pocz;
}

bool czy_wylosowana(long long  tab_pocz[], long long tab_kon[], int pocz, int kon, long long ile)
{
	for (long long i = 0; i <ile; i++)
	{
		if ((tab_pocz[i] == pocz && tab_kon[i] == kon))
		{
			return true;
		}
	}
	return false;
}
