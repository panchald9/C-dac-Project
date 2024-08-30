import tkinter as tk
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
        self.calendar_frame = tk.Frame(self.root)
        self.calendar_frame.pack()
        
        self.month_year_label = tk.Label(self.root, text="", font=("Arial", 16))
        self.month_year_label.pack()
        
        self.prev_button = tk.Button(self.root, text="<<", command=self.prev_month)
        self.prev_button.pack(side=tk.LEFT)
        
        self.next_button = tk.Button(self.root, text=">>", command=self.next_month)
        self.next_button.pack(side=tk.RIGHT)
    
    def show_calendar(self, year, month):
        self.month_year_label.config(text=f"{calendar.month_name[month]} {year}")
        
        cal = calendar.monthcalendar(year, month)
        
        for widget in self.calendar_frame.winfo_children():
            widget.destroy()
        
        days = ["Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"]
        for day in days:
            tk.Label(self.calendar_frame, text=day, font=("Arial", 12), borderwidth=1, relief="solid").grid(row=0, column=days.index(day))
        
        for week in range(len(cal)):
            for day in range(len(cal[week])):
                day_num = cal[week][day]
                if day_num != 0:
                    tk.Label(self.calendar_frame, text=str(day_num), font=("Arial", 12), borderwidth=1, relief="solid", width=5).grid(row=week+1, column=day)
    
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
    app = CalendarApp(root)
    root.mainloop()
