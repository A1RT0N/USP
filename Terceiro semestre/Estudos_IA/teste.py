import numpy as np
import sklearn # ml

# a = np.random.randn(3,3)
# b = np.random.rand(3,1)

# c = a*b

# print(a)
# print("\n")
# print(b)
# print("\n")


# print(c)

x = np.random.rand(3, 2)

y = np.sum(x, axis=0, keepdims=True)

print(np.shape(y))

logprobs = np.sum(np.multiply(np.log(A2),Y),np.multiply(1-Y,np.log(1-A2))
cost = log.probs/m
