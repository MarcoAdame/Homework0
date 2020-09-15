# -*- coding: utf-8 -*-
#!/usr/bin/env python
__author__ = "Marco-Federico Adame-Oropeza"
__copyright__ = "Copyright 2020 Master Project"
__credits__ = ["Andres Mendez-Vazquez"]
__license__ = "GPL"
__version__ = "1.0.0"
__maintainer__ = "Marco-Federico Adame-Oropeza"
__email__ = "marco.adame@cinvestav.mx"
__status__ = "Development"

import numpy as np 
from numpy.ctypeslib import ndpointer 
import ctypes
from ctypes import c_int 
import pathlib
from random import randrange

if __name__ == "__main__":

    tlabel = 1

    if tlabel == 1:
        # Load the shared library into c types.
        libname = pathlib.Path().absolute() / "libc_reader.so"
        c_lib = ctypes.CDLL(libname)

        # Define return void pointer
        c_lib.c_reader.restype = ctypes.c_int

        # Define arguments
        singlepp = ndpointer(dtype = np.int32, ndim = 1, flags = 'C')
        c_lib.c_reader.argtypes = [singlepp, ctypes.c_int]

        # Define the m parameter for the array len 
        m = ctypes.c_int(12) 
        # Define random list 
     
        lista= [randrange(0,100) for _ in range(m.value)]
        # 
        x =np.asarray(lista,  dtype='int32') 
        print(x)      
        x1=c_lib.c_reader(x,m)
        print(x1)
    elif tlabel == 2:
      print("No message")