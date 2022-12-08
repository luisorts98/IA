#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"

using namespace std;

//luis Orts Ferrer
class ComportamientoJugador : public Comportamiento{

  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size){
      // Constructor de la clase
     if(sensor.nivel == 1){
     fila = -1;
     colum = -1;
     }
      fila = 99;
      colum = 99; //columna
     cargado=0;
      brujula = 0;	
      ultAccion = actIDLE; //actidel NO HACE nada //ultima acción
      girar_der = false;
      bien_situado = false;
      hacemos_giro =40;
      destino = false;
      tiene_bikini = false;
      tiene_zapatillas = false;
      Giro = actIDLE;
      posicion_des = -1;
}
    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);
void Ruta(int & num_pasos_al_objetivo, Action & Giro);
  private:
  
  // Declarar aquí las variables de estado
  int fila, colum, brujula;
  Action ultAccion;
  bool girar_der;
  bool bien_situado;
  bool tiene_bikini;
  bool tiene_zapatillas;
  Action Giro;
  int num_pasos_al_objetivo;
  int hacemos_giro;
  Sensores sensor;
  bool destino;
  int cargado;
  int posicion_des;
  int nivel;

};

#endif
