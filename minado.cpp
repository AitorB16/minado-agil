//minado.cpp by AitorB16
#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include "md5.h"
 
using std::cout; using std::endl;
 
int main(int argc, char *argv[])
{
    std::string hash;
    std::string grupo;
    std::string ceros="";
    std::string copia;
    std::string f_output = "minado.txt";
    char bloque_print[9];
    int num_ceros= atoi(argv[2]);
    unsigned int bloque = 0x00000000;

    //crear string con la extension de 0s a minar
    for(int i=0; i<num_ceros; i++){
        ceros+="0";
    }
    
    //comprobar si hay nombre de minero(s) para asignarle(s) el bloque
    if(argc < 4){
        grupo="";
    }else{
        grupo=" ";
        grupo+=argv[3];
    }

    //lectura completa del fichero input a string
    std::ifstream t(argv[1]);
    std::string str((std::istreambuf_iterator<char>(t)),
                 std::istreambuf_iterator<char>());
    
    //guardar una copia para el minado
    copia = str;
   
    //minar el bloque mientras los 0s del comienzo del hash md5 sean menos que num_ceros
    do{
        //resetear la string
        str = copia;
        //pasar el el bloque a formato hexa en string, con 8 ceros.
        sprintf(bloque_print,"%08x",bloque);
        //hacer append al ficher con bloque y nombre del grupo
        str+= bloque_print+grupo;
        //calcular hash
        hash = md5(str);
        //usar otro bloque para la proxima
        bloque++;
    }while((ceros.compare(hash.substr(0,num_ceros)) !=0) && bloque != 0); //si encuentra el bloque o hace overflow sale del bucle
    
    if(bloque !=0){
        std::ofstream out(f_output);
        out << str;

        cout << "Bloque encontrado: "<< hash << endl;

        out.close();
    }else{
        cout << "No se ha encontrado ningun bloque" << endl;
    }

    return 0;
}
