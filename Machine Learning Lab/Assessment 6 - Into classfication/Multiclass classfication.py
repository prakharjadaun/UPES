# -*- coding: utf-8 -*-
"""
Created on Fri Feb 25 12:40:29 2022

@author: Prakhar Jadaun
"""
#importing the required librarie
from sklearn.model_selection import train_test_split
from sklearn.datasets import make_classification
import numpy as np
from sklearn.metrics import accuracy_score
'''

X, t = make_classification(100, 5, n_classes = classes, random_state= 40, n_informative = 2, n_clusters_per_class = 1)

res = np.zeros((t.shape[0], classes), dtype=int)

res[np.arange(t.shape[0]), t] = 1
'''

classes = 3
X, t = make_classification(100, 5, n_classes = classes, random_state= 40, n_informative = 2, n_clusters_per_class = 1)

res = np.zeros((t.shape[0], classes), dtype=int)
res[np.arange(t.shape[0]), t] = 1

#creating a 1D array containing only 1s (x0)
x0= np.ones((100,1))
#concatenating it to the main variable x
X = np.concatenate((x0,X),axis=1)

print(X.shape)
print(res.shape)

X_train,X_test, res_train,res_test = train_test_split(X,res,random_state=80)
W = np.dot(np.dot( np.linalg.inv(np.dot(X_train.transpose(),X_train)), X_train.transpose()),res_train)

y = np.dot(X_test,W)
print(y.shape)

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