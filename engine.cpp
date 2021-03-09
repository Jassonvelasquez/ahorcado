#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>


using namespace std;


// struct global para guardar el estado del juego.

struct game { int lives = 10; int tries; int points; } Game;


void draw_screen (const string &w) {
    cout << "\e[2J\e[4;4H";                     // '\e[2J' -> secuencia ANSI para borrar la pantalla.

    for (auto _ : w) cout << "_ ";              // imprimir un «_» + « » por cada caracter en la palabra.
                     cout << w << "\e[;4H";     // mover el cursor al principio de la línea; luego moverlo
                                                // cuatro espacios.
}


void set_status () {
    cout << "\e[s"                                          // '\e[s'    -> guardar la posición del cursor.
         << "\e[0;2H"                                       // '\e[0;2H' -> ubicar el cursor en la posición 0,2.
         << "\e[m  lives: "  << "\e[31m" << Game.lives
         << "\e[m  tries: "  << "\e[35m" << Game.tries
         << "\e[m  points: " << "\e[32m" << Game.points
         << "\e[u";                                         // '\e[u'    -> restaurar la posición anterior del cursor
                                                            //              (la que se guardó con '\e[s').
}


void guess (const string &w) {
    draw_screen(w);

    char l;
    for (auto c : w) {
        for (Game.tries = 1; Game.tries < 3; Game.tries += 1) {
            set_status();

            cin >> l;                  // leer un caracter en «c».
            if (l == '\e') exit(0);    // si el usuario presiona «ESC», salir del juego.

            if (c == l) goto good;     // si «c» es igual al caracter actual, imprimir «c» + « ».

        }

        Game.lives -= 1;
        cout << "\e[34m" << c << " \e[m";

        good:
            cout << l << " ";
    }

    Game.points += w.size();
    Game.lives += 1;
}


int main () {
    vector <string> d { "hola"
                      , "esternocleidomastoideo"
                      , "vaso"
                      , "ufano"
                      , "molecular"
                      , "procesador"
                      , "universidad"
                      , "dificultades"
                      , "lodazal"
                      , "estero"
                      , "gracia"
                      , "quiste"
                      , "misericordioso"
                      , "gato"
                      , "humanidad"
                      , "olvido"
                      , "dialecto"
                      , "salvador"
                      , "cual"
                      , "adepto"
                      , "bazo"
                      , "muralla"
                      , "pueril"
                      , "bueno"
                      , "gusto"
                      , "hematoma"
                      , "negrita"
                      , "mano"
                      , "quien"
                      , "radiactivo"
                      , "zarza"
                      , "anormal"
                      , "austeridad"
                      , "mordaz"
                      , "perla"
                      , "sequedad"
                      , "sacrificio"
                      , "una"
                      , "perfeccionamiento"
                      , "no"
                      , "coherente"
                      , "zarcillo"
                      , "bajo"
                      , "unanimidad"
                      , "empirismo"
                      , "triste"
                      , "maleta"
                      , "rey"
                      , "zaranda"
                      , "inmenso"
                      , "majestad"
                      , "ubicuo"
                      , "muerte"
                      , "humilde"
                      , "bondadoso"
                      , "dominante"
                      , "bismuto"
                      , "gatitos"
                      , "capricho"
                      , "pundonor"
                      , "mantel"
                      , "apaciguar"
                      , "hemorragia"
                      , "sistema"
                      , "el"
                      , "carro"
                      , "duna"
                      , "coraje"
                      , "por"
                      , "puente"
                      , "almohada"
                      , "igual"
                      , "sucumbir"
                      , "a"
                      , "cereza"
                      , "memoria"
                      , "compasivo"
                      , "paciente"
                      , "sencillez"
                      , "astillero"
                      , "ellos"
                      , "antagonista"
                      , "nacimiento"
                      , "manivela"
                      , "ebanista"
                      , "semejanza"
                      , "justicia"
                      , "reverso"
                      , "amor"
                      , "diversidad"
                      , "diferente"
                      , "pared"
                      , "uno"
                      , "prehistoria"
                      , "ella"
                      , "esclavos"
                      , "eterno"
                      , "interesante"
                      , "su"
                      , "perdonar"
                      , "mesa"
                      , "capitalismo"
                      , "esencia"
                      , "suplicio"
                      , "playa"
                      , "cama"
                      , "dogma"
                      , "glaucoma"
                      , "piadoso"
                      , "apuesta"
                      , "seguidores"
                      , "azul"
                      , "apto"
                      , "raya"
                      , "cataclismo"
                      , "azahar"
                      , "austero"
                      , "epopeya"
                      , "ribosoma"
                      , "glorioso"
                      , "carga"
                      , "brutalismo"
                      , "bella"
                      , "fanatismo"
                      , "sediento"
                      , "redimir"
                      , "apacible"
                      , "justo"
                      , "mar"
                      , "matriz"
                      , "nombre"
                      , "sindicato"
                      , "presencia"
                      , "anverso"
                      , "preprocesador"
                      , "servicio"
                      , "inesperado"
                      , "voraz"
                      , "inepto"
                      , "orgullo"
                      , "anatema"
                      , "rojo"
                      , "incapaz"
                      , "dolmen"
                      , "vacuo"
                      , "cavidad"
                      , "centella"
                      , "trasluz"
                      , "soslayo"
                      , "rimbombante"
                      , "cultismo"
                      , "animosidad"
                      , "espirituoso"
                      , "ardiente"
                      , "bronce"
                      , "celda"
                      , "litio"
                      , "cerbatana"
                      , "millar"
                      , "pertinente"
                      , "sargento"
                      , "soledad"
                      , "firme"
                      , "valiente"
                      , "fugaz"
                      };

    srand (time(0));
    for (;;) guess (d[rand() % d.size()]);
}
