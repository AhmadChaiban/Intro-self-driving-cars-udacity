#Modify the program to find and print the sum of all 
#the entries in the list p.

p=[0.2, 0.2, 0.2, 0.2, 0.2]
pHit = 0.6
pMiss = 0.2

# p[0]=p[0]*pMiss
# p[1]=p[1]*pHit
# p[2]=p[2]*pHit
# p[3]=p[3]*pMiss
# p[4]=p[4]*pMiss

for i in range(len(p)):
    if i == 1 or i == 2:
        p[i] = p[i]*pHit
    else:
        p[i] = p[i]*pMiss

p_sum = sum(p)

for i in range(len(p)):
    p[i] = p[i]/p_sum

print p
