from enum import IntEnum

class quantum_gate_param_type(IntEnum):
    GATE_TYPE = 1
    FREQ = 2
    I_AMP = 3
    Q_AMP = 4
    I_BW = 5
    Q_BW = 6
    PROC_TIME = 7
    CTRL_DC_MODE = 8
    QUBIT_ID = 9
    WAIT_TIME = 10
