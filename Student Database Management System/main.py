class Student:
    def __init__(self, fname, lname, roll, cgpa, cid):
        self.fname = fname
        self.lname = lname
        self.roll = roll
        self.cgpa = cgpa
        self.cid = cid

class StudentDB:
    def __init__(self):
        self.students = []

    def add_student(self):
        fname = input("Enter first name: ")
        lname = input("Enter last name: ")
        roll = int(input("Enter roll number: "))
        cgpa = float(input("Enter CGPA: "))
        cid = []
        for i in range(5):
            cid.append(int(input(f"Enter course ID {i+1}: ")))
        student = Student(fname, lname, roll, cgpa, cid)
        self.students.append(student)
        print("Student added successfully!")

    def find_by_roll(self):
        roll = int(input("Enter roll number: "))
        for student in self.students:
            if student.roll == roll:
                print("Student found!")
                print(f"First name: {student.fname}")
                print(f"Last name: {student.lname}")
                print(f"CGPA: {student.cgpa}")
                print("Course IDs: ", end="")
                for cid in student.cid:
                    print(cid, end=" ")
                print()
                return
        print("Student not found!")

    def find_by_fname(self):
        fname = input("Enter first name: ")
        for student in self.students:
            if student.fname == fname:
                print("Student found!")
                print(f"Last name: {student.lname}")
                print(f"Roll number: {student.roll}")
                print(f"CGPA: {student.cgpa}")
                print("Course IDs: ", end="")
                for cid in student.cid:
                    print(cid, end=" ")
                print()
                return
        print("Student not found!")

    def find_by_cid(self):
        cid = int(input("Enter course ID: "))
        for student in self.students:
            if cid in student.cid:
                print("Student found!")
                print(f"First name: {student.fname}")
                print(f"Last name: {student.lname}")
                print(f"Roll number: {student.roll}")
                print(f"CGPA: {student.cgpa}")
                return
        print("Student not found!")

    def total_students(self):
        print(f"Total students: {len(self.students)}")

    def delete_student(self):
        roll = int(input("Enter roll number to delete: "))
        for i, student in enumerate(self.students):
            if student.roll == roll:
                del self.students[i]
                print("Student deleted successfully!")
                return
        print("Student not found!")

    def update_student(self):
        roll = int(input("Enter roll number to update: "))
        for student in self.students:
            if student.roll == roll:
                print("Enter new details:")
                student.fname = input("Enter first name: ")
                student.lname = input("Enter last name: ")
                student.cgpa = float(input("Enter CGPA: "))
                student.cid = []
                for i in range(5):
                    student.cid.append(int(input(f"Enter course ID {i+1}: ")))
                print("Student updated successfully!")
                return
        print("Student not found!")

def main():
    db = StudentDB()
    while True:
        print("1. Add student")
        print("2. Find student by roll number")
        print("3. Find student by first name")
        print("4. Find student by course ID")
        print("5. Total students")
        print("6. Delete student")
        print("7. Update student")
        print("8. Exit")
        choice = int(input("Enter your choice: "))
        if choice == 1:
            db.add_student()
        elif choice == 2:
            db.find_by_roll()
        elif choice == 3:
            db.find_by_fname()
        elif choice == 4:
            db.find_by_cid()
        elif choice == 5:
            db.total_students()
        elif choice == 6:
            db.delete_student()
        elif choice == 7:
            db.update_student()
        elif choice == 8:
            break
        else:
            print("Invalid choice!")

if __name__ == "__main__":
    main()