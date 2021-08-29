#include <iostream>
#include "PVI.h"
using namespace std;

void RK3(double v0, double y0, double k, double m, int nIter, double t, double t_s) {

  PVI *p = new PVI(v0, y0, k, m);

  double maxY = y0;
  double tMaxY = 0;
  double yAtImpact = y0;
  double vAtImpact = v0;
  double tImpact = 0;
  double v_s = 0;
  double y_s = 0;

  int iter = 0;

  while (1) {

    p->atualizarEstado(t);

    if (p->yi > maxY) {
      maxY = p->yi;
      tMaxY = p->tempo;
    }

    if (abs(p->yi) < abs(yAtImpact)) {
      yAtImpact = p->yi;
      vAtImpact = p->vi;
      tImpact = p->tempo;
    }

    if (p->tempo - t_s < 0.00001) {
      v_s = p->vi;
      y_s = p->yi;
    }

    if ((p->yi < 0) && (p->tempo >= t_s)) {
      break;
    }
    iter++;
    if (iter > nIter) {
      break;
    }

  }

  cout << "Solução para o valor de t_s dado: (v = " << v_s << ", y = " << y_s << ")\n";
  cout << "3a) Altura máxima: " << maxY << "\n";
  cout << "3b) Tempo na altura máxima: " << tMaxY << "\n";
  cout << "3c) Tempo até o impacto: " << tImpact << "\n";
  cout << "3d) Velocidade no momento do impacto: " << vAtImpact << "\n";

}

int main() {

  double v0, y0, k, m;
  int nIter;
  double t;
  double t_s;

  cout << "Digite o valor de v0: ";
  cin >> v0;
  cout << "Digite o valor de y0: ";
  cin >> y0;
  cout << "Digite o valor de k: ";
  cin >> k;
  cout << "Digite o valor de m: ";
  cin >> m;
  cout << "Digite o número máximo de iterações: ";
  cin >> nIter;
  cout << "Digite o valor de t em cada iteração: ";
  cin >> t;
  cout << "Digite o valor t_s do tempo para o qual você quer a solução (esse valor deve ser múltiplo de t): ";
  cin >> t_s;
  cout << "\n";

  RK3(v0,y0,k,m,nIter,t,t_s);

}