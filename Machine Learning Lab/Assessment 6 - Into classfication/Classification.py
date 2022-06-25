# -*- coding: utf-8 -*-
"""
Created on Fri Feb 25 11:06:55 2022

@author: Prakhar Jadaun
SAP ID : 500083429
"""
#%%
#importing the required librarie
from sklearn.model_selection import train_test_split
from sklearn.datasets import make_classification
import numpy as np
from sklearn.metrics import accuracy_score

#%%
#creating the data set for performing classfication
# Generate a random n-class classification problem.
# This initially creates clusters of points normally distributed (std=1) about vertices of an n_informative-dimensional hypercube with sides of length 2*class_sep and assigns an equal number of clusters to each class. 
x,t = make_classification(100,5,n_classes=2,random_state=25)
print(x.shape)
print(t.shape)


#%%
#creating a 1D array containing only 1s (x0)
x0= np.ones((100,1))
#concatenating it to the main variable x
x = np.concatenate((x0,x),axis=1)

x_train,x_test, t_train,t_test = train_test_split(x,t,random_state=80)
print(x_train.shape)
print(t_train.shape)

#%%

print(x_test.shape)
print(t_test.shape)

#%%
#computing w
W = np.dot(np.dot( np.linalg.inv(np.dot(x_train.transpose(),x_train)), x_train.transpose()),t_train)
print(W)

#%%
#predicting the y(new) with unseeen x (x new)
t_pred = np.dot(x_test,W.transpose())
print(t_pred)

#%%
#assigning the respective class value that is 0 or 1
for i in range(len(t_pred)):
    if(t_pred[i]>=0):
        t_pred[i]=1
    else:
        t_pred[i]=0

#%%
#printing the 
print("Predicted t :",t_pred)
print("Original t : ",t_test)
print(len(t_pred))

#%%

print(W)

#%%

#----- multi class classfication--------------

classes = 3
X, t = make_classification(100, 5, n_classes = classes, random_state= 40, n_informative = 2, n_clusters_per_class = 1)

res = np.zeros((t.shape[0], classes), dtype=int)
res[np.arange(t.shape[0]), t] = 1

#creating a 1D array containing only 1s (x0)
x0= np.ones((100,1))
#concatenating it to the main variable x
X = np.concatenate((x0,X),axis=1)
#%%

print(X.shape)
print(res.shape)

#%%
X_train,X_test, res_train,res_test = train_test_split(X,res,random_state=80)
W = np.dot(np.dot( np.linalg.inv(np.dot(X_train.transpose(),X_train)), X_train.transpose()),res_train)

#%%
y = np.dot(X_test,W)
print(y.shape)

#%%
for i in range(len(y)):
    if(y[i][0]>y[i][1] and y[i][0]>y[i][2]):
        y[i][0]=1
        y[i][1]=0
        y[i][2]=0
    elif(y[i][1]>y[i][0] and y[i][1]>y[i][2]):
        y[i][0]=0
        y[i][1]=1
        y[i][2]=0
    else:
        y[i][0]=0
        y[i][1]=0
        y[i][2]=1

#accuracy
print(accuracy_score(res_test,y))








# %%
