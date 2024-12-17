// BruteForceKolmogorov.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <initializer_list>

template<typename ZZ>
class Term
{

};

template<typename ZZ>
class Var
{
public:
    Var(const std::string& name)
    {
        this->name = name;
    }

protected:
    std::string name;
};

template<typename ZZ>
class BinaryOp : public Term
{
public:
    BinaryOp(const Term& a, const Term& b)
    {
        lhs = a;
        rhs = b;
    }

protected:
    Term& lhs;
    Term& rhs;
};

template<typename ZZ>
class Add : public BinaryOp
{
public:
    Add(const Term& a, const Term& b) : BinaryOp(a,b)
    {}
};

template<typename ZZ>
void bruteForceKolmogorov(const std::vector <std::pair<std::pair<ZZ, ZZ>, ZZ>>& examples)
// For discovering the binary integer functions
{
    std::vector<std::set<Term<ZZ>*>> X(examples.length());
    int varCount = 0;

    for (size_t i = 0; i < examples.size(); i++)
    {
        std::pair<std::pair<ZZ, ZZ>, ZZ>& example = examples[i];
        auto a = new Var("a" + std::string(varCount));
        auto b = new Var("b" + std::string(varCount));  

        X[i].insert(a);
        X[i].insert(b);
        varCount++;
    }

    while (1) {
        for (size_t i = 0; i < X.size(); i++) {
            std::vector<Term<ZZ>*> X1;

            for (auto x = X[i].begin(); x != X[i].end(); x++)
            {
                for (auto y = X[i].begin(); y != X[i].end(); y++)
                {
                    Term* z = x + y;
                    auto zEval = z.eval();
                    if (zEval == examples[i].second)
                        
                    X1.push_back(z);
                    z = x - y;
                    X1.push_back(z);
                    z = x * y;
                    X1.push_back(z);
                    if (y != 0)
                    {
                        z = x / y;
                        X1.push_back(z);
                        z = x % y;
                        X1.push_back(z);
                    }                                            
                }
            }

            if 
        }
    }
}

int main()
{
    std::cout << "Hello World!\n";
}
