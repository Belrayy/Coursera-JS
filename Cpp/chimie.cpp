#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Flacon
{
private:
  string Nom;
  double Volume;
  double pH;

public:
  /*****************************************************
    Compléter le code à partir d'ici
  *******************************************************/
  string getNom(void) const
  {
    return Nom;
  }
  double getVolume(void) const
  {
    return Volume;
  }
  double getPH(void) const
  {
    return pH;
  }

  Flacon(string n, double v, double p) : Nom(n), Volume(v), pH(p) {}

  ostream &etiquette(ostream &sortie) const
  {
    sortie << Nom << " : " << Volume << " ml, pH " << pH << endl;
    return sortie;
  }
};
ostream &operator<<(ostream &sortie, Flacon const &z)
{
  return z.etiquette(sortie);
}

const Flacon operator+(Flacon const &flac1, Flacon const &flac2)
{
  string nom = flac1.getNom() + " + " + flac2.getNom();
  double vol = flac1.getVolume() + flac2.getVolume();
  double pH = -log10((flac1.getVolume() * pow(10, -flac1.getPH()) + flac2.getVolume() * pow(10, -flac2.getPH())) / (flac1.getVolume() + flac2.getVolume()));
  Flacon flac(nom, vol, pH);
  return flac;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void afficher_melange(Flacon const &f1, Flacon const &f2)
{
  cout << "Si je mélange " << endl;
  cout << "\t\"" << f1 << "\"" << endl;
  cout << "avec" << endl;
  cout << "\t\"" << f2 << "\"" << endl;
  cout << "j'obtiens :" << endl;
  cout << "\t\"" << (f1 + f2) << "\"" << endl;
}

int main()
{
  Flacon flacon1("Eau", 600.0, 7.0);
  Flacon flacon2("Acide chlorhydrique", 500.0, 2.0);
  Flacon flacon3("Acide perchlorique", 800.0, 1.5);

  afficher_melange(flacon1, flacon2);
  afficher_melange(flacon2, flacon3);

  return 0;
}
