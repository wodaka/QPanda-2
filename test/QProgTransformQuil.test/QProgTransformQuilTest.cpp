#include <iostream>
#include "QPanda.h"
#include <iostream>
#include "gtest/gtest.h"
#include "QPanda.h"
#include <map>
#include <cstdlib>
#include <sstream>
#include <string>
#include <algorithm>  

USING_QPANDA

TEST(QProgTransformQuil, QUIL)
{
    init();
    auto qubits = qAllocMany(4);
    auto cbits = cAllocMany(4);
    QProg prog;
    QCircuit circuit;

    circuit << RX(qubits[0], PI / 6) << H(qubits[1]) << Y(qubits[2])
        << iSWAP(qubits[2], qubits[3]);
    prog << circuit << MeasureAll(qubits, cbits);
    auto quil = qProgToQuil(prog);
    std::cout << quil << std::endl;

    finalize();
    system("pause");
    return;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}