#include <iostream>
#include <iterator>
#include <regex>
#include <string>
#include <vector>
#include <map>

/*
    Qué hay que hacer
  Tenemos que corregir el codigo para que  que la CURP que no es valida indique
porque no es valida, en cada uno de sus posiciones:

Posición Normas generales para la construcción de la clave
Posición 1-4 La letra inicial y la primera vocal interna del primer apellido, la
letra inicial del segundo apellido y la primera letra del nombre. En el caso de
las mujeres casadas, se deberán usar los apellidos de soltera (alfabetica)
Posición 5-10
La fecha de nacimiento en el orden de año, mes y dia. Para el año se tomarán los
dos últimos digitos, cuando el mes o el dia sea menor a diez, se antepondrà un
cero. 1 de diciembre de 1995, Quedaria: 951201 (numèrica) Posición 11 Sexo M
para mujer y H para hombre (alfabetica) Posición 12-13 La letra inicial y última
consonante, nacimiento conforme al Catálogo (SEGOB) de Entidades Federativas
(alfabética) Ver el script Posición 14-16 Integradas por las primeras
consonantes internas del primer apellido, segundo apellido y nombre
(alfabética). Posición 17 Diferenciador de homonimia y siglo, caracter
progresivo asignado por la Secretaria de Gobernación que se emplea para
diferenciar registros homónimos, 1-9 para fechas de nacimiento hasta el año 1999
y A-Z para fechas de nacimiento a partir de 2000 (alfanumérica). Posición 18
Digito verificador, caracter asignado por la Secretaria de Gobernación a través
de la aplicación de un algoritmo que permite calcular y verificar la correcta
conformación y transcripción de la clave

*/

/*
CAPM000719HDFMDNA2
^(
([A-Z]{1}          -> C
[AEIOU]{1}         -> A
[A-Z]{2}           -> PM
[0-9]{2}           -> 00
(0[1-9]|1[0-2]){2}    -> 07
(0[1-9]|1[0-9]|2[0-9]|3[0-1]){2}  -> 19
[HM]{1}                          -> H

(AS|BC|BS|CC|CS|CH|CL|CM|DF|DG|GT|GR|HG|JC|MC|MN|MS|NT|NL|OC|PL|QT|QR|SP|SL|SR|TC|TS|TL|VZ|YN|ZS|NE){2}                    -> DF
[B-DF-HJ-NP-TV-Z]{3}     -> MDN
[0-9|A-Z]{1}    -> A
[0-9]{1}))$     -> 2
*/

void validateCURP(std::string curp, std::vector<std::string> regexConditions);
void whyNot(std::string curp, std::vector<std::string> regexConditions);
std::string getDescription(int i);

int main()
{
    // O  E  VR  67 01  03  19  H  DF  FJLL  0  8
    // OEVR670103HDFJLL08

    std::string curp = "123456789012345678";

    std::vector<std::string> regexConditions = {"[A-Z]{1}", "[AEIOU]{1}", "[A-Z]{2}", "[0-9]{2}", "(0[1-9]|1[0-2]){1}", "(0[1-9]|1[0-9]|2[0-9]|3[0-1]){1}", "[HM]{1}", "(AS|BC|BS|CC|CS|CH|CL|CM|DF|DG|GT|GR|HG|JC|MC|MN|MS|NT|NL|OC|PL|QT|QR|SP|SL|SR|TC|TS|TL|VZ|YN|ZS|NE){1}", "[B-DF-HJ-NP-TV-Z]{3}", "[0-9|A-Z]{1}", "[0-9]{1}"};

    validateCURP(curp, regexConditions);
    return 0;
}

void validateCURP(std::string curp, std::vector<std::string> regexConditions)
{
    /*
      - Tiempo: O(n)
      - Memoria: O(n)
    */

    // Creamos un string desde un vector, que será nuestro patron para validar en regex_match
    std::string regex = "^(";
    for (auto i : regexConditions)
        regex += i;
    regex += ")$";

    std::regex pattern(regex); // Creamos patrón

    std::cout << "\nTu CURP ingresada: " << curp << std::endl
              << std::endl;

    if (std::regex_match(curp, pattern))
        std::cout << "[VALIDO]: Tu CURP cumple con las expresiones regulares" << std::endl;
    else
        whyNot(curp, regexConditions);
}

void whyNot(std::string curp, std::vector<std::string> regexConditions)
{
    /*
      Complejidad:
      - Tiempo: O(n)
      - Memoria: O(n)
    */
    if (!(curp.length() == 18))
    {
        std::cout << "[INVALIDO]: Tu CURP no tiene 18 caracteres" << std::endl;
        return;
    }

    std::vector<std::string> curpPartitions;
    curpPartitions.push_back(curp.substr(0, 1));  // C
    curpPartitions.push_back(curp.substr(1, 1));  // A
    curpPartitions.push_back(curp.substr(2, 2));  // PM
    curpPartitions.push_back(curp.substr(4, 2));  // 00
    curpPartitions.push_back(curp.substr(6, 2));  // 07
    curpPartitions.push_back(curp.substr(8, 2));  // 19
    curpPartitions.push_back(curp.substr(10, 1)); // H
    curpPartitions.push_back(curp.substr(11, 2)); // DF
    curpPartitions.push_back(curp.substr(13, 3)); // MDN
    curpPartitions.push_back(curp.substr(16, 1)); // A
    curpPartitions.push_back(curp.substr(17, 1)); // 2

    std::string regexStep;
    for (int i = 0; i < curpPartitions.size(); i++)
    {

        regexStep = "^" + regexConditions[i] + "$";
        std::regex pattern(regexStep);

        if (!(std::regex_match(curpPartitions[i], pattern)))
            std::cout << "La parte \"" << curpPartitions[i] << "\" de la curp ingresada en la posicion " << i + 1 << " no es correcta porque: -> " << getDescription(i + 1) << std::endl
                      << std::endl;
    }
}

std::string getDescription(int i)
{
    /*
      Complejidad:
      - Tiempo: O(n)
      - Memoria: O(n)
    */

    std::map<int, std::string> descriptions{
        {1, "La letra inicial del apellido paterno no es valida"},
        {2, "La primera vocal del apellido paterno no es valida"},
        {3, "La primera letra del apellido materno y el nombre no son validas"},
        {4, "El anio de nacimiento no es el correcto (ultimos dos digitos)"},
        {5, "El mes de nacimiento no es el correcto"},
        {6, "El día de nacimiento no es el correcto"},
        {7, "El sexo es incorrecto"},
        {8, "La letra inicial y ultima consonante, nacimiento conforme al Catálogo (SEGOB) de Entidades Federativas (alfabetica) es incorrecta"},
        {9, "Las primeras consonantes internas del primer apellido, segundo apellido y nombre es incorrecta"},
        {10, "El diferenciador deregistros homónimos, 1-9 para fechas de nacimiento hasta el año 1999 y A-Z para fechas de nacimiento a partirde 2000 es incorrecto"},
        {11, "Digito verificador, caracter asignado por la Secretaria de Gobernación es incorrecto"},
    };

    const auto iter = descriptions.find(i);

    if (iter != descriptions.cend())
        return iter->second;
    return "";
}
