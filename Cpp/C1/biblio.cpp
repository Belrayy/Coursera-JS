#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*******************************************
 * Completez le programme a partir d'ici.
 *******************************************/
// Chaines de caractÃ¨res Ã  utiliser pour les affichages:
/*

Ã©tÃ© jetÃ©

d'un

n'est

L'oeuvre

bibliothÃ¨que

dÃ©truit

*/

class Auteur
{
private:
     string Nom;
     bool Prime;

public:
     Auteur(string n, bool p = false) : Nom(n), Prime(p) {}
     string getNom() const { return Nom; }
     bool getPrix() const { return Prime; }
};

class Oeuvre
{
private:
     string Titre;
     Auteur &Aut;
     string Langue;

public:
     Oeuvre(string t, Auteur &a, string l) : Titre(t), Aut(a), Langue(l) {};
     string getTitre() const { return Titre; }
     Auteur getAuteur() const { return Aut; }
     string getLangue() const { return Langue; }
     void afficher() const { cout << Titre << ", " << Aut.getNom() << ", en " << Langue << endl; }
     ~Oeuvre() { cout << "L'oeuvre \"" << Titre << ", " << (Aut).getNom() << ", en " << Langue << "\" n'est plus disponible.\n"; }
     Oeuvre(Oeuvre const &) = delete;
};

class Exemplaire
{
private:
     Oeuvre &Oeuv;

public:
     Exemplaire(Oeuvre &o) : Oeuv(o)
     {
          cout << "Nouvel exemplaire de : " << Oeuv.getTitre() << ", " << Oeuv.getAuteur().getNom() << ", en " << Oeuv.getLangue() << endl;
     }
     Exemplaire(Exemplaire const &e) : Oeuv(e.Oeuv)
     {
          cout << "Copie d'un exemplaire de : " << Oeuv.getTitre() << ", " << Oeuv.getAuteur().getNom() << ", en " << Oeuv.getLangue() << endl;
     }
     ~Exemplaire()
     {
          cout << "Un exemplaire de \"" << Oeuv.getTitre() << " , " << Oeuv.getAuteur().getNom() << ", en " << Oeuv.getLangue() << "\" a Ã©tÃ© jetÃ© !\n";
     }
     Oeuvre& getOeuvre() const { return Oeuv; }
     void affiche() const { 
          cout << "Exemplaire de : " << Oeuv.getTitre() << ", " << Oeuv.getAuteur().getNom() << ", en " << Oeuv.getLangue() << " "; 
     }
};

class Bibliotheque{
     private:
          string Nom;
          vector<Exemplaire*> exemplaires;
     public:
          Bibliotheque(string n) : Nom(n) { cout << "La bibliothÃ¨que " << Nom << " est ouverte !\n"; }
          ~Bibliotheque()
          {
               cout << "La bibliothÃ¨que " << Nom << " ferme ses portes,\n"
                    << "et dÃ©truit ses exemplaires :\n";
               for (unsigned int i = 0; i < exemplaires.size(); i++)
               {
                    delete exemplaires[i];
               }
          }
          string getNom() const { return Nom; }
          void stocker(Oeuvre &o, int n = 1)
          {
               for (int i = 0; i < n; i++)
               {
                    Exemplaire *e = new Exemplaire(o);
                    exemplaires.push_back(e);
               }
          }
          void lister_exemplaires(string l = "")
          {
               for (unsigned int i = 0; i < exemplaires.size(); i++)
               {
                    if ((l == "") || (l == exemplaires[i]->getOeuvre().getLangue()))
                    {
                         exemplaires[i]->affiche();
                         cout << "\n";
                    }
               }
          }
          int compter_exemplaires(Oeuvre &o)
          {
               int counter = 0;
               for (unsigned int i = 0; i < exemplaires.size(); i++)
               {
                    if ((o.getTitre() == exemplaires[i]->getOeuvre().getTitre()) && (o.getLangue() == exemplaires[i]->getOeuvre().getLangue()))
                    {
                         counter++;
                    }
               }
               return counter;
          }
          void afficher_auteurs(bool b = false)
          {
               for (unsigned int i = 0; i < exemplaires.size(); i++)
               {
                    if (!b)
                    {
                         cout << exemplaires[i]->getOeuvre().getAuteur().getNom() << "\n";
                    }
                    else
                    {
                         if (exemplaires[i]->getOeuvre().getAuteur().getPrix())
                         {
                              cout << exemplaires[i]->getOeuvre().getAuteur().getNom() << "\n";
                         }
                    }
               }
          }
};


/*******************************************
 * Ne rien modifier apres cette ligne.
 *******************************************/

int main()
{
     Auteur a1("Victor Hugo"),
         a2("Alexandre Dumas"),
         a3("Raymond Queneau", true);

     Oeuvre o1("Les MisÃ©rables", a1, "franÃ§ais"),
         o2("L'Homme qui rit", a1, "franÃ§ais"),
         o3("Le Comte de Monte-Cristo", a2, "franÃ§ais"),
         o4("Zazie dans le mÃ©tro", a3, "franÃ§ais"),
         o5("The Count of Monte-Cristo", a2, "anglais");

     Bibliotheque biblio("municipale");
     biblio.stocker(o1, 2);
     biblio.stocker(o2);
     biblio.stocker(o3, 3);
     biblio.stocker(o4);
     biblio.stocker(o5);

     cout << "La bibliothÃ¨que " << biblio.getNom()
          << " offre les exemplaires suivants :" << endl;
     biblio.lister_exemplaires();

     const string langue("anglais");
     cout << " Les exemplaires en " << langue << " sont :" << endl;
     biblio.lister_exemplaires(langue);

     cout << " Les auteurs Ã  succÃ¨s sont :" << endl;
     biblio.afficher_auteurs(true);

     cout << " Il y a " << biblio.compter_exemplaires(o3) << " exemplaires de "
          << o3.getTitre() << endl;

     return 0;
}
