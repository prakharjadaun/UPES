# -*- coding: utf-8 -*-
"""
Created on Fri Feb 18 11:10:58 2022

@author: Prakhar Jadaun
"""
#%%
#importing the required libraries 
from sklearn.datasets import make_regression
from sklearn.linear_model import LinearRegression,Ridge,Lasso
from sklearn.model_selection import train_test_split
from sklearn.metrics import r2_score
import matplotlib.pyplot as plt 

#for storing the different noise values 
NOISE = [0,10,30,100]

#for storing the r2 score of training data using Linear regression 
SCORE_train_linear = []
#for storing the r2 score of testing data using Linear Regression 
SCORE_test_linear = []

#for storing the r2 score of training data using Ridge regression 
SCORE_train_ridge =[]
#for storing the r2 score of testing data using Ridge regression 
SCORE_test_ridge=[]

#for storing the r2 score of training data using Lasso regression 
SCORE_train_lasso = [] 
#for storing the r2 score of testing data using Lasso regression 
SCORE_test_lasso = [] 

for i in NOISE :
    #generating data set values using make_regression() func. 
    x,t = make_regression(50,8,n_targets=3,shuffle=True,bias=0,noise=i,random_state=50)
   
   #Split arrays or matrices into random train  and test subsets
    x_train,x_test, t_train,t_test = train_test_split(x,t)
    #performing regression using sklearn library 
    linear_reg = LinearRegression().fit(x_train,t_train)
    #predicting with linear regression 
    y_pred_train = linear_reg.predict(x_train)
    y_pred_test = linear_reg.predict(x_test)
    
    #calculating the r2 score for training and testing data set
    score = r2_score(t_train,y_pred_train)
    SCORE_train_linear.append(score)
    score = r2_score(t_test,y_pred_test)
    SCORE_test_linear.append(score)
    
   #training the ridge regression model 
    #This model solves a regression model where the loss function is the linear least squares function and regularization is given by the l2-norm. Also known as Ridge Regression or Tikhonov regularization. This estimator has built-in support for multi-variate regression
    ridge_reg = Ridge(alpha=100).fit(x_train,t_train)
    #predicting with the help of Ridge Regression 
    y_pred_train = ridge_reg.predict(x_train)
    y_pred_test = ridge_reg.predict(x_test)
    
    #calculating the r2 score for training and testing data set
    score = r2_score(t_train,y_pred_train)
    SCORE_train_ridge.append(score)
    score = r2_score(t_test,y_pred_test)
    SCORE_test_ridge.append(score)
    
    #training with lasso regression
    #Linear Model trained with L1 prior as regularizer (aka the Lasso).
    # The optimization objective for Lasso is:
    # (1 / (2 * n_samples)) * ||y - Xw||^2_2 + alpha * ||w||_1
    # Technically the Lasso model is optimizing the same objective function as the Elastic Net with l1_ratio=1.0
    lasso_reg = Lasso(alpha=15).fit(x_train,t_train)
    
    #predicting with the help of Lasso Regression
    y_pred_train = lasso_reg.predict(x_train)
    y_pred_test = lasso_reg.predict(x_test)
    
    #calculating the r2 score for training and testing data set 
    score = r2_score(t_train,y_pred_train)
    SCORE_train_lasso.append(score)
    score = r2_score(t_test,y_pred_test)
    SCORE_test_lasso.append(score)
#%% 
#printing the r2 scores with different noises  
print("Score with linear regression : ")
print("Training : ",SCORE_train_linear)
print("Testing : ",SCORE_test_linear)
print("\nScore with Ridge regression : ")
print("Training : ",SCORE_train_ridge)
print("Testing : ",SCORE_test_ridge)
print("\nScore with Lasso regression : ")
print("Training : ",SCORE_train_lasso)
print("Testing : ",SCORE_test_lasso)

#%%
#plotting the graph between noise and the scores calculated 
plt.plot(NOISE,SCORE_train_linear,label="Training set")
plt.plot(NOISE,SCORE_test_linear,label="Testing set")
plt.ylabel("R2 SCORE")
plt.xlabel("NOISE")
plt.title("With Linear Regression")
plt.legend()
plt.show()

#%%
plt.plot(NOISE,SCORE_train_ridge,label="Training set")
plt.plot(NOISE,SCORE_test_ridge,label="Testing set")
plt.ylabel("R2 SCORE")
plt.xlabel("NOISE")
plt.title("With Ridge Regression")
plt.legend()
plt.show()

#%%
plt.plot(NOISE,SCORE_train_lasso,label="Training set")
plt.plot(NOISE,SCORE_test_lasso,label="Testing set")
plt.ylabel("R2 SCORE")
plt.xlabel("NOISE")
plt.title("With Lasso Regression")
plt.legend()
plt.show()
