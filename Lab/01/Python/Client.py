from tkinter import *
from json import *
import requests
def font1(event):
	r = requests.get('http://localhost:1234/raw')
	p = r.json()
	f = str(p["description_12"])
	f = f.encode('l1').decode()



r = requests.get('http://localhost:1234/raw')
p = r.json()
f = str(p["description_12"])
f = f.encode('l1').decode()


root = Tk()
root.title("HELLO OCHEREDNOY")

City = Label(root, width = 17, text = "Симферополь",  font= "Arial 12", bg="orange")
Description = Label(root, width = 25, height = 1, text = (f), font= " Arial 8", bg="orange")
Temp = Label(root, text =(p["Temperature"],"°C"), height = 2 , font = "Arial 30")
Bottom = Label(root, width = 22,height = 2, bg = "orange")


City.grid(row=0,column=0)
Description.grid(row=1,column=0)
Temp.grid(row=2,column=0)
Bottom.grid(row=3,column=0)
City.bind('<Button-3>', font1 )
Description.bind('<Button-3>', font1)
Temp.bind('<Button-3>', font1)
Bottom.bind('<Button-3>', font1)
root.mainloop()
