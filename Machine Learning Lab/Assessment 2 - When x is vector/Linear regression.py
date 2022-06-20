# -*- coding: utf-8 -*-
"""
Created on Fri Jan 28 11:20:11 2022

@author: Prakhar Jadaun
SAP - 500083429
"""

#%%

#importing the required libraries 
from sklearn.datasets import make_regression
from sklearn.linear_model import LinearRegression
import numpy as np 

x,t = make_regression(100,5,shuffle=True,bias=0,noise=0,random_state=2)
#generating data set values using make_regression() func. 
'''
Generate a random regression problem.
Parameters
1. n_samplesint default=100
The number of samples.

2. n_featuresint, default=100
The number of features.

3. shufflebool, default=True
Shuffle the samples and the features.

4. biasfloat, default=0.0
The bias term in the underlying linear model.

5. noisefloat, default=0.0
The standard deviation of the gaussian noise applied to the output.

6. random_stateint, RandomState instance or None, default=None
Determines random number generation for dataset creation. Pass an int for reproducible output across multiple function calls.
'''

#%%
#printing the shape of the x and t
print(x.shape)
print(t.shape)

#%%
#creating a 1D array containing only 1s (x0)
x0= np.ones((100,1))
#concatenating it to the main variable x
x = np.concatenate((x0,x),axis=1)
#shape of x has been changed to (100,6) now 
print(x.shape)

#%%
#calculating the weights 
#w wala equation 
W = np.dot(np.dot( np.linalg.inv(np.dot(x.transpose(),x)), x.transpose()),t)
#printing the shape of the weights 
print(W.shape)
# print(W)

#%%
#calculating the values of y 
y=0
for i in range(0,x.shape[1]):
    y = y + W[i]*x[i]
print(y.shape)
print(y)

#%%
#performing regression using sklearn library
# LinearRegression fits a linear model with coefficients w = (w1, ..., wp) to minimize the residual sum of squares between the observed targets in the dataset, and the targets predicted by the linear approximation. 
# .fit() : Fits linear model.
reg = LinearRegression().fit(x,t)

#Return the coefficient of determination of the prediction.
print("Reg score : ",reg.score(x,t))
#%%
#coef_
#Estimated coefficients for the linear regression problem. If multiple targets are passed during the fit (y 2D), this is a 2D array of shape (n_targets, n_features), while if only one target is passed, this is a 1D array of length n_features.
print("Regression coefficient : ",reg.coef_)
#%%


# intercept_
# Independent term in the linear model. 
print("Regression intercept : ",reg.intercept_)
# %%
