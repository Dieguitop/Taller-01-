#include "Raiz.h"

//Aqui se realiza el calculo de raices
double Raiz::calcular_raiz(std::vector<Monomio> monomios)
{

    //el while termina cuando se encuentra el primer valor >0
    bool found_positive = false;

    //limites inferior y superior para saber entre que numeros esta la solucion
    double lim_superior;
    double lim_inferior;
    for(int i = 0; found_positive == false; i++)
    {

      double calculo = Utils::evaluar(monomios, i);

      double calculo_anterior;
        
      if(calculo > 0)
      {

        found_positive = true;
          

        lim_superior = i;
        lim_inferior = calculo_anterior;

      }
      else
      {
          
        calculo_anterior = i;

      }
        

    }

    //Proceso de derivar la funcion
    std::vector<Monomio> monomios_derivados;
    for (int i = 0; i < monomios.size(); i++)
    {

      Monomio monomio = monomios[i];

      monomios_derivados.push_back(monomio.derivar());

    }

    double xn, xn1;

    //Reemplazar en la formula de Newton-Raphson
    if(lim_inferior == 0) xn = lim_superior;
    else if(lim_superior == 0) xn = lim_inferior;
    else
    {

      if(abs(lim_inferior) > abs(lim_superior))
      {xn = lim_superior;}
      else 
      {xn = lim_inferior;}

    }

    
    //Se realizan 10 iteraciones
    for(int i = 0; i < 10; i++)
    {
      
      xn1 = xn - (Utils::evaluar(monomios, xn) / Utils::evaluar(monomios_derivados,xn));
      //std::cout << xn1 << std::endl;
      xn = xn1;
      
    }

    return xn1;
}