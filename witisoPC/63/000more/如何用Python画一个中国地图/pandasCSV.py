import pandas as pd
import numpy as np
df = pd.read_csv('chnpop.csv', header=None,sep=' ')
#df=pd.read_csv('chnpop.csv',header=None,sep=' ') 
print(df.head())
print(df.tail())
