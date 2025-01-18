# ifndef COMPLEXO_H
    # define COMPLEXO_H
    typedef struct complexo Complexo ;
    
    Complexo * criar (double real, double imag);
    void liberar ( Complexo *c);
    void copiar ( Complexo *source, Complexo *target);
    Complexo *adicao ( Complexo *a, Complexo *b);
    Complexo *subtracao ( Complexo *a, Complexo *b);
    int e_real ( Complexo *c);
    double real ( Complexo *c);
    double imag ( Complexo *c);
    void atribuir ( Complexo *c, double real, double imag);
    void atribuir_real ( Complexo *c, double real);
    void atribuir_imag ( Complexo *c, double imag);
# endif 