class PVI {

  public:
    double v0, y0, k, m; 
    double vi, yi, tempo;

    PVI (double v0, double y0, double k, double m);
    void atualizarEstado(double t);

};