# include "AIPlayer.h"
# include "Parchis.h"

const double masinf = 9999999999.0, menosinf = -9999999999.0;
const double gana = masinf - 1, pierde = menosinf + 1;
const int num_pieces = 4;
const int PROFUNDIDAD_MINIMAX = 4;  // Umbral maximo de profundidad para el metodo MiniMax
const int PROFUNDIDAD_ALFABETA = 6; // Umbral maximo de profundidad para la poda Alfa_Beta

bool AIPlayer::move(){
   cout << "Realizo un movimiento automatico" << endl;
   
   color c_piece;
   int id_piece;
   int dice;
   think(c_piece, id_piece, dice);

   cout << "Movimiento elegido: " << str(c_piece) << " " << id_piece << " " << dice << endl;

   actual->movePiece(c_piece, id_piece, dice);
   return true;
}

void AIPlayer::think(color & c_piece, int & id_piece, int & dice) const{
  
    // Si quiero poder manejar varias heurísticas, puedo usar la variable id del agente para usar una u otra.
    
  /* switch(id){
         case 0:
             thinkAleatorio(c_piece, id_piece, dice);
             break;
         case 1:
             thinkAleatorioMasInteligente(c_piece, id_piece, dice);
             break;
         case 2:
             thinkFichaMasAdelantada(c_piece, id_piece, dice);
             break;
         case 3:
             thinkMejorOpcion(c_piece, id_piece, dice);
             break;
         }*/
       // El siguiente código se proporciona como sugerencia para iniciar la implementación del agente.

   double valor; // Almacena el valor con el que se etiqueta el estado tras el proceso de busqueda.
   double alpha = menosinf, beta = masinf; // Cotas iniciales de la poda AlfaBeta
   // Llamada a la función para la poda (los parámetros son solo una sugerencia, se pueden modificar).
//valor = Poda_AlfaBeta(*actual, jugador, 0, PROFUNDIDAD_ALFABETA, c_piece, id_piece, dice, alpha, beta, ValoracionTest);
  // valor = Min_Max(*actual, jugador, 0, PROFUNDIDAD_MINIMAX, c_piece, id_piece, dice, ValoracionTest); //*actual
  // cout << "Valor MiniMax: " << valor << "  Accion: " << str(c_piece) << " " << id_piece << " " << dice << endl;
//*
   // ----------------------------------------------------------------- //

    switch(id){
        case 0:
           //valor = Poda_AlfaBeta(*actual, jugador,0,PROFUNDIDAD_ALFABETA, c_piece, id_piece, dice, alpha, beta, ValoracionTest);
           valor = Min_Max(*actual, jugador, 0, PROFUNDIDAD_MINIMAX, c_piece, id_piece, dice, MiValoracion);
            
            break;
        case 1:
            //valor = thinkFichaMasAdelantada(color & c_piece, int & id_piece, int & dice);
            //valor = Min_Max(*actual, jugador, 0, PROFUNDIDAD_MINIMAX, c_piece, id_piece, dice, ValoracionTest);
           break;
        case 2:
          //  valor = Poda_AlfaBeta(*actual, jugador, 0, PROFUNDIDAD_ALFABETA, c_piece, id_piece, dice, alpha, beta, MiValoracion2);
            break;
    }
    cout << "Valor Poda_AlfaBeta: " << valor << "  Accion: " << str(c_piece) << " " << id_piece << " " << dice << endl;


   
   }
   void AIPlayer::thinkAleatorio(color & c_piece, int & id_piece, int & dice) const {
   // IMPLEMENTACIÓN INICIAL DEL AGENTE
   // Esta implementación realiza un movimiento aleatorio.
   // Se proporciona como ejemplo, pero se debe cambiar por una que realice un movimiento inteligente
   //como lo que se muestran al final de la función.
   
   // OBJETIVO: Asignar a las variables c_piece, id_piece, dice (pasadas por referencia) los valores,
   //respectivamente, de:
   // - color de ficha a mover
   // - identificador de la ficha que se va a mover
   // - valor del dado con el que se va a mover la ficha.

   // El color de ficha que se va a mover
   c_piece = actual->getCurrentColor();

   // Vector que almacenará los dados que se pueden usar para el movimiento
   vector<int> current_dices;
   // Vector que almacenará los ids de las fichas que se pueden mover para el dado elegido.
   vector<int> current_pieces;

   // Se obtiene el vector de dados que se pueden usar para el movimiento
   current_dices = actual->getAvailableDices(c_piece);
   // Elijo un dado de forma aleatoria.
   dice = current_dices[rand() % current_dices.size()];

   // Se obtiene el vector de fichas que se pueden mover para el dado elegido
   current_pieces = actual->getAvailablePieces(c_piece, dice);

   // Si tengo fichas para el dado elegido muevo una al azar.
   if(current_pieces.size() > 0){
       id_piece = current_pieces[rand() % current_pieces.size()];
   }
   else{
       // Si no tengo fichas para el dado elegido, pasa turno (la macro SKIP_TURN me permite no mover).
       id_piece = SKIP_TURN;
   }
   

   }




void AIPlayer::thinkAleatorioMasInteligente(color & c_piece, int & id_piece, int & dice) const {
   // IMPLEMENTACIÓN INICIAL DEL AGENTE
   // Esta implementación realiza un movimiento aleatorio.
   // Se proporciona como ejemplo, pero se debe cambiar por una que realice un movimiento inteligente
   //como lo que se muestran al final de la función.
   
   // OBJETIVO: Asignar a las variables c_piece, id_piece, dice (pasadas por referencia) los valores,
   //respectivamente, de:
   // - color de ficha a mover
   // - identificador de la ficha que se va a mover
   // - valor del dado con el que se va a mover la ficha.

   // El color de ficha que se va a mover
   c_piece = actual->getCurrentColor();

   // Vector que almacenará los dados que se pueden usar para el movimiento
   vector<int> current_dices;
   // Vector que almacenará los ids de las fichas que se pueden mover para el dado elegido.
   vector<int> current_pieces;

   // Se obtiene el vector de dados que se pueden usar para el movimiento
   current_dices = actual->getAvailableDices(c_piece);
   
   //En vez de elegir un dado al azar, miro primero cuáles tienen fichas que se puedan mover.
   vector<int> current_dices_que_pueden_mover_ficha;
   for (int i = 0; i < current_dices.size(); i++) {
   current_pieces = actual->getAvailablePieces(c_piece, current_dices[i]);
   //Si se peden mover fichar para el dado actual, lo añado al vector de dados que pueden mover fichas.
   if (current_pieces.size() > 0) {
       current_dices_que_pueden_mover_ficha.push_back(current_dices[i]);
       }
       
   }
   
   //Si no tengo ningún dado que pueda mover fichas, paso turno con un dado al azar(la macro SKIP_TURN me permite no mover).
   if(current_dices_que_pueden_mover_ficha.size() == 0){
   // Elijo un dado de forma aleatoria.
   dice = current_dices[rand() % current_dices.size()];
   id_piece = SKIP_TURN;
   }
   
   else{
   dice = current_dices_que_pueden_mover_ficha[rand() % current_dices_que_pueden_mover_ficha.size()];
   // Se obtiene el vector de fichas que se pueden mover para el dado elegido
   current_pieces = actual->getAvailablePieces(c_piece, dice);

   // Muevo una ficha al azar de entre las que se pueden mover

       id_piece = current_pieces[rand() % current_pieces.size()];
   }
   

}
void AIPlayer::thinkFichaMasAdelantada(color & c_piece, int & id_piece, int & dice) const {
   //Elijo el dado haciendo lo mismo que el jugador anterior.
   thinkAleatorioMasInteligente(c_piece, id_piece, dice);
   //Tras llamar a esta función, ya tengo en dice el número de dado que quiero usar.
   //Ahora, en vez de mover una ficha al azar, voy a mover la que esté más adelantada
   //(equivalentemente, la más cercana a la meta).
   
   vector<int> current_pieces = actual->getAvailablePieces(c_piece, dice);
   
   int id_ficha_mas_adelantada = -1;
   int min_distancia_meta = 9999;
   
   for (int i = 0; i < current_pieces.size(); i++){
   
   //distanceToGoal(color,id) devuelve la distancia a la meta de la ficha [id] del color que le indique.
   int distancia_meta = actual->distanceToGoal(c_piece, current_pieces[i]);
   if(distancia_meta < min_distancia_meta){
   min_distancia_meta = distancia_meta;
   id_ficha_mas_adelantada = current_pieces[i];
   }
   }
   
   //Si no he encontrado ninguna ficha, paso turno.
   if(id_ficha_mas_adelantada == -1){
   

   id_piece = SKIP_TURN;
   }
   //En caso contrario, moveré la ficha más adelantada
   else{
   
       id_piece = id_ficha_mas_adelantada;
   }
   

}
void AIPlayer::thinkMejorOpcion(color & c_piece, int & id_piece, int & dice) const {
  // Vamos a mirar todos los posibles movimientos del jugador actual accediendo a los hijos del estado actual
  // generateNextMove va iterando sobre cada hijo. Le paso la acción del último movimiento sobre
   // el que he iterado y me devolverá el siguiente. Inicialmente, cuando aún no he hecho ningún
  // movimiento, lo inicializo así.
   color last_c_piece = none; // El color de la última ficha que se movió.
   int last_id_piece = -1; // El id de la última ficha que se movió.
   int last_dice = -1;
   // El dado que se usó en el último movimiento.
// Cuando ya he recorrido todos los hijos, la función devuelve el estado actual. De esta forma puedo saber
// cuándo paro de iterar
Parchis siguiente_hijo = actual->generateNextMove(last_c_piece, last_id_piece, last_dice);
bool me_quedo_con_esta_accion = false;
while(!(siguiente_hijo == *actual) && !me_quedo_con_esta_accion){
if(siguiente_hijo.isEatingMove() or // Si con este movimiento como ficha,
siguiente_hijo.isGoalMove() or
// Si con este movimiento llego a la meta,
(siguiente_hijo.gameOver() and siguiente_hijo.getWinner() == this->jugador) // Si con este movimiento gano la partida.
){
// Me quedo con la acción actual (se almacenó en last c piece, last id piece, last dice al llamar a generateNextMove)
me_quedo_con_esta_accion = true;
}
else{
// Genero el siguiente hijo.
siguiente_hijo = actual->generateNextMove(last_c_piece, last_id_piece, last_dice);
}
}
// Si he encontrado una acción que me interesa, la guardo en las variables pasadas por referencia.
if(me_quedo_con_esta_accion){
c_piece = last_c_piece;
id_piece = last_id_piece;
dice = last_dice;
}
// Si no, muevo la ficha más adelantada como antes.
else{
thinkFichaMasAdelantada(c_piece, id_piece, dice);
   }
   

}
double AIPlayer::Poda_AlfaBeta(const Parchis &actual, int jugador, int profundidad, int profundidad_max, color &c_piece, int &id_piece, int &dice, double alpha, double beta, double (*heuristic)(const Parchis &, int)) const{
    if(profundidad== profundidad_max|| actual.gameOver()){
              return heuristic(actual,jugador);
              
          }
          color last_c_piece=none;
          int last_id_piece=-1;
          int last_dice=-1;
          Parchis hijopoda;
          double aux2=0; //valor
      double valor;
          if(actual.getCurrentPlayerId()==jugador){ //si es una nodo max
              valor = menosinf;
              hijopoda=actual.generateNextMove(last_c_piece,last_id_piece,last_dice);
              while(!(hijopoda==actual)){
                   aux2=Poda_AlfaBeta(hijopoda,jugador,profundidad+1,profundidad_max,last_c_piece,last_id_piece,last_dice,alpha,beta,heuristic); //
                  alpha = max(alpha, aux2);
                  if(aux2 > valor){
                      valor = aux2;
                  
                      if(profundidad == 0){
                      c_piece = last_c_piece;
                      id_piece=last_id_piece;
                      dice=last_dice;
                      }
                  }
                  //hijopoda=actual.generateNextMove(last_c_piece,last_id_piece,last_dice);
              if(alpha>=beta){
                      return beta;
              }
                 hijopoda=actual.generateNextMove(last_c_piece,last_id_piece,last_dice);
                 
                  
              }
              
              
             
          }else{
              valor = masinf;
               hijopoda=actual.generateNextMove(last_c_piece,last_id_piece,last_dice);
              while(!(hijopoda==actual)){
                   aux2=Poda_AlfaBeta(hijopoda,jugador,profundidad+1,profundidad_max,last_c_piece,last_id_piece,last_dice,alpha,beta,heuristic);
                  beta = min(beta,aux2);
                  if(aux2 < valor){
                      valor = aux2;
                  
                      if(profundidad == 0){
                      c_piece = last_c_piece;
                      id_piece=last_id_piece;
                      dice=last_dice;
                      }
                  }
                  //hijopoda=actual.generateNextMove(last_c_piece,last_id_piece,last_dice);
                  if(alpha >= beta){
                      return alpha;
                
                  }
                  hijopoda=actual.generateNextMove(last_c_piece,last_id_piece,last_dice);
                 
              }
              
             
             // c_piece = last_c_piece;
              //id_piece=last_id_piece;
             // dice=last_dice;
          }
return valor;

      }






double AIPlayer::Min_Max(const Parchis &actual, int jugador, int profundidad, int profundidad_max, color &c_piece, int &id_piece, int &dice, double (*heuristic)(const Parchis &, int)) const{
    if(profundidad==profundidad_max || actual.gameOver()){
    return heuristic(actual,jugador);
    }
    color last_c_piece=none;
    //color ult_aux;
    int last_id_piece=-1, id_aux;
    int last_dice=-1, dado_aux;
        double aux = 0;
        double valor;
    Parchis hijo;

    if(actual.getCurrentPlayerId()==jugador){ //nodo max
    valor=menosinf;
    hijo=actual.generateNextMove(last_c_piece,last_id_piece,last_dice);
    while(!(hijo==actual)){

    aux=Min_Max(hijo,jugador,profundidad+1,profundidad_max,last_c_piece,last_id_piece,last_dice,heuristic);
    if(aux > valor){
    valor = aux;
        if(profundidad==0){
        
        c_piece = last_c_piece;
        id_piece=last_id_piece;
        dice= last_dice;
        }
    
    }
    hijo=actual.generateNextMove(last_c_piece,last_id_piece,last_dice);
    }
    }
    else{
    valor=masinf;
    hijo=actual.generateNextMove(last_c_piece,last_id_piece,last_dice);
    
        while(!(hijo==actual)){
    aux=Min_Max(hijo,jugador,profundidad+1,profundidad_max,last_c_piece,last_id_piece,last_dice,heuristic);
    if(aux < valor){
        
    valor = aux;
        if(profundidad==0){
    c_piece = last_c_piece;
    id_piece=last_id_piece;
    dice= last_dice;
        }
    }

    hijo=actual.generateNextMove(last_c_piece,last_id_piece,last_dice);
    
    }
    
    }
    
return valor;
}

double AIPlayer::ValoracionTest(const Parchis &estado, int jugador)
{
    // Heurística de prueba proporcionada para validar el funcionamiento del algoritmo de búsqueda.


    int ganador = estado.getWinner();
    int oponente = (jugador + 1) % 2;

    // Si hay un ganador, devuelvo más/menos infinito, según si he ganado yo o el oponente.
    if (ganador == jugador)
    {
        return gana;
    }
    else if (ganador == oponente)
    {
        return pierde;
    }
    else
    {
        // Colores que juega mi jugador y colores del oponente
        vector<color> my_colors = estado.getPlayerColors(jugador);
        vector<color> op_colors = estado.getPlayerColors(oponente);
        
    
        // Recorro todas las fichas de mi jugador
        int puntuacion_jugador = 0;
        // Recorro colores de mi jugador.
        for (int i = 0; i < my_colors.size(); i++)
        {
            color c = my_colors[i];
            // Recorro las fichas de ese color.
            for (int j = 0; j < num_pieces; j++)
            {
               
                // Valoro positivamente que la ficha esté en casilla segura o meta.
                if (estado.isSafePiece(c, j))
                {
                    puntuacion_jugador++;
                }
                else if (estado.getBoard().getPiece(c, j).type == goal)
                {
                    puntuacion_jugador += 5;
                }
            }
        }

        // Recorro todas las fichas del oponente
        int puntuacion_oponente = 0;
        // Recorro colores del oponente.
        for (int i = 0; i < op_colors.size(); i++)
        {
            color c = op_colors[i];
            // Recorro las fichas de ese color.
            for (int j = 0; j < num_pieces; j++)
            {
                if (estado.isSafePiece(c, j))
                {
                    // Valoro negativamente que la ficha esté en casilla segura o meta.
                    puntuacion_oponente++;
                }
                
                else if (estado.getBoard().getPiece(c, j).type == goal)
                {
                    puntuacion_oponente += 5;
                }
            }
        }

        // Devuelvo la puntuación de mi jugador menos la puntuación del oponente.
        return puntuacion_jugador - puntuacion_oponente;
    }
}


double AIPlayer::MiValoracion(const Parchis &estado, int jugador)
{
    // Heurística de prueba proporcionada para validar el funcionamiento del algoritmo de búsqueda.


        int ganador = estado.getWinner();
        int oponente = (jugador + 1) % 2;

        // Si hay un ganador, devuelvo más/menos infinito, según si he ganado yo o el oponente.
        if (ganador == jugador)
        {
            return gana;
        }
        else if (ganador == oponente)
        {
            return pierde;
        }
        else
        {
            // Colores que juega mi jugador y colores del oponente
            vector<color> my_colors = estado.getPlayerColors(jugador);
            
            vector<color> op_colors = estado.getPlayerColors(oponente);
            
        
            // Recorro todas las fichas de mi jugador
            int puntuacion_jugador = 0;
            // Recorro colores de mi jugador.
            for (int i = 0; i < my_colors.size(); i++)
            {
                color c = my_colors[i];
                
                // Recorro las fichas de ese color.
                for (int j = 0; j < num_pieces; j++)
                {
                    int distancia_meta = estado.distanceToGoal(c,j);
                    int piezas_en_meta = estado.piecesAtGoal(c);
                    // Valoro positivamente que la ficha esté en casilla segura o meta.
                    if (estado.isSafePiece(c, j))
                    {
                        
                        puntuacion_jugador++;
                        
                    }if(estado.getBoard().getPiece(op_colors[0], j).type == home){
                        puntuacion_jugador += 7;
                    }
                    if(estado.getBoard().getPiece(op_colors[1], j).type == home){
                        puntuacion_jugador += 7;
                    }
                    
                    if (estado.getBoard().getPiece(c, j).type == goal)
                    {
                        
                        puntuacion_jugador += 20;
                        
                        
                    }
                    if(estado.goalBounce()){
                        puntuacion_jugador -= 4;
                    }
                    
                    if (estado.isEatingMove()){
                       
                        puntuacion_jugador += 10;
                       
                    }
                    if(distancia_meta--){
                        puntuacion_jugador += 3;
                    }
                    if(piezas_en_meta++){
                        puntuacion_jugador += 15;
                    }
                    if(estado.getBoard().getPiece(c, j).type == home){
                        
                        puntuacion_jugador += -30;
                        
                    }
                    
                }
           
            }

            // Recorro todas las fichas del oponente
            int puntuacion_oponente = 0;
            // Recorro colores del oponente.
            for (int i = 0; i < op_colors.size(); i++)
            {
                color c = op_colors[i];
                // Recorro las fichas de ese color.
                for (int j = 0; j < num_pieces; j++)
                {
                    int distancia_meta = estado.distanceToGoal(c,j);
                    int piezas_en_meta = estado.piecesAtGoal(c);
                    // Valoro positivamente que la ficha esté en casilla segura o meta.
                    if (estado.isSafePiece(c, j))
                    {
                        
                        puntuacion_oponente++;
                        
                    }if(estado.getBoard().getPiece(op_colors[0], j).type == home){
                        puntuacion_oponente += 7;
                    }
                    if(estado.getBoard().getPiece(op_colors[1], j).type == home){
                        puntuacion_oponente += 7;
                    }
                    
                    if (estado.getBoard().getPiece(c, j).type == goal)
                    {
                        
                        puntuacion_oponente += 20;
                        
                        
                    }
                    if(estado.goalBounce()){
                        puntuacion_oponente -= 4;
                    }
                    
                    if (estado.isEatingMove()){
                       
                        puntuacion_oponente += 10;
                       
                    }
                    if(distancia_meta--){
                        puntuacion_oponente += 3;
                    }
                    if(piezas_en_meta++){
                        puntuacion_oponente += 15;
                    }
                    if(estado.getBoard().getPiece(c, j).type == home){
                        
                        puntuacion_oponente += -30;
                        
                    }
                   
                }
           
            }

            // Devuelvo la puntuación de mi jugador menos la puntuación del oponente.
            return puntuacion_jugador - puntuacion_oponente;
        }
    }
