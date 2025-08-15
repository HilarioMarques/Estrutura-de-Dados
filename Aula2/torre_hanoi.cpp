#include <bits/stdc++.h>
using namespace std;

class TorreHanoi {
    private:
        int n; //numero discos
        vector<vector<int>> pinos; //pinos[0] = A; pinos[1] = B; pinos[2] = C
        long long movCont; //contador de movimentos
        bool controlador; //vai imprimir cada movimento se true

         // move o disco do topo de um pino para outro
        void movDisco(int de, int para){
            
            if(pinos[de].empty()){
                throw runtime_error("Tentativa de mover de pino vazio!");
            }

            int disco = pinos[de].back();
            if(!pinos[para].empty() && pinos[para].back() < disco){
                throw runtime_error("Movimento inválido: não é permitido colocar disco maior sobre menor.");
            }

            pinos[de].pop_back();
            pinos[para].push_back(disco);

            movCont++;
            if(controlador) printMove(disco, de, para);

        }

        void printMove(int disco, int de, int para) const {
            static const char *names = "ABC";
            cout << "Mover disco " << disco << " de " << names[de] << " para " << names[para] << "\n";
        }
        // Função recursiva que resolve k discos do pino `de` à `para` usando `aux` como auxiliar
        void funREC(int k, int de, int para, int aux){
            if(k == 0) return; // caso base: nada a mover
            
            // mover k-1 discos de 'de' para 'aux'
            funREC(k - 1, de, aux, para);

            // mover o disco restante de 'de' à 'para'
            movDisco(de, para);

            // mover os k-1 discos de 'aux' à 'para'
            funREC(k - 1, aux, para, de);
        }

    public:
        TorreHanoi(int disco, bool controladorSaida = true)
            : n(disco), pinos(3), movCont(0), controlador(controladorSaida){

                // Coloca discos no pino 0 (A). Maior disco = n, menor = 1.
                // Empurramos do maior ao menor para que back() seja o topo (disco 1).
                for(int d = n; d >= 1; --d) pinos[0].push_back(d);
            }

            void resolucao(){
                movCont = 0;
                funREC(n, 0, 1, 2); // mover n discos de A(0) para C(2) usando B(1)
            }
            
            // retorna o número total de movimentos efetuados
            long long getMovCont() const {return movCont;}

            void estado() const{
                cout << "Estado dos pinos (de baixo -> topo):\n";

                for(int i = 0; i < 3; i++){
                    cout << char('A' + i) << ": ";
                    for(int disco : pinos[i]) cout << disco << " ";
                    cout << "\n";
                }
            }
};

int main(){
    int n;
    cout << "Quantos discos? ";
    if(!(cin >> n) || n < 1) {
        cerr << "Número inválido de discos.\n";
        return 1;
    }

    TorreHanoi jogo(n, true);

    cout << "Estado inicial:\n";
    jogo.estado();

    jogo.resolucao();

    cout << "Resolvido! Total de movimentos = " << jogo.getMovCont() << "\n";
    return 0;
}