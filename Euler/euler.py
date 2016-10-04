
def calculateTriangles(n):
    triangles = [1]
    result = 1
    for i in range(2,n):
        result += i
        triangles += [result]
    return triangles

def findTriangle(triangles, n):
    for triangle in triangles:
        x = 1
        temp = 1
        remainingValue = triangle
        while  x*x <= triangle:
            if triangle % x == 0:
                temp += 2
            x += 1
        if x*x == triangle:
            temp -= 1
        if temp >  n:
            return triangle

    return -1

triangles = calculateTriangles(100000)
print findTriangle(triangles,500)
