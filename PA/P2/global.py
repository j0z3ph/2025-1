var_global = 5

def funcion():
    global var_global
    var_global = 10
    
    
def funcion2():
    var_local = 4
    def funcion2_interna():
        nonlocal var_local
        var_local = 6
    
    
funcion()
print(var_global)