
# SubTask-1

# How to run program :-

1. type make on command line

2. then type
a)./yourcode.out fullyconnected inputmatrix.txt weightmatrix.txt biasmatrix.txt outputmatrix.txt :-- To use fullyconnected function 
b)./yourcode.out activation relu inputmatrix.txt outputmatrix.txt --> for using relu function
c)./yourcode.out activation tanh inputmatrix.txt outputmatrix.txt --> for using tanh function
d)./yourcode.out pooling average inputmatrix.txt stride outputmatrix.txt --> for using pooling average function
e)./yourcode.out probability softmax inputvector.txt outputvector.txt --> for using probability softmax function
f)./yourcode.out probability sigmoid inputvector.txt outputvector.txt --> for using probability sigmoid function 
g)./yourcode.out pooling max inputmatrix.txt stride outputmatrix.txt --> for using pooling max function

3. This will give you outputmatrix/outputvector in that txt file.

4. all these test files should be made by you in a particular format
```
row
column
column-major order matrix
```

