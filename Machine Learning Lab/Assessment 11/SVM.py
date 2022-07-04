# -*- coding: utf-8 -*-
"""
Created on Fri Apr  8 11:38:27 2022

@author: Prakhar Jadaun
"""

#%%
from sklearn.svm import SVC
from sklearn.datasets import make_classification
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
import matplotlib.pyplot as plt
from mlxtend.plotting import plot_decision_regions

#%%
x,t = make_classification(n_samples=100,n_classes=2,random_state=25)

#%%

print(x.shape)
print(t.shape)

x = x[:,0:2]
print(x.shape)
#%%
x_train,x_test, t_train,t_test = train_test_split(x,t,random_state=80)

#%%

# Support vector machines (SVMs) are a set of supervised learning methods used for classification, regression and outliers detection.

# The advantages of support vector machines are:

# Effective in high dimensional spaces.

# Still effective in cases where number of dimensions is greater than the number of samples.

# Uses a subset of training points in the decision function (called support vectors), so it is also memory efficient.

# Versatile: different Kernel functions can be specified for the decision function. Common kernels are provided, but it is also possible to specify custom kernels.

# The disadvantages of support vector machines include:

# If the number of features is much greater than the number of samples, avoid over-fitting in choosing Kernel functions and regularization term is crucial.

# SVMs do not directly provide probability estimates, these are calculated using an expensive five-fold cross-validation (see Scores and probabilities, below).


model = SVC(decision_function_shape='ovo')
model.fit(x_train,t_train)

#%%

y_pred = model.predict(x_test)

#%%

print(accuracy_score(t_test, y_pred))

#%%


plot_decision_regions(x_test, t_test, clf=model)
plt.xlabel("X")
plt.ylabel("T")
plt.title("Testing data")


#%%


plot_decision_regions(x_test, y_pred, clf=model)
plt.xlabel("X")
plt.ylabel("T")
plt.title("Predicted data")
plt.show()


# %%
