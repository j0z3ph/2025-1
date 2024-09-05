var_global = 5

def funcion():
    global var_global
    var_global = 10
    
funcion()
print(var_global)