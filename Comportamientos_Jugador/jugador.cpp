#include "../Comportamientos_Jugador/jugador.hpp"
#include "motorlib/util.h"

#include <iostream>
#include <cmath>
#include <set>
#include <stack>
#include <queue>


// Este es el método principal que debe contener los 4 Comportamientos_Jugador
// que se piden en la práctica. Tiene como entrada la información de los
// sensores y devuelve la acción a realizar.
Action ComportamientoJugador::think(Sensores sensores) {

//falta elegir nuevo path cuando solo ve agua
//sensor atrasado un paso
//memoria

//-------------------------------------------------

//NIVEL 2 REACTIVO/DELIBERATIVO


	if(sensores.nivel==4){



		if(sensores.terreno[0]=='K'){
			estoy_bien_situado=true;
		}
		if (sensores.mensajeF!=-1){
			fil=sensores.mensajeF;
			col=sensores.mensajeC;
			ultimaAccion=actIDLE;
		}


		switch(ultimaAccion){
			case actTURN_R: brujula = (brujula+1)%4; break;
			case actTURN_L: brujula = (brujula+3)%4; break;
			case actFORWARD:
				switch (brujula) {
					case 0: fil--; break;
					case 1: col++; break;
					case 2: fil++; break;
					case 3: col--; break;
				}
				break;
		}
		switch(ultimaAccion){
			case actTURN_R: brujula_p = (brujula_p+1)%4; break;
			case actTURN_L: brujula_p = (brujula_p+3)%4; break;
			case actFORWARD:
				switch (brujula_p) {
					case 0: fil_p--; break;
					case 1: col_p++; break;
					case 2: fil_p++; break;
					case 3: col_p--; break;
				}
				mapaPulgarcito[fil_p][col_p]=mapaPulgarcito[fil_p][col_p]+1;
				break;
		}


		if(estoy_bien_situado){
			mapaResultado[fil][col]=sensores.terreno[0];
			switch (brujula) {
				case 0://Norte
					mapaResultado[fil-1][col-1]=sensores.terreno[1];
					mapaResultado[fil-1][col]=sensores.terreno[2];
					mapaResultado[fil-1][col+1]=sensores.terreno[3];

					mapaResultado[fil-2][col-2]=sensores.terreno[4];
					mapaResultado[fil-2][col-1]=sensores.terreno[5];
					mapaResultado[fil-2][col]=sensores.terreno[6];
					mapaResultado[fil-2][col+1]=sensores.terreno[7];
					mapaResultado[fil-2][col+2]=sensores.terreno[8];

					mapaResultado[fil-3][col-3]=sensores.terreno[9];
					mapaResultado[fil-3][col-2]=sensores.terreno[10];
					mapaResultado[fil-3][col-1]=sensores.terreno[11];
					mapaResultado[fil-3][col]=sensores.terreno[12];
					mapaResultado[fil-3][col+1]=sensores.terreno[13];
					mapaResultado[fil-3][col+2]=sensores.terreno[14];
					mapaResultado[fil-3][col+3]=sensores.terreno[15];
					break;
				case 1://ESTE
					mapaResultado[fil-1][col+1]=sensores.terreno[1];
					mapaResultado[fil][col+1]=sensores.terreno[2];
					mapaResultado[fil+1][col+1]=sensores.terreno[3];

					mapaResultado[fil-2][col+2]=sensores.terreno[4];
					mapaResultado[fil-1][col+2]=sensores.terreno[5];
					mapaResultado[fil][col+2]=sensores.terreno[6];
					mapaResultado[fil+1][col+2]=sensores.terreno[7];
					mapaResultado[fil+2][col+2]=sensores.terreno[8];

					mapaResultado[fil-3][col+3]=sensores.terreno[9];
					mapaResultado[fil-2][col+3]=sensores.terreno[10];
					mapaResultado[fil-1][col+3]=sensores.terreno[11];
					mapaResultado[fil][col+3]=sensores.terreno[12];
					mapaResultado[fil+1][col+3]=sensores.terreno[13];
					mapaResultado[fil+2][col+3]=sensores.terreno[14];
					mapaResultado[fil+3][col+3]=sensores.terreno[15];
					break;
				case 2://SUR
					mapaResultado[fil+1][col+1]=sensores.terreno[1];
					mapaResultado[fil+1][col]=sensores.terreno[2];
					mapaResultado[fil+1][col-1]=sensores.terreno[3];

					mapaResultado[fil+2][col+2]=sensores.terreno[4];
					mapaResultado[fil+2][col+1]=sensores.terreno[5];
					mapaResultado[fil+2][col]=sensores.terreno[6];
					mapaResultado[fil+2][col-1]=sensores.terreno[7];
					mapaResultado[fil+2][col-2]=sensores.terreno[8];

					mapaResultado[fil+3][col+3]=sensores.terreno[9];
					mapaResultado[fil+3][col+2]=sensores.terreno[10];
					mapaResultado[fil+3][col+1]=sensores.terreno[11];
					mapaResultado[fil+3][col]=sensores.terreno[12];
					mapaResultado[fil+3][col-1]=sensores.terreno[13];
					mapaResultado[fil+3][col-2]=sensores.terreno[14];
					mapaResultado[fil+3][col-3]=sensores.terreno[15];
					break;
				case 3://OESTE
					mapaResultado[fil+1][col-1]=sensores.terreno[1];
					mapaResultado[fil][col-1]=sensores.terreno[2];
					mapaResultado[fil-1][col-1]=sensores.terreno[3];

					mapaResultado[fil+2][col-2]=sensores.terreno[4];
					mapaResultado[fil+1][col-2]=sensores.terreno[5];
					mapaResultado[fil][col-2]=sensores.terreno[6];
					mapaResultado[fil-1][col-2]=sensores.terreno[7];
					mapaResultado[fil-2][col-2]=sensores.terreno[8];

					mapaResultado[fil+3][col-3]=sensores.terreno[9];
					mapaResultado[fil+2][col-3]=sensores.terreno[10];
					mapaResultado[fil+1][col-3]=sensores.terreno[11];
					mapaResultado[fil][col-3]=sensores.terreno[12];
					mapaResultado[fil-1][col-3]=sensores.terreno[13];
					mapaResultado[fil-2][col-3]=sensores.terreno[14];
					mapaResultado[fil-3][col-3]=sensores.terreno[15];
					break;
			}
		}

		if(sensores.destinoF != destino.fila or sensores.destinoC != destino.columna){
			destino.fila=sensores.destinoF;
			destino.columna=sensores.destinoC;
			hayPlan=false;
		}
		if (!hayPlan && estoy_bien_situado){
				actual.fila=fil;
				actual.columna=col;
				actual.orientacion=brujula;
				hayPlan=pathFinding(sensores.nivel,actual,destino,plan);
			}


		//Sistema de movimiento

		//busqueda de punto referencia

		bool hayPK;
		int indicePK;
		for(int i=0;i<16;i++){
			if (sensores.terreno[i]=='K'){
				hayPK=true;
				indicePK=i;
				break;
			}
		}

		Action accion = actIDLE;

		if(hayPlan and plan.size()>0){

			if(sensores.superficie[2]=='a'){

				hayPlan=false;
				accion=actIDLE;
			}else if(sensores.terreno[2]=='P' or sensores.terreno[2]=='M' or
					sensores.terreno[2]=='D'){
					switch(brujula_p){
						case 0: mapaPulgarcito[fil_p-1][col_p]=1000; break;
						case 1: mapaPulgarcito[fil_p][col_p+1]=1000; break;
						case 2: mapaPulgarcito[fil_p+1][col_p]=1000; break;
						case 3: mapaPulgarcito[fil_p][col_p-1]=1000; break;
					}
				hayPlan=false;
				accion=actTURN_R;
			}
			else{
				accion=plan.front();
			}
			plan.erase(plan.begin());
			if (plan.size()==0){
				hayPlan=false;
			}
		}
		else{

			if (sensores.terreno[2]=='P' or sensores.terreno[2]=='M' or
					sensores.terreno[2]=='D' /*or sensores.superficie[2]=='a'*/){
						switch(brujula_p){
							case 0: mapaPulgarcito[fil_p-1][col_p]=1000; break;
							case 1: mapaPulgarcito[fil_p][col_p+1]=1000; break;
							case 2: mapaPulgarcito[fil_p+1][col_p]=1000; break;
							case 3: mapaPulgarcito[fil_p][col_p-1]=1000; break;
						}

						accion=actTURN_R;
					}
			else{

				if (hayPK){
					hayPlan=true;
					switch (indicePK) {
						case 1:
							plan.push_back(actFORWARD);
							plan.push_back(actTURN_L);
							plan.push_back(actFORWARD);
							break;
						case 2:
							plan.push_back(actFORWARD);
							break;
						case 3:
							plan.push_back(actFORWARD);
							plan.push_back(actTURN_R);
							plan.push_back(actFORWARD);
							break;
						case 4:
							plan.push_back(actFORWARD);
							plan.push_back(actFORWARD);
							plan.push_back(actTURN_L);
							plan.push_back(actFORWARD);
							plan.push_back(actFORWARD);
							break;
						case 5:
							plan.push_back(actFORWARD);
							plan.push_back(actFORWARD);
							plan.push_back(actTURN_L);
							plan.push_back(actFORWARD);
							break;
						case 6:
							plan.push_back(actFORWARD);
							plan.push_back(actFORWARD);
							break;
						case 7:
							plan.push_back(actFORWARD);
							plan.push_back(actFORWARD);
							plan.push_back(actTURN_R);
							plan.push_back(actFORWARD);
							break;
						case 8:
							plan.push_back(actFORWARD);
							plan.push_back(actFORWARD);
							plan.push_back(actTURN_R);
							plan.push_back(actFORWARD);
							plan.push_back(actFORWARD);
							break;
						case 9:
							plan.push_back(actFORWARD);
							plan.push_back(actFORWARD);
							plan.push_back(actFORWARD);
							plan.push_back(actTURN_L);
							plan.push_back(actFORWARD);
							plan.push_back(actFORWARD);
							plan.push_back(actFORWARD);
							break;
						case 10:
							plan.push_back(actFORWARD);
							plan.push_back(actFORWARD);
							plan.push_back(actFORWARD);
							plan.push_back(actTURN_L);
							plan.push_back(actFORWARD);
							plan.push_back(actFORWARD);
							break;
						case 11:
							plan.push_back(actFORWARD);
							plan.push_back(actFORWARD);
							plan.push_back(actFORWARD);
							plan.push_back(actTURN_L);
							plan.push_back(actFORWARD);
							break;
						case 12:
							plan.push_back(actFORWARD);
							plan.push_back(actFORWARD);
							plan.push_back(actFORWARD);
							break;
						case 13:
							plan.push_back(actFORWARD);
							plan.push_back(actFORWARD);
							plan.push_back(actFORWARD);
							plan.push_back(actTURN_R);
							plan.push_back(actFORWARD);
							break;
						case 14:
							plan.push_back(actFORWARD);
							plan.push_back(actFORWARD);
							plan.push_back(actFORWARD);
							plan.push_back(actTURN_R);
							plan.push_back(actFORWARD);
							plan.push_back(actFORWARD);
							break;
						case 15:
							plan.push_back(actFORWARD);
							plan.push_back(actFORWARD);
							plan.push_back(actFORWARD);
							plan.push_back(actTURN_R);
							plan.push_back(actFORWARD);
							plan.push_back(actFORWARD);
							plan.push_back(actFORWARD);
							break;
					}
				}else{
					int minvalor;
					int dondeIr;
					switch (brujula_p){
						case 0: minvalor=mapaPulgarcito[fil_p-1][col_p];
						dondeIr=0; break;
						case 1: minvalor=mapaPulgarcito[fil_p][col_p+1];
						dondeIr=1; break;
						case 2: minvalor=mapaPulgarcito[fil_p+1][col_p];
						dondeIr=2; break;
						case 3: minvalor=mapaPulgarcito[fil_p][col_p-1];
						dondeIr=3; break;
					}
					if(mapaPulgarcito[fil_p-1][col_p]<minvalor){
						minvalor=mapaPulgarcito[fil_p-1][col_p];
						dondeIr=0;
					}
					if ((mapaPulgarcito[fil_p][col_p+1])<minvalor){
						minvalor=mapaPulgarcito[fil_p][col_p+1];
						dondeIr=1;
					}
					if ((mapaPulgarcito[fil_p+1][col_p])<minvalor){
						minvalor=mapaPulgarcito[fil_p+1][col_p];
						dondeIr=2;
					}
					if ((mapaPulgarcito[fil_p][col_p-1])<minvalor){
						minvalor=mapaPulgarcito[fil_p][col_p-1];
						dondeIr=3;
					}
					switch (dondeIr) {
						case 0:
							switch(brujula_p){
								case 0: accion=actFORWARD; break;
								case 1: hayPlan=true; plan.push_back(actTURN_L);
																			plan.push_back(actFORWARD);
																			break;
								case 2: hayPlan=true; plan.push_back(actTURN_L);
																			plan.push_back(actTURN_L);
																			plan.push_back(actFORWARD);
																			break;
							  case 3: hayPlan=true; plan.push_back(actTURN_R);
																			plan.push_back(actFORWARD);
																			break;
							}
							break;
							case 1:
								switch(brujula_p){
									case 0: hayPlan=true; plan.push_back(actTURN_R);
																				plan.push_back(actFORWARD);
																				break;
									case 1: accion=actFORWARD; break;
									case 2: hayPlan=true; plan.push_back(actTURN_L);
																				plan.push_back(actFORWARD);
																				break;
									case 3: hayPlan=true; plan.push_back(actTURN_L);
																				plan.push_back(actTURN_L);
																				plan.push_back(actFORWARD);
																				break;
								}
								break;
								case 2:
									switch(brujula_p){
										case 0: hayPlan=true; plan.push_back(actTURN_L);
																					plan.push_back(actTURN_L);
																					plan.push_back(actFORWARD);
																					break;
										case 1: hayPlan=true; plan.push_back(actTURN_R);
																					plan.push_back(actFORWARD);
																					break;
										case 2: accion=actFORWARD; break;
										case 3: hayPlan=true; plan.push_back(actTURN_L);
																					plan.push_back(actFORWARD);
																					break;
									}
									break;
									case 3:
										switch(brujula_p){
											case 0: hayPlan=true; plan.push_back(actTURN_L);
																						plan.push_back(actFORWARD);
																						break;
											case 1: hayPlan=true; plan.push_back(actTURN_L);
																						plan.push_back(actTURN_L);
																						plan.push_back(actFORWARD);
																						break;
											case 2: hayPlan=true; plan.push_back(actTURN_R);
																						plan.push_back(actFORWARD);
																						break;
											case 3: accion=actFORWARD; break;
										}
										break;
					}

			}
		}
	}


		ultimaAccion=accion;



		return accion;







//--------------------------------------------------------------------

//NIVEL 1 AGENTE DELIBERATIVO

	}else{

	if (sensores.mensajeF!=-1){
		fil=sensores.mensajeF;
		col=sensores.mensajeC;
		ultimaAccion=actIDLE;
	}



	switch(ultimaAccion){
		case actTURN_R: brujula = (brujula+1)%4; break;
		case actTURN_L: brujula = (brujula+3)%4; break;
		case actFORWARD:
			switch (brujula) {
				case 0: fil--; break;
				case 1: col++; break;
				case 2: fil++; break;
				case 3: col--; break;
			}
			break;
	}

	//cout << "Fila: "<<fil<<" Col: "<<col<<" Or: "<<brujula<<endl;



	if(sensores.destinoF != destino.fila or sensores.destinoC != destino.columna){
		destino.fila=sensores.destinoF;
		destino.columna=sensores.destinoC;
		hayPlan=false;
	}


		if (!hayPlan){
			actual.fila=fil;
			actual.columna=col;
			actual.orientacion=brujula;
			hayPlan=pathFinding(sensores.nivel,actual,destino,plan);
		}


	unsigned char contenidoCasilla;
	switch(brujula){
		case 0: contenidoCasilla = mapaResultado[fil-1][col]; break;
		case 1: contenidoCasilla = mapaResultado[fil][col+1]; break;
		case 2: contenidoCasilla = mapaResultado[fil+1][col]; break;
		case 3: contenidoCasilla = mapaResultado[fil][col-1]; break;
	}


	//Sistema de movimiento
	Action accion = actIDLE;
	if(hayPlan and plan.size()>0){
		accion=plan.front();
		plan.erase(plan.begin());
	}
	else{
		if (contenidoCasilla=='P' or contenidoCasilla=='M' or
				contenidoCasilla=='D' or sensores.superficie[2]=='a'){
					accion=actTURN_R;
				}
		else{
			accion=actFORWARD;
		}
	}


	ultimaAccion=accion;



  return accion;
}
//-------------------------------------------------------------
}


// Llama al algoritmo de busqueda que se usará en cada comportamiento del agente
// Level representa el comportamiento en el que fue iniciado el agente.
bool ComportamientoJugador::pathFinding (int level, const estado &origen, const estado &destino, list<Action> &plan){
	switch (level){
		case 1: cout << "Busqueda en profundad\n";
			      return pathFinding_Profundidad(origen,destino,plan);
						break;
		case 2: cout << "Busqueda en Anchura\n";
			      return pathFinding_Anchura(origen,destino,plan);
						break;
		case 3: cout << "Busqueda Costo Uniforme\n";
						return pathFinding_CUniforme(origen,destino,plan);
						break;
		case 4: cout << "Busqueda para el reto\n";
						return pathFinding_CUniforme(origen,destino,plan);
						break;
	}
	cout << "Comportamiento sin implementar\n";
	return false;
}


//---------------------- Implementación de la busqueda en profundidad ---------------------------

// Dado el código en carácter de una casilla del mapa dice si se puede
// pasar por ella sin riegos de morir o chocar.
bool EsObstaculo(unsigned char casilla){
	if (casilla=='P' or casilla=='M' or casilla =='D')
		return true;
	else
	  return false;
}


// Comprueba si la casilla que hay delante es un obstaculo. Si es un
// obstaculo devuelve true. Si no es un obstaculo, devuelve false y
// modifica st con la posición de la casilla del avance.
bool ComportamientoJugador::HayObstaculoDelante(estado &st){
	int fil=st.fila, col=st.columna;

  // calculo cual es la casilla de delante del agente
	switch (st.orientacion) {
		case 0: fil--; break;
		case 1: col++; break;
		case 2: fil++; break;
		case 3: col--; break;
	}

	// Compruebo que no me salgo fuera del rango del mapa
	if (fil<0 or fil>=mapaResultado.size()) return true;
	if (col<0 or col>=mapaResultado[0].size()) return true;

	// Miro si en esa casilla hay un obstaculo infranqueable
	if (!EsObstaculo(mapaResultado[fil][col])){
		// No hay obstaculo, actualizo el parámetro st poniendo la casilla de delante.
    st.fila = fil;
		st.columna = col;
		return false;
	}
	else{
	  return true;
	}
}




struct nodo{
	estado st;
	list<Action> secuencia;
	bool operator<(const nodo& otro) const{
		return st.coste > otro.st.coste;
	}
	bool operator==(const nodo &otro) const{
		return st==otro.st;
	}
};

struct ComparaEstados{
	bool operator()(const estado &a, const estado &n) const{
		if ((a.fila > n.fila) or (a.fila == n.fila and a.columna > n.columna) or
	      (a.fila == n.fila and a.columna == n.columna and a.orientacion > n.orientacion))
			return true;
		else
			return false;
	}
};


// Implementación de la búsqueda en profundidad.
// Entran los puntos origen y destino y devuelve la
// secuencia de acciones en plan, una lista de acciones.
bool ComportamientoJugador::pathFinding_Profundidad(const estado &origen, const estado &destino, list<Action> &plan) {
	//Borro la lista
	cout << "Calculando plan\n";
	plan.clear();
	set<estado,ComparaEstados> generados; // Lista de Cerrados
	stack<nodo> pila;											// Lista de Abiertos

  nodo current;
	current.st = origen;
	current.secuencia.empty();

	pila.push(current);

  while (!pila.empty() and (current.st.fila!=destino.fila or current.st.columna != destino.columna)){

		pila.pop();
		generados.insert(current.st);

		// Generar descendiente de girar a la derecha
		nodo hijoTurnR = current;
		hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion+1)%4;
		if (generados.find(hijoTurnR.st) == generados.end()){
			hijoTurnR.secuencia.push_back(actTURN_R);
			pila.push(hijoTurnR);

		}

		// Generar descendiente de girar a la izquierda
		nodo hijoTurnL = current;
		hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion+3)%4;
		if (generados.find(hijoTurnL.st) == generados.end()){
			hijoTurnL.secuencia.push_back(actTURN_L);
			pila.push(hijoTurnL);
		}

		// Generar descendiente de avanzar
		nodo hijoForward = current;
		if (!HayObstaculoDelante(hijoForward.st)){
			if (generados.find(hijoForward.st) == generados.end()){
				hijoForward.secuencia.push_back(actFORWARD);
				pila.push(hijoForward);
			}
		}

		// Tomo el siguiente valor de la pila
		if (!pila.empty()){
			current = pila.top();
		}
	}

  cout << "Terminada la busqueda\n";

	if (current.st.fila == destino.fila and current.st.columna == destino.columna){
		cout << "Cargando el plan\n";
		plan = current.secuencia;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		return true;
	}
	else {
		cout << "No encontrado plan\n";
	}


	return false;
}







// Sacar por la términal la secuencia del plan obtenido
void ComportamientoJugador::PintaPlan(list<Action> plan) {
	auto it = plan.begin();
	while (it!=plan.end()){
		if (*it == actFORWARD){
			cout << "A ";
		}
		else if (*it == actTURN_R){
			cout << "D ";
		}
		else if (*it == actTURN_L){
			cout << "I ";
		}
		else {
			cout << "- ";
		}
		it++;
	}
	cout << endl;
}



void AnularMatriz(vector<vector<unsigned char> > &m){
	for (int i=0; i<m[0].size(); i++){
		for (int j=0; j<m.size(); j++){
			m[i][j]=0;
		}
	}
}


// Pinta sobre el mapa del juego el plan obtenido
void ComportamientoJugador::VisualizaPlan(const estado &st, const list<Action> &plan){
  AnularMatriz(mapaConPlan);
	estado cst = st;

	auto it = plan.begin();
	while (it!=plan.end()){
		if (*it == actFORWARD){
			switch (cst.orientacion) {
				case 0: cst.fila--; break;
				case 1: cst.columna++; break;
				case 2: cst.fila++; break;
				case 3: cst.columna--; break;
			}
			mapaConPlan[cst.fila][cst.columna]=1;
		}
		else if (*it == actTURN_R){
			cst.orientacion = (cst.orientacion+1)%4;
		}
		else {
			cst.orientacion = (cst.orientacion+3)%4;
		}
		it++;
	}
}



int ComportamientoJugador::interact(Action accion, int valor){
  return false;
}




//CODIGO AÑADIDO PARA ALGORITMOS DE BUSQUEDA EN ANCHURA Y DE COSTO UNIFORME
//Implementación de la búsqueda en anchura.

bool ComportamientoJugador::pathFinding_Anchura(const estado &origen, const estado &destino, list<Action> &plan) {
	//Borro la lista
	cout << "Calculando plan\n";
	plan.clear();
	set<estado,ComparaEstados> generados; 		// Lista de Cerrados
	queue<nodo> abiertos;											// Lista de Abiertos

  nodo current;
	current.st = origen;
	current.secuencia.empty();

	abiertos.push(current);

  while (!abiertos.empty() and (current.st.fila!=destino.fila or current.st.columna != destino.columna)){

		abiertos.pop();
		generados.insert(current.st);

		// Generar descendiente de girar a la derecha
		nodo hijoTurnR = current;
		hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion+1)%4;
		if (generados.find(hijoTurnR.st) == generados.end()){  //si el estado no existe en cerrados
			hijoTurnR.secuencia.push_back(actTURN_R);
			abiertos.push(hijoTurnR);

		}

		// Generar descendiente de girar a la izquierda
		nodo hijoTurnL = current;
		hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion+3)%4;
		if (generados.find(hijoTurnL.st) == generados.end()){
			hijoTurnL.secuencia.push_back(actTURN_L);
			abiertos.push(hijoTurnL);
		}

		// Generar descendiente de avanzar
		nodo hijoForward = current;
		if (!HayObstaculoDelante(hijoForward.st)){
			if (generados.find(hijoForward.st) == generados.end()){
				hijoForward.secuencia.push_back(actFORWARD);
				abiertos.push(hijoForward);
			}
		}

		// Tomo el siguiente valor de la cola
		if (!abiertos.empty()){
			current = abiertos.front();
		}
	}

  cout << "Terminada la busqueda\n";

	if (current.st.fila == destino.fila and current.st.columna == destino.columna){
		cout << "Cargando el plan\n";
		plan = current.secuencia;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		return true;
	}
	else {
		cout << "No encontrado plan\n";
	}


	return false;
}


struct ComparaCostes{
	bool operator()(const nodo &a, const nodo &n) const{
		if (a.st.coste<n.st.coste)
			return true;
		else
			return false;
	}
};

//Implementación de la búsqueda de costo uniforme.

int obtenerCoste(unsigned char x){
	if(x == 'T') { return 2;}
	if(x == 'B') { return 5;}
	if(x == 'A') { return 10;}
	if(x == '?') { return 4;}
	else return 1;
}

void borraNodo(multiset<nodo,ComparaCostes> mset, nodo nod){
	multiset<nodo,ComparaCostes>::iterator i=mset.begin();
	bool salir=false;
	while(i!=mset.end() && !salir){
		if ((*i)==nod){
			mset.erase(i);
			salir=true;
		}
		++i;
	}
}

/*struct ComparaEstados2{
	bool operator()(const nodo &a, const nodo &n) const{
		if ((a.st.fila > n.st.fila) or (a.st.fila == n.st.fila and a.st.columna > n.st.columna) or
	      (a.st.fila == n.st.fila and a.st.columna == n.st.columna and a.st.orientacion > n.st.orientacion))
			return true;
		else
			return false;
	}
};*/


bool ComportamientoJugador::pathFinding_CUniforme(const estado &origen, const estado &destino, list<Action> &plan) {
	//Borro la lista
	cout << "Calculando plan\n";
	plan.clear();
	set<estado,ComparaEstados> generados; 		// Lista de Cerrados
	multiset<nodo,ComparaCostes> abiertos;			// Lista de Abiertos
	//set<nodo,ComparaEstados2> abiertos_st;


  nodo current;
	current.st = origen;
	current.secuencia.empty();
	current.st.coste=0;

	abiertos.insert(current);

  while (!abiertos.empty()){

		if (current.st.fila == destino.fila and current.st.columna == destino.columna)
		break;

		abiertos.erase(abiertos.begin());
		generados.insert(current.st);

		/*multiset<nodo,ComparaCostes>::iterator it=abiertos.begin();
		while(it!=abiertos.end()){
			abiertos_st.insert(*it);
			++it;
		}*/

		// Generar descendiente de girar a la derecha
		nodo hijoTurnR = current;
		hijoTurnR.st.orientacion = (hijoTurnR.st.orientacion+1)%4;
		if (generados.find(hijoTurnR.st) == generados.end()  ){  //si el estado no existe en cerrados
			hijoTurnR.secuencia.push_back(actTURN_R);
			hijoTurnR.st.coste=current.st.coste+1;
			//set<nodo,ComparaEstados2>::iterator it=abiertos_st.find(hijoTurnR);
			//if(it==abiertos_st.end())
			abiertos.insert(hijoTurnR);
			/*else{
				if((*it).st.coste > (hijoTurnR.st.coste)){
					borraNodo(abiertos,(*it));
					abiertos.insert(hijoTurnR);
				}
			}*/

		}




		// Generar descendiente de girar a la izquierda
		nodo hijoTurnL = current;
		hijoTurnL.st.orientacion = (hijoTurnL.st.orientacion+3)%4;
		if (generados.find(hijoTurnL.st) == generados.end() ){  //si el estado no existe en cerrados
			hijoTurnL.secuencia.push_back(actTURN_L);
			hijoTurnL.st.coste=current.st.coste+1;
			//set<nodo,ComparaEstados2>::iterator it=abiertos_st.find(hijoTurnL);
			//if(it==abiertos_st.end())
			abiertos.insert(hijoTurnL);
			/*else{
				if((*it).st.coste > (hijoTurnL.st.coste)){
					borraNodo(abiertos,(*it));
					abiertos.insert(hijoTurnL);
				}
			}*/
		}

		// Generar descendiente de avanzar
		nodo hijoForward = current;
		if (!HayObstaculoDelante(hijoForward.st)){
			if (generados.find(hijoForward.st) == generados.end() ){
				hijoForward.secuencia.push_back(actFORWARD);
				hijoForward.st.coste=current.st.coste+obtenerCoste(mapaResultado[hijoForward.st.fila][hijoForward.st.columna]);
				//set<nodo,ComparaEstados2>::iterator it=abiertos_st.find(hijoForward);
				//if(it==abiertos_st.end())
				abiertos.insert(hijoForward);
			/*	else{
					if((*it).st.coste > (hijoForward.st.coste)){
						borraNodo(abiertos,(*it));
						abiertos.insert(hijoForward);
					}
				}*/
			}
		}


		// Tomo el siguiente valor de la cola
		if (!abiertos.empty()){
			current = (*abiertos.begin());
			while(generados.find(current.st)!=generados.end()){
				abiertos.erase(abiertos.begin()); //borra el nodo repetido (esta en cerrados), ya que es mejor el ya cerrado (por orden del coste(multiset))
				current=(*abiertos.begin());
			}

		}


	}

	if (current.st.fila == destino.fila and current.st.columna == destino.columna){
		cout << "Cargando el plan\n";
		plan = current.secuencia;
		cout << "Longitud del plan: " << plan.size() << endl;
		PintaPlan(plan);
		// ver el plan en el mapa
		VisualizaPlan(origen, plan);
		return true;
	}else {
		cout << "No encontrado plan\n";
	}



	return false;
}
