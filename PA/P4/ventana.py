import tkinter as tk
from tkinter import ttk

def presionado():
    texto.set("No tan fuerte >:(")
    
    

ventana = tk.Tk()
ventana.wm_title("Mi primer ventana")

texto = tk.StringVar()
texto.set("Hola")
etiqueta = ttk.Label(ventana,textvariable=texto,foreground="red")
etiqueta.pack()

entrada = tk.Entry(ventana,justify="left").pack()

boton = tk.Button(ventana,text="Apachurrame", command=presionado)

boton.pack()
#ventana.wm_minsize(800, 600)

ventana.mainloop()
