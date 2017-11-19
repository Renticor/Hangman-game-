#pragma once
#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>
#include <vector>
#include <io.h>
#include <fstream>
//#include <iostream>
#include <ctime>

class hangman
{
private:
 // public:
    std::vector<std::string> tablicaKategori;           //wektor zawierajacy nazwy kaetgorii z nazw plikow
    std::vector<std::vector<std::string>> tablicaHasel; //wektor 2 wymiarowy z haslami z zawartosci poszczegolnych plikow
    std::string nie_ukryte;                 //wylosowane haslo i nie zasloniete '_'
    std::string ukryte;                     //wylosowane haslo i zasloniete
    std::string kategoria;                  //nazwa kategori z ktorej pochodzi haslo
    int indeksKategoria ,indeksHasla ;      //indeksy do pliku kategori i hasla
    unsigned bledy;                         //bledne podanie litery

public:
    hangman();                  //konstruktor
    ~hangman();                 //destruktor
    void wczytaj();             //funkcja wczytuje do wektorow nazwy kategori i hasla
    void losuj();               //funkcja losuje indeksy do kategorii, hasla i przypisuje je
    void ukryj();               //funkcja zaslania haslo wylosowane w ukryte znakiem '_'
    void setKategoria();        //funkcja z ustawiajaca nazwe kategori !".txt"
    void graj(char);            //funkcja sprawdza czy podany znak jest w nie_ukryte
    void restart();             //funkcja zeruje zmienne
    bool czyWygralem();         //funkcja sprawdza
    unsigned getBledy();        //
    std::string getKategoria(); //
    std::string getUkryte();    //
    std::string getNie_ukryte();//
};

#endif
