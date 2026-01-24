if __name__ == '__main__':
    n = int(input())
    arr = map(int, input().split())
    
max_num = float('-inf')
second_max = float('-inf')
for i in arr:
    if i > max_num:
        second_max = max_num
        max_num = i
        
    if  (i > second_max and i != max_num):
        second_max = i
            
print(second_max)
