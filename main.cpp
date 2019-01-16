/**
 * Programme test de Piece
 *
 * @file main.cpp
 */

// Utile pour l'affichage
#include <iostream>
#include "piece.h"
#include "joueur.h"
#include "echec.h"
#include <assert.h>


using namespace std;

bool compare (const Piece & p, const Piece & q)
{
  return (p.x() == q.x()) && (p.y() == q.y());
}

/**
 * Programme principal
 */
int main()
{

  Echec e;
  //Joueur j(true); // classe abstraite
  JoueurBlanc jb;
  JoueurNoir jn;
  jb.affiche();
  jn.affiche();
  jb.placerPieces(e);
  jn.placerPieces(e);

  e.affiche();

  return 0;
}
