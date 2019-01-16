#ifndef PIECE_H
#define PIECE_H

/**
 * Header de piece.cpp
 *
 * @file piece.h
 */


class Echec;
/**
 * Declaration d'une classe modelisant une piece de jeu d'echec.
 */
class Piece
{
protected:
  int m_x;
  int m_y;
  bool m_white;

public:
  Piece();
  Piece(int x,int y,bool white);
  virtual ~Piece();
  Piece(const Piece &p);
  void init( int x, int y, bool white );
  void move( int x, int y );
  int x() const;
  int y() const;
  bool isWhite() const;
  bool isBlack() const;
  void affiche() const;
  bool memeEndroit(const Piece & p1, const Piece & p2) const;
  virtual bool mouvementValide(const Echec & echiquier, int x, int y) const = 0;
  char getChar() const;

  const Piece & plusForte(const Piece & p) const;
};


#endif // PIECE_H
