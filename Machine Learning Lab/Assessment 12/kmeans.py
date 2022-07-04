# -*- coding: utf-8 -*-
"""
Created on Fri Apr  8 11:52:10 2022

@author: Prakhar Jadaun
"""
#%%
from sklearn.svm import SVC
from sklearn.datasets import make_classification
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
from sklearn.cluster import KMeans
#%%
x = make_classification(100,2,n_classes=2,random_state=25)


#%%
model = KMeans(n_clusters=5)
temp = model.fit(x)

#%%

print(temp)


