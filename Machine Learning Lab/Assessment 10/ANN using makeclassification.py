# -*- coding: utf-8 -*-
"""
Created on Fri Apr  1 12:33:44 2022

@author: Prakhar Jadaun
"""



#%%
#Input datasets
import numpy as np 
from sklearn.datasets import make_classification
import random
classes = 3
#X, t = make_classification(100, 3, n_classes = classes, random_state= 40)
X, t = make_classification(5, 5, n_classes = classes, random_state= 40, n_informative = 2, n_clusters_per_class = 1)


#%%

print(X)

#%%

print(t)
print(t.shape)

#%%
t = np.reshape(t,(5,1))
print(t)
print(t.shape)

#%%

epoch =0
lr = 0.9

#%%

inputLayerNeurons = 5
hiddenLayerNeurons = 5
outputLayerNeurons = 1

#%%


hidden_weights = []
for i in range(1,inputLayerNeurons+1):
	hidden_weights_ind = []
	for j in range(inputLayerNeurons+1,inputLayerNeurons+hiddenLayerNeurons+1):
		hidden_weights_ind.append(float(random.random()))
	hidden_weights.append(hidden_weights_ind)
    
output_weights = []
for i in range(inputLayerNeurons+1,inputLayerNeurons+hiddenLayerNeurons+1):
	output_weights_ind = []
	for j in range(inputLayerNeurons+hiddenLayerNeurons+1,inputLayerNeurons+hiddenLayerNeurons+outputLayerNeurons+1):
		output_weights_ind.append(float(random.random()))
	output_weights.append(output_weights_ind)


hidden_bias = []
output_bias = []
for i in range(inputLayerNeurons+1,inputLayerNeurons+hiddenLayerNeurons+outputLayerNeurons+1):
	if i > inputLayerNeurons+hiddenLayerNeurons:
		output_bias.append(float(random.random()))
	else:
		hidden_bias.append(float(random.random()))


#%%

hidden_weights = np.asarray(hidden_weights)
hidden_bias = np.asarray([hidden_bias])
output_weights = np.asarray(output_weights)
output_bias = np.asarray([output_bias])

print("Initial hidden weights: ",end='')
print(*hidden_weights)
print("Initial hidden biases: ",end='')
print(*hidden_bias)
print("Initial output weights: ",end='')
print(*output_weights)
print("Initial output biases: ",end='')
print(*output_bias)

#%%

predicted_output = [0]*5
predicted_output = np.reshape(predicted_output, (5,1))
print(predicted_output)

#%%


import numpy as np 

def abs(x):
	return x if x>0 else -x

def sigmoid (x):
    return 1/(1 + np.exp(-x))
def sigmoid_derivative(x):
    return x * (1 - x)

def checkError(predicted_output,t):
	expected_output = t
	for i,j in  zip(expected_output , predicted_output):
		if abs(i[0]-j[0]) > 0.8:
			return True
	return False

#%%


while checkError(predicted_output,t):
	epoch += 1
	#Forward Propagation
	hidden_layer_activation = np.dot(X,hidden_weights)
	hidden_layer_activation += hidden_bias
	hidden_layer_output = np.argmax(hidden_layer_activation)

	output_layer_activation = np.dot(hidden_layer_output,output_weights)
	output_layer_activation += output_bias
	predicted_output = np.argmax(output_layer_activation)
    #predicted_output = sigmoid(output_layer_activation)

	#Backpropagation
	error = t - predicted_output
	d_predicted_output = error * sigmoid_derivative(predicted_output)
    
	error_hidden_layer = d_predicted_output.dot(output_weights.T)
	d_hidden_layer = error_hidden_layer * sigmoid_derivative(hidden_layer_output)

	#Updating Weights and Biases
	output_weights += hidden_layer_output.T.dot(d_predicted_output) * lr
	output_bias += np.sum(d_predicted_output,axis=0,keepdims=True) * lr
	hidden_weights += X.T.dot(d_hidden_layer) * lr
	hidden_bias += np.sum(d_hidden_layer,axis=0,keepdims=True) * lr

#%%

print("Final hidden weights: ",end='')
print(*hidden_weights)
print("Final hidden bias: ",end='')
print(*hidden_bias)
print("Final output weights: ",end='')
print(*output_weights)
print("Final output bias: ",end='')
print(*output_bias)

print("\nOutput from neural network: ",end='')
print(*predicted_output)
print("\nNo of epochs")
print(epoch)
