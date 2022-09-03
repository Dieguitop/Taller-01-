#include "Utils.h"
#include "Monomio.h"
#include "Raiz.h"
#include <cstdlib>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  int exitCode;

  /// Si no hay argumentos suficientes mostramos un texto por defecto.
  if (argc != 2) {
    std::cout
        << "Argumentos inválidos, ejecute el programa de la siguiente forma:"
        << std::endl;
    std::cout << argv[0] << " \"[integral polinomica]\""<< std::endl;
    exitCode = EXIT_FAILURE;
  } 


  else 
  {
    /// Procesamos
    const std::string polinomio(argv[1]);
    std::cout << std::endl << "polinomio (cmd): " << polinomio << std::endl;

    std::cout << "polinomio (convertido): ";
    std::vector<Monomio> monomios = Utils::convertir(polinomio);
    std::vector<Monomio>::size_type i = 0;
    for (i = 0; i < monomios.size(); i++) {
      Monomio monomio = monomios[i];
      std::cout << monomio.GetCoeficiente() << "x^" << monomio.GetGrado()
                << " ";
    }
    std::cout << std::endl;
    // Hasta aqui es plantilla

    //Aqui comienza el proceso de calculo de raiz
    double resultado = Raiz::calcular_raiz(monomios);
    std::cout << "La solucion esta alrededor de: " << resultado << std::endl;

    std::cout << std::endl << "Vicente Gallegos" << std::endl << "Diego Pizarro" << std::endl;

    exitCode = EXIT_SUCCESS;
  }
  return exitCode;

}
