/*
* @file Dugum.cpp
* @description Dugum sinifinin metodlarinin govdelerini bulundurur
* @course 1A
* @assigment Odev 1
* @date 16.08.2020
* @author Maftun Hashimli
*/

#include "Dugum.h"
using namespace std;
Dugum::Dugum(int data, Dugum* ilr, Dugum* gr) //Kurucu fonk
{
    this->data = data;
   ileri = ilr;
   geri = gr;
}

int Dugum::GetirData()
{
    return data;
}
Dugum::~Dugum()
{

}