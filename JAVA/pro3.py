import tkinter as tk
import calendar
from datetime import datetime

class PhoneCalendarApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Phone Calendar Interface")

        self.current_year = datetime.now().year
        self.current_month = datetime.now().month

        self.create_widgets()
        self.show_calendar(self.current_year, self.current_month)

    def create_widgets(self):
        self.display_var = tk.StringVar()
        self.display = tk.Entry(self.root, textvariable=self.display_var, font=("Arial", 24), bd=10, insertwidth=2, width=15, borderwidth=4)
        self.display.grid(row=0, column=0, columnspan=3)

        self.buttons = []
        for i in range(1, 10):
            self.create_button(str(i), i // 3 + 1, (i - 1) % 3)

        self.create_button("10", 4, 0)
        self.create_button("11", 4, 1)
        self.create_button("12", 4, 2)
        self.create_button("13", 5, 0)
        self.create_button("14", 5, 1)
        self.create_button("15", 5, 2)
        self.create_button("16", 6, 0)
        self.create_button("17", 6, 1)
        self.create_button("18", 6, 2)
        self.create_button("19", 7, 0)
        self.create_button("20", 7, 1)
        self.create_button("21", 7, 2)
        self.create_button("22", 8, 0)
        self.create_button("23", 8, 1)
        self.create_button("24", 8, 2)
        self.create_button("25", 9, 0)
        self.create_button("26", 9, 1)
        self.create_button("27", 9, 2)
        self.create_button("28", 10, 0)
        self.create_button("29", 10, 1)
        self.create_button("30", 10, 2)
        self.create_button("31", 11, 1)

        self.create_button("<<", 11, 0, self.prev_month, "lightblue")
        self.create_button(">>", 11, 2, self.next_month, "lightblue")
    
    def create_button(self, text, row, col, command=None, color=None):
        if not command:
            command = lambda: self.select_day(text)
        button = tk.Button(self.root, text=text, padx=20, pady=20, font=("Arial", 18), bg=color, command=command)
        button.grid(row=row, column=col, padx=5, pady=5)
        self.buttons.append(button)

    def show_calendar(self, year, month):
        self.display_var.set(f"{calendar.month_name[month]} {year}")

        days_in_month = calendar.monthrange(year, month)[1]
        for i in range(31):
            if i < days_in_month:
                self.buttons[i].config(state="normal")
            else:
                self.buttons[i].config(state="disabled")
    
    def select_day(self, day):
        self.display_var.set(f"Selected Date: {day} {calendar.month_name[self.current_month]} {self.current_year}")
    
    def prev_month(self):
        self.current_month -= 1
        if self.current_month == 0:
            self.current_month = 12
            self.current_year -= 1
        self.show_calendar(self.current_year, self.current_month)
    
    def next_month(self):
        self.current_month += 1
        if self.current_month == 13:
            self.current_month = 1
            self.current_year += 1
        self.show_calendar(self.current_year, self.current_month)

if __name__ == "__main__":
    root = tk.Tk()
    app = PhoneCalendarApp(root)
    root.mainloop()
