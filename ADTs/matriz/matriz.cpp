#include "matriz.hpp"
#include <QDebug>


Matriz::Matriz(int x,  int y){
    this-> x = x;
    this-> y = y;
    this->varx = 0;
    this->vary = 0;
    matriz = new double*[x];
    for (int countx = 0; countx < x; countx++){
        matriz[countx] = new double[y];
        for(int county = 0; county < y; county++){
                matriz[countx][county] = 0;
        }
    }
}

bool Matriz::isEmpty(){
        for(int countx = 0; countx< this->x; countx++){
            for(int county = 0; county < this->y; county++){
                    if(this->matriz[countx][county] != 0){
                        return false;
                    }
            }
        }
        return true;
}
QString Matriz::toString() const{

    QString fullprint = "\n";

    for (int countx = 0; countx < x; countx++){
                for(int county = 0; county < y; county++){
                    fullprint += QString::number(matriz[countx][county]);
                    fullprint += " ";
                }
              fullprint += "\n";
        }

     return fullprint;
}

bool  Matriz::isDivisible(){
        return false;
}

double* Matriz::getRow(const int y){
    double * rowprint = new double[x];
    for (int countx = 0; countx < x; countx++){
            rowprint[countx] = matriz[y][countx];
    }
    return rowprint;

}

double* Matriz::getColumn(const int x){
        double * colprint = new double[y];
        for (int county = 0; county < y; county++){
                colprint[county] = matriz[county][x];
        }
        return colprint;
}

void  Matriz::insert(int x,int y, double value){
        if(x < this-> x && y< this ->y){
             matriz[y][x] = value;
        }
}
void Matriz::addRow(double *array){
        if(sizeof(array) == sizeof(matriz[varx])){
            for (int count = 0; count < x; count++){
                matriz[varx][count] = array[count];
            }
            varx++;
        }
        else{
            qDebug() << "invalido";
        }
}
void Matriz::addColumn(double *array){
        for(int count = 0; count <y; count++){
            matriz[count][vary] = array[count];
        }
}
double Matriz::determinant() const{
        if(x==2 && y==2){
             return matriz[0][0]*matriz[1][1] - matriz[0][1]*matriz[1][0];
        }
        if(x==3 && y==3){
            return (matriz[0][0]*matriz[1][1]*matriz[2][2] + matriz[0][1]*matriz[1][2]*matriz[2][0] + matriz[0][2]*matriz[1][0]*matriz[2][1]) -
                       (matriz[2][0]*matriz[1][1]*matriz[0][2] + matriz[2][1]*matriz[1][2]*matriz[0][0] + matriz[2][2]*matriz[1][0]*matriz[0][1]);
        }
        else qDebug() << "invalido";
}

MatrizADT* Matriz::transposed(){
        MatrizADT *aux = new Matriz(x,y);
        for (int countx = 0; countx < x; countx++){
            for(int county = 0; county < y; county++){
                aux->insert(county, countx, matriz[county][countx]);
            }
        }
        return aux;
}
MatrizADT* Matriz::multiply(double z){
        MatrizADT *aux = new Matriz(x,y);
        for(int countx = 0; countx < x; countx++){
            for (int county = 0; county< y; county++){
                aux->insert(countx, county, this->matriz[countx][county] * z);
            }
        }
        return aux;
}

Matriz::~Matriz(){

}


