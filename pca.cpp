#include "Eigen/Dense"
#include "values.hpp"
#include <iostream>
using namespace Eigen;
using namespace std;
int main(int argc,char* argv[]){
    double janMean;
    double juneMean;

    for (int i = 0; i < january.size(); i++)
    {
        janMean+=january[i];
        juneMean+=june[i];

    }
    janMean=janMean/(january.size());
    juneMean=juneMean/(june.size());

    for (int i = 0; i < january.size(); i++)
    {
        january[i]=january[i]-janMean;
        june[i]=june[i]-juneMean;
    }
    
    
    cout<<janMean<<"  "<<january[0]<<"  "<<juneMean<<endl;
    
    MatrixXd m(2,2);     
    double varianceX=0;
    double varianceY=0;
    double varianceXY=0;
    for (int i = 0; i < january.size(); i++)
    {
        varianceX+=(january[i]*january[i]);
        varianceY+=(june[i]*june[i]);
        varianceXY+=(january[i]*june[i]);
    }
    m(0,0)=varianceX/(january.size()-1);
    
    m(1,1)=varianceY/(june.size()-1);
    
    varianceXY=varianceXY/(january.size()-1);
    m(0,1)=varianceXY;
    m(1,0)=varianceXY;
cout<<m<<endl;

}