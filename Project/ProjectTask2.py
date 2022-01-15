import networkx as nx
import csv
import pandas as pd

graph=nx.DiGraph()

with open('dataset.csv','r') as CF:
    CSVR=csv.reader(CF)
    next(CSVR)

    for line in CSVR:    
        count = 14
        while(count != 44):
          # if line[count]!='0':
          graph.add_edge(line[3],line[count])
          count = count +3

x = input(print("do you want to sort the csv file ? : "))

if x == "yes":
  csvD=pd.read_csv("dataset.csv")
  print("Before Sorting the CSV : \n\n")
  print(csvD)

  csvD.sort_values(["N-Battery.9"], axis = 0 , ascending=[False], inplace = True)

  print("\nAfter sorting the CSV : \n\n")
  print(csvD)
  nx.draw_circular(graph,with_labels=1,node_size=250,width=.5)

if x == "no":
  nx.draw_circular(graph,with_labels=1,node_size=250,width=.5)