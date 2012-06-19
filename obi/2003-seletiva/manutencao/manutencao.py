
n = 400
print("%d %d" % (n, n-1))

for i in range(1, 400):
    print("%d %d" % (i, i +1))
    
print("%d %d" % (n, n*(n-1)//2))

for i in range(1, 400):
    for j in range(i + 1, 401):
        print("%d %d" % (i, j))
        
print("0 0")
