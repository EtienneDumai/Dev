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
