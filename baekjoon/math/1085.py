## Bronze3

#             (n,h)
#
#       (x,y)
#
# (0,0)------------

# input = x y w h



x, y, w, h = map(int, input().split())
print(min(x, y, h-y, w-x))
