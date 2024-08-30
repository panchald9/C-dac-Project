import tkinter as tk

class PhoneApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Phone Interface")
        
        self.create_widgets()
    
    def create_widgets(self):
        self.display_var = tk.StringVar()
        self.display = tk.Entry(self.root, textvariable=self.display_var, font=("Arial", 24), bd=10, insertwidth=2, width=15, borderwidth=4)
        self.display.grid(row=0, column=0, columnspan=3)
        
        button_texts = [
            ('1', 1, 0), ('2', 1, 1), ('3', 1, 2),
            ('4', 2, 0), ('5', 2, 1), ('6', 2, 2),
            ('7', 3, 0), ('8', 3, 1), ('9', 3, 2),
            ('*', 4, 0), ('0', 4, 1), ('#', 4, 2)
        ]
        
        for (text, row, col) in button_texts:
            self.create_button(text, row, col)
        
        self.create_button("Call", 5, 0, self.call, color="green")
        self.create_button("Clear", 5, 2, self.clear, color="red")
    
    def create_button(self, text, row, col, command=None, color=None):
        if not command:
            command = lambda: self.button_click(text)
        button = tk.Button(self.root, text=text, padx=20, pady=20, font=("Arial", 18), bg=color, command=command)
        button.grid(row=row, column=col, padx=5, pady=5)
    
    def button_click(self, number):
        current = self.display_var.get()
        self.display_var.set(current + number)
    
    def call(self):
        number = self.display_var.get()
        if number:
            print(f"Calling {number}...")
            self.display_var.set("Calling...")
    
    def clear(self):
        self.display_var.set("")

if __name__ == "__main__":
    root = tk.Tk()
    app = PhoneApp(root)
    root.mainloop()
