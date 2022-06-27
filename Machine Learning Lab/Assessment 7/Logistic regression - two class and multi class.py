# -*- coding: utf-8 -*-
"""
Created on Fri Mar  4 11:10:26 2022

@author: Prakhar Jadaun
"""
#%%
#importing the required librarie
from sklearn.model_selection import train_test_split
from sklearn.datasets import make_classification
import numpy as np
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score
from sklearn.linear_model import SGDClassifier

#%%
#creating the data set for performing classfication
x,t = make_classification(100,5,n_classes=2,random_state=25)
print(x.shape)
print(t.shape)
#print(t)
#print(x)

#%%
#creating a 1D array containing only 1s (x0)
x0= np.ones((100,1))
#concatenating it to the main variable x
x = np.concatenate((x0,x),axis=1)

#%%
x_train,x_test, t_train,t_test = train_test_split(x,t,random_state=80)

#%%
print(x_train.shape)
print(t_train.shape)

#%%
print(x_test.shape)
print(t_test.shape)

#%%

# Logistic Regression (aka logit, MaxEnt) classifier.
# This class implements regularized logistic regression using the ‘liblinear’ library, ‘newton-cg’, ‘sag’, ‘saga’ and ‘lbfgs’ solvers. Note that regularization is applied by default. It can handle both dense and sparse input.
# The ‘newton-cg’, ‘sag’, and ‘lbfgs’ solvers support only L2 regularization with primal formulation, or no regularization. The ‘liblinear’ solver supports both L1 and L2 regularization, with a dual formulation only for the L2 penalty. The Elastic-Net regularization is only supported by the ‘saga’ solver.

model = LogisticRegression(penalty='l2',solver='newton-cg',max_iter=100,C=1.0)
model.fit(x_train,t_train)

#%%
y_test = model.predict(x_test)
y_train = model.predict(x_train)
#print(y)

#%%
print(model.coef_)
print(model.intercept_)

#%%
#calculating the accuracy 
train_acc = accuracy_score(t_train,y_train)
test_acc =  accuracy_score(t_test,y_test)
print(train_acc)
#%%
print(test_acc)

#%%
print("Difference between train and test accuracy : ",(train_acc-test_acc))

#%%

#-------------------- Multi class logistic regression ----------------



print("----------------Multi Class Logistic regression------------")
classes = 3
X, t = make_classification(100, 5, n_classes = classes, random_state= 40, n_informative = 2, n_clusters_per_class = 1)

#%%
#res = np.zeros((t.shape[0], classes), dtype=int)
#res[np.arange(t.shape[0]), t] = 1

#%%
#creating a 1D array containing only 1s (x0)
x0= np.ones((100,1))
#concatenating it to the main variable x
X = np.concatenate((x0,X),axis=1)

print(X.shape)
#print(res.shape)
#%%

X_train,X_test, res_train,res_test = train_test_split(X,t,random_state=80)

#%%
# Logistic Regression (aka logit, MaxEnt) classifier.


model = LogisticRegression(penalty='l2',solver='newton-cg',max_iter=100,multi_class="multinomial")

#%%
#model = SGDClassifier(loss='log')
print(X_train.shape)
print(res_train.shape)
model.fit(X_train,res_train)

#%%
y_test = model.predict(X_test)
y_train = model.predict(X_train)


#%%
#calculating the accuracy 
train_acc = accuracy_score(res_train,y_train)
test_acc =  accuracy_score(res_test,y_test)
print(train_acc)
print(test_acc)
print("Difference between train and test accuracy : ",(train_acc-test_acc))


# %%
