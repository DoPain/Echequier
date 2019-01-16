#ifndef JOUEUR_H
#define JOUEUR_H

/**
 * Header de Joueur.cxx
 *
 * @file Joueur.h
 */

#include "piece.h"
#include "echec.h"
#include <vector>
#include <memory>

/**
 * Declaration d'une classe modelisant une piece de jeu d'echec.
 */
class Joueur
{
protected:
  std::vector<std::shared_ptr<Piece> > m_pieces;

public:
  Joueur( bool white );
  ~Joueur();
  void placerPieces(Echec &e);
  void affiche();
  virtual bool isWhite() const =0;
};

class JoueurBlanc : public Joueur
{
  public:
    JoueurBlanc();
    bool isWhite() const;
};

class JoueurNoir : public Joueur
{
  public:
    JoueurNoir();
    bool isWhite() const;
};


#endif // JOUEUR_H
