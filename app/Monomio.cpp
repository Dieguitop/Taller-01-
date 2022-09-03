#include "Monomio.h"

Monomio::Monomio() {
    this->coeficiente = (double) 0;
    this->grado = 0;
}

Monomio::Monomio(const Monomio& orig) {
    this->coeficiente = orig.GetCoeficiente();
    this->grado = orig.GetGrado();
}

Monomio::~Monomio() {
}

double Monomio::GetCoeficiente() const {
    return coeficiente;
}

void Monomio::SetCoeficiente(double coeficiente) {
    this->coeficiente = coeficiente;
}

int Monomio::GetGrado() const {
    return grado;
}

void Monomio::SetGrado(int grado) {
    this->grado = grado;
}


//Se deriva un monomio
Monomio Monomio::derivar()
{

    Monomio new_monomio;
    new_monomio.SetGrado(grado - 1);
    if(grado == 0 && coeficiente == 0) new_monomio.SetCoeficiente(0);
    else new_monomio.SetCoeficiente(coeficiente * grado);
    return new_monomio;

}