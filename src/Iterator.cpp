/*
* @file Iterator.cpp
* @description Iterator sinifinin metodlarinin govdelerini bulundurur
* @course 1A
* @assigment Odev 1
* @date 16.08.2020
* @author Maftun Hashimli
*/
#include "Iterator.h"
#include <cstddef>
using namespace std;
Iterator::Iterator()
{
    current = NULL;
}
Iterator::Iterator(Dugum* current)
{
    this->current = current;
}
bool Iterator::IsEndNode()
{
    return current == NULL;
}
void Iterator::StepNext()
{
    if (!IsEndNode())
    {
        current = current->ileri; //Son dugume gelinmemisse sonraki dugume gec
    }
}
void Iterator::StepBack()
{
    if (!IsEndNode())
    {
        current = current->geri; //Dairesel oldugu icin bunda da son dugume gelinmemisse onceki dugume gec
    }
}

int Iterator::GetCurrentData()
{
    return current->GetirData(); //simdiki dugumun verisini getir
}