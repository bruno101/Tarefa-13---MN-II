#include <iostream>
#include "PVI.h"
using namespace std;

void RK3(double v0, double y0, double k, double m, int nIter, double t) {

  PVI *p = new PVI(v0, y0, k, m);

  double maxY = y0;
  double tMaxY = 0;
  double yAtImpact = y0;
  double vAtImpact = v0;
  double tImpact = 0;

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

    if (p->yi < 0) {
      break;
    }
    iter++;
    if (iter > nIter) {
      break;
    }

  }

  cout << "a) Altura máxima: " << maxY << "\n";
  cout << "b) Tempo na altura máxima: " << tMaxY << "\n";
  cout << "c) Tempo até o impacto: " << tImpact << "\n";
  cout << "d) Velocidade no momento do impacto: " << vAtImpact << "\n";

}

int main() {

  double v0, y0, k, m;
  int nIter;
  double t;

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
  cout << "\n";

  RK3(v0,y0,k,m,nIter,t);

}