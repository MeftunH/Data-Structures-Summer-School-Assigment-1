/*
* @file Dugum.h
* @description Dugumun olusturuldugu sinifin head dosyasi.Dugum sinifindaki public ve private sekmelerinde sinifa ait metodalari ve degiskenleri bulundurur.Metodalarin deklerasyonlarini bulundurur.
* @course 1A
* @assigment Odev 1
* @date 16.08.2020
* @author Maftun Hashimli
*/
#ifndef DUGUM_H
#define DUGUM_H
#include <iostream>
using namespace std;
class Dugum
{
private:
    int data; //dugumun int datasi
public:
    Dugum* ileri; //ileri verisi
    Dugum* geri;   //geri verisi
    Dugum(int data, Dugum* ilr=NULL, Dugum* gr=NULL); //constructor
    int GetirData(); //dugumun icindeki veriyi getiren metot
    ~Dugum(); //Yikici fonksiyon
};
#endif