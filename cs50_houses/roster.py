import cs50
import csv
from sys import argv, exit

if len(argv) != 2:
    print('error occured')
    exit(1)


db = cs50.SQL("sqlite:///students.db")

rows = db.execute('SELECT first , middle, last , birth FROM students WHERE house = ? ORDER BY last' , argv[1])

for row in rows:
    print(row['first'] + ' '+ (row['middle'] + ' ' if row['middle'] else '') + row['last'] + ', born ' + str(row['birth']))






































