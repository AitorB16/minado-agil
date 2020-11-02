//minado_par.cpp by AitorB16
#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <omp.h>
#include "md5.h"
 
using std::cout; using std::endl;


#define bloque 0x00000000
#define bloque_max 0xffffffff

 
int main(int argc, char *argv[])
{
    std::string hash;
    std::string grupo;
    std::string ceros="";
    std::string f_output = "minado.txt";
    int num_ceros= atoi(argv[2]);
    std::string copia;
    char bloque_print[9];
    unsigned int i;

    omp_set_num_threads(16); //NUMERO DE CORES

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

     //copia del fichero;
     copia = str;
     
     //Paralelizar for
     #pragma omp parallel for private(i, str, hash, bloque_print) shared(copia, grupo, ceros, num_ceros)
     for(i=bloque; i<bloque_max; i++){
        str = copia;
        //pasar el el bloque a formato hexa en string, con 8 ceros.
        sprintf(bloque_print,"%08x",i);
        //hacer append al ficher con bloque y nombre del grupo
        str+= bloque_print+grupo;
        //calcular hash
        hash = md5(str);
        //int pid = omp_get_thread_num();
        if(ceros.compare(hash.substr(0,num_ceros)) == 0){
            std::ofstream out("minado_par.txt");
            out << str;
            cout << "Bloque encontrado: "<< hash << endl;
            out.close();
            exit(0);
        }
    }
    return 0;
}
