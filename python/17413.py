s = input()
answer = ""
stack = []
for i in s:
    if len(stack) == 0:
        if i == '<': answer += '<'
        stack.append(i)
    elif stack[-1] == '<':
        if i == '>': stack.pop()
        answer += i
    elif i == '<' or i == ' ':
        while len(stack) > 0:
            answer += stack.pop()
        if i == '<':
            answer += '<'
            stack.append(i)
        else:
            answer += " "
    else:
        stack.append(i)
while len(stack) > 0:
    answer += stack.pop()
print(answer)