
#ifndef RAIZ_H
#define RAIZ_H

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

#include "Utils.h"
#include "Monomio.h"

namespace Raiz
{
    // @param Vector monomio
    // @return double con la solucion
    double calcular_raiz(std::vector<Monomio> monomios);

}

#endif