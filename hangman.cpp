#include "hangman.h"
/***************************************************************************/
hangman::hangman():bledy(0),tablicaKategori(),tablicaHasel(),kategoria(""),indeksKategoria(-1),indeksHasla(-1),nie_ukryte(""),ukryte("")
{}
/***************************************************************************/
hangman::~hangman()
{
    for(unsigned i=0;i<tablicaKategori.size();++i)
    {
        tablicaHasel[i].clear();
    }
    tablicaHasel.clear();
    tablicaKategori.clear();
}
/***************************************************************************/
void hangman::wczytaj()
{
	_finddata_t danePliku;
	std::string b = "kategorie/", linia = "";
	long long uchwyt = _findfirst("kategorie/*.txt", &danePliku);//jak to zrobc lepiej ?
	int SzukamDalej = 1;
	if (uchwyt != -1)
	{
		while (SzukamDalej != -1)
		{
			std::ifstream plik;	//
			plik.open(b + danePliku.name, std::ios::in);//proba otwarcia pliku
			if (plik.good()) {//jesli otwarto
                tablicaKategori.push_back(danePliku.name);
				std::vector< std::string> tmp;
				while (std::getline(plik, linia)) {//poki jest jakas linia w pliku
                    for (unsigned i = 0; i < linia.length(); ++i)
					{
						linia[i] = toupper(linia[i]);
					}
					tmp.push_back(linia);
				}
                tablicaHasel.push_back(tmp);
				plik.close();
			}
            //std::cout << plik.is_open() << "\t" << std::endl;
			SzukamDalej = _findnext(uchwyt, &danePliku);
		}
		_findclose(uchwyt);
	}
}
/***************************************************************************/
void hangman::losuj()
{
	srand(time(NULL));

    indeksKategoria = rand() % tablicaKategori.size();
    if(indeksKategoria!=-1){
    indeksHasla = rand() % tablicaHasel[indeksKategoria].size();
    if(indeksHasla!=-1)
    {
    ukryte = nie_ukryte = tablicaHasel[indeksKategoria][indeksHasla];
    }}
    else{
        ukryte = nie_ukryte ="a<0";
       // break;
    }

    }
/***************************************************************************/
void hangman::setKategoria()
{
std::string tmp=tablicaKategori[indeksKategoria];
int i=0;
while(tmp[i]!='.')
{
    kategoria+=tmp[i];
    ++i;
}
}
/***************************************************************************/
void hangman::ukryj()
{

    for (unsigned i = 0; i < ukryte.length(); i++)
	{
		ukryte[i] = '_';
	}
}
/***************************************************************************/
void hangman::graj(char _znak)
{
    int  czyZmieniono = 0;
    for (unsigned i = 0; i < ukryte.length(); ++i)
	{
        if ((int)nie_ukryte[i] == (int)_znak && ukryte[i] != _znak)
		{
            czyZmieniono++;
            ukryte[i] = _znak;
			//std::cout << ukryte[i] << " " << i << " " << abec<< " w " << std::endl;
		}
		//std::cout << (int)nie_ukryte[i] << " " << i << " " << (int)abec <<" poza "<<std::endl;
	}
    if (czyZmieniono == 0)
	{
        ++bledy;
	}
    //for (unsigned i = 0; i < ukryte.length(); i++)
    //{
        //std::cout << ukryte[i] << " ";

    //}
    //std::cout << "\n";
}
/***************************************************************************/
std::string hangman::getKategoria()
{
    return kategoria;
}
/***************************************************************************/
unsigned hangman::getBledy()
{
    return bledy;
}
/***************************************************************************/
std::string hangman::getUkryte()
{

    return ukryte;

}/***************************************************************************/
std::string hangman::getNie_ukryte()
{
    return nie_ukryte;
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
 void hangman::restart()
 {
bledy=0;
indeksKategoria=-1;
indeksHasla=-1;
 kategoria="";
 }
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
bool hangman::czyWygralem()
{
    if(ukryte==nie_ukryte && ukryte!="" && bledy<6)
        return true;
    return false;
}
