# -*- coding: utf-8 -*-
"""
Created on Fri Mar 11 11:12:56 2022

@author: Prakhar Jadaun
"""
#%%
#decision tree classifier 

#required libraries 
from sklearn.datasets import make_classification
from sklearn.model_selection import train_test_split
from sklearn import tree
from sklearn.metrics import accuracy_score

#number of classes in the target column
classes = 3

#%%

#creating the data set using the classification function
x,t = make_classification(100,5,n_classes = classes, random_state=40,n_informative = 2,n_clusters_per_class=1)

#%%
#printing the shape of the x and t 
print("Shape of x : ",x.shape)
print("Shape of t : ",t.shape)

#%%
#splitting the data set into the training 
x_train,x_test,t_train,t_test = train_test_split(x,t)

#%%
#defining or model
# A decision tree classifier.
# splitter{“best”, “random”}, default=”best”
# The strategy used to choose the split at each node. Supported strategies are “best” to choose the best split and “random” to choose the best random split.
model = tree.DecisionTreeClassifier(splitter='best')
#fitting our model 
model.fit(x_train,t_train)

#%%
#plottting the model in the form of the tree 
tree.plot_tree(model)

#%%
#predicting values with unseen data set
y_pred = model.predict(x_test)

#%%
#calculatung the accuracy score between the actual and the predicted data 
print(accuracy_score(t_test,y_pred))


# %%
