/*
* @file CircularLinkedList.cpp
* @description CircularLinkedList sinifinin metodlarinin govdelerini bulundurur
* @course 1A
* @assigment Odev 1
* @date 16.08.2020
* @author Maftun Hashimli
*/

#include "CircularDoublyLinkedList.h"
#include "Iterator.h"
#include <iostream>
using namespace std;

int CircularDoublyLinkedList::Count() //listenin sizeini donduruyor
{
	return size;
}

Iterator CircularDoublyLinkedList::IterateFromPrevIndex(int index) //verilen indexten sona kadar geizyor
{
	if (!(index < 0 || index > Count())) 
	{
		int i = 0;
		Iterator itr(basdugum);
		while (!itr.IsEndNode() && index != i++)  //eger iterator son dugumde degilse 
		{
			itr.StepNext(); //sonrakine gec
		}
		return itr; //ve iteratoru dondur
	}
	return NULL;
}
Iterator CircularDoublyLinkedList::IterateFromFirstNode() //ilk dugumden sona kadar geziyor
{
	if (!IsEmpty())
	{
		return Iterator(basdugum->ileri);
	}
	return NULL;
}
CircularDoublyLinkedList::CircularDoublyLinkedList()
{
	DegistiMi = false;
	basdugum = new Dugum(0, NULL, NULL);
	obeb = 0;
	enbuyukobeb = 0;
	size = 0;
}
bool CircularDoublyLinkedList::IsEmpty()
{
	return size == 0;
}

void CircularDoublyLinkedList::Add(int sayi)
{
	int mod = 0;

	if (Count() == 0)  //eger ilk eleman gelecekse buraya giriyor nede olsa karsilastirmamiza gerek yok.Elimizde karsilastiracagimiz birsey yok
	{
		obeb = 0;
		enbuyukobeb = 0;
		Insert(0, sayi); //0 indexine ekle
		mod = 0;
	}
	else 
	{
		Iterator itr(basdugum->ileri); //iretoru olustur
		int tempenbuyukobeb = 0;
		int sayac = 0;
		Dugum *tmp = basdugum; 
		
		while (sayac != Count()) //listenin basindan sonuna kadar gitmek icin
		{
			int tempindex = -1;
			tempindex = IndexOf(itr.current);
			sayac++;

			obeb = ObebBul(itr.GetCurrentData(), sayi); //yeni eklenen sayiyla iteratorun suanda bulundugu dugumun verisini karsilastiriyor

			if (enbuyukobeb <= obeb) //eger eklenen sayiyila suanki dugumdeki verinin obebi eski obebden buyukse giriyor
			{
				DegistiMi = true; //enbuyuk obeb degisecek
				enbuyukobeb = obeb; //artik en buyuk obeb yeni gelen olacak
				break;
			}
			if (sayac == Count()) //listenin sonuna gelindiginde obeb degismeyecek ama  o dugumde kalmamiz lazim oyuzden true olacak
			{
				DegistiMi = true;
				break;
			}
			itr.StepNext();
		}
		if (DegistiMi == true) //enbuyuk obeb degismisse
		{
			for (itr; !itr.IsEndNode(); itr.StepNext()) 
			{
				//yeni gelen sayiyla icinde bulunulan dugumun verisinin modunu aliyor
				if (itr.GetCurrentData() == 0 || sayi == 0)
				{
					mod = 0;
				}
				else if (itr.GetCurrentData() > sayi)
				{
					mod = itr.GetCurrentData() % sayi;
				}
				else if (itr.GetCurrentData() < sayi)
				{
					mod = sayi % itr.GetCurrentData();
				}
				else if (itr.GetCurrentData() == sayi)
				{
					mod = sayi % itr.GetCurrentData();
				}
				//mod 0'a esitse
				if (mod == 0)
				{

					if (!itr.IsEndNode())
					{
						//eger son dugum degilse bir sagina ekliyoruz
						Insert(IndexOf(itr.current) + 1, sayi);
						break;
					}
					else
					{
						//eger son dugumse liste sonuna ekliyoruz
						Insert(Count(), sayi);
						break;
					}
				}
				if (mod != 0)
				{
					
					int sayac = 0, tmpIndex = -1;
					bool tmp = false;
					//mod kadar geriye git
					for (itr = IterateFromPrevIndex(IndexOf(itr.current) + 1); sayac != mod; itr.StepBack())
					{
						sayac++;
						tmpIndex = IndexOf(itr.current);
						//liste basina geldiysen oraya ekle
						if (tmpIndex == 0)
						{
							Insert(0, sayi);
							tmp = true;
							break;
						}
					}
					//liste basina gelmediysen durdugun indexe ekle sayiyi
					if (tmp == false)
						Insert(tmpIndex, sayi);
					break;
				}
			}
		}
	}
}

void CircularDoublyLinkedList::Insert(int index, int sayi)
{
	Iterator itr;
//iterator olsutur
	itr = IterateFromPrevIndex(index);
	//Eklecek dugumun ilerisi icin yer ac
	Dugum *yeniIleri = itr.current->ileri;
	//dugumu olustur
	itr.current->ileri = new Dugum(sayi, yeniIleri, itr.current);
	//son degilse
	if (yeniIleri != NULL)
	{
		//Dariesel liste mantigiyla ekle
		Dugum *son = yeniIleri->geri;
		yeniIleri->geri = itr.current->ileri;
		//eger listede 1 eleman varsa zaten kendi basi kendi sonuna esit olacak
		if (index == 0)
		{
			basdugum->ileri->geri = son;
			son->ileri = basdugum->ileri;
		}
	}

	if (Count() == 0)
	{
		basdugum->ileri->ileri = basdugum->ileri;
		basdugum->ileri->geri = basdugum->ileri;
	}
	//yeni dugum eklendigi icin size da artacak
	size++;
}

int CircularDoublyLinkedList::IndexOf(Dugum *dgm)
{
	int index = 0;
	Iterator *itr = new Iterator(basdugum->ileri);

	for (itr; index < Count(); itr->StepNext()) //bastan sona gez
	{
		//dugumu buldugunda indexini geri dondur
		if (itr->current == dgm)
		{
			return index;
		}
		index++;
	}
	return -1;
}

void CircularDoublyLinkedList::Print()
{
	int sayac = 0;
	Iterator *itr = new Iterator(basdugum->ileri);
	//bastan sona gez
	for (itr; sayac < Count(); itr->StepNext())
	{
		sayac++;
		//cout << itr->GetCurrentData() << " ";
		//listedeki sayilari char olarak bas
		cout << char(itr->GetCurrentData());
	}
	cout << endl;
}

int CircularDoublyLinkedList::ObebBul(int sayi1, int sayi2)
{
	while (sayi1 != sayi2)
	{
		if (sayi1 == 0 || sayi2 == 0)
		{
			return 0;
			break;
		}
		if (sayi1 > sayi2)
			sayi1 = sayi1 - sayi2;
		else if (sayi2 > sayi1)
			sayi2 = sayi2 - sayi1;
	}
	return sayi1;
}
void CircularDoublyLinkedList::Remove(Dugum *silinecek)
{
	Iterator *itr = new Iterator(basdugum->ileri);
	int index = IndexOf(itr->current);
	//o indexdeki dugumu sil
	RemoveAt(index);
}
void CircularDoublyLinkedList::RemoveAt(int index)
{
	Iterator itr;
	itr = IterateFromPrevIndex(index);
	if (itr.current->ileri != NULL)
	{
		Dugum *oldNode = itr.current->ileri;
		//Eski dugum iteraoturn ilerisiydi simdi ilerisinin ilerisi oldu yani datasi oldu
		itr.current->ileri = itr.current->ileri->ileri;
		//data null degilse
		if (oldNode->ileri != NULL)
			oldNode->ileri->geri = oldNode->geri; //esksini listeden kaldirmis olduk
		delete oldNode; //copu temizle
		size--;
	}
}
void CircularDoublyLinkedList::Clear()
{
	//bos olana kadar silmeye devam et
	while (!IsEmpty())
	{
		RemoveAt(0);
	}
}
CircularDoublyLinkedList::~CircularDoublyLinkedList()
{
	Clear();
	//en sonda bas dugumu siliyoruz
	delete basdugum;
}