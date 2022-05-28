from SALib.sample import saltelli
from SALib.analyze import sobol
import numpy as np
import random,math

def Model(x1,x2,x3):
    return x1+x2+2*x3#+5*random.random()

def Evaluate(param_values):
    Y = []
    for params in param_values:
        x1,x2,x3 = params
        res = Model(x1,x2,x3)                
        Y.append(res)
    return np.array(Y)
    
# Define the model inputs
problem = {
    'num_vars': 3,
    'names': ['x1', 'x2', 'x3'],
    'bounds': [[-1, 1],
               [-1, 1],
               [-1, 1]]
}

# Generate samples
param_values = saltelli.sample(problem, 1000)

# Run model (example)
Y = Evaluate(param_values)

# Perform analysis
Si = sobol.analyze(problem, Y, print_to_console=False)

# Print the first-order sensitivity indices
print("__________________")
print(Si['S1'])

#[0.32874603 0.33437377 0.33501784]
#[0.49654772 0.49935905 0.        ]
#[0.16355185 0.16824364 0.66641135]
#[0.08345167 0.08736053 0.34520158]

#  [0.32874603 0.33437377 0.33501784]
#  [0.49654772 0.49935905 0.        ]
# [0.16337219 0.66797468 0.16838126]
# [0.29795194 0.29583904 0.3045322 ]
# [0.05396651 0.09625796 0.15481404]


