#include "PVI.h"

PVI::PVI (double v0, double y0, double k, double m) {
  this->v0 = v0;
  this->y0 = y0;
  this->k = k;
  this->m = m;

  this->vi = v0;
  this->yi = y0;
  this->tempo = 0;
}

void PVI::atualizarEstado(double t) {

  double v_int, v_n, y_int, y_n;

  v_int = vi + (t/2.0)*(-10.0-(k/m)*vi);
  y_int = yi + (t/2.0)*vi;

  v_n = vi + t*( -(-10.0-(k/m)*vi) + 2.0*(-10.0-(k/m)*v_int) );
  y_n = yi + t*( -(vi) + 2.0*(v_int) );

  this->vi = vi + t*( (1.0/6.0)*(-10.0-(k/m)*vi) + (4.0/6.0)*(-10.0-(k/m)*v_int) + (1.0/6.0)*(-10.0-(k/m)*v_n)  );
  this->yi = yi + t*( (1.0/6.0)*(vi) + (4.0/6.0)*(v_int) + (1.0/6.0)*(v_n) );
  this->tempo = tempo+t;

}