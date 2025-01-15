#include <iostream>
#include <string>
using namespace std;

class Souris
{
    /*****************************************************
      ComplÃ©ter le code Ã  partir d'ici
    *******************************************************/
private:
    double poids;
    string couleur;
    unsigned int age;
    unsigned int esperance_vie;
    bool clonee;

public:
    Souris(double poids, string couleur, unsigned int age = 0, unsigned int esperance_vie = 36)
        : poids(poids), couleur(couleur), age(age), esperance_vie(esperance_vie), clonee(false)
    {
        cout << "Une nouvelle souris !" << endl;
    }
    Souris(Souris const &clone)
        : poids(clone.poids), couleur(clone.couleur), age(clone.age), esperance_vie(clone.esperance_vie * 0.8), clonee(true)
    {
        cout << "Clonage d'une souris !" << endl;
    }
    ~Souris()
    {
        cout << "Fin d'une souris... " << endl;
    }
    void afficher() const
    {
        if (!clonee)
        {
            cout << "Une souris " << couleur << " de " << age << " mois et pesant " << poids << " grammes" << endl;
        }
        else
        {
            cout << "Une souris " << couleur << ", clonee," << " de " << age << " mois et pesant " << poids << " grammes" << endl;
        }
    }
    void viellir()
    {
        this->age++;
        if (this->age >= this->esperance_vie/2 && this->clonee)
        {
            couleur = "verte";
        }
    }
    void evolue()
    {
        while (this->age < this->esperance_vie)
        {
            this->viellir();
        }
    }

    /*******************************************
     * Ne rien modifier aprÃ¨s cette ligne.
     *******************************************/

}; // fin de la classe Souris

int main()
{
    Souris s1(50.0, "blanche", 2);
    Souris s2(45.0, "grise");
    Souris s3(s2);
    // ... un tableau peut-Ãªtre...
    s1.afficher();
    s2.afficher();
    s3.afficher();
    s1.evolue();
    s2.evolue();
    s3.evolue();
    s1.afficher();
    s2.afficher();
    s3.afficher();
    return 0;
}
