/*
* @file CircularDoublyLinkedList.h
* @description :Listenin olusturuldugu sinifin head dosyasi.Liste sinifindaki public ve private sekmelerinde sinifa ait metodalari ve degiskenleri bulundurur.Metodalarin deklerasyonlarini bulundurur.
* @course 1A
* @assigment Odev 1
* @date 16.08.2020
* @author Maftun Hashimli
*/

#ifndef CircularDoublyLinkedList_H
#define CircularDoublyLinkedList_H
#include "Iterator.h"
#include "Dugum.h"

class  CircularDoublyLinkedList
{
private:
    int size;
    int enbuyukobeb;
    int obeb;
    Dugum* basdugum;
public:
    Iterator IterateFromPrevIndex(int index);
    Iterator IterateFromFirstNode();
    CircularDoublyLinkedList();
    bool DegistiMi; //enbuyukobeb in degisip degismedigini kontrol ediyor
    int Count();
    int IndexOf(Dugum*); //o anki dugumun indexini donduruyor
    bool IsEmpty();
    void Add(int);
    void Insert(int index, int sayi); //indexle ekleme
    void Print();
    int ObebBul(int sayi1,int sayi2); 
    void Remove(Dugum*); //kaldirma
    void RemoveAt(int index); //indexle kaldirma
    void Clear();
    ~CircularDoublyLinkedList();
};

#endif