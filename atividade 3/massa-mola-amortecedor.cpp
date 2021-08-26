#include <iostream>
#include <memory>

/*
 * Código para simular um sistema massa massamola 
 * Utilizou-se o modelo MVC, separando os dados na classe modelo, a classe 
 * Visualizador printa os dados
 * Controller é responsável por realizar os cálculos e chamar os métodos de Modelo 
 * para armazená-los 
 */

using namespace std;


class Modelo{
  private:
    // Constantes
    float b;
    float m;
    float k;
    float dt;
    // Variáveis
    float velocidade;
    float posicao;

  public: 
    // Construtor que inicializa todas as variáveis
    Modelo(float posicao_inicial, float velocidade_inicial, float b_input, float k_input, float m_input, float dt_input);

    // Setters
    void seta_posicao(float dado);
    void seta_velocidade(float dado);
    
    // Getters
    float pega_posicao();
    float pega_velocidade();
    float pega_b();
    float pega_m();
    float pega_k();
    float pega_dt();

};

// Métodos do modelo
  Modelo::Modelo(float posicao_inicial, float velocidade_inicial, float b_input, float k_input, float m_input, float dt_input){
    // Configura constantes (que não vao ser mais alteradas)
    b = b_input;
    k = k_input;
    m = m_input;
    dt = dt_input;

    // configura dados inciais
    velocidade = velocidade_inicial;
    posicao = posicao_inicial;

  }
  void Modelo::seta_posicao(float dado){
  posicao = dado;
  }

  void Modelo::seta_velocidade(float dado){
  velocidade = dado;
  }

  float Modelo::pega_posicao(){
  return posicao;
  }
  float Modelo::pega_velocidade(){
  return velocidade;
  }
  float Modelo::pega_b(){
  return b;
  }
  float Modelo::pega_m(){
  return m;
  }
  float Modelo::pega_k(){
  return k;
  }
  float Modelo::pega_dt(){
    return dt;
  }


class Visualizador{
  private:
    Modelo &modelo;
  public:
    Visualizador(Modelo &modelo);
    void printa_constantes(char oque); // printa as constantes
    void printa_velocidade();
    void printa_posicao();
};

Visualizador::Visualizador(Modelo &modelo):modelo(modelo){
  cout << "Visualizador inicializado" << endl;
}

void Visualizador::printa_constantes(char oque){
    switch(oque){
    case 'k':
      cout<<"k = "<< modelo.pega_k()<<endl;
      break;
    case 'b':
      cout<<"b = "<<modelo.pega_b()<<endl;
       break;
    case 'm':
      cout<<"m = "<<modelo.pega_m()<<endl;
       break;
    case 't':
      cout<<"t = "<<modelo.pega_dt()<<endl;
       break;
  }
}
void Visualizador::printa_velocidade(){
  cout << "Velocidade: " << modelo.pega_velocidade() << endl;
}
void Visualizador::printa_posicao(){
  cout << "Posição: " << modelo.pega_posicao() << endl;
}

// Classe responsável por calcular os novos valores e fazer chamadas dos métodos de armazenamento da classe Modelo
class Controller{
  private:
    Modelo &modelo; 
    Visualizador &visualizador;
  public:
    Controller(Modelo &modelo,Visualizador &visualizador);
    void atualizador(); // função que realiza o cálculo
};

Controller::Controller(Modelo &modelo,Visualizador &visualizador):modelo(modelo),visualizador(visualizador){
cout << "Controlador inicializado" << endl;
}

void Controller::atualizador(){
  float forca = -modelo.pega_posicao()*modelo.pega_k() -modelo.pega_b()*modelo.pega_velocidade();
 
  float aceleracao = forca/modelo.pega_m();

  modelo.seta_velocidade(modelo.pega_velocidade() + aceleracao*modelo.pega_dt());
 
  modelo.seta_posicao(modelo.pega_posicao() + modelo.pega_velocidade()*modelo.pega_dt());
}



int main() {

  Modelo massamola = Modelo(0, 10, 0.1, 3, 10, 0.1);
  Visualizador view = Visualizador(massamola);
  Controller simulacao = Controller(massamola, view);

  for (int i = 0; i < 100; i++){
    simulacao.atualizador();
    view.printa_posicao();
  }



}
