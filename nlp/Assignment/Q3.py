# edit distance
s1 = input("Enter the first string: ")
s2 = input("Enter the second string: ")

dp = [[0 for x in range(len(s1)+1)] for x in range(len(s2)+1)]

for i in range(len(s1)):
    dp[0][i] = i

for i in range(len(s2)):
    dp[i][0] = i

for i in range(1, len(s1)+1):
    for j in range(1, len(s2)+1):
        if s1[i-1] != s2[j-1]:
            dp[i][j] = 1 + min(dp[i-1][j],  dp[i][j-1], dp[i-1][j-1])
        else:
            dp[i][j] = dp[i-1][j-1]

print(dp[len(s1)][len(s2)])
