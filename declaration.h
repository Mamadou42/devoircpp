#ifndef DECLARATION_H
#define DECLARATION_H

#include "etudiant.h"
#include "utilisateur.h"

void addEtudiant(Etudiant *etudiant);
void updateEtudiant(Etudiant *etudiant);
void addUtilisateur(Utilisateur *utilisateur);
void updateUtilisateur(Utilisateur *utilisateur);
QSqlQueryModel *loadEtudiant();

#endif // DECLARATION_H
