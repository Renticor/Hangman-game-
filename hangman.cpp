#include "hangman.h"
/***************************************************************************/
hangman::hangman():bledy(0),tablicaPlikow(),tablicaImion(),kategoria(""),a(-1),c(-1),nie_ukryte(""),ukryte(""),przejsc(0)
{}
/***************************************************************************/
hangman::~hangman()
{
    for(unsigned i=0;i<tablicaPlikow.size();++i)
    {
        tablicaImion[i].clear();
    }
    tablicaImion.clear();
    tablicaPlikow.clear();
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
				tablicaPlikow.push_back(danePliku.name);
				std::vector< std::string> tmp;
				while (std::getline(plik, linia)) {//poki jest jakas linia w pliku

                    for (unsigned i = 0; i < linia.length(); ++i)
					{
						linia[i] = toupper(linia[i]);
					}

					tmp.push_back(linia);
				}
				tablicaImion.push_back(tmp);
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

    a = rand() % tablicaPlikow.size();
    if(a!=-1){
	c = rand() % tablicaImion[a].size();
    if(c!=-1)
    {
	ukryte = nie_ukryte = tablicaImion[a][c];
    }}
    else{ukryte = nie_ukryte ="a<0";}

    }
/***************************************************************************/
void hangman::setKategoria()
{
std::string tmp=tablicaPlikow[a];
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
void hangman::graj(char cos)
{
	int  czy_zmieniono = 0;
    for (unsigned i = 0; i < ukryte.length(); ++i)
	{
		if ((int)nie_ukryte[i] == (int)cos && ukryte[i] != cos)
		{
			czy_zmieniono++;
			ukryte[i] = cos;
			//std::cout << ukryte[i] << " " << i << " " << abec<< " w " << std::endl;
		}
		//std::cout << (int)nie_ukryte[i] << " " << i << " " << (int)abec <<" poza "<<std::endl;
	}
	if (czy_zmieniono == 0)
	{
        ++bledy;
	}
    //for (unsigned i = 0; i < ukryte.length(); i++)
    //{
        //std::cout << ukryte[i] << " ";

    //}
	przejsc += czy_zmieniono;
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

 void hangman::restart()
 {
bledy=0;
przejsc=0;
a=-1;
c=-1;
 kategoria="";
 }

bool hangman::czyWygralem()
{
    if(ukryte==nie_ukryte && ukryte!="")
        return true;
    return false;
}
