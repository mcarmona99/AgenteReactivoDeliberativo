#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"

#include <list>

struct estado {
  int fila;
  int columna;
  int orientacion;
  int coste;

  bool operator==(const estado &otro)const{
    return (fila==otro.fila && columna==otro.columna && orientacion==otro.orientacion);
  }
  void operator=(const estado &otro){
    fila=otro.fila;
    columna=otro.columna;
    orientacion=otro.orientacion;
    coste=otro.coste;
  }
};

class ComportamientoJugador : public Comportamiento {
  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size) {
      // Inicializar Variables de Estado
      fil = col = 99;
      brujula = 0; // 0: Norte, 1:Este, 2:Sur, 3:Oeste
      destino.fila = -1;
      destino.columna = -1;
      destino.orientacion = -1;
      ultimaAccion=actIDLE;
      estoy_bien_situado=false;
      hayPlan=false;
      for(int i=0;i<200;++i)
        for(int j=0;j<200;++j)
          mapaPulgarcito[i][j]=0;
      fil_p=100;
      col_p=100;
      brujula_p=0;
    }
    ComportamientoJugador(std::vector< std::vector< unsigned char> > mapaR) : Comportamiento(mapaR) {
      // Inicializar Variables de Estado
      fil = col = 99;
      brujula = 0; // 0: Norte, 1:Este, 2:Sur, 3:Oeste
      destino.fila = -1;
      destino.columna = -1;
      destino.orientacion = -1;
      ultimaAccion=actIDLE;
      estoy_bien_situado=false;
      hayPlan=false;
      for(int i=0;i<200;++i)
        for(int j=0;j<200;++j)
          mapaPulgarcito[i][j]=0;
      fil_p=100;
      col_p=100;
      brujula_p=0;
    }
    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);
    void VisualizaPlan(const estado &st, const list<Action> &plan);
    ComportamientoJugador * clone(){return new ComportamientoJugador(*this);}

  private:
    // Declarar Variables de Estado
    int fil, col, brujula;
    estado actual, destino;
    list<Action> plan;
    //Nuevas variables de estado
    Action ultimaAccion;
    bool estoy_bien_situado;
    bool hayPlan;
    //control de pulgarcito
    long int mapaPulgarcito[200][200];
    int fil_p, col_p, brujula_p;


    // Métodos privados de la clase
    bool pathFinding(int level, const estado &origen, const estado &destino, list<Action> &plan);
    bool pathFinding_Profundidad(const estado &origen, const estado &destino, list<Action> &plan);
    bool pathFinding_Anchura(const estado &origen, const estado &destino, list<Action> &plan);
    bool pathFinding_CUniforme(const estado &origen, const estado &destino, list<Action> &plan);


    void PintaPlan(list<Action> plan);
    bool HayObstaculoDelante(estado &st);

};

#endif
