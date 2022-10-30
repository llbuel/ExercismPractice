#include "anagram.h"

namespace anagram {

templateClass::templateClass(int priv, int pub) : m_priv_variable(priv), m_pub_variable(pub) {}

int templateClass::classFcn() {
    int var1 = localFcn(m_priv_variable);
    int var2 = m_priv_variable + m_pub_variable;

    return classFcn2(var1, var2);
}

int templateClass::classFcn2(int input1, int input2) {
    return input1 - input2;
}

int localFcn(int input) {
    return input * input;
}

}