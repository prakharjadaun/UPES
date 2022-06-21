# -*- coding: utf-8 -*-
"""
Created on Fri Feb  4 10:07:58 2022

@author: Prakhar Jadaun
"""
#%%
#importing the required libraries 
from sklearn.datasets import make_regression
from sklearn.linear_model import LinearRegression
import numpy as np 

#%%
#generating data set values using make_regression() func. 

x,t = make_regression(100,5,n_targets=3,shuffle=True,bias=0,noise=0,random_state=2)
#initial shape of x 

#%%
print(x.shape)   
print(t.shape)

#initial shape of t (target variable)

#%%
#creating a 1D array containing only 1s (x0)
x0= np.ones((100,1))
#concatenating it to the main variable x
x = np.concatenate((x0,x),axis=1)
#%%
#shape of x has been changed to (100,6) now 
print(x.shape)

#%%
#using sigmoid function
x = 1/(1 + np.exp(-x))
print(x.shape)

#%%

#calculating the weights 
W = np.dot(np.dot( np.linalg.inv(np.dot(x.transpose(),x)), x.transpose()),t)
#printing the shape of the weights 
print(W.shape)
print(W)
print(x.shape)
#%%
# y = Wt x X
y = np.dot(W.transpose(),x.transpose())
print(y.shape)

#%%
#performing regression using sklearn library
# .fit() : Fits linear model. 
reg = LinearRegression().fit(x,t)

#Return the coefficient of determination of the prediction.
print("Reg score : ",reg.score(x,t))


#%%
print("Regression coefficient : \n",(reg.coef_.transpose()))

#%%
# intercept_
# Independent term in the linear model.
print("Regression intercept : \n",reg.intercept_)


# %%
