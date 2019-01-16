/**
 * Mise en oeuvre de Echec.h
 *
 * @file Echec.cpp
 */

#include <iostream>
#include <assert.h>
// A besoin de la declaration de la classe
#include "echec.h"

using namespace std;

/**
 * Constructeur par defaut.
 * Initialise a vide l'echiquier.
 */
Echec::Echec()
{
    for (int i = 0; i < 64; i++)
        m_cases[i] = nullptr;
}

/**
 * Recupere la piece situee sur une case.
 *
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return nullptr si aucune piece n'est sur cette case et un pointeur
 * vers une piece sinon.
 */
shared_ptr<Piece>
Echec::getPiece( int x, int y )
{
    assert(x >= 1 && x <= 8 && y >= 1 && y <= 8);
    return m_cases[(x - 1) + 8 * (y - 1)];
}

/**
 * Place une piece sur l'echiquier, aux coordonnees specifiees dans la piece.
 *
 * @param p un pointeur vers une piece
 *
 * @return 'true' si le placement s'est bien passe, 'false' sinon
 * (case occupee, coordonnees invalides, piece vide )
 */
bool
Echec::placer( shared_ptr<Piece> p )
{
    if ( nullptr==p )
        return false;
    assert(p->x() >= 1 && p->x() <= 8 &&
                 p->y() >= 1 && p->y() <= 8);
    int pos = (p->x() - 1) + 8 * (p->y() - 1);
  if ( m_cases[pos]!=nullptr )
        return false;
    m_cases[pos] = p;
    return true;
}

/**
 * Deplace une piece sur l'echiquier, des coordonnees specifiees
 * dans la piece aux coordonnees x,y.
 *
 * @param p un pointeur vers une piece
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return 'true' si le placement s'est bien passe, 'false' sinon
 * (case occupee, coordonnees invalides, piece vide, piece pas
 * presente au bon endroit sur l'echiquier)
 */
bool
Echec::deplacer( Echec e,shared_ptr<Piece> p, int x, int y )
{
    if(p->mouvementValide(e,x,y)==true){
        p->move(x,y);
        return true;
    }
}


/**
 * Enleve la piece situee sur une case (qui devient vide).
 *
 * @param x un entier entre 1 et 8
 * @param y un entier entre 1 et 8
 *
 * @return nullptr si aucune piece n'est sur cette case et le pointeur
 * vers la piece enlevee sinon.
 */
shared_ptr<Piece>
Echec::enleverPiece( int x, int y )
{
    assert(x >= 1 && x <= 8 && y >= 1 && y <= 8);
    int pos = (x - 1) + 8 * (y - 1);
    shared_ptr<Piece> tmp = m_cases[pos];
    m_cases[pos] = nullptr;
    return tmp;
}

/**
 * Affiche l'echiquier avec des # pour les cases noires et . pour
 * les blanches si elles sont vides, et avec B pour les pieces
 * blanches et N pour les pieces noires.
 */
void
Echec::affiche()
{
  cout << endl << "  12345678" << endl;
  for ( int y = 1; y <= 8; ++y )
    {
      cout << y << " ";
      for ( int x = 1; x <= 8; ++x )
    {
      char c;
      shared_ptr<Piece> p = getPiece( x, y );
      if ( p == nullptr )
        c = ( ( x + y ) % 2 ) == 0 ? '#' : '.';
      else
            c = p->getChar();  //p->isWhite() ? 'B' : 'N';
        cout << c;
    }
      cout << " " << y << endl;
    }
  cout << "  12345678" << endl;
}


