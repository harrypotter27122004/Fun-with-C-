#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdint.h>
int64_t A[100], B[100], C[100], e, f, h, p, q;
int i,j,k;
int main()
{
    e=0; f=0; h=0, p=0; q=0;
    int s=0;
    std::ifstream input("Sub3Seq.inp");
    std::ofstream output("Sub3Seq.out");
    std::string line;
    std::getline(input, line);
    std::istringstream is(line);
    while (is >> A[e]) e++;

    std::getline(input, line);
    is.str(line); is.clear();
    while (is >> B[f]) f++;

    std::getline(input, line);
    is.str(line); is.clear();
    while (is >> C[h]) h++;

    for (i=0; i<e; i++)
        for (j=p; j<f; j++)
            for (k=q; k<h; k++)
            if ((A[i]==B[j]) && (B[j]==C[k])) 
            {
                s++;
                p=j;
                q=k++;
                break;
            };
    output << s;
    return 0;    
}