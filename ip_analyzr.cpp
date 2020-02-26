/*
 * Questo programma analizza IP immesso, e fa le sue elaborazioni
 */

// package 
#include <iostream>
#include "ip_func.h"
// dichiatazione di costanti
// #define NOME_COST VAL
// const NOME_CONST = VAL;

// Variabili globali (valide in tutto il programma)
// int x = ?

using namespace std;


int main() {
	
	// Variabili del programma
    string ip,sm,br,net;
    int n_host;
    bool stay = true; // fa rimanere nel ciclo di controllo input utente
	
	// Variabili chiusura prog std
	bool end_prog = true;
	char response;

    
	// programma che esegue operazioni finche l'utente non decide di uscire
	while(end_prog) {
		
		// Inizio Programma
		cout << "Benvenuto in IP Analyzr\nIl programma esamina l'IP immesso e restituisce le info sulla rete\n";

		cout << "\nInserisci l'IP: ";
		cin >> ip;
		fflush(stdin);

		while(cin.fail() || !(valid_ip(ip)) ) {
			cin.clear();
			cout << "\nERRORE nell'inserimento dell'IP!\nInserisci IP valido: ";
		}

		
	
		// Richiesta di continuare
		cout << "Vuoi continuare con l'esecuzione del programma? (S/N)" << endl;
		cin >> response;	
		
		if(tolower(response) != 's') {
			end_prog = false;
		}
		else {
			cout << "Continui!!\n\n" << endl;
			fflush(stdin);
		}	
	}

	return 0;
}


