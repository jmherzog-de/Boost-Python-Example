import matplotlib.pyplot as plt
import math

'''
This method draw a simple 2D-plot of given input data x and y
'''
def Plot2D(x,y,title_text,xlabel_text,ylabel_text):
    plt.plot(x,y)
    plt.title(title_text)
    plt.xlabel(xlabel_text)
    plt.ylabel(ylabel_text)
    plt.show()
    return 0

'''
This method add x and y and return the sum
'''
def Add(x,y):
    return x+y

'''
Call functions for direct testing purposes
'''
#Plot2D([1,2,3,4],[1,2,3,4], 'Gerade', 'x', 'y')
#Add(3,1)