/**
 * Mise en oeuvre de piece.h
 *
 * @file piece.cpp
 */

// A besoin de la declaration de la classe
#include <iostream>
#include "echec.h"
#include "piece.h"

#include <array>
#include <math.h>

using namespace std;

using namespace std;

Piece::Piece()
{
  cout << "Piece()" << endl;
}

Piece::Piece(int x, int y, bool white)
: m_x(x),m_y(y),m_white(white){
  /*m_x = x;
  m_y = y;
  m_white = white;*/
}


Piece::~Piece(){
  cout << "Une pièce "<< m_x << " " << m_y << " a été détruite"<< endl;
}

void
Piece::init( int x, int y, bool white )
{
  m_x = x;
  m_y = y;
  m_white = white;
}

void
Piece::move( int x, int y )
{
  m_x = x;
  m_y = y;
}

int
Piece::x() const
{
  return m_x;
}

int
Piece::y() const
{
  return m_y;
}

bool
Piece::isWhite() const
{
  return m_white;
}

bool
Piece::isBlack()const
{
  return !m_white;

}

void
Piece::affiche()const {
  cout << "Piece: x=" << m_x << " y=" << m_y << " "
       << ( m_white ? "blanche" : "noire" ) << endl;
}

bool
Piece::mouvementValide(const Echec & echiquier, int x, int y)const {
  if(!echiquier.posValide(x,y)) return false;
  const Piece * p = echiquier.getPiece(x,y);
  return p == nullptr;
}

bool
Piece::memeEndroit(const Piece & p1, const Piece & p2) const{
  return (p1.x() == p2.x()) && (p1.y()==p2.y());
}

const Piece & Piece::plusForte(const Piece & p) const {
  if (this < &p){
    return p;
    }else {
      return *this;
    }

}

char
Piece::getChar() const
{
  return m_white ? 'B' : 'N';
}










