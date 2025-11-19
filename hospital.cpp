#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct fila{
    string senha;
    string prioridade;
    int horas;
    int minutos;
};

struct prioridade{
    int ve = 0;
    int am = 0;
    int verd = 0;
    int az = 0;
};

void menu(){
    cout << "Menu de Selecao:\n" 
         << "C - Adicionar paciente.\n"
         << "A - Atender.\n"
         << "D - Situacao da fila.\n"
         << "Q - Encerrar." << endl;
};

int transformar(int a, int b){
    return a*60 + b;
};

int main(){
    queue<fila> vermelha;
    queue<fila> amarela;
    queue<fila> verde;
    queue<fila> azul;
    prioridade prior;
    int v = 0;
    int amar = 0;
    int ver = 0;
    int azu = 0;
    int atendidos = 0;
    int media = 0;
    int chegada, espera;
    int maior = 0;
    string selecao;
    fila aux;

    while(true){
        menu();
        cin >> selecao;
        if(selecao == "C" || selecao == "c"){
            cout << "Insira a senha: ";
            cin >> aux.senha;
            cout << "Insira a prioridade: ";
            cin >> aux.prioridade;
            cout << "Insira o horario (hh mm): ";
            cin >> aux.horas >> aux.minutos;
            if(aux.prioridade == "V" || aux.prioridade == "v"){
                vermelha.push(aux);
                v++;
                prior.ve++;
            } else if(aux.prioridade == "A" || aux.prioridade == "a" ){
                amarela.push(aux);
                amar++;
                prior.am++;
            } else if(aux.prioridade == "D" || aux.prioridade == "d"){
                verde.push(aux);
                ver++;
                prior.verd++;
            } else if(aux.prioridade == "B" || aux.prioridade == "b"){
                azul.push(aux);
                azu++;
                prior.az++;
            }
        }else if(selecao == "A" || selecao == "a"){
            cout << "Insira o horario (hh mm): ";
            cin >> aux.horas >> aux.minutos;
            int atendimento = transformar(aux.horas, aux.minutos);
            if(!vermelha.empty()){
                chegada = transformar(vermelha.front().horas, vermelha.front().minutos);
                espera = atendimento - chegada;
                if(espera > maior)
                    maior = espera;
                media+=espera;
                vermelha.pop();
                atendidos++;
                v--;
            } else if(!amarela.empty()){
                chegada = transformar(amarela.front().horas, amarela.front().minutos);
                espera = atendimento - chegada;
                if(espera > maior)
                    maior = espera;
                media+=espera;
                amarela.pop();
                atendidos++;
                amar--;
            } else if(!verde.empty()){
                chegada = transformar(verde.front().horas, verde.front().minutos);
                espera = atendimento - chegada;
                media+=espera;
                verde.pop();
                atendidos++;
                ver--;
            } else if(!azul.empty()){
                chegada = transformar(azul.front().horas, azul.front().minutos);
                espera = atendimento - chegada;
                if(espera > maior)
                    maior = espera;
                media+=espera;
                azul.pop();
                atendidos++;
                azu--;
            } else {
                cout << " Sem pacientes aguardando atendimento." << endl;
            }
        }else if(selecao == "D" || selecao == "d"){
            cout << "V: " << v <<  " A: " << amar << " D: " << ver 
                 << " B: " << azu  << " Atendidos: " << atendidos << endl;
        } else if(selecao == "Q" || selecao == "q"){
            media = media/atendidos;
            cout << "--- Relatorio Final --- \n"
                 << "Total atendidos: " << atendidos << endl
                 << "Por prioridade: " << "V: " << prior.ve << " A: " << prior.am 
                 << " D: " << prior.verd << " B: " << prior.az << endl
                 << "Pico de lotacao: " << atendidos+v+amar+ver+azu << endl
                 << "Tempo medio de espera: " << media/60 << " h " << media%60 << " min" << endl
                 << "Tempo maximo de espera: " << maior/60 << " h " << maior%60 << " min " << endl;

            
            break;
        }
    }

    return 0;
}