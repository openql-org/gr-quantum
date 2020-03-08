from enum import IntEnum

class quantum_gate_type(IntEnum):
    NONE = 0
    INIT = 1
    X = 2
    Y = 3
    Z = 4
    H = 5
    S = 6
    T = 7
    CNOT = 8
    RO = 9
    WAIT = 10
    JUNC = 11
    JUNC_LIST = 12
    SIM_DATA = 13
