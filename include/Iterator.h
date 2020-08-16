/*
* @file Iterator.h
* @descriptionIteratorun olusturuldugu sinifin head dosyasi.Iterator sinifindaki public ve private sekmelerinde sinifa ait metodalari ve degiskenleri bulundurur.Metodalarin deklerasyonlarini bulundurur.
* @course 1A
* @assigment Odev 1
* @date 16.08.2020
* @author Maftun Hashimli
*/

#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include "Dugum.h"

class Iterator
{
public:
	Dugum* current; //Gezicinin gezmesi icin o anki dugum
	Iterator();
	Iterator(Dugum* dugum);
	bool IsEndNode(); //listenin sonuna gelinmismi
	void StepNext(); //Sonraki dugume gecme
	void StepBack(); //onceki dugume gecme
	int GetCurrentData();
};

#endif