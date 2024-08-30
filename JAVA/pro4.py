import tkinter as tk
from tkinter import ttk
import calendar
from datetime import datetime

class CalendarApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Calendar")

        self.current_year = datetime.now().year
        self.current_month = datetime.now().month

        self.create_widgets()
        self.show_calendar(self.current_year, self.current_month)

    def create_widgets(self):
        header_frame = tk.Frame(self.root)
        header_frame.pack(pady=10)

        self.date_label = tk.Label(header_frame, text="", font=("Arial", 18))
        self.date_label.pack(side=tk.LEFT)

        self.month_var = tk.StringVar()
        self.month_var.set(calendar.month_name[self.current_month])
        self.month_menu = ttk.Combobox(header_frame, textvariable=self.month_var, values=list(calendar.month_name)[1:], state="readonly", width=12)
        self.month_menu.pack(side=tk.LEFT, padx=5)
        self.month_menu.bind("<<ComboboxSelected>>", self.update_calendar)

        self.year_var = tk.StringVar()
        self.year_var.set(str(self.current_year))
        self.year_menu = ttk.Combobox(header_frame, textvariable=self.year_var, values=[str(y) for y in range(1980, 2101)], state="readonly", width=6)
        self.year_menu.pack(side=tk.LEFT)
        self.year_menu.bind("<<ComboboxSelected>>", self.update_calendar)

        self.calendar_frame = tk.Frame(self.root)
        self.calendar_frame.pack()

    def show_calendar(self, year, month):
        self.date_label.config(text=f"{calendar.month_name[month]} {year}")

        for widget in self.calendar_frame.winfo_children():
            widget.destroy()

        days = ["Su", "Mo", "Tu", "We", "Th", "Fr", "Sa"]
        for day in days:
            tk.Label(self.calendar_frame, text=day, font=("Arial", 12), width=5).grid(row=0, column=days.index(day))

        cal = calendar.monthcalendar(year, month)

        for r, week in enumerate(cal, 1):
            for c, day in enumerate(week):
                if day != 0:
                    tk.Button(self.calendar_frame, text=str(day), font=("Arial", 12), width=5).grid(row=r, column=c)

    def update_calendar(self, event):
        month = list(calendar.month_name).index(self.month_var.get())
        year = int(self.year_var.get())

        self.show_calendar(year, month)

if __name__ == "__main__":
    root = tk.Tk()
    app = CalendarApp(root)
    root.mainloop()
