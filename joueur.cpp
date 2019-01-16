#include "joueur.h"
#include "Roi.h"
#include "Reine.h"
#include "Fou.h"
#include "Cavalier.h"
#include "Tour.h"

Joueur::Joueur( bool white )
{
}

Joueur::~Joueur()
{
    /*
    for (int i = 0; i < m_pieces.size(); i++)
        delete m_pieces[i];
        */
    /* no delete on shared_ptr !
    vector<shared_ptr<Piece> >::iterator p = m_pieces.begin();
    while (p != m_pieces.end())
    {
        delete *p;
        p++;
    }
    */
}

JoueurBlanc::JoueurBlanc() : Joueur(true)
{
  m_pieces.push_back(std::shared_ptr<Piece>(new Roi( true )) );
  m_pieces.push_back(std::shared_ptr<Piece>(new Reine( true )) );
  m_pieces.push_back(std::shared_ptr<Piece>(new Fou( true, true )) );
  m_pieces.push_back(std::shared_ptr<Piece>(new Fou( true, false )) );
  m_pieces.push_back(std::shared_ptr<Piece>(new Cavalier( true, true )) );
  m_pieces.push_back(std::shared_ptr<Piece>(new Cavalier( true, false )) );
  m_pieces.push_back(std::shared_ptr<Piece>(new Tour( true, true )) );
  m_pieces.push_back(std::shared_ptr<Piece>(new Tour( true, false )) );
  for (int x = 1; x <= 8; x++)
    m_pieces.push_back(std::shared_ptr<Piece>(new Pion( true, x )) );
}

JoueurNoir::JoueurNoir() : Joueur(false)
{
  m_pieces.push_back(std::shared_ptr<Piece>(new Roi( false )) );
  m_pieces.push_back(std::shared_ptr<Piece>(new Reine( false )) );
  m_pieces.push_back(std::shared_ptr<Piece>(new Fou( false, true )) );
  m_pieces.push_back(std::shared_ptr<Piece>(new Fou( false, false )) );
  m_pieces.push_back(std::shared_ptr<Piece>(new Cavalier( false, true )) );
  m_pieces.push_back(std::shared_ptr<Piece>(new Cavalier( false, false )) );
  m_pieces.push_back(std::shared_ptr<Piece>(new Tour( false, true )) );
  m_pieces.push_back(std::shared_ptr<Piece>(new Tour( false, false )) );
  for (int x = 1; x <= 8; x++)
    m_pieces.push_back(std::shared_ptr<Piece>((new Pion( false, x )) ));
}

void
Joueur::affiche()
{
    /*
    for (int i = 0; i < m_pieces.size(); i++)
        m_pieces[i]->affiche();
        */
       for ( auto p : m_pieces)
       {
           p->affiche();
       }
}

void
Joueur::placerPieces(Echec & e)
{
    for (int i = 0; i < m_pieces.size(); i++)
        e.placer( m_pieces[i] );
}

bool
JoueurBlanc::isWhite() const
{
    return true;
}

bool
JoueurNoir::isWhite() const
{
    return false;
}
