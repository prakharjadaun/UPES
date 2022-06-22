# -*- coding: utf-8 -*-
"""
Created on Fri Feb 11 11:39:41 2022

@author: Prakhar Jadaun
"""
#%%
#importing the required libraries 
from sklearn.datasets import make_regression
from sklearn.linear_model import LinearRegression
from sklearn.linear_model import Ridge
from sklearn.model_selection import train_test_split
from sklearn.metrics import r2_score
import matplotlib.pyplot as plt 

#%%
#for storing the different noise values 
NOISE = [0,10,30,100]
#for storing the r2 score of training data using Linear regression 
SCORE_train = []
#for storing the r2 score of testing data using Linear Regression 
SCORE_test = []
#for storing the r2 score of training data using Ridge regression 
SCORE_train_ridge =[]
#for storing the r2 score of testing data using Ridge regression 
SCORE_test_ridge=[]

#%%
for i in NOISE :
    #generating data set values using make_regression() func. 
    x,t = make_regression(100,5,n_targets=3,shuffle=True,bias=0,noise=i,random_state=10)
    
    #Split arrays or matrices into random train and test subsets
    x_train,x_test, t_train,t_test = train_test_split(x,t)
    #performing regression using sklearn library 
    reg = LinearRegression().fit(x_train,t_train)
    #predicting with linear regression model both with the training and the testing data set
    y_pred_train = reg.predict(x_train)
    y_pred_test = reg.predict(x_test)
    
    #calculating the r2 score for training and testing data set through linear regression
    score = r2_score(t_train,y_pred_train)
    SCORE_train.append(score)
    score = r2_score(t_test,y_pred_test)
    SCORE_test.append(score)
    
    #training the ridge regression model 
    #This model solves a regression model where the loss function is the linear least squares function and regularization is given by the l2-norm. Also known as Ridge Regression or Tikhonov regularization. 
    ridge_reg = Ridge(alpha=0.5).fit(x_train,t_train)
    #predicting with the help of Ridge Regression 
    y_pred_train = ridge_reg.predict(x_train)
    y_pred_test = ridge_reg.predict(x_test)
    
    #calculating the r2 score for training and testing data set
    score = r2_score(t_train,y_pred_train)
    SCORE_train_ridge.append(score)
    score = r2_score(t_test,y_pred_test)
    SCORE_test_ridge.append(score)

#%%
#printing the r2 scores of linear regression with training and the testing data set
print("Score with linear regression : ")
print(SCORE_train)
print(SCORE_test)


#%%
#printing the r2 scores of ridge regression with training and the testing data set
print("Score with Ridge regression : ")
print(SCORE_train_ridge)
print(SCORE_test_ridge)


#%%
#plotting the r2score of training and testing data through linear regression
plt.plot(NOISE,SCORE_train)
plt.plot(NOISE,SCORE_test)
plt.ylabel("R2 SCORE")
plt.xlabel("NOISE")
plt.title("With Linear Regression")
plt.show()

#%%
#plotting the r2score of training and testing data through Ridge regression
plt.plot(NOISE,SCORE_train_ridge)
plt.plot(NOISE,SCORE_test_ridge)
#labelling the x and y axis
plt.ylabel("R2 SCORE")
plt.xlabel("NOISE")
#setting the title for the graph
plt.title("With Ridge Regression")
plt.show()
