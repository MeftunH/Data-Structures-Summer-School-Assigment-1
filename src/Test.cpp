/*
* @file Test.cpp
* @description Test programi icin gerekli kodlari bulundurur.Programin calistirilmasi dosyadan okuma cop temizlenmesinin tetiklenmesi
* @course 1A
* @assigment Odev 1
* @date 16.08.2020
* @author Maftun Hashimli
*/
#include "CircularDoublyLinkedList.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    int rakam;
    const int maxchar = 1024; //degiskenleri olustur
    CircularDoublyLinkedList* list; //listeyi olustur ama daha atama
    char icerik[maxchar];
    ifstream input("./doc/Sayilar.txt"); //dosyayi ac
    while(!input.eof())  //dosyanin sonuna kadar
    {
        input.getline(icerik, maxchar);  //line by line oku
        list= new CircularDoublyLinkedList(); //burada tanimla listeyi
    int i = 0;
    int j;
    for (; icerik[i] != '\0';) //ben char char okuyorum
    {
        char sayichar[50] = { 0 }; 
        for (j = 0; icerik[i] != '\0'; j++, i++) //gelen sayiyi aliyorum bosluk gelinceye kadar dongu devam edecek
        {
            if (icerik[i] == ' ')
            {
                i++;
                break; //bosluk gelirse sayiyi almisim demektir
            }
            else
            {
                sayichar[j] = icerik[i]; //diger turlu diziye atacak
                rakam = stoi(sayichar); //char'i inte ceviriyorum
            }

        }
      
      list->Add(rakam); //listeye ekliyorum
     
    }  
    cout<<"Sifre: ";
    list->Print();  //listeyi yazdiriyorum 
     delete list; //copu temizle
     list=new CircularDoublyLinkedList(); //yeni liste
     }  
    input.close(); //dosyayi kapat
  
    return 0;
}
