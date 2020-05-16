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

}