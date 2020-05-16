#include "Eigen/Dense"
#include "values.hpp"
#include <iostream>
#include <fstream>

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
    
    varianceX=varianceX/(january.size()-1);
    m(0,0)=varianceX;
    
    varianceY=varianceY/(june.size()-1);
    m(1,1)=varianceY;
    varianceXY=varianceXY/(january.size()-1);
    m(0,1)=varianceXY;
    m(1,0)=varianceXY;
        double totalVariance=varianceX+varianceY;

    EigenSolver<MatrixXd> es(m);
    ofstream myfile;
    myfile.open ("Answers.txt");
    myfile << "The eigenvalues of A are:" << endl << es.eigenvalues().real() << endl<<endl;;
    myfile << "The matrix of eigenvectors, V, is:" << endl << es.eigenvectors().real() << endl << endl;
    myfile<<"Co Variance Matrix is:"<<endl;
    myfile<<m<<endl<<endl;
    myfile<< "The total variance is: "<<endl<<totalVariance<<endl;
    myfile<<"The total % Variance for principle component 1 is: "<<((es.eigenvalues()[0]/totalVariance).real())*100<<"%"<<endl;
    myfile<<"The total % Variance for principle component 2 is: "<<((es.eigenvalues()[1]/totalVariance).real())*100<<"%"<<endl;
    myfile.close();
    cout<<"Answers have been written to a text file called Answers.txt"<<endl;
    return 0;

}