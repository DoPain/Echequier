#ifndef ECHEC_H
#define ECHEC_H

/**
 * Header de Echec.cpp
 *
 * @file Echec.h
 */

#include "piece.h"
#include <memory>


/**
 * Declaration d'une classe modelisant une piece de jeu d'echec.
 */
class Echec
{
private:
  /**
   * Les cases de l'echiquier
   */
  std::shared_ptr<Piece> m_cases[ 64 ];

public:

  /**
   * Constructeur par defaut.
   * Initialise a vide l'echiquier.
   */
  Echec();

  /**
   * Recupere la piece situee sur une case.
   *
   * @param x un entier entre 1 et 8
   * @param y un entier entre 1 et 8
   *
   * @return 0 si aucune piece n'est sur cette case et un pointeur
   * vers une piece sinon.
   */
  std::shared_ptr<Piece> getPiece(int x, int y);

  /**
   * Place une piece sur l'echiquier, aux coordonnees specifiees dans la piece.
   *
   * @param p un pointeur vers une piece
   *
   * @return 'true' si le placement s'est bien passe, 'false' sinon
   * (case occupee, coordonnees invalides, piece vide )
   */
  bool placer( std::shared_ptr<Piece> p );

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
  bool deplacer( Echec e,std::shared_ptr<Piece> p, int x, int y );

  /**
   * Enleve la piece situee sur une case (qui devient vide).
   *
   * @param x un entier entre 1 et 8
   * @param y un entier entre 1 et 8
   *
   * @return 0 si aucune piece n'est sur cette case et le pointeur
   * vers la piece enlevee sinon.
   */
  std::shared_ptr<Piece> enleverPiece( int x, int y );

  /**
   * Affiche l'echiquier avec des # pour les cases noires et . pour
   * les blanches si elles sont vides, et avec B pour les pieces
   * blanches et N pour les pieces noires.
   */
  void affiche();

};



#endif // ECHEC_H
