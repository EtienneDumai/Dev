import sys
from PyQt5.QtWidgets import QApplication, QWidget, QLabel, QVBoxLayout

# Create the application
app = QApplication(sys.argv)

# Create a window
window = QWidget()
window.setWindowTitle("Simple Interface")

# Create a label
label = QLabel("Hello, World!")

# Create a layout and add the label to it
layout = QVBoxLayout()
layout.addWidget(label)

# Set the layout for the window
window.setLayout(layout)

# Show the window
window.show()

# Run the application
sys.exit(app.exec_())
import sys
from PyQt5.QtWidgets import QApplication, QWidget, QLabel, QVBoxLayout

# Create a custom QWidget class for our interface
class MyInterface(QWidget):
    def __init__(self):
        super().__init__()

        # Create the interface elements
        label = QLabel("Hello, World!")

        # Create a layout and add the elements to it
        layout = QVBoxLayout()
        layout.addWidget(label)

        # Set the layout for the QWidget
        self.setLayout(layout)

# Create the application instance
app = QApplication(sys.argv)

# Create an instance of our custom interface
interface = MyInterface()

# Show the interface
interface.show()

# Start the event loop
sys.exit(app.exec_())
import PySimpleGUI as sg

# Define the layout of the interface
layout = [
    [sg.Text("Welcome to the Interface!")],
    [sg.Button("Click Me")]
]

# Create the window
window = sg.Window("Simple Interface", layout)

# Event loop to process events and interact with the interface
while True:
    event, values = window.read()
    
    # If the window is closed or the "Click Me" button is clicked, exit the loop
    if event == sg.WINDOW_CLOSED or event == "Click Me":
        break

# Close the window
window.close()
import tkinter as tk

def button_click():
    label.config(text="Button clicked!")

root = tk.Tk()

label = tk.Label(root, text="Hello, World!")
label.pack()

button = tk.Button(root, text="Click me!", command=button_click)
button.pack()

root.mainloop()
