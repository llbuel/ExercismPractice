#ifndef HEADER_H
#define HEADER_H

namespace test {

class templateClass{
private:
    int m_priv_variable;

public:
    int m_pub_variable;

    templateClass(int priv, int pub);

    int classFcn();
    int classFcn2(int input1, int input2);
};

int localFcn(int input);

}

#endif