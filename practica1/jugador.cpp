 #include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
using namespace std;

//Luis Orts Ferrer




Action ComportamientoJugador::think(Sensores sensores){
Action accion = actIDLE;
if (sensores.nivel <= 1 and !bien_situado){
	brujula = sensores.sentido;
	}

if(sensores.reset){
     fila = 99;
     colum = 99; 
      brujula = 0;
      ultAccion = actIDLE; //actidel NO HACE nada //ultima acción
      girar_der = false;
      if(sensores.nivel == 0){
      bien_situado = true;
     } else{
      bien_situado = false;
      }
      hacemos_giro = 61;
      destino = false;
      posicion_des = -1;
      tiene_bikini = false;
      tiene_zapatillas = false;
      Giro = actIDLE;
	}
	 
	
  // brujula = sensores.sentido;
	switch (ultAccion){
	   case actFORWARD:
	   if(!sensores.colision){
	     switch (brujula){
	     	case 0: //NORTE 
	        	fila--; break;
	     	case 1: //Este
	     		colum++; break;
	     	case 2: //sur
	     		fila++; break;
	     	case 3: //oeste
	     		colum--; break;
	     	}
	     	}
	     	break;
	     case actTURN_L: //girar izquierda
	       brujula = (brujula+3)%4;
	       girar_der = (rand()%2==0);
	       break;
	      
	     case actTURN_R: //girar derecha
	       brujula = (brujula+1)%4;
	       girar_der = (rand()%2==0);
	       break;
	     }
	     
		if( sensores.nivel == 0){
		bien_situado = true;
		fila = sensores.posF;
		colum = sensores.posC;
		//brujula = sensor.sentido;
		}
		
	   if ( sensores.terreno[0] == 'G' and !bien_situado){
	   	fila = sensores.posF;
	   	colum = sensores.posC;
	   	bien_situado = true;
	   	}
	   
	   if (bien_situado){
	   	
	   	mapaResultado[fila][colum] = sensores.terreno[0];
	   	switch (brujula) {
			case 0:
				mapaResultado[fila-1][colum-1] = sensores.terreno[1];
				mapaResultado[fila-1][colum] = sensores.terreno[2];
				mapaResultado[fila-1][colum+1] = sensores.terreno[3];
				mapaResultado[fila-2][colum-2] = sensores.terreno[4];
				mapaResultado[fila-2][colum-1] = sensores.terreno[5];
				mapaResultado[fila-2][colum] = sensores.terreno[6];
				mapaResultado[fila-2][colum+1] = sensores.terreno[7];
				mapaResultado[fila-2][colum+2] = sensores.terreno[8];
				mapaResultado[fila-3][colum-3] = sensores.terreno[9];
				mapaResultado[fila-3][colum-2] = sensores.terreno[10];
				mapaResultado[fila-3][colum-1] = sensores.terreno[11];
				mapaResultado[fila-3][colum] = sensores.terreno[12];
				mapaResultado[fila-3][colum+1] = sensores.terreno[13];
				mapaResultado[fila-3][colum+2] = sensores.terreno[14];
				mapaResultado[fila-3][colum+3] = sensores.terreno[15];
			break;
			case 1:
				mapaResultado[fila-1][colum+1] = sensores.terreno[1];
				mapaResultado[fila][colum+1] = sensores.terreno[2];
				mapaResultado[fila+1][colum+1] = sensores.terreno[3];
				mapaResultado[fila-2][colum+2] = sensores.terreno[4];
				mapaResultado[fila-1][colum+2] = sensores.terreno[5];
				mapaResultado[fila][colum+2] = sensores.terreno[6];
				mapaResultado[fila+1][colum+2] = sensores.terreno[7];
				mapaResultado[fila+2][colum+2] = sensores.terreno[8];
				mapaResultado[fila-3][colum+3] = sensores.terreno[9];
				mapaResultado[fila-2][colum+3] = sensores.terreno[10];
				mapaResultado[fila-1][colum+3] = sensores.terreno[11];
				mapaResultado[fila][colum+3] = sensores.terreno[12];
				mapaResultado[fila+1][colum+3] = sensores.terreno[13];
				mapaResultado[fila+2][colum+3] = sensores.terreno[14];
				mapaResultado[fila+3][colum+3] = sensores.terreno[15];
			break;
			case 2:
				mapaResultado[fila+1][colum+1] = sensores.terreno[1];
				mapaResultado[fila+1][colum] = sensores.terreno[2];
				mapaResultado[fila+1][colum-1] = sensores.terreno[3];
				mapaResultado[fila+2][colum+2] = sensores.terreno[4];
				mapaResultado[fila+2][colum+1] = sensores.terreno[5];
				mapaResultado[fila+2][colum] = sensores.terreno[6];
				mapaResultado[fila+2][colum-1] = sensores.terreno[7];
				mapaResultado[fila+2][colum-2] = sensores.terreno[8];
				mapaResultado[fila+3][colum+3] = sensores.terreno[9];
				mapaResultado[fila+3][colum+2] = sensores.terreno[10];
				mapaResultado[fila+3][colum+1] = sensores.terreno[11];
				mapaResultado[fila+3][colum] = sensores.terreno[12];
				mapaResultado[fila+3][colum-1] = sensores.terreno[13];
				mapaResultado[fila+3][colum-2] = sensores.terreno[14];
				mapaResultado[fila+3][colum-3] = sensores.terreno[15];
			break;
			case 3:
				mapaResultado[fila+1][colum-1] = sensores.terreno[1];
				mapaResultado[fila][colum-1] = sensores.terreno[2];
				mapaResultado[fila-1][colum-1] = sensores.terreno[3];
				mapaResultado[fila+2][colum-2] = sensores.terreno[4];
				mapaResultado[fila+1][colum-2] = sensores.terreno[5];
				mapaResultado[fila][colum-2] = sensores.terreno[6];
				mapaResultado[fila-1][colum-2] = sensores.terreno[7];
				mapaResultado[fila-2][colum-2] = sensores.terreno[8];
				mapaResultado[fila+3][colum-3] = sensores.terreno[9];
				mapaResultado[fila+2][colum-3] = sensores.terreno[10];
				mapaResultado[fila+1][colum-3] = sensores.terreno[11];
				mapaResultado[fila][colum-3] = sensores.terreno[12];
				mapaResultado[fila-1][colum-3] = sensores.terreno[13];
				mapaResultado[fila-2][colum-3] = sensores.terreno[14];
				mapaResultado[fila-3][colum-3] = sensores.terreno[15];
			break;
		}
	}
	
	
	if(!bien_situado){ //si no esta bien situado buscar g
		for ( int i =0; i < sensores.terreno.size(); i++){
			if(sensores.terreno[i] == 'G' ){
			destino = true;
			posicion_des = i;
			Ruta(num_pasos_al_objetivo, Giro);
			}
			}
			}
		if(bien_situado and !tiene_bikini and !tiene_zapatillas){ //si no tenemos zapatillas ni bikini y estamos bien situados buscar alguno de los objetos
			for ( int i =0; i < sensores.terreno.size(); i++){
			if(sensores.terreno[i] == 'K' or sensores.terreno[i] == 'D' ){
			destino = true;
			posicion_des = i;
			Ruta(num_pasos_al_objetivo, Giro);
			}
			}		}
		if(bien_situado and !tiene_zapatillas and tiene_bikini){ //si solo nos falta un objeto buscar ese 
			for ( int i =0; i < sensores.terreno.size(); i++){
			if(sensores.terreno[i] == 'D' ){
			destino = true;
			posicion_des = i;
			Ruta(num_pasos_al_objetivo, Giro);
			}
			}
			}
		if(bien_situado and tiene_zapatillas and !tiene_bikini){ //si solo nos falta un objeto buscar ese
			for ( int i =0; i < sensores.terreno.size(); i++){
			if(sensores.terreno[i] == 'K' ){
			destino = true;
			posicion_des = i;
			Ruta(num_pasos_al_objetivo, Giro);
			}
			}
			}
		
		
		if(bien_situado and tiene_bikini and tiene_zapatillas and sensores.bateria < 1500 and cargado < 4){
		
		for ( int i =0; i < sensores.terreno.size(); i++){
			if(sensores.terreno[i] == 'X' ){
			destino = true;
			posicion_des = i;
		
			Ruta(num_pasos_al_objetivo, Giro);
			}
			}
			}
		if (sensores.bateria >= 1500 and sensores.terreno[0] == 'X'){
		cargado++;
		}
		
			
	   	//COMPORTAMIENTO
	   	//si puedo avanzar hacemos
	   	if ((sensores.terreno[2] == 'S' or sensores.terreno[2] == 'G' or sensores.terreno[2] == 'X' or sensores.terreno[2] == 'T' ) && sensores.superficie[2] == '_') {
	   	if(destino) { //si tengo destio sigo la ruta
	   		if(num_pasos_al_objetivo > 0){
	   		accion = actFORWARD; 
	   		num_pasos_al_objetivo--;
	   		}else{ 
	   		accion = Giro;
	   		destino = false; //si ya tengo el objetivo, ya no tenemos destino
	   		}

	   		}
	   		else  //si no hay destino realizar ruta ordinaria
	   			if(hacemos_giro > 0) {
	   				accion = actFORWARD; 
	   				hacemos_giro--;
	   				}
	   			else if (rand()%2==0){
	   				accion = actTURN_L;
	   				hacemos_giro= 61;
	   				}
	   			else {
	   			accion = actTURN_R; 
	   			hacemos_giro = 61;
	   			}		
	   			}
	   			
	   	else if(sensores.terreno[2] == 'K'){ 	
	   	//SI DELANTE TENGO UN OBJETO
	   		if(!tiene_bikini){
	   		accion = actFORWARD;
	   		tiene_bikini = true;
	   		}else{ //si lo tengo, lo esquivo
	   		
	   		if(!girar_der){
	   		 accion = actTURN_L; 
	   		 destino = false;
	   		 } 
	   		 else {
	   		 accion = actTURN_R;
	   		destino = false;
	   		 }
	   		 }
	   		 }
	   		 else if(sensores.terreno[2] == 'D'){
	   		 
	   		 if(!tiene_zapatillas){
	   		 accion = actFORWARD;
	   		
	   		 tiene_zapatillas = true;
	   		 
	   		 }else{ //si lo tengo, lo esquivo
	   		if(!girar_der){
	   		 accion = actTURN_L; 
	   		 destino = false;
	   		 } 
	   		 else {
	   		 accion = actTURN_R;
	   		 destino = false;
	   		 }
	   		 }
	   		}
	   		
	   		
	       else if(sensores.terreno[2] == 'B' and sensores.superficie[2] == '_' ){
	  
	   	
	   	if(tiene_zapatillas){	//si tenemos zapatillas y tenemos desitno lo seguimos
	   	if(destino){ 
	   		if(num_pasos_al_objetivo > 0){
	   		accion = actFORWARD; 
	   		num_pasos_al_objetivo--;
	   		}
	   		else { 
	   		accion = Giro; 
	   		destino = false;
	   		}
	   		}
	   		else 
	   			if(hacemos_giro > 0) {
	   				accion = actFORWARD; hacemos_giro--;
	   				}
	   			else if (rand()%2==0){
	   				accion = actTURN_L;
	   				hacemos_giro= 61;
	   				}
	   			else {
	   			accion = actTURN_R; 
	   			hacemos_giro = 61;
	   			}
	   	
	   			}else{	 //si no, no entramos al bosque
	 		  	if(!girar_der){
	   			 accion = actTURN_L; 
	   			destino = false;
	   			 } 
	   			 else {
	   			 accion = actTURN_R;
	   			destino = false;
	   			 }
	   			}
	   		
	   		} else if(sensores.terreno[2] == 'A' and sensores.superficie[2] == '_' ){
	   	///SI HAY AGUA Y TENGO EL BIKINI sigo la ruta
	   	if(tiene_bikini){	
	   	if(destino){ 
	   		if(num_pasos_al_objetivo > 0){
	   		accion = actFORWARD; 
	   		num_pasos_al_objetivo--;
	   		}
	   		else { 
	   		accion = Giro; 
	   		destino = false;
	   		}
	   		}
	   		else 
	   			if(hacemos_giro > 0) {
	   				accion = actFORWARD; hacemos_giro--;
	   				}
	   			else if (rand()%2==0){
	   				accion = actTURN_L;
	   				hacemos_giro= 61;
	   				}
	   			else {
	   			accion = actTURN_R; 
	   			hacemos_giro = 61;
	   			}
	   	
	   	}
	   	else{ 
	   
	 		  	if(!girar_der){
	   			 accion = actTURN_L; 
	   			 destino = false;
	   			 } 
	   			 else {
	   			 accion = actTURN_R;
	   			 destino = false;
	   			 }
	   			}
	   		
	   		
	   		
	   	}else if (sensores.terreno[0] == 'B' and !tiene_zapatillas ){ //si reiniciamos o empezamos en una zona de bosque
	   	for ( int i =0; i < sensores.terreno.size(); i++){
			if(sensores.terreno[i] == 'T' or sensores.terreno[i] == 'S' or sensores.terreno[i] == 'D' ){ //buscamos o un objeto para pasar por esa zona sin gasta demasiada bateria o buscamos un terreno que no consuma demasiada bateria
			destino = true;
			posicion_des = i;
			Ruta(num_pasos_al_objetivo, Giro);
			}
			}
			if(destino){ 
	   		if(num_pasos_al_objetivo > 0){
	   		accion = actFORWARD; 
	   		num_pasos_al_objetivo--;
	   		}
	   		else { 
	   		accion = Giro; 
	   		destino = false;
	   		}
	   		}
	   		else //si no realizamos ruta ordinaria
	   			if(hacemos_giro > 0) {
	   				accion = actFORWARD; hacemos_giro--;
	   				}
	   			else if (rand()%2==0){
	   				accion = actTURN_L;
	   				hacemos_giro= 61;
	   				}
	   			else {
	   			accion = actTURN_R; 
	   			hacemos_giro = 61;
	   			}
	   	}else if (sensores.terreno[0] == 'A' and !tiene_zapatillas ){ //idem para agua
	   	for ( int i =0; i < sensores.terreno.size(); i++){
			if(sensores.terreno[i] == 'T' or sensores.terreno[i] == 'S' or sensores.terreno[i] == 'D' ){
			destino = true;
			posicion_des = i;
			Ruta(num_pasos_al_objetivo, Giro);
			}
			}
			if(destino){ 
	   		if(num_pasos_al_objetivo > 0){
	   		accion = actFORWARD; 
	   		num_pasos_al_objetivo--;
	   		}
	   		else { 
	   		accion = Giro; 
	   		destino = false;
	   		}
	   		}
	   		else 
	   			if(hacemos_giro > 0) {
	   				accion = actFORWARD; hacemos_giro--;
	   				}
	   			else if (rand()%2==0){
	   				accion = actTURN_L;
	   				hacemos_giro= 61;
	   				}
	   			else {
	   			accion = actTURN_R; 
	   			hacemos_giro = 61;
	   			}
	   	   }
	   		
	   		
	   		else if(sensores.terreno[2] == 'M' or sensores.terreno[2] == 'P'){ //si nos encontramos un muro o precipicio lo evitamos
	   	if(!girar_der){
	   		 accion = actTURN_L; 
	   		 destino = false;
	   		 } 
	   		 else {
	   		 accion = actTURN_R;
	   		 destino = false;
	   		 }
	   		 }
	   		
	   	else if(sensores.superficie[2] = 'l'){ //si nos encontramos un lobo lo evitamos
	   	if(!girar_der){
	   		 accion = actTURN_L; 
	   		 destino = false;
	   		 } 
	   		 else {
	   		 accion = actTURN_R;
	   		 destino = false;
	   		 }
	  		 
	 
	   	}else if(sensores.superficie[0] = 'l'){ // si finalmente topamos con un lobo, reiniciamos 
	   		tiene_zapatillas = false;
	   		tiene_bikini = false;
	   		bien_situado = false;
	   		}
	     
	 	
	   			
		
	cout << "Posicion: fila " << sensores.posF << " columna " << sensores.posC << " ";
	switch(sensores.sentido){
		case 0: cout << "Norte" << endl; break;
		case 1: cout << "Este" << endl; break;
		case 2: cout << "Sur " << endl; break;
		case 3: cout << "Oeste" << endl; break;
	}
	cout << "Terreno: ";
	for (int i=0; i<sensores.terreno.size(); i++)
		cout << sensores.terreno[i];
	cout << endl;

	cout << "Superficie: ";
	for (int i=0; i<sensores.superficie.size(); i++)
		cout << sensores.superficie[i];
	cout << endl;

	cout << "Colisión: " << sensores.colision << endl;
	cout << "Reset: " << sensores.reset << endl;
	cout << "Vida: " << sensores.vida << endl;
	cout << endl;

	ultAccion = accion;
	return accion;

}	   	
	

void ComportamientoJugador::Ruta(int & num_pasos_al_objetivo, Action & Giro){ //metodo para realizar la ruta
	if(1 == posicion_des or posicion_des == 3 or posicion_des == 2)
		num_pasos_al_objetivo = 1;
	else if (4 == posicion_des or posicion_des == 5 or 7 == posicion_des or posicion_des == 8 or posicion_des == 6)
		num_pasos_al_objetivo = 2;
	else if(posicion_des == 12 or posicion_des == 13 or posicion_des == 14 or posicion_des == 15 )
		num_pasos_al_objetivo = 3;

	if(posicion_des == 1 or posicion_des == 4 or posicion_des == 5 or posicion_des == 9 or posicion_des == 10 or posicion_des == 11){
	
		Giro = actTURN_L;
	}
		else{
		Giro = actTURN_R;
}
}

int ComportamientoJugador::interact(Action accion, int valor){
  return false;
}
