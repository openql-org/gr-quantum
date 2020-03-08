from __future__ import division
from __future__ import unicode_literals

from gnuradio import gr
from gnuradio import blocks
import pmt

import matplotlib.pyplot as plt
import numpy as np
from qutip import *
import numpy as np
import scipy.sparse as sp
import scipy.linalg as la
import qutip.settings as settings
import sys, math
import threading


class quantum_measurements_QuTiP_Wave2Qob(gr.basic_block):


    def __init__(self, qubit_num):
        gr.basic_block.__init__(self,
            "quantum_measurements_QuTiP_Wave2Qob",
            gr.py_io_signature(0, 0, np.array([np.float64])),
            gr.py_io_signature(0, 0, np.array([np.float64])))
        pass

