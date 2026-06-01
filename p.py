def func1(fator):
    def func2(x):
        return x * fator
    return func2

funcao = func1(3)
print(funcao(5))