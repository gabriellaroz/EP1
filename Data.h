#ifndef DATA_H
#define DATA_H

class Data {
public:
    Data(int mes, int ano);
    virtual ~Data();

    int getMes();
    int getAno();

private: 

 int mes = 0;
 int ano = 0;
    
}
#endif