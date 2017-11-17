#pragma once
#ifndef HANGMAN_H
#define HANGMAN_H

//#include <string>
#include <vector>
#include <io.h>
#include <fstream>
//#include <iostream>
#include <ctime>

class hangman
{
private:
 // public:
	std::vector<std::string> tablicaPlikow;
	std::vector<std::vector<std::string>> tablicaImion;
	std::string nie_ukryte;
	std::string ukryte;
    int a ,c ;
    unsigned bledy, przejsc;
    std::string kategoria;

public:
	hangman();
	~hangman();
	void wczytaj();
	void losuj();
	void ukryj();
	void graj(char);
    void setKategoria();
    void restart();
    bool czyWygralem();
    std::string getKategoria();
    unsigned getBledy();
    std::string getUkryte();
    std::string getNie_ukryte();
};

#endif
